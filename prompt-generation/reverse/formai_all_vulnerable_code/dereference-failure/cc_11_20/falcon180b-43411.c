//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 25
#define MAX_LINE_LEN 1024
#define MAX_LINE_NUM 10
#define ERR_MSG_LEN 100

int main() {
    int sockfd;
    int ret;
    char recv_buf[MAX_LINE_LEN];
    char send_buf[MAX_LINE_LEN];
    char err_msg[ERR_MSG_LEN];
    int line_num = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        sprintf(err_msg, "Error creating socket: %s\n", strerror(errno));
        printf("%s", err_msg);
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        sprintf(err_msg, "Error connecting to server: %s\n", strerror(errno));
        printf("%s", err_msg);
        exit(1);
    }

    printf("Connected to server.\n");

    while (1) {
        memset(send_buf, 0, MAX_LINE_LEN);
        memset(recv_buf, 0, MAX_LINE_LEN);

        printf("Enter command (EHLO, MAIL FROM, RCPT TO, DATA, QUIT): ");
        fgets(send_buf, MAX_LINE_LEN, stdin);

        ret = send(sockfd, send_buf, strlen(send_buf), 0);
        if (ret == -1) {
            sprintf(err_msg, "Error sending data: %s\n", strerror(errno));
            printf("%s", err_msg);
            exit(1);
        }

        memset(recv_buf, 0, MAX_LINE_LEN);
        ret = recv(sockfd, recv_buf, MAX_LINE_LEN, 0);
        if (ret == -1) {
            sprintf(err_msg, "Error receiving data: %s\n", strerror(errno));
            printf("%s", err_msg);
            exit(1);
        }

        printf("Server response: %s\n", recv_buf);

        if (strstr(recv_buf, "250")!= NULL) {
            if (line_num == 0) {
                printf("Server ready.\n");
            } else if (line_num == 1) {
                printf("Mail from accepted.\n");
            } else if (line_num == 2) {
                printf("Rcpt to accepted.\n");
            } else if (line_num == 3) {
                printf("Data accepted.\n");
            } else if (line_num == 4) {
                printf("Message sent.\n");
            }
        } else if (strstr(recv_buf, "550")!= NULL) {
            printf("Error: %s\n", recv_buf + 4);
        }

        line_num++;
    }

    close(sockfd);
    return 0;
}