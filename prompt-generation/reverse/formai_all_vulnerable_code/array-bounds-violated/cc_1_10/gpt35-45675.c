//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT 8080
#define BUFSIZE 1024

int sockfd;
struct sockaddr_in server, client;

void sigint_handler(int sig)
{
    printf("Interrupt signal received, closing socket and exiting...\n");
    close(sockfd);
    exit(0);
}

void handle_request(int client_sockfd)
{
    char buffer[BUFSIZE];
    int n;

    while ((n = recv(client_sockfd, buffer, BUFSIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("[FROM CLIENT]: %s", buffer);
        if (send(client_sockfd, buffer, n, 0) < 0) {
            perror("send() error");
        }
    }

    if (n == 0) {
        printf("Client disconnected\n");
    } else {
        perror("recv() error");
    }

    close(client_sockfd);
}

void run_server()
{
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error");
        return;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind() error");
        return;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen() error");
        return;
    }

    printf("Server started. Listening on port %d...\n", PORT);

    while (1) {
        socklen_t client_len = sizeof(client);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client, &client_len);

        if (client_sockfd < 0) {
            perror("accept() error");
            continue;
        }

        printf("Connected with client %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        handle_request(client_sockfd);
    }
}

int main()
{
    signal(SIGINT, sigint_handler);
    run_server();
    return 0;
}