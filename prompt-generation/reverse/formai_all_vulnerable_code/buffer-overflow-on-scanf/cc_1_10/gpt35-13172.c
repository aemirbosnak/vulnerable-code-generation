//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_THREADS 100

struct thread_args {
    int id;
    char* ip_address;
    int prefix_length;
};

void* subnet_calculator(void* arg) {
    struct thread_args* args = (struct thread_args*) arg;
    char* ip_address = args->ip_address;
    int prefix_length = args->prefix_length;
    
    struct in_addr network_addr, broadcast_addr;
    inet_pton(AF_INET, ip_address, &network_addr);
    network_addr.s_addr &= htonl(~((1 << (32 - prefix_length)) - 1));
    broadcast_addr.s_addr = network_addr.s_addr | htonl((1 << (32 - prefix_length)) - 1);
    
    printf("Thread %d: IP Address: %s, Prefix Length: %d, Network Address: %s, Broadcast Address: %s\n", 
           args->id, ip_address, prefix_length, inet_ntoa(network_addr), inet_ntoa(broadcast_addr));
    
    free(args);
    pthread_exit(NULL);
}

int main() {
    char ip_address[20];
    int prefix_length;
    int num_threads;
    pthread_t threads[MAX_THREADS];
    
    printf("Enter the IP address and prefix length (separated by a space):\n");
    scanf("%s %d", ip_address, &prefix_length);
    
    printf("Enter the number of threads to use:\n");
    scanf("%d", &num_threads);
    
    int i;
    for (i = 0; i < num_threads; i++) {
        struct thread_args* args = (struct thread_args*) malloc(sizeof(struct thread_args));
        args->id = i;
        args->ip_address = ip_address;
        args->prefix_length = prefix_length;
        pthread_create(&threads[i], NULL, subnet_calculator, (void*) args);
    }
    
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}