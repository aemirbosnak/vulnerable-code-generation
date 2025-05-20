//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: portable
/*
 * fitness_tracker.c
 *
 * A simple C program for tracking fitness data.
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Structures for holding fitness data
typedef struct {
    float distance;
    float time;
    float pace;
} FitnessData;

typedef struct {
    FitnessData run;
    FitnessData bike;
    FitnessData swim;
} FitnessDataSet;

// Function prototypes
void readFitnessData(FitnessData* data);
void displayFitnessData(FitnessData* data);

int main() {
    // Initialize the fitness data set
    FitnessDataSet data;
    readFitnessData(&data.run);
    readFitnessData(&data.bike);
    readFitnessData(&data.swim);

    // Display the fitness data
    displayFitnessData(&data.run);
    displayFitnessData(&data.bike);
    displayFitnessData(&data.swim);

    return 0;
}

// Function to read fitness data from the user
void readFitnessData(FitnessData* data) {
    // Prompt the user to enter the distance, time, and pace
    printf("Enter the distance: ");
    scanf("%f", &data->distance);
    printf("Enter the time: ");
    scanf("%f", &data->time);
    printf("Enter the pace: ");
    scanf("%f", &data->pace);
}

// Function to display fitness data
void displayFitnessData(FitnessData* data) {
    // Calculate the total distance
    float totalDistance = data->distance * data->time / 60.0;

    // Display the fitness data
    printf("Total distance: %f\n", totalDistance);
    printf("Pace: %f\n", data->pace);
}