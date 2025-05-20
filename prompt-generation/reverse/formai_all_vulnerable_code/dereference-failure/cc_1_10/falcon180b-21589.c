//Falcon-180B DATASET v1.0 Category: Firewall ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

char *allowed_sites[] = {"google.com", "yahoo.com", "bing.com"};
int num_allowed_sites = sizeof(allowed_sites) / sizeof(char *);

void process_request(int client_socket, char *request) {
    char *host;
    int i;
    host = strtok(request, " ");
    for (i = 0; i < num_allowed_sites; i++) {
        if (strcmp(host, allowed_sites[i]) == 0) {
            printf("Request to %s allowed.\n", host);
            break;
        }
    }
    if (i == num_allowed_sites) {
        printf("Request to %s denied.\n", host);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket.\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket.\n");
        exit(1);
    }

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection.\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                printf("Error receiving data.\n");
                break;
            }
            process_request(client_socket, buffer);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}