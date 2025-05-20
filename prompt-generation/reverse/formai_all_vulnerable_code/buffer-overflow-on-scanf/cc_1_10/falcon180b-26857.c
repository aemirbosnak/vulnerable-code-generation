//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

// Function to calculate the subnet mask
void *subnet_calculator(void *arg) {
    char *ip_address = (char *) arg;
    char *subnet_mask;
    int i;

    // Calculate the subnet mask
    for (i = 0; i < strlen(ip_address); i++) {
        if (ip_address[i] == '.') {
            subnet_mask = (char *) malloc(strlen(ip_address) + 1);
            strncpy(subnet_mask, ip_address, i);
            strcat(subnet_mask, "255.255.255.0");
            break;
        }
    }

    // Print the subnet mask
    printf("Subnet mask for %s is %s\n", ip_address, subnet_mask);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    char ip_addresses[MAX_THREADS][15];
    int i;

    // Get IP addresses from user
    for (i = 0; i < MAX_THREADS; i++) {
        printf("Enter IP address %d: ", i+1);
        scanf("%s", ip_addresses[i]);
    }

    // Create threads for each IP address
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, subnet_calculator, (void *) ip_addresses[i]);
    }

    // Join threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}