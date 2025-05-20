//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_LINE 1024
#define POP3_PORT 110
#define USER "your_username"
#define PASS "your_password"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE];
    char send_buffer[MAX_LINE];
    char pop3_commands[] = "USER " USER "\r\n"
                            "PASS " PASS "\r\n"
                            "STAT\r\n"
                            "RETR 1\r\n"
                            ".\r\n";
    int cmd_index = 0;
    int bytes_read, bytes_sent;
    time_t start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("pop.gmail.com");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    start_time = time(NULL);

    while (cmd_index < sizeof(pop3_commands) - 1) {
        if (send(sockfd, pop3_commands + cmd_index, strlen(pop3_commands + cmd_index), 0) == -1) {
            perror("send");
            exit(1);
        }
        cmd_index += strlen(pop3_commands + cmd_index);
    }

    while (1) {
        bytes_read = recv(sockfd, buffer, MAX_LINE, 0);
        if (bytes_read <= 0) {
            printf("Disconnected from server\n");
            break;
        }
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    end_time = time(NULL);
    printf("Total time taken: %ld seconds\n", end_time - start_time);

    close(sockfd);
    return 0;
}