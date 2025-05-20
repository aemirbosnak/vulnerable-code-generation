//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <email>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *email = argv[2];

    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    addr.sin_addr = *(struct in_addr *) he->h_addr_list[0];

    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
        perror("socket");
        return 1;
    }

    if (connect(s, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    char buf[1024];
    int n;

    // Read the greeting message from the server
    n = recv(s, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the HELO command
    sprintf(buf, "HELO %s\r\n", host);
    n = send(s, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return 1;
    }

    // Read the HELO response from the server
    n = recv(s, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the MAIL FROM command
    sprintf(buf, "MAIL FROM: <%s>\r\n", email);
    n = send(s, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return 1;
    }

    // Read the MAIL FROM response from the server
    n = recv(s, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the RCPT TO command
    sprintf(buf, "RCPT TO: <%s>\r\n", email);
    n = send(s, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return 1;
    }

    // Read the RCPT TO response from the server
    n = recv(s, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the DATA command
    sprintf(buf, "DATA\r\n");
    n = send(s, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return 1;
    }

    // Read the DATA response from the server
    n = recv(s, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the email message
    sprintf(buf, "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
    n = send(s, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return 1;
    }

    // Read the QUIT response from the server
    n = recv(s, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Close the socket
    close(s);

    return 0;
}