//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

struct subnet_calculator_arguments {
    char subnet[16];
    int prefix_length;
};

void calculate_subnet(struct subnet_calculator_arguments *args) {
    struct in_addr subnet_ip;
    struct in_addr broadcast_ip;
    struct in_addr start_ip;
    struct in_addr end_ip;
    struct in_addr netmask;
    inet_aton(args->subnet, &subnet_ip);

    netmask.s_addr = htonl(~((1 << (32 - args->prefix_length)) - 1));
    broadcast_ip.s_addr = (subnet_ip.s_addr | htonl(~netmask.s_addr));
    start_ip.s_addr = (subnet_ip.s_addr & netmask.s_addr) + htonl(1);
    end_ip.s_addr = (broadcast_ip.s_addr & netmask.s_addr) - htonl(1);

    printf("Subnet: %s/%d\n", args->subnet, args->prefix_length);
    printf("Network address: %s\n", inet_ntoa(subnet_ip));
    printf("Netmask: %s\n", inet_ntoa(netmask));
    printf("Broadcast address: %s\n", inet_ntoa(broadcast_ip));
    printf("Usable range: %s to %s\n\n", inet_ntoa(start_ip), inet_ntoa(end_ip));
}

void *run_subnet_calculator(void *arg) {
    struct subnet_calculator_arguments *args = (struct subnet_calculator_arguments*) arg;
    calculate_subnet(args);
    free(args);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [subnet/prefix_length]...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t threads[argc - 1];
    int thread_count = 0;

    for (int i = 1; i < argc; i++) {
        char subnet[16];
        int prefix_length;

        sscanf(argv[i], "%15[^/]/%d", subnet, &prefix_length);

        struct subnet_calculator_arguments *args = malloc(sizeof(struct subnet_calculator_arguments));
        strncpy(args->subnet, subnet, sizeof(args->subnet));
        args->prefix_length = prefix_length;

        if (pthread_create(&threads[thread_count++], NULL, &run_subnet_calculator, args) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < thread_count; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}