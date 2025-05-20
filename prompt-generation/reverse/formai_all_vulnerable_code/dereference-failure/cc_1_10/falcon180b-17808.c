//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MSG_SIZE 1024
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char msg[MAX_MSG_SIZE];
    int msg_len;
    struct hostent *host;
    struct timeval tv;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: Invalid hostname.\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    while (1) {
        bzero(msg, MAX_MSG_SIZE);
        msg_len = recv(sock, msg, MAX_MSG_SIZE, 0);
        if (msg_len <= 0) {
            printf("Error: Failed to receive message.\n");
            break;
        }
        msg[msg_len] = '\0';
        printf("Received message: %s\n", msg);

        bzero(msg, MAX_MSG_SIZE);
        strcpy(msg, "ACK");
        send(sock, msg, strlen(msg), 0);
    }

    close(sock);
    exit(0);
}