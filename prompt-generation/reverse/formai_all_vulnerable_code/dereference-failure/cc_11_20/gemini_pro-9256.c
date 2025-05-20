//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 10

typedef struct {
    char *name;
    int age;
    time_t time_of_travel;
} time_traveler;

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create an array of time travelers
    time_traveler time_travelers[MAX_TIME_TRAVELERS];

    // Initialize the time travelers
    for (int i = 0; i < MAX_TIME_TRAVELERS; i++) {
        time_travelers[i].name = NULL;
        time_travelers[i].age = 0;
        time_travelers[i].time_of_travel = 0;
    }

    // Get the number of time travelers from the user
    int num_time_travelers;
    printf("Enter the number of time travelers: ");
    scanf("%d", &num_time_travelers);

    // Check if the number of time travelers is valid
    if (num_time_travelers < 1 || num_time_travelers > MAX_TIME_TRAVELERS) {
        printf("Invalid number of time travelers. Must be between 1 and %d.\n", MAX_TIME_TRAVELERS);
        return 1;
    }

    // Get the names and ages of the time travelers from the user
    for (int i = 0; i < num_time_travelers; i++) {
        // Get the name of the time traveler
        char name[256];
        printf("Enter the name of time traveler %d: ", i + 1);
        scanf("%s", name);

        // Allocate memory for the name of the time traveler
        time_travelers[i].name = malloc(strlen(name) + 1);

        // Copy the name of the time traveler to the allocated memory
        strcpy(time_travelers[i].name, name);

        // Get the age of the time traveler
        int age;
        printf("Enter the age of time traveler %d: ", i + 1);
        scanf("%d", &age);

        // Check if the age of the time traveler is valid
        if (age < 1 || age > 120) {
            printf("Invalid age for time traveler %d. Must be between 1 and 120.\n", i + 1);
            return 1;
        }

        // Set the age of the time traveler
        time_travelers[i].age = age;
    }

    // Get the time of travel from the user
    time_t time_of_travel;
    printf("Enter the time of travel (in seconds since the epoch): ");
    scanf("%ld", &time_of_travel);

    // Check if the time of travel is valid
    if (time_of_travel < 0) {
        printf("Invalid time of travel. Must be a non-negative integer.\n");
        return 1;
    }

    // Set the time of travel for all time travelers
    for (int i = 0; i < num_time_travelers; i++) {
        time_travelers[i].time_of_travel = time_of_travel;
    }

    // Print the time travelers
    printf("\nTime Travelers:\n");
    for (int i = 0; i < num_time_travelers; i++) {
        printf("Name: %s\n", time_travelers[i].name);
        printf("Age: %d\n", time_travelers[i].age);
        printf("Time of travel: %ld\n\n", time_travelers[i].time_of_travel);
    }

    // Free the memory allocated for the names of the time travelers
    for (int i = 0; i < num_time_travelers; i++) {
        free(time_travelers[i].name);
    }

    return 0;
}