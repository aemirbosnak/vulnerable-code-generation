//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024
#define MAX_SUBJECT_LEN 80
#define MAX_BODY_LEN 2048

struct email {
    char recipient[256];
    char sender[256];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
};

int get_user_input(struct email *email) {
    printf("Recipient: ");
    scanf("%s", email->recipient);

    printf("Sender: ");
    scanf("%s", email->sender);

    printf("Subject: ");
    scanf("%s", email->subject);

    printf("Body: ");
    scanf("%[^\\n]", email->body);

    return 0;
}

int send_email(struct email *email) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    struct hostent *host = gethostbyname("smtp.example.com");
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(25);
    memcpy(&addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    char buf[MAX_BUF_SIZE];

    // Receive the greeting
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    }
    printf("Greeting: %s", buf);

    // Send the HELO command
    sprintf(buf, "HELO %s\r\n", host->h_name);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the HELO response
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    }
    printf("HELO response: %s", buf);

    // Send the MAIL FROM command
    sprintf(buf, "MAIL FROM: <%s>\r\n", email->sender);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the MAIL FROM response
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    }
    printf("MAIL FROM response: %s", buf);

    // Send the RCPT TO command
    sprintf(buf, "RCPT TO: <%s>\r\n", email->recipient);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the RCPT TO response
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    }
    printf("RCPT TO response: %s", buf);

    // Send the DATA command
    if (send(sockfd, "DATA\r\n", 5, 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the DATA response
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    }
    printf("DATA response: %s", buf);

    // Send the email headers
    sprintf(buf, "From: %s\r\n", email->sender);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    sprintf(buf, "To: %s\r\n", email->recipient);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    sprintf(buf, "Subject: %s\r\n", email->subject);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Send the email body
    sprintf(buf, "%s\r\n", email->body);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Send the end of the email
    if (send(sockfd, ".\r\n", 3, 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the end of the email response
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    }
    printf("End of email response: %s", buf);

    close(sockfd);

    return 0;
}

int main() {
    struct email email;

    get_user_input(&email);
    send_email(&email);

    return 0;
}