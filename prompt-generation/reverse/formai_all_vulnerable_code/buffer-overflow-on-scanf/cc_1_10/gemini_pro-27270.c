//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the serenity mode
#define SERENITY_MODE 1

// Define the exercise modes
#define WALKING_MODE 2
#define RUNNING_MODE 3
#define CYCLING_MODE 4
#define SWIMMING_MODE 5
#define OTHER_MODE 6

// Define the intensity levels
#define LOW_INTENSITY 1
#define MEDIUM_INTENSITY 2
#define HIGH_INTENSITY 3

// Define the data structures
typedef struct {
    int mode;
    int intensity;
    int duration;
    int distance;
} ExerciseData;

typedef struct {
    int totalDuration;
    int totalDistance;
} FitnessSummary;

// Function to print the serenity mode message
void printSerenityMessage() {
    printf("Take a deep breath and relax. Serenity mode activated.\n");
}

// Function to print the exercise mode message
void printExerciseMessage(int mode) {
    switch (mode) {
        case WALKING_MODE:
            printf("Walking mode activated.\n");
            break;
        case RUNNING_MODE:
            printf("Running mode activated.\n");
            break;
        case CYCLING_MODE:
            printf("Cycling mode activated.\n");
            break;
        case SWIMMING_MODE:
            printf("Swimming mode activated.\n");
            break;
        case OTHER_MODE:
            printf("Other mode activated.\n");
            break;
        default:
            printf("Invalid mode.\n");
            break;
    }
}

// Function to print the exercise intensity message
void printExerciseIntensityMessage(int intensity) {
    switch (intensity) {
        case LOW_INTENSITY:
            printf("Low intensity selected.\n");
            break;
        case MEDIUM_INTENSITY:
            printf("Medium intensity selected.\n");
            break;
        case HIGH_INTENSITY:
            printf("High intensity selected.\n");
            break;
        default:
            printf("Invalid intensity.\n");
            break;
    }
}

// Function to get the exercise data from the user
ExerciseData getExerciseData() {
    ExerciseData data;

    // Get the mode
    printf("Enter the exercise mode (1 for Serenity, 2 for Walking, 3 for Running, 4 for Cycling, 5 for Swimming, 6 for Other): ");
    scanf("%d", &data.mode);

    // Get the intensity
    printf("Enter the exercise intensity (1 for Low, 2 for Medium, 3 for High): ");
    scanf("%d", &data.intensity);

    // Get the duration
    printf("Enter the exercise duration (in minutes): ");
    scanf("%d", &data.duration);

    // Get the distance (in kilometers)
    printf("Enter the exercise distance (in kilometers): ");
    scanf("%d", &data.distance);

    return data;
}

// Function to calculate the fitness summary
FitnessSummary calculateFitnessSummary(ExerciseData data) {
    FitnessSummary summary;

    summary.totalDuration = data.duration;
    summary.totalDistance = data.distance;

    return summary;
}

// Function to print the fitness summary
void printFitnessSummary(FitnessSummary summary) {
    printf("Total duration: %d minutes\n", summary.totalDuration);
    printf("Total distance: %d kilometers\n", summary.totalDistance);
}

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to the Serenity Fitness Tracker!\n");

    // Get the exercise data from the user
    ExerciseData data = getExerciseData();

    // Check if the user wants to enter serenity mode
    if (data.mode == SERENITY_MODE) {
        printSerenityMessage();
    } else {
        // Print the exercise mode message
        printExerciseMessage(data.mode);

        // Print the exercise intensity message
        printExerciseIntensityMessage(data.intensity);

        // Calculate the fitness summary
        FitnessSummary summary = calculateFitnessSummary(data);

        // Print the fitness summary
        printFitnessSummary(summary);
    }

    return 0;
}