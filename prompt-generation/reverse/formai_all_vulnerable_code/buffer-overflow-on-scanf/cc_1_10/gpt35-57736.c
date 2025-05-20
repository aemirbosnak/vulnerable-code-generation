//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: interoperable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int bags, conveyor_capacity, conveyor_speed;
    printf("Enter the number of bags: ");
    scanf("%d", &bags);
    printf("Enter the conveyor capacity: ");
    scanf("%d", &conveyor_capacity);
    printf("Enter the conveyor speed (bags/minute): ");
    scanf("%d", &conveyor_speed);

    int *bag_weights = (int*)malloc(sizeof(int) * bags);
    printf("Enter the weights of the bags: ");
    for (int i = 0; i < bags; i++) {
        scanf("%d", &bag_weights[i]);
    }

    int total_weight = 0;
    for (int i = 0; i < bags; i++) {
        total_weight += bag_weights[i];
    }

    int time_to_process = total_weight / (conveyor_speed * conveyor_capacity) + 1;
    printf("Time to process all bags: %d minutes\n\n", time_to_process);

    srand(time(NULL));
    int conveyor_count = 0, baggage_count = 0;
    while (baggage_count < bags) {
        int conveyor_load = conveyor_capacity < (bags - baggage_count) ? conveyor_capacity : (bags - baggage_count);
        conveyor_count++;

        printf("Conveyor %d is loaded with %d bags\n", conveyor_count, conveyor_load);

        int weight_on_conveyor = 0;
        for (int i = 0; i < conveyor_load; i++) {
            weight_on_conveyor += bag_weights[baggage_count];
            baggage_count++;
        }

        int processing_time = weight_on_conveyor / conveyor_speed + 1;
        printf("Processing time for conveyor %d: %d minutes\n\n", conveyor_count, processing_time);

        int sleep_time = processing_time < time_to_process ? processing_time : time_to_process;
        sleep(sleep_time);
    }

    printf("All bags have been processed!\n\n");
    free(bag_weights);
    return 0;
}