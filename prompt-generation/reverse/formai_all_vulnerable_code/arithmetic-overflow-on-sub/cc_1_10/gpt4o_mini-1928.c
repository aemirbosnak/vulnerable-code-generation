//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define NUM_TESTS 10
#define TIMEOUT 5

typedef struct {
    int latency; // in milliseconds
    int packet_loss; // as a percentage
    float throughput; // in Mbps
} QosMetrics;

void calculate_metrics(QosMetrics *metrics, int sent_packets, int received_packets, int total_time) {
    metrics->packet_loss = ((sent_packets - received_packets) * 100) / sent_packets;
    metrics->latency = total_time / received_packets;
    metrics->throughput = (received_packets * BUFFER_SIZE * 8.0) / (total_time * 1000000.0); // in Mbps
}

void print_metrics(QosMetrics metrics) {
    printf("QoS Metrics:\n");
    printf("Latency: %d ms\n", metrics.latency);
    printf("Packet Loss: %d%%\n", metrics.packet_loss);
    printf("Throughput: %.2f Mbps\n", metrics.throughput);
    printf("----------------------------\n");
}

void start_server() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        recvfrom(server_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_size);
        sendto(server_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, addr_size);
    }

    close(server_fd);
}

void start_client() {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    QosMetrics metrics = {0, 0, 0};
    int sent_packets = 0, received_packets = 0;
    clock_t start_time, end_time;

    client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(SERVER_PORT);

    for (int i = 0; i < NUM_TESTS; i++) {
        memset(buffer, 0, BUFFER_SIZE);
        snprintf(buffer, BUFFER_SIZE, "Ping %d", i + 1);
        sent_packets++;

        start_time = clock();
        sendto(client_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        recvfrom(client_fd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        end_time = clock();

        if (strcmp(buffer, "Ping") == 0) {
            received_packets++;
        }

        metrics.latency += (int)(1000.0 * (end_time - start_time) / CLOCKS_PER_SEC); // convert to ms
        sleep(1); // wait for a second before the next ping
    }

    calculate_metrics(&metrics, sent_packets, received_packets, (int)(metrics.latency));
    print_metrics(metrics);

    close(client_fd);
}

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process runs the server
        start_server();
    } else {
        // Parent process runs the client
        sleep(1); // give the server time to start
        start_client();
        wait(NULL); // wait for child process to finish
    }
    return 0;
}