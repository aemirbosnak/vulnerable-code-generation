//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <time.h>

#define PORT 54000
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) die("socket creation error");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        die("bind failed");

    char buffer[BUFFER_SIZE];
    int n;
    char name[32];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    while (true) {
        printf("(%s) ", name);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "/quit") == 0) {
            close(sockfd);
            return 0;
        }

        n = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)NULL, sizeof(struct sockaddr));
        if (n < 0) die("sendto error");

        socklen_t clilen = sizeof(struct sockaddr_in);
        struct sockaddr_in client_addr;

        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &clilen);
        if (n < 0) die("recvfrom error");

        buffer[n] = '\0';
        printf("%s: %s\n", inet_ntoa(client_addr.sin_addr), buffer);
    }
}