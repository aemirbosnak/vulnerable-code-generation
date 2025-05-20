//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 50

struct thread_info { // Structure for passing data to threads
    int start_ip[4];
    int end_ip[4];
    int subnet_mask;
};

void *calculate_subnet(void *arg) {
    struct thread_info *data = (struct thread_info *) arg;
    int num_ips = 0;

    for(int i=0; i<4; i++) { // Convert IP address to a single integer
        data->start_ip[i] = data->start_ip[i] << (8*i);
        data->end_ip[i] = data->end_ip[i] << (8*i);
    }

    unsigned int start_ip = data->start_ip[0] | data->start_ip[1] | data->start_ip[2] | data->start_ip[3];
    unsigned int end_ip = data->end_ip[0] | data->end_ip[1] | data->end_ip[2] | data->end_ip[3];

    for(unsigned int i=start_ip; i<=end_ip; i++) { // Calculate number of IPs in subnet
        unsigned int masked_ip = i & (0xFFFFFFFF << (32-data->subnet_mask));
        if(masked_ip == i) num_ips++;
    }

    printf("Subnet range: %d.%d.%d.%d - %d.%d.%d.%d\n", data->start_ip[0], data->start_ip[1], data->start_ip[2], data->start_ip[3], data->end_ip[0], data->end_ip[1], data->end_ip[2], data->end_ip[3]);
    printf("Subnet mask: /%d\n", data->subnet_mask);
    printf("Number of IPs in subnet: %d\n\n", num_ips);

    pthread_exit(NULL);
}

int main() {
    int num_threads, num_ips, subnet_mask;
    struct thread_info thread_data[MAX_THREADS];
    pthread_t threads[MAX_THREADS];

    printf("How many subnets do you want to calculate? (1-50): ");
    scanf("%d", &num_threads);
    if(num_threads > MAX_THREADS) num_threads = MAX_THREADS;

    for(int i=0; i<num_threads; i++) { // Get subnet data from user
        printf("Subnet %d Start IP (x.x.x.x): ", i+1);
        scanf("%d.%d.%d.%d", &thread_data[i].start_ip[0], &thread_data[i].start_ip[1], &thread_data[i].start_ip[2], &thread_data[i].start_ip[3]);
        printf("Subnet %d End IP (x.x.x.x): ", i+1);
        scanf("%d.%d.%d.%d", &thread_data[i].end_ip[0], &thread_data[i].end_ip[1], &thread_data[i].end_ip[2], &thread_data[i].end_ip[3]);
        printf("Subnet %d Subnet Mask (1-32): ", i+1);
        scanf("%d", &thread_data[i].subnet_mask);

        pthread_create(&threads[i], NULL, calculate_subnet, (void *)&thread_data[i]); // Create thread to calculate subnet
    }

    for(int i=0; i<num_threads; i++) {
        pthread_join(threads[i], NULL); // Wait for all threads to finish
    }

    return 0;
}