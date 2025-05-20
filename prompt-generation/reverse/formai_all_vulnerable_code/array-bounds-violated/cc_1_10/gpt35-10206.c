//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_MSG_LENGTH 1024
#define MAX_CACHE_SIZE 100

typedef struct {
    char url[MAX_MSG_LENGTH];
    char response[MAX_MSG_LENGTH];
} cache_entry;

cache_entry CACHE[MAX_CACHE_SIZE];

int cache_pos = 0;

void handle_request(int client_fd) {
    char buffer[MAX_MSG_LENGTH], url[MAX_MSG_LENGTH], ip[MAX_MSG_LENGTH], response[MAX_MSG_LENGTH];
    int server_fd, num_bytes;

    num_bytes = recv(client_fd, buffer, MAX_MSG_LENGTH, 0);
    buffer[num_bytes] = '\0';

    sscanf(buffer, "GET %s HTTP/1.0\r\n", url);

    for (int i = 0; i < cache_pos; i++) {
        if (strcmp(CACHE[i].url, url) == 0) {
            printf("Found in Cache: %s\n", url);
            send(client_fd, CACHE[i].response, strlen(CACHE[i].response), 0);
            return;
        }
    }

    printf("Proxying Request: %s\n", url);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    inet_aton("127.0.0.1", &server_address.sin_addr);
    server_address.sin_port = htons(80);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    connect(server_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    sprintf(buffer, "GET %s HTTP/1.0\r\n\r\n", url);

    send(server_fd, buffer, strlen(buffer), 0);

    while ((num_bytes = recv(server_fd, buffer, MAX_MSG_LENGTH, 0)) > 0) {
        buffer[num_bytes] = '\0';
        strcat(response, buffer);
    }

    close(server_fd);
    send(client_fd, response, strlen(response), 0);

    if (cache_pos < MAX_CACHE_SIZE) {
        strcpy(CACHE[cache_pos].url, url);
        strcpy(CACHE[cache_pos].response, response);
        cache_pos++;
    }
}

int main() {
    int server_fd, client_fd, len;
    struct sockaddr_in server_address, client_address;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(server_fd, 5);
    len = sizeof(client_address);

    printf("Proxy Server listening on port 8080...\n\n");

    while(1) {
        client_fd = accept(server_fd, (struct sockaddr*)&client_address, &len);
        handle_request(client_fd);
        close(client_fd);
    }

    return 0;
}