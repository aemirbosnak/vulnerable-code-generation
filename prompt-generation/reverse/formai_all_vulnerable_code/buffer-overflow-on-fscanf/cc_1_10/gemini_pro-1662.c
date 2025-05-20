//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Constants
#define MAX_THREADS 10
#define MAX_PORTS 100
#define MAX_HOSTS 100
#define MAX_HOSTNAME 256

// Data structures
typedef struct host_info {
    char hostname[MAX_HOSTNAME];
    int port;
    bool is_alive;
} host_info;

typedef struct thread_data {
    int start_index;
    int end_index;
    host_info* host_list;
} thread_data;

// Global variables
host_info host_list[MAX_HOSTS];
int num_hosts = 0;

// Function declarations
void* scan_hosts(void* arg);
void print_results();

// Main function
int main(int argc, char** argv) {
    // Check arguments
    if (argc != 2) {
        printf("Usage: %s <hostname file>\n", argv[0]);
        return 1;
    }

    // Read hostname file
    FILE* hostname_file = fopen(argv[1], "r");
    if (hostname_file == NULL) {
        perror("fopen");
        return 1;
    }

    while (fscanf(hostname_file, "%s", host_list[num_hosts].hostname) != EOF) {
        num_hosts++;
    }

    fclose(hostname_file);

    // Spawn threads to scan hosts
    pthread_t threads[MAX_THREADS];
    int thread_count = (num_hosts + MAX_THREADS - 1) / MAX_THREADS;
    for (int i = 0; i < thread_count; i++) {
        thread_data* data = malloc(sizeof(thread_data));
        data->start_index = i * MAX_THREADS;
        data->end_index = (i + 1) * MAX_THREADS;
        data->host_list = host_list;
        pthread_create(&threads[i], NULL, scan_hosts, data);
    }

    // Join threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    print_results();

    return 0;
}

// Function to scan hosts
void* scan_hosts(void* arg) {
    thread_data* data = (thread_data*)arg;

    for (int i = data->start_index; i < data->end_index && i < num_hosts; i++) {
        // Resolve hostname
        struct hostent* hostent = gethostbyname(data->host_list[i].hostname);
        if (hostent == NULL) {
            perror("gethostbyname");
            continue;
        }

        // Iterate over IP addresses
        for (int j = 0; hostent->h_addr_list[j] != NULL; j++) {
            // Create socket
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                perror("socket");
                continue;
            }

            // Set socket timeout
            struct timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

            // Connect to host
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(data->host_list[i].port);
            addr.sin_addr = *(struct in_addr*)hostent->h_addr_list[j];
            int connect_status = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
            if (connect_status == -1) {
                perror("connect");
                close(sockfd);
                continue;
            }

            // Host is alive
            data->host_list[i].is_alive = true;
            close(sockfd);
        }
    }

    return NULL;
}

// Function to print results
void print_results() {
    printf("Hostname\tPort\tStatus\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("%s\t%d\t%s\n", host_list[i].hostname, host_list[i].port, host_list[i].is_alive ? "Alive" : "Dead");
    }
}