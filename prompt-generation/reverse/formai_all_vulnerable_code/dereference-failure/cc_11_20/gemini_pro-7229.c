//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname("pop.example.com");
    if (!host) {
        perror("gethostbyname");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    char buf[1024];

    // Receive the greeting
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the username
    sprintf(buf, "USER %s\r\n", argv[1]);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the password
    sprintf(buf, "PASS %s\r\n", argv[2]);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the STAT command
    if (send(sock, "STAT\r\n", 6, 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    // Send the LIST command
    if (send(sock, "LIST\r\n", 6, 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response
    while (recv(sock, buf, sizeof(buf), 0) > 0) {
        printf("%s", buf);
    }

    // Send the QUIT command
    if (send(sock, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        return 1;
    }

    close(sock);

    return 0;
}