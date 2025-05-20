//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 256

struct subnet {
    int size;
    int num_hosts;
    int first_ip;
    int last_ip;
};

struct subnet subnets[MAX_SUBNETS];
int num_subnets = 0;

void *calculate_subnet(void *arg) {
    int id = *(int *)arg;
    int start_ip = 192 + 168 + (id * 16);
    int end_ip = start_ip + 14;

    int size = end_ip - start_ip;
    int num_hosts = size - 2;

    subnets[num_subnets].size = size;
    subnets[num_subnets].num_hosts = num_hosts;
    subnets[num_subnets].first_ip = start_ip;
    subnets[num_subnets].last_ip = end_ip;

    num_subnets++;

    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, calculate_subnet, (void *)i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Number of subnets: %d\n", num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: Size %d, Number of hosts %d, First IP %d, Last IP %d\n",
               i, subnets[i].size, subnets[i].num_hosts, subnets[i].first_ip, subnets[i].last_ip);
    }

    return 0;
}