//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_DEVICES 100
#define BUFFER_SIZE 1024

int total_devices = 0; // total number of devices in network
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER; // mutex for thread safety

typedef struct {
    char ip_address[16];
    char name[50];
} NetworkDevice;

NetworkDevice devices[MAX_DEVICES];

void* device_mapper(void* arg) {
    char *ip_start = (char*)arg;
    char ip_end[16];
    strncpy(ip_end, ip_start, sizeof(ip_end));
    
    // Find position of last dot in IP address
    int last_dot_pos = -1;
    for(int i=strlen(ip_start)-1; i>=0; i--) {
        if(ip_start[i] == '.') {
            last_dot_pos = i;
            break;
        }
    }
    if(last_dot_pos == -1) {
        printf("Invalid IP address format\n");
        pthread_exit(NULL);
    }
    
    // Generate IP addresses within the subnet
    int device_count = 0;
    for(int i=1; i<=255; i++) {
        char current_ip[16];
        sprintf(current_ip, "%.*s%d", last_dot_pos, ip_start, i);
        if(strcmp(current_ip, ip_end) == 0) { // End of subnet reached
            break;
        }
        
        int sockfd;
        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Socket creation error");
            continue;
        }
        
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(22);
        inet_pton(AF_INET, current_ip, &addr.sin_addr);
        
        if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == 0) { // Device found
            pthread_mutex_lock(&mtx);
            strcpy(devices[total_devices].ip_address, current_ip);
            strcpy(devices[total_devices].name, "Unknown");
            total_devices++;
            device_count++;
            pthread_mutex_unlock(&mtx);
        }
        close(sockfd);
    }
    
    printf("Device mapper finished scanning subnet %s with %d devices found\n", ip_start, device_count);
    pthread_exit(NULL);
}

int main() {
    char network_subnet[16];
    printf("Enter network subnet in CIDR notation (e.g. 192.168.0.0/24): ");
    scanf("%s", network_subnet);
    
    // Extract IP address and prefix length from CIDR notation
    char* prefix_ptr = strchr(network_subnet, '/');
    if(prefix_ptr == NULL) {
        printf("CIDR notation format is incorrect\n");
        return 1;
    }
    *prefix_ptr = '\0';
    prefix_ptr++;
    int prefix_len = atoi(prefix_ptr);
    if(prefix_len < 1 || prefix_len > 32) {
        printf("CIDR notation format is incorrect\n");
        return 1;
    }
    
    pthread_t threads[128]; // maximum number of subnets is 128
    int thread_count = 0;
    char base_ip[16];
    strncpy(base_ip, network_subnet, sizeof(base_ip));
    strtok(base_ip, "."); strtok(NULL, "."); // skip first two octets
    int start_octet = atoi(strtok(NULL, "."));
    int num_subnets = 1 << (32-prefix_len); // total number of subnets in network
    
    // Check if total number of subnets is not too large
    if(num_subnets > 128) {
        printf("Network is too large to scan\n");
        return 1;
    }
    
    // Launch device mapper threads for each subnet
    for(int i=0; i<num_subnets; i++) {
        char ip_start[16];
        int subnet_id = start_octet + i;
        sprintf(ip_start, "%s.%d.0/24", base_ip, subnet_id);
        if(pthread_create(&threads[thread_count], NULL, device_mapper, (void*)ip_start)) {
            perror("Thread creation error");
            return 1;
        }
        thread_count++;
    }
    
    // Wait for all threads to finish
    for(int i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print results
    printf("\nFound %d devices in network:\n", total_devices);
    for(int i=0; i<total_devices; i++) {
        printf("- %s (%s)\n", devices[i].name, devices[i].ip_address);
    }
    
    return 0;
}