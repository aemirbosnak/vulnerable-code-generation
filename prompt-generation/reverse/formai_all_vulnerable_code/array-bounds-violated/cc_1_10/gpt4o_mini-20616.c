//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define SERVER_PORT 8888
#define MAX_SENSORS 10
#define BUFFER_SIZE 256

typedef struct {
    int id;
    float temperature;
} SensorData;

SensorData sensorData[MAX_SENSORS];
pthread_mutex_t lock;

void* sensor(void* arg) {
    int sensor_id = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Sensor: Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    while (1) {
        // Generate a random temperature between 15.0 to 30.0
        float temp = 15.0 + ((rand() % 1500) / 100.0);
        snprintf(buffer, sizeof(buffer), "Sensor %d: %.2f", sensor_id, temp);

        pthread_mutex_lock(&lock);
        sensorData[sensor_id].id = sensor_id;
        sensorData[sensor_id].temperature = temp;
        pthread_mutex_unlock(&lock);

        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        printf("Sensor %d sent data: %.2f\n", sensor_id, temp);
        sleep(2);
    }
    close(sock);
    return NULL;
}

void* server(void* arg) {
    int sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Server: Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    
    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Server: Bind failed.");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int n = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);
        buffer[n] = '\0';
        printf("Server received: %s\n", buffer);
    }
    close(sock);
    return NULL;
}

int main() {
    pthread_t sensor_threads[MAX_SENSORS];
    pthread_t server_thread;
    int sensor_ids[MAX_SENSORS];
    
    pthread_mutex_init(&lock, NULL);

    // Start server thread
    pthread_create(&server_thread, NULL, server, NULL);

    // Create sensor threads
    for (int i = 0; i < MAX_SENSORS; i++) {
        sensor_ids[i] = i;
        pthread_create(&sensor_threads[i], NULL, sensor, (void*)&sensor_ids[i]);
    }

    // Join sensor threads
    for (int i = 0; i < MAX_SENSORS; i++) {
        pthread_join(sensor_threads[i], NULL);
    }

    // Join server thread
    pthread_join(server_thread, NULL);
    
    pthread_mutex_destroy(&lock);
    return 0;
}