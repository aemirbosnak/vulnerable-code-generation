//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

void handleClient(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;
    float total_temp = 0;
    int count = 0;

    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        float temp = atof(buffer);
        total_temp += temp;
        count++;
        printf("Received temperature: %.2f from client.\n", temp);
        send(client_socket, "Temp received. Send another.", 30, 0);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv");
    }

    if (count > 0) {
        float average_temp = total_temp / count;
        printf("Average temperature from clients: %.2f\n", average_temp);
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return 1;
    }

    listen(server_socket, MAX_CLIENTS);
    printf("Waiting for clients to connect on port %d...\n", PORT);

    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        printf("Client connected.\n");
        handleClient(client_socket);
    }

    if (client_socket < 0) {
        perror("Accept failed");
        return 1;
    }

    close(server_socket);
    return 0;
}