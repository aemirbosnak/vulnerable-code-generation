//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDRESS "8.8.8.8" // Google's Public DNS for testing
#define SAMPLE_SIZE 10

typedef struct {
    double latency; // in milliseconds
    double packet_loss; // in percentage
    double jitter; // in milliseconds
} QoSData;

QoSData qos_data[SAMPLE_SIZE];
int data_index = 0;

void record_qos_data(double latency, double packet_loss, double jitter) {
    qos_data[data_index].latency = latency;
    qos_data[data_index].packet_loss = packet_loss;
    qos_data[data_index].jitter = jitter;
    data_index = (data_index + 1) % SAMPLE_SIZE;
}

void print_qos_report() {
    printf("QoS Report:\n");
    printf("| Index | Latency (ms) | Packet Loss (%) | Jitter (ms) |\n");
    printf("|-------|---------------|------------------|--------------|\n");
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        printf("| %5d | %13.2f | %16.2f | %12.2f |\n", i, qos_data[i].latency, qos_data[i].packet_loss, qos_data[i].jitter);
    }
    printf("|-------|---------------|------------------|--------------|\n");
}

double calculate_latency(const char *ip_address) {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    char send_buffer[MAX_BUFFER_SIZE] = "PING";
    char recv_buffer[MAX_BUFFER_SIZE];
    struct timeval timeout;

    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    
    timeout.tv_sec = 1; // 1 second timeout
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    clock_t start_time = clock();
    sendto(sock, send_buffer, strlen(send_buffer), MSG_CONFIRM, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    int n = recvfrom(sock, recv_buffer, MAX_BUFFER_SIZE, MSG_WAITALL, NULL, NULL);
    clock_t end_time = clock();
    double latency = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;

    close(sock);
    return (n < 0) ? -1 : latency;
}

double simulate_packet_loss() {
    return (rand() % 100) < 20 ? 100.0 : 0.0; // 20% packet loss probability
}

double simulate_jitter() {
    return (double)(rand() % 50); // Random jitter between 0 to 50 ms
}

int main() {
    srand(time(NULL));

    printf("Starting QoS Monitor...\n");
    while (1) {
        double latency = calculate_latency(SERVER_ADDRESS);
        if (latency < 0) {
            printf("Request timed out. Simulating data...\n");
            latency = -1;
        }
        
        double packet_loss = simulate_packet_loss();
        double jitter = simulate_jitter();

        record_qos_data(latency, packet_loss, jitter);
        print_qos_report();

        sleep(5); // Wait for 5 seconds before the next sample
    }

    return 0;
}