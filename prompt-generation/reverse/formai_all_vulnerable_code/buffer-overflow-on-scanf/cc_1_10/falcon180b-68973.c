//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define TRUE 1
#define FALSE 0

int g_server_socket = -1;
char g_ip_address[20];
char g_subnet_mask[20];
char g_gateway[20];
char g_dns_server[20];

void *receive_thread(void *arg) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (TRUE) {
        bytes_received = recv(g_server_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received: %s\n", buffer);
    }

    close(g_server_socket);
    pthread_exit(0);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    pthread_t thread_id;

    printf("Enter IP address: ");
    scanf("%s", g_ip_address);

    printf("Enter subnet mask: ");
    scanf("%s", g_subnet_mask);

    printf("Enter gateway: ");
    scanf("%s", g_gateway);

    printf("Enter DNS server: ");
    scanf("%s", g_dns_server);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, g_ip_address, &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        close(server_socket);
        return 1;
    }

    printf("Server started on port %d\n", SERVER_PORT);

    pthread_create(&thread_id, NULL, receive_thread, NULL);

    while (TRUE) {
        sleep(1);
    }

    return 0;
}