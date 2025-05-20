//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_DEVICES 50
#define DEVICE_NAME_LEN 30

typedef struct {
    char name[DEVICE_NAME_LEN];
    char ip[INET_ADDRSTRLEN];
    int connected;
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;
pthread_mutex_t mutex;

void* listen_for_devices(void* param) {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &client_len);
        buffer[n] = '\0';

        pthread_mutex_lock(&mutex);
        if (device_count < MAX_DEVICES) {
            strcpy(devices[device_count].name, buffer);
            inet_ntop(AF_INET, &client_addr.sin_addr, devices[device_count].ip, sizeof(devices[device_count].ip));
            devices[device_count].connected = 1;
            device_count++;
        }
        pthread_mutex_unlock(&mutex);

        printf("Device detected: %s [%s]\n", buffer, devices[device_count - 1].ip);
    }

    close(sockfd);
    return NULL;
}

void display_network_topology() {
    printf("\n--- Network Topology ---\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device Name: %s, IP Address: %s, Status: %s\n", 
               devices[i].name, 
               devices[i].ip, 
               devices[i].connected ? "Connected" : "Disconnected");
    }
}

int main() {
    pthread_t listener_thread;
    pthread_mutex_init(&mutex, NULL);

    printf("Starting Network Topology Mapper...\n");

    // Start a thread to listen for devices
    if (pthread_create(&listener_thread, NULL, listen_for_devices, NULL) != 0) {
        perror("Failed to create listener thread");
        exit(EXIT_FAILURE);
    }

    while (1) {
        char command[10];
        printf("Enter 'show' to display network topology or 'quit' to exit: ");
        scanf("%s", command);

        if (strcmp(command, "show") == 0) {
            display_network_topology();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    // Cleanup and exit
    pthread_cancel(listener_thread);
    pthread_join(listener_thread, NULL);
    pthread_mutex_destroy(&mutex);
    
    printf("Thank you for using the Network Topology Mapper! Goodbye!\n");
    return 0;
}