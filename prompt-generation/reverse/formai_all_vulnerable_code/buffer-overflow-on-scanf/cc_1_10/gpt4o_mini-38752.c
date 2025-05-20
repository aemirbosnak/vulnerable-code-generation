//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MIN_PROCESS_TIME 1
#define MAX_PROCESS_TIME 5

typedef struct {
    int bag_id;
    int process_time; // in seconds
} Bag;

Bag bags[MAX_BAGS];
int bags_processed = 0;
int total_processing_time = 0;

void initialize_bags(int num_bags) {
    for (int i = 0; i < num_bags; i++) {
        bags[i].bag_id = i + 1;
        bags[i].process_time = rand() % (MAX_PROCESS_TIME - MIN_PROCESS_TIME + 1) + MIN_PROCESS_TIME;
    }
}

void process_bags(int num_bags) {
    for (int i = 0; i < num_bags; i++) {
        printf("Processing bag ID: %d, Time: %d seconds\n", bags[i].bag_id, bags[i].process_time);
        total_processing_time += bags[i].process_time;
        bags_processed++;
        // Simulate processing time
        sleep(bags[i].process_time);
    }
}

void print_statistics() {
    if (bags_processed == 0) {
        printf("No bags processed.\n");
        return;
    }
    
    double average_processing_time = (double)total_processing_time / bags_processed;
    printf("\n--- Baggage Handling Statistics ---\n");
    printf("Total bags processed: %d\n", bags_processed);
    printf("Total processing time: %d seconds\n", total_processing_time);
    printf("Average processing time per bag: %.2f seconds\n", average_processing_time);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int num_bags;

    printf("Enter the number of bags to simulate (up to %d): ", MAX_BAGS);
    scanf("%d", &num_bags);
    
    if (num_bags < 1 || num_bags > MAX_BAGS) {
        printf("Invalid number of bags. Please enter between 1 and %d.\n", MAX_BAGS);
        return 1;
    }

    initialize_bags(num_bags);
    process_bags(num_bags);
    print_statistics();

    return 0;
}