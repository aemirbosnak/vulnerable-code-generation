//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MIN_VALUE -100
#define MAX_VALUE 100

// Define a struct to hold the statistics
typedef struct {
    double mean;
    double stddev;
    int count;
} stats_t;

// Function to generate random numbers
stats_t* generate_stats(int n) {
    stats_t* stats = malloc(sizeof(stats_t));
    int i;

    for (i = 0; i < n; i++) {
        // Generate a random number between MIN_VALUE and MAX_VALUE
        double x = (double)(rand() % (MAX_VALUE - MIN_VALUE)) + MIN_VALUE;

        // Calculate the mean and standard deviation
        stats->mean += x;
        stats->count++;

        // Calculate the standard deviation
        stats->stddev = stats->mean / stats->count;
    }

    return stats;
}

// Function to print the statistics
void print_stats(stats_t* stats) {
    printf("Mean: %f\n", stats->mean);
    printf("Standard Deviation: %f\n", stats->stddev);
    printf("Count: %d\n", stats->count);
}

int main() {
    srand(time(NULL));

    // Generate 100 random numbers
    stats_t* stats = generate_stats(100);

    // Print the statistics
    print_stats(stats);

    // Free the memory
    free(stats);

    return 0;
}