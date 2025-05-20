//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_SERVERS 10
#define BUFFER_SIZE 256

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int port;
    double latency;
    double jitter;
    double packet_loss;
} Server;

void ping_server(Server *server);
void report_quality(Server *server);
void display_summary(Server servers[], int count);

int main() {
    Server servers[MAX_SERVERS] = {
        {"8.8.8.8", 53, 0.0, 0.0, 0.0}, // Google DNS
        {"1.1.1.1", 53, 0.0, 0.0, 0.0}, // Cloudflare DNS
        {"208.67.222.222", 53, 0.0, 0.0, 0.0}, // OpenDNS
        {"9.9.9.9", 53, 0.0, 0.0, 0.0}, // Quad9 DNS
        {"8.26.56.26", 53, 0.0, 0.0, 0.0}, // Comodo DNS
        // Additional servers can be added here
    };
    int server_count = 5; // Number of servers to monitor
    int i;

    printf("Starting Network Quality of Service (QoS) Monitor...\n");

    for (i = 0; i < server_count; i++) {
        ping_server(&servers[i]);
        report_quality(&servers[i]);
    }

    display_summary(servers, server_count);
    return 0;
}

void ping_server(Server *server) {
    struct sockaddr_in server_addr;
    int sock;
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    socklen_t addr_len = sizeof(server_addr);
    int sent_bytes, received_bytes;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server->port);
    inet_pton(AF_INET, server->ip, &server_addr.sin_addr);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);
    sent_bytes = sendto(sock, "ping", strlen("ping"), 0, 
                        (struct sockaddr*)&server_addr, sizeof(server_addr));
    
    if (sent_bytes < 0) {
        perror("sendto failed");
        close(sock);
        return;
    }

    received_bytes = recvfrom(sock, buffer, BUFFER_SIZE, 0, 
                              (struct sockaddr*)&server_addr, &addr_len);
    gettimeofday(&end, NULL);

    if (received_bytes < 0) {
        perror("recvfrom failed");
        close(sock);
        return;
    }

    double latency = ((end.tv_sec - start.tv_sec) * 1000.0) + 
                     ((end.tv_usec - start.tv_usec) / 1000.0);
    server->latency = latency;

    // Simulate jitter and packet loss (for the sake of this example)
    server->jitter = (double)(rand() % 10); // Random jitter
    server->packet_loss = (double)(rand() % 5); // Random packet loss percentage

    close(sock);
}

void report_quality(Server *server) {
    printf("Server: %s:%d\n", server->ip, server->port);
    printf("Latency: %.2f ms\n", server->latency);
    printf("Jitter: %.2f ms\n", server->jitter);
    printf("Packet Loss: %.2f%%\n\n", server->packet_loss);
}

void display_summary(Server servers[], int count) {
    double avg_latency = 0.0, avg_jitter = 0.0, avg_packet_loss = 0.0;
    int i;

    for (i = 0; i < count; i++) {
        avg_latency += servers[i].latency;
        avg_jitter += servers[i].jitter;
        avg_packet_loss += servers[i].packet_loss;
    }

    avg_latency /= count;
    avg_jitter /= count;
    avg_packet_loss /= count;

    printf("=== Summary ===\n");
    printf("Average Latency: %.2f ms\n", avg_latency);
    printf("Average Jitter: %.2f ms\n", avg_jitter);
    printf("Average Packet Loss: %.2f%%\n", avg_packet_loss);
}