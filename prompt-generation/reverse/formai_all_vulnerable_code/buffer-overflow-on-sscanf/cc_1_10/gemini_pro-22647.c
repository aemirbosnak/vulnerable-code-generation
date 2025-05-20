//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Structure to store QoS data
typedef struct {
    int socket_fd;
    struct sockaddr_in server_addr;
    int num_packets_sent;
    int num_packets_received;
    int num_packets_lost;
    double average_latency;
} qos_data;

// Function to send QoS data to the server
void *send_qos_data(void *args) {
    qos_data *q = (qos_data *)args;

    // Create a UDP socket
    if ((q->socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    q->server_addr.sin_family = AF_INET;
    q->server_addr.sin_port = htons(1234);
    q->server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send QoS data to the server
    while (1) {
        char buffer[1024];
        sprintf(buffer, "%d %d %d %f", q->num_packets_sent, q->num_packets_received, q->num_packets_lost, q->average_latency);
        if (sendto(q->socket_fd, buffer, strlen(buffer), 0, (struct sockaddr *)&q->server_addr, sizeof(q->server_addr)) < 0) {
            perror("sendto() failed");
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }

    return NULL;
}

// Function to receive QoS data from the client
void *receive_qos_data(void *args) {
    qos_data *q = (qos_data *)args;

    // Create a UDP socket
    if ((q->socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the server address
    if (bind(q->socket_fd, (struct sockaddr *)&q->server_addr, sizeof(q->server_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // Receive QoS data from the client
    while (1) {
        char buffer[1024];
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        if (recvfrom(q->socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &client_addr_len) < 0) {
            perror("recvfrom() failed");
            exit(EXIT_FAILURE);
        }
        sscanf(buffer, "%d %d %d %f", &q->num_packets_sent, &q->num_packets_received, &q->num_packets_lost, &q->average_latency);
    }

    return NULL;
}

int main() {
    // Create a QoS data structure
    qos_data q;
    q.num_packets_sent = 0;
    q.num_packets_received = 0;
    q.num_packets_lost = 0;
    q.average_latency = 0.0;

    // Create a thread to send QoS data to the server
    pthread_t send_thread;
    if (pthread_create(&send_thread, NULL, send_qos_data, &q) != 0) {
        perror("pthread_create() failed");
        exit(EXIT_FAILURE);
    }

    // Create a thread to receive QoS data from the client
    pthread_t receive_thread;
    if (pthread_create(&receive_thread, NULL, receive_qos_data, &q) != 0) {
        perror("pthread_create() failed");
        exit(EXIT_FAILURE);
    }

    // Join the threads
    if (pthread_join(send_thread, NULL) != 0) {
        perror("pthread_join() failed");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(receive_thread, NULL) != 0) {
        perror("pthread_join() failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}