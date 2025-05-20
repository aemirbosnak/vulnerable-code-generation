//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 5
#define MAX_LINE 256
#define DELAY 1000 // 1 second

int main(int argc, char *argv[]) {
    int opt = TRUE;
    char *ip = "127.0.0.1";
    int port = PORT;
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_LINE];
    int new_socket;
    char *message;
    int valread;

    while (opt) {
        printf("Enter IP address: ");
        scanf("%s", ip);
        printf("Enter port number: ");
        scanf("%d", &port);
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &opt);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    while (TRUE) {
        printf("Enter message: ");
        fgets(buffer, MAX_LINE, stdin);
        message = strtok(buffer, "\n");
        send(sockfd, message, strlen(message), 0);
        valread = read(sockfd, buffer, MAX_LINE);
        if (valread <= 0) {
            printf("Disconnected from server\n");
            exit(0);
        }
        printf("Received message: %s", buffer);
        usleep(DELAY);
    }

    return 0;
}