//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/statvfs.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void check_qos(int sockfd);
double calculate_packet_loss(int sent, int received);
double get_latency(int sockfd);
void log_to_file(const char* message);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    char buffer[BUFFER_SIZE];
    while (1) {
        printf("Sending ping to server...\n");
        sendto(sockfd, "ping", strlen("ping"), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

        check_qos(sockfd);
        sleep(1); // wait for 1 second before sending the next ping
    }

    close(sockfd);
    return 0;
}

void check_qos(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    int sent = 1;
    int received = 0;

    // The monitoring duration in seconds
    for (int i = 0; i < 5; ++i) {
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&server_addr, &addr_len);
        if (strcmp(buffer, "pong") == 0) {
            received++;
        }
        sleep(1);
    }

    double packet_loss = calculate_packet_loss(sent, received);
    double latency = get_latency(sockfd);

    char log_message[BUFFER_SIZE];
    sprintf(log_message, "Packet Loss: %.2f%%, Latency: %.2f ms\n", packet_loss, latency);
    log_to_file(log_message);
}

double calculate_packet_loss(int sent, int received) {
    return ((double)(sent - received) / sent) * 100.0;
}

double get_latency(int sockfd) {
    struct timespec start, end;
    char buffer[BUFFER_SIZE];

    clock_gettime(CLOCK_MONOTONIC, &start);
    
    sendto(sockfd, "ping", strlen("ping"), 0, NULL, 0);
    recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
    
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = (end.tv_sec - start.tv_sec) * 1e3 + (end.tv_nsec - start.tv_nsec) * 1e-6;
    return time_taken;
}

void log_to_file(const char* message) {
    FILE *fp;
    fp = fopen("qos_log.txt", "a");
    if (fp == NULL) {
        perror("Error opening log file");
        return;
    }
    
    time_t now = time(NULL);
    fprintf(fp, "[%s]: %s", ctime(&now), message);
    fclose(fp);
}