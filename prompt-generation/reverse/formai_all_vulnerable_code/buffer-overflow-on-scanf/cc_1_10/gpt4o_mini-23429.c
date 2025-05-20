//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define THREAD_POOL_SIZE 100

typedef struct {
    char *ip_address;
    int port;
} thread_arg_t;

void *scan_port(void *arg) {
    thread_arg_t *t_arg = (thread_arg_t *)arg;
    int sock;
    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_port = htons(t_arg->port);
    target.sin_addr.s_addr = inet_addr(t_arg->ip_address);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) >= 0) {
        printf("🎉 Port %d is open on %s!\n", t_arg->port, t_arg->ip_address);
    } else {
        // Port is closed or filtered. No output needed.
    }

    close(sock);
    pthread_exit(NULL);
}

void scan_ports(const char *ip_address) {
    pthread_t threads[THREAD_POOL_SIZE];
    thread_arg_t args[THREAD_POOL_SIZE];

    int thread_count = 0;

    for (int port = MIN_PORT; port <= MAX_PORT; port++) {
        if (thread_count >= THREAD_POOL_SIZE) {
            for (int i = 0; i < THREAD_POOL_SIZE; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset for the new batch of threads
        }
        
        args[thread_count].ip_address = (char *)ip_address;
        args[thread_count].port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)&args[thread_count]) != 0) {
            perror("Failed to create thread");
        }

        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    char ip_address[INET_ADDRSTRLEN];
    
    printf("🌟 Welcome to the Happy Port Scanner! 🌟\n");
    
    // Input the target IP address
    printf("Please enter the IP address to scan (e.g., 192.168.1.1): ");
    scanf("%s", ip_address);

    // Validate IP Address
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    if (result != 1) {
        printf("❌ Invalid IP Address! Please run the program again with a valid IP.\n");
        return 1;
    }

    printf("🎈 Scanning for open ports on %s...\n", ip_address);
    scan_ports(ip_address);
    printf("✨ Scanning completed! Thank you for using Happy Port Scanner! ✨\n");

    return 0;
}