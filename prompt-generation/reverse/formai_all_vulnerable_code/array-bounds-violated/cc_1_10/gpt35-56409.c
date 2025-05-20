//FormAI DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;

    len = sizeof(cliaddr);

    while (1) {
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
        buffer[n] = '\0';
        if (strncmp(buffer, "add", 3) == 0) {
            float amount = atof(buffer + 4);
            FILE *fp = fopen("record.dat", "r");
            if (fp == NULL) {
                perror("File opening failed");
                exit(EXIT_FAILURE);
            }
            char temp[MAXLINE];
            fgets(temp, MAXLINE, fp);
            fclose(fp);
            float balance = atof(temp);
            balance += amount;
            fp = fopen("record.dat", "w");
            if (fp == NULL) {
                perror("File opening failed");
                exit(EXIT_FAILURE);
            }
            fprintf(fp, "%.2f", balance);
            fclose(fp);
            char message[MAXLINE];
            sprintf(message, "Balance updated to %.2f", balance);
            sendto(sockfd, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
        } else if (strncmp(buffer, "view", 4) == 0) {
            FILE *fp = fopen("record.dat", "r");
            if (fp == NULL) {
                perror("File opening failed");
                exit(EXIT_FAILURE);
            }
            char balance_str[MAXLINE];
            fgets(balance_str, MAXLINE, fp);
            fclose(fp);
            sendto(sockfd, (const char *)balance_str, strlen(balance_str), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
        } else {
            sendto(sockfd, (const char *)"Command not recognized", strlen("Command not recognized"), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
        }
    }

    close(sockfd);

    return 0;
}