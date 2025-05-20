//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_BAGGAGE 100
#define MAX_THREADS 10

pthread_t threads[MAX_THREADS];

int baggage_count = 0;
int luggage_belts[5];

void *passenger(void *ptr) {
    int bag_count = *(int *)ptr;
    free(ptr);

    // Generate bag count number of bags for passenger
    for(int i = 0; i < bag_count; i++) {
        int output_belt = rand() % 5;
        luggage_belts[output_belt]++;
        baggage_count++;
        printf("Passenger added bag to luggage belt %d.\n", output_belt);
    }

    pthread_exit(NULL);
}

void *handler(void *ptr) {
    int total_bags_to_handle = *(int *)ptr;
    free(ptr);

    while(baggage_count < total_bags_to_handle) {
        for(int i = 0; i < 5; i++) {
            if(luggage_belts[i] > 0) {
                luggage_belts[i]--;
                baggage_count--;
                printf("Handler removed bag from luggage belt %d.\n", i);
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    int total_bags = 0;
    printf("Enter total number of bags to be processed: ");
    scanf("%d", &total_bags);

    int bags_per_thread = total_bags / MAX_THREADS;
    int remainder_bags = total_bags % MAX_THREADS;

    // Create passenger threads
    for(int i = 0; i < MAX_THREADS; i++) {
        int *bag_count;
        if(i == 0)
            bag_count = malloc(sizeof(int));
        else
            bag_count = malloc(sizeof(int) + 1);
        *bag_count = bags_per_thread;
        if (remainder_bags > 0) {
            *bag_count += 1;
            remainder_bags--;
        }
        pthread_create(&threads[i], NULL, passenger, bag_count);
        printf("Created passenger thread %ld.\n", threads[i]);
    }

    // Create handler thread
    int *total_bag_count = malloc(sizeof(int));
    *total_bag_count = total_bags;
    pthread_create(&threads[MAX_THREADS - 1], NULL, handler, total_bag_count);
    printf("Created handler thread %ld.\n", threads[MAX_THREADS - 1]);

    // Wait for all threads to finish
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All passenger threads finished.\n");
    pthread_join(threads[MAX_THREADS - 1], NULL);
    printf("Handler thread finished.\n");

    return 0;
}