//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <math.h>

void qos_monitor(int sock_fd, struct sockaddr_in address) {
    char buffer[1024];
    printf("QoS monitor is up and running!\n");
    while(1) {
        float time_taken = 0;
        int packets_received = 0;
        int total_packets = 100;
        int len = sizeof(address);
        for(int i=0; i<total_packets; i++) {
            sendto(sock_fd, buffer, strlen(buffer), 0, (struct sockaddr*)&address, len);
            struct timeval start_time;
            gettimeofday(&start_time, NULL);
            recvfrom(sock_fd, buffer, 1024, 0, (struct sockaddr*)&address, &len);
            struct timeval end_time;
            gettimeofday(&end_time, NULL);
            time_taken += (float)(end_time.tv_usec - start_time.tv_usec) / 1000000 + (float)(end_time.tv_sec - start_time.tv_sec);
            packets_received++;
        }
        float avg_time_taken = time_taken / packets_received;
        float variance_sum = 0;
        for(int i=0; i<total_packets; i++) {
            sendto(sock_fd, buffer, strlen(buffer), 0, (struct sockaddr*)&address, len);
            struct timeval start_time;
            gettimeofday(&start_time, NULL);
            recvfrom(sock_fd, buffer, 1024, 0, (struct sockaddr*)&address, &len);
            struct timeval end_time;
            gettimeofday(&end_time, NULL);
            float packet_time = (float)(end_time.tv_usec - start_time.tv_usec) / 1000000 + (float)(end_time.tv_sec - start_time.tv_sec);
            variance_sum += pow((packet_time - avg_time_taken), 2);
        }
        float variance = variance_sum / packets_received;
        float std_deviation = sqrt(variance);
        printf("Current QoS: %.3fms (± %.3fms)\n", avg_time_taken * 1000, std_deviation * 1000);
        sleep(5);
    }
}

int main() {
    int sock_fd;
    struct sockaddr_in address;
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock_fd < 0) {
        printf("An error occurred while creating the socket.");
        exit(1);
    } 
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(9999);
    if(bind(sock_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        printf("An error occurred while binding the socket.");
        exit(1);
    }
    qos_monitor(sock_fd, address);
    return 0;
}