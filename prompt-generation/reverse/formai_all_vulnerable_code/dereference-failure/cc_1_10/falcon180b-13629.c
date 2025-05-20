//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char ip[16];
    char mac[18];
    int signal_strength;
};

void *handle_client(void *arg) {
    struct client_data *client_data = (struct client_data *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_data->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message from %s: %s\n", client_data->ip, buffer);
    }

    close(client_data->sock);
    free(client_data);
}

void *monitor_wifi(void *arg) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    while (1) {
        bytes_received = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (bytes_received <= 0) {
            continue;
        }

        struct client_data *client_data = (struct client_data *) malloc(sizeof(struct client_data));
        memset(client_data, 0, sizeof(struct client_data));
        strncpy(client_data->ip, inet_ntoa(server_addr.sin_addr), 16);
        strncpy(client_data->mac, "00:00:00:00:00:00", 18);
        client_data->signal_strength = bytes_received * 100 / 1024;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, client_data);
    }

    close(sock);
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_wifi, NULL);

    while (1) {
        sleep(1);
    }

    return 0;
}