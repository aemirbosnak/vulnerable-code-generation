//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
int 
main() {

    printf("Welcome to Airport Baggage Handling Simulation!\n\n");
    printf("Enter the number of bags to be handled by the system: ");
    int num_bags;
    scanf("%d", &num_bags);
    fflush(stdin);

    printf("\nEnter the number of workers available: ");
    int num_workers;
    scanf("%d", &num_workers);
    fflush(stdin);

    printf("\nEnter the time taken by each worker to handle a bag (in minutes): ");
    int worker_time;
    scanf("%d", &worker_time);
    fflush(stdin);

    printf("\nEnter the number of baggage processing zones equipped with conveyor belts: ");
    int num_zones;
    scanf("%d", &num_zones);
    fflush(stdin);

    printf("\nEnter the time taken by the conveyor belt to deliver a bag to the processing zone (in minutes): ");
    int conveyor_time;
    scanf("%d", &conveyor_time);
    fflush(stdin);

    printf("\nEnter the maximum time a bag can wait in the queue before getting processed (in minutes): ");
    int max_wait_time;
    scanf("%d", &max_wait_time);
    fflush(stdin);

    int i;
    int *bags = (int*)malloc(sizeof(int)*num_bags);
    for(i=0; i<num_bags; i++) {
        printf("\nEnter the processing time required for bag %d to get handled at the processing zone (in minutes): ", i+1);
        scanf("%d", &bags[i]);
        fflush(stdin);
    }

    int total_time_taken = 0;
    int *waiting_time = (int*)malloc(sizeof(int)*num_bags);

    for(i=0; i<num_bags; i++) {
        int min_wait_time = 999999;
        int free_worker_zone = -1;
        int j;
        for(j=0; j<num_zones; j++) {
            if(waiting_time[j] < min_wait_time) {
                min_wait_time = waiting_time[j];
                free_worker_zone = j;
            }
        }

        if(min_wait_time > max_wait_time) {
            printf("\nBag %d left unprocessed after waiting for too long!\n", i+1);
            waiting_time[free_worker_zone] = 0;
            continue;
        }

        total_time_taken = total_time_taken + min_wait_time + bags[i];
        waiting_time[free_worker_zone] = min_wait_time + bags[i] + conveyor_time + (worker_time*(num_workers-1));
        printf("\nBag %d processed successfully in time %d minutes!\n", i+1, total_time_taken);

    }
    
    printf("\nTotal time taken to process all the bags: %d minutes\n", total_time_taken);
}