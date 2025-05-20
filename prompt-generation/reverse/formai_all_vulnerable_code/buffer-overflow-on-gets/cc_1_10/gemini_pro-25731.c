//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

// Server enigma
#define SERVER_PORT 6180
#define SERVER_IP "127.0.0.1"

// Client riddle
#define CLIENT_PORT 5730
#define CLIENT_IP "127.0.0.1"

// Thread puzzle
pthread_t server_thread, client_thread;

// Socket secret
int server_socket, client_socket;

// Buffer key
char server_buffer[1024], client_buffer[1024];

// Function riddles
void *server_function(void *arg) {
    while (1) {
        recv(server_socket, server_buffer, sizeof(server_buffer), 0);
        printf("Server> %s\n", server_buffer);
        memset(server_buffer, 0, sizeof(server_buffer));
    }
}

void *client_function(void *arg) {
    while (1) {
        gets(client_buffer);
        send(client_socket, client_buffer, strlen(client_buffer), 0);
        memset(client_buffer, 0, sizeof(client_buffer));
    }
}

int main(int arc, char **argv) {
    // Server setup enigma
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    listen(server_socket, 5);

    // Client setup riddle
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(CLIENT_PORT);
    client_address.sin_addr.s_addr = inet_addr(CLIENT_IP);
    connect(client_socket, (struct sockaddr *)&client_address, sizeof(client_address));

    // Thread wizardry
    pthread_create(&server_thread, NULL, server_function, NULL);
    pthread_create(&client_thread, NULL, client_function, NULL);

    pthread_join(server_thread, NULL);
    pthread_join(client_thread, NULL);

    return 0;
}