//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define INTERVAL 1

typedef struct {
    char interface[16];
    char ip_address[INET_ADDRSTRLEN];
    float latency;
    int packet_loss;
} QoSData;

void get_ip_address(const char *interface, char *ip_address) {
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL || strcmp(ifa->ifa_name, interface) != 0) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
            inet_ntop(AF_INET, &addr->sin_addr, ip_address, INET_ADDRSTRLEN);
            break;
        }
    }

    freeifaddrs(ifaddr);
}

float measure_latency(const char *target_ip) {
    struct timespec start, end;
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    clock_gettime(CLOCK_MONOTONIC, &start);
    if (sendto(sockfd, "ping", 4, 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("sendto");
        close(sockfd);
        return -1;
    }

    socklen_t addrlen = sizeof(server_addr);
    if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&server_addr, &addrlen) < 0) {
        perror("recvfrom");
        close(sockfd);
        return -1;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    close(sockfd);
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0; // in milliseconds
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <target_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *target_ip = argv[1];
    QoSData qos_data;
    strcpy(qos_data.interface, "eth0");
    get_ip_address(qos_data.interface, qos_data.ip_address);
    qos_data.latency = 0;
    qos_data.packet_loss = 0;

    printf("Network QoS Monitor\n");
    printf("Monitoring interface: %s\n", qos_data.interface);
    printf("Local IP Address: %s\n", qos_data.ip_address);
    printf("Target IP: %s\n", target_ip);

    while (1) {
        qos_data.latency = measure_latency(target_ip);
        
        if (qos_data.latency < 0) {
            printf("Error measuring latency\n");
            qos_data.packet_loss++;
        } else {
            printf("Latency to %s: %.2f ms\n", target_ip, qos_data.latency);
        }
        
        printf("Packet Loss Count: %d\n", qos_data.packet_loss);
        sleep(INTERVAL);
    }

    return 0;
}