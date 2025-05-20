//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_MONITORS 3

typedef struct {
    int id;
    struct sockaddr_in address;
    int sockfd;
} QoSMonitor;

void* monitorQoS(void* arg) {
    QoSMonitor* monitor = (QoSMonitor*) arg;
    char buffer[BUFFER_SIZE];
    int bytesRead;

    while (1) {
        bytesRead = recvfrom(monitor->sockfd, buffer, BUFFER_SIZE, 0,
                             (struct sockaddr*)&monitor->address, sizeof(monitor->address));
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            printf("[Monitor %d] Received: %s\n", monitor->id, buffer);
        }
        usleep(500000);  // Sleep for 500 ms
    }

    return NULL;
}

void* sendTraffic(void* arg) {
    int sockfd;
    struct sockaddr_in serverAddr;
    char* messages[] = {
        "Ping 1",
        "Ping 2",
        "Ping 3",
        "Ping 4",
        "Ping 5"
    };

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (1) {
        for (int i = 0; i < 5; i++) {
            sendto(sockfd, messages[i], strlen(messages[i]), 
                   0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
            printf("[Traffic Sender] Sent: %s\n", messages[i]);
            sleep(1);  // Sleep for 1 second
        }
    }

    close(sockfd);
    return NULL;
}

int main() {
    pthread_t monitors[NUM_MONITORS];
    QoSMonitor qosMonitors[NUM_MONITORS];

    for (int i = 0; i < NUM_MONITORS; i++) {
        qosMonitors[i].id = i + 1;

        qosMonitors[i].sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (qosMonitors[i].sockfd < 0) {
            perror("Socket creation failed for monitor");
            exit(EXIT_FAILURE);
        }

        memset(&qosMonitors[i].address, 0, sizeof(qosMonitors[i].address));
        qosMonitors[i].address.sin_family = AF_INET;
        qosMonitors[i].address.sin_addr.s_addr = INADDR_ANY;
        qosMonitors[i].address.sin_port = htons(PORT);

        if (bind(qosMonitors[i].sockfd, (struct sockaddr*)&qosMonitors[i].address,
                  sizeof(qosMonitors[i].address)) < 0) {
            perror("Bind failed");
            exit(EXIT_FAILURE);
        }

        pthread_create(&monitors[i], NULL, monitorQoS, (void*)&qosMonitors[i]);
    }

    pthread_t trafficSender;
    pthread_create(&trafficSender, NULL, sendTraffic, NULL);

    for (int i = 0; i < NUM_MONITORS; i++) {
        pthread_join(monitors[i], NULL);
    }
    pthread_join(trafficSender, NULL);

    // Cleanup
    for (int i = 0; i < NUM_MONITORS; i++) {
        close(qosMonitors[i].sockfd);
    }

    return 0;
}