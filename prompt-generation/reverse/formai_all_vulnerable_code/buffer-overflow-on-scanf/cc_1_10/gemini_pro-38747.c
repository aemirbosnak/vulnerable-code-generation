//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Colors for console output
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

// Data structures
typedef struct {
    int steps;
    int calories;
    int distance;
    int active_time;
} FitnessData;

// Function prototypes
FitnessData get_fitness_data();
void print_fitness_data(FitnessData data);

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Get the fitness data from the user
    FitnessData data = get_fitness_data();

    // Print the fitness data to the console
    print_fitness_data(data);

    return 0;
}

FitnessData get_fitness_data() {
    FitnessData data;

    // Get the number of steps taken
    printf("How many steps have you taken today? ");
    scanf("%d", &data.steps);

    // Get the number of calories burned
    printf("How many calories have you burned today? ");
    scanf("%d", &data.calories);

    // Get the distance travelled
    printf("How many kilometers have you travelled today? ");
    scanf("%d", &data.distance);

    // Get the active time
    printf("How many minutes have you been active today? ");
    scanf("%d", &data.active_time);

    return data;
}

void print_fitness_data(FitnessData data) {
    printf("\n\n");

    // Print the number of steps taken
    printf("Steps taken: %d\n", data.steps);

    // Print the number of calories burned
    printf("Calories burned: %d\n", data.calories);

    // Print the distance travelled
    printf("Distance travelled: %d km\n", data.distance);

    // Print the active time
    printf("Active time: %d minutes\n", data.active_time);

    // Print a motivational message
    printf("\n\nKeep up the great work!\n\n");
}