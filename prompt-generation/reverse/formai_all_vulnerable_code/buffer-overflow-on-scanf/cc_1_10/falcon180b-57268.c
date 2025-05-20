//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to calculate subnet mask
void *subnet_calculator(void *arg) {
    char ip[16], subnet[16];
    int i, j, k, mask = 0;

    // Get input IP address from user
    printf("Enter IP address: ");
    scanf("%s", ip);

    // Convert IP address to integer
    int ip_int = inet_addr(ip);

    // Calculate subnet mask
    for (i = 0; i < 32; i++) {
        if ((ip_int & (1 << i)) == 0) {
            mask++;
        } else {
            break;
        }
    }

    // Convert subnet mask to dotted decimal format
    for (i = 0, k = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if ((mask & (1 << (7 - j))) == 0) {
                subnet[k++] = '.';
            } else {
                subnet[k++] = '1';
            }
        }
        subnet[k++] = '\0';
        mask <<= 8;
    }

    // Print subnet mask
    printf("Subnet mask: %s\n", subnet);

    pthread_exit(0);
}

int main() {
    int i, ret;
    pthread_t threads[10];

    // Create threads
    for (i = 0; i < 10; i++) {
        ret = pthread_create(&threads[i], NULL, subnet_calculator, NULL);
        if (ret!= 0) {
            printf("Error: Unable to create thread, %d\n", ret);
            exit(-1);
        }
    }

    // Join threads
    for (i = 0; i < 10; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret!= 0) {
            printf("Error: Unable to join thread, %d\n", ret);
            exit(-1);
        }
    }

    return 0;
}