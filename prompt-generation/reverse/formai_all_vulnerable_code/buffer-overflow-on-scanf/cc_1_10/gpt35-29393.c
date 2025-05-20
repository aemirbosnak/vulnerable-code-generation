//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>

// Define constants
#define MAX_THREADS 10
#define MAX_IP_LEN 16

// Define global variables
int num_threads;
char ip_address[MAX_IP_LEN];
int subnet_mask;

// Define thread data structure
typedef struct {
    int id;
    int thread_count;
} thread_data;

// Function to calculate subnet
void *calculate_subnet(void *arg) {
    thread_data *data = (thread_data *) arg;
    int id = data->id;

    // Calculate number of IPs per thread
    int num_ips = pow(2, (32 - subnet_mask)) / data->thread_count;
    int start_ip = id * num_ips;
    int end_ip = start_ip + num_ips - 1;

    // Convert IP address to binary
    unsigned int ip_binary = 0;
    int i; 
    char *token = strtok(ip_address, ".");
    for (i = 0; i < 4; i++) {
        int octet = atoi(token);
        unsigned int octet_binary = octet << ((3 - i) * 8);
        ip_binary |= octet_binary;
        token = strtok(NULL, ".");
    }

    // Calculate subnet mask in binary
    unsigned int subnet_binary = 0xFFFFFFFF;
    subnet_binary = subnet_binary << (32 - subnet_mask);

    // Determine network address and broadcast address
    unsigned int network_address = ip_binary & subnet_binary;
    unsigned int broadcast_address = network_address + pow(2, (32 - subnet_mask)) - 1;

    // Print subnet information
    printf("Thread %d Info -> Start IP: %u.%u.%u.%u, End IP: %u.%u.%u.%u\n", id + 1,
           (start_ip >> 24) & 0xFF, (start_ip >> 16) & 0xFF, (start_ip >> 8) & 0xFF, start_ip & 0xFF, 
           (end_ip >> 24) & 0xFF, (end_ip >> 16) & 0xFF, (end_ip >> 8) & 0xFF, end_ip & 0xFF);
    printf("Network Address: %u.%u.%u.%u\n", (network_address >> 24) & 0xFF, 
           (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, network_address & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n", (broadcast_address >> 24) & 0xFF, 
           (broadcast_address >> 16) & 0xFF, (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);
}

int main() {
    // Get user input
    printf("Enter IP address (format xxx.xxx.xxx.xxx): ");
    scanf("%s", ip_address);
    printf("Enter subnet mask: ");
    scanf("%d", &subnet_mask);
    printf("Enter number of threads (1 to %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    // Create threads
    pthread_t threads[num_threads];
    thread_data data[num_threads];
    int i;
    for (i = 0; i < num_threads; i++) {
        data[i].id = i;
        data[i].thread_count = num_threads;
        pthread_create(&threads[i], NULL, calculate_subnet, &data[i]);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}