//Falcon-180B DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <curl/curl.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"
#define EMAIL_SERVER "smtp.gmail.com"
#define EMAIL_PORT 587
#define EMAIL_USER "your_email@gmail.com"
#define EMAIL_PASS "your_email_password"

typedef struct client {
    int sock;
    char name[50];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *client = (client_t *) arg;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client->sock, buffer, BUFFER_SIZE, 0) <= 0) {
            break;
        }

        printf("%s: %s\n", client->name, buffer);

        // Send message to all other clients
        for (int i = 0; i < num_clients; i++) {
            if (i!= client - clients) {
                send(clients[i].sock, buffer, strlen(buffer), 0);
            }
        }
    }

    close(client->sock);
    num_clients--;
}

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("bind failed\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CLIENTS) < 0) {
        printf("listen failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        if ((new_sock = accept(server_sock, (struct sockaddr *) &client_addr, (socklen_t*) &addrlen)) < 0) {
            printf("accept failed\n");
            exit(EXIT_FAILURE);
        }

        if (num_clients >= MAX_CLIENTS) {
            send(new_sock, "Server is full.\n", strlen("Server is full.\n"), 0);
            close(new_sock);
        } else {
            strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
            clients[num_clients].sock = new_sock;
            num_clients++;

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) &clients[num_clients - 1]);
        }
    }

    return 0;
}