//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define a structure to store fitness data
typedef struct FitnessData {
    int stepsTaken;
    int caloriesBurned;
    char workoutType;
    time_t timestamp;
} FitnessData;

// Function to calculate the number of calories burned
int calculateCalories(int stepsTaken) {
    return (stepsTaken * 10) / 2;
}

// Function to store fitness data
void storeFitnessData(FitnessData data) {
    FILE *file = fopen("fitness_data.txt", "a");
    fprintf(file, "%d, %d, %c, %ld\n", data.stepsTaken, data.caloriesBurned, data.workoutType, data.timestamp);
    fclose(file);
}

// Main function
int main() {
    // Create a fitness data structure
    FitnessData data;

    // Get the current time
    time_t timestamp = time(NULL);

    // Prompt the user to enter the number of steps taken
    printf("Enter the number of steps taken: ");
    scanf("%d", &data.stepsTaken);

    // Calculate the number of calories burned
    data.caloriesBurned = calculateCalories(data.stepsTaken);

    // Prompt the user to enter the workout type
    printf("Enter the workout type (e.g. running, biking): ");
    scanf("%c", &data.workoutType);

    // Store the fitness data
    storeFitnessData(data);

    // Print the stored fitness data
    printf("Stored fitness data:\n");
    FILE *file = fopen("fitness_data.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        printf("%s", line);
    }
    fclose(file);

    return 0;
}