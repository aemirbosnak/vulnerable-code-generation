//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>

#define MAX_NODES 50
#define BUFFER_SIZE 1024

typedef struct Node {
    char ip[INET_ADDRSTRLEN];
    char hostname[256];
    int ping_time; // in milliseconds
} Node;

Node nodes[MAX_NODES];
int node_count = 0;

void add_node(const char *ip, const char *hostname, int ping_time) {
    if (node_count < MAX_NODES) {
        strncpy(nodes[node_count].ip, ip, INET_ADDRSTRLEN);
        strncpy(nodes[node_count].hostname, hostname, 256);
        nodes[node_count].ping_time = ping_time;
        node_count++;
    } else {
        printf("Node limit reached! Cannot add more nodes.\n");
    }
}

void print_topology() {
    printf("\nNetwork Topology:\n");
    printf("%-20s %-30s %-10s\n", "IP Address", "Hostname", "Ping Time(ms)");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < node_count; i++) {
        printf("%-20s %-30s %-10d\n", nodes[i].ip, nodes[i].hostname, nodes[i].ping_time);
    }
}

void ping_node(const char *ip) {
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "ping -c 1 %s | grep 'time=' | awk '{print $7}'", ip);
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        return;
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        float ping_time;
        sscanf(buffer, "time=%f", &ping_time);
        add_node(ip, "Unknown", (int)ping_time); // For simplicity, we use "Unknown" for hostname
    } else {
        printf("Ping failed for %s\n", ip);
    }
    pclose(fp);
}

void get_local_ip() {
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr, ip, sizeof(ip));
            printf("Local IP: %s\n", ip);
            ping_node(ip); // Ping the local IP for demonstration
        }
    }

    freeifaddrs(ifaddr);
}

int main() {
    printf("Starting Network Topology Mapper...\n");

    get_local_ip();

    // Example: Add some static nodes for demonstration purposes
    add_node("192.168.1.1", "Router", 2);
    add_node("192.168.1.100", "Laptop", 8);
    add_node("192.168.1.101", "Smartphone", 12);
    add_node("192.168.1.102", "Desktop", 5);

    // Print the complete network topology
    print_topology();

    return 0;
}