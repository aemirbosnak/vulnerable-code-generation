//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>
#include <signal.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    int sockfd, portno, n;
    struct sockaddr_in client_addr;
    char buffer[BUFFER_SIZE];
    char *msg = "Hello, world!";
    char client_msg[BUFFER_SIZE];
    int i;
    int clients[MAX_CLIENTS];

    portno = atoi(argv[1]);
    printf("Listening on port %d\n", portno);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, MAX_CLIENTS);

    while (1) {
        socklen_t client_len = sizeof(client_addr);
        clients[0] = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (clients[0] < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        printf("Client %d connected\n", clients[0]);
        for (i = 1; i < MAX_CLIENTS; i++) {
            if (clients[i-1] < 0) {
                clients[i] = clients[i-1];
                i--;
            }
        }
        printf("Number of clients: %d\n", i);

        while (1) {
            n = recv(clients[0], buffer, BUFFER_SIZE, 0);
            if (n < 0) {
                perror("ERROR receiving from client");
                exit(1);
            }
            if (strcmp(buffer, "quit") == 0) {
                close(clients[0]);
                clients[0] = -1;
                break;
            }
            printf("Client %d: %s\n", clients[0], buffer);
            send(clients[0], msg, strlen(msg), 0);
            for (i = 1; i < MAX_CLIENTS; i++) {
                if (clients[i] >= 0) {
                    send(clients[i], buffer, strlen(buffer), 0);
                }
            }
        }
        close(clients[0]);
    }

    return 0;
}