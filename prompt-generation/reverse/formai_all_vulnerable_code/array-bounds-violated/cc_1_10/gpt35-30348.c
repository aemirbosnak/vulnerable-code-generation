//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
// A TCP/IP Chat Application in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int sock;

void *send_message(void *arg) {
    char message[BUFFER_SIZE];
    while(1) {
        fgets(message, BUFFER_SIZE, stdin);
        send(sock, message, strlen(message), 0);
    }
}

void *receive_message(void *arg) {
    char message[BUFFER_SIZE];
    while(1) {
        int read_size = recv(sock, message, BUFFER_SIZE, 0);
        if(read_size > 0) {
            message[read_size] = '\0';
            printf("%s", message);
        }
    }
}

int main() {
    struct sockaddr_in server_addr;
    char name[BUFFER_SIZE];

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address specified");
        exit(1);
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        exit(1);
    }

    // Receive name from server
    if(recv(sock, name, BUFFER_SIZE, 0) < 0) {
        perror("Could not receive name from server");
        exit(1);
    }
    printf("Connected to server as %s\n", name);

    // Start threads for sending and receiving messages
    pthread_t send_thread, receive_thread;
    pthread_create(&send_thread, NULL, send_message, NULL);
    pthread_create(&receive_thread, NULL, receive_message, NULL);

    // Wait for threads to terminate
    pthread_join(send_thread, NULL);
    pthread_join(receive_thread, NULL);

    // Close socket
    close(sock);

    return 0;
}