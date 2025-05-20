//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A charming structure representing a valiant knight
typedef struct {
    char name[50];
    int prowess;  // Combat prowess level of the knight
    int endurance; // Stamina level of the knight
} Knight;

// Function to simulate a duel between two knights
void duel(Knight *knight1, Knight *knight2) {
    printf("In the realm of valor, %s duels with %s!\n", knight1->name, knight2->name);

    if (knight1->prowess > knight2->prowess) {
        printf("%s triumphantly defeats %s!\n", knight1->name, knight2->name);
    } else if (knight1->prowess < knight2->prowess) {
        printf("%s valiantly falls to %s's might!\n", knight1->name, knight2->name);
    } else {
        printf("A fierce draw between %s and %s ensues!\n", knight1->name, knight2->name);
    }
}

// Function to benchmark the performance of duels
void benchmark_duels(int num_duels) {
    Knight knights[2];
    
    // Create the knights with randomized prowess and endurance
    sprintf(knights[0].name, "Sir Lancelot");
    knights[0].prowess = rand() % 100 + 1;  // Prowess between 1 and 100
    knights[0].endurance = rand() % 100 + 1; // Endurance between 1 and 100

    sprintf(knights[1].name, "Lord Galahad");
    knights[1].prowess = rand() % 100 + 1;
    knights[1].endurance = rand() % 100 + 1;

    printf("Benchmarking %d duels between %s and %s...\n", num_duels, knights[0].name, knights[1].name);
    
    clock_t start = clock(); // Start time
    for (int i = 0; i < num_duels; i++) {
        duel(&knights[0], &knights[1]);
    }
    clock_t end = clock(); // End time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time in seconds
    printf("All duels completed in %.2f seconds.\n", time_taken);
    
    // Display final prowess and endurance
    printf("%s: Prowess = %d, Endurance = %d\n", knights[0].name, knights[0].prowess, knights[0].endurance);
    printf("%s: Prowess = %d, Endurance = %d\n", knights[1].name, knights[1].prowess, knights[1].endurance);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int num_duels = 10; // Set the number of duels to benchmark
    benchmark_duels(num_duels); // Perform the benchmark

    return 0;
}