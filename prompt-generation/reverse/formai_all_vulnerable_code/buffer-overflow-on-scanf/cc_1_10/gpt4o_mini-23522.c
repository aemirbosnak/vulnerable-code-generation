//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_DEVICES 100

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int port;
} Device;

Device device_list[MAX_DEVICES];
int device_count = 0;
pthread_mutex_t lock;

void* receive_device_info(void* args) {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return NULL;
    }

    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);
        buffer[n] = '\0';

        // Lock to safely update the device list
        pthread_mutex_lock(&lock);
        if (device_count < MAX_DEVICES) {
            strcpy(device_list[device_count].ip, inet_ntoa(client_addr.sin_addr));
            device_list[device_count].port = ntohs(client_addr.sin_port);
            device_count++;
        }
        pthread_mutex_unlock(&lock);

        printf("Discovered device: %s:%d\n", device_list[device_count - 1].ip, device_list[device_count - 1].port);
    }

    close(sockfd);
    return NULL;
}

void send_echo_requests(const char* target_ip, int target_port) {
    int sockfd;
    struct sockaddr_in server_addr;
    char message[] = "Echo Request";

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    sendto(sockfd, message, sizeof(message), 0, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Sent echo request to %s:%d\n", target_ip, target_port);

    close(sockfd);
}

void print_device_list() {
    printf("Current devices in network:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%d: %s:%d\n", i + 1, device_list[i].ip, device_list[i].port);
    }
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t receiver_thread;

    // Start the receiver thread
    if (pthread_create(&receiver_thread, NULL, receive_device_info, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Simulate sending echo requests
    sleep(1); // Let the receiver start listening
    for (int i = 0; i < device_count; i++) {
        send_echo_requests(device_list[i].ip, device_list[i].port);
        sleep(1);
    }

    // Wait for the user to terminate
    char command;
    while (1) {
        printf("Press 'p' to print device list or 'q' to quit: ");
        scanf(" %c", &command);
        if (command == 'p') {
            print_device_list();
        } else if (command == 'q') {
            break;
        }
    }

    pthread_cancel(receiver_thread);
    pthread_join(receiver_thread, NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}