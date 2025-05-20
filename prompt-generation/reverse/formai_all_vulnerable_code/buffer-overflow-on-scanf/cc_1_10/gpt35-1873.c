//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the user's name and exercise name
#define MAX_NAME_LENGTH 30
#define MAX_EXERCISE_LENGTH 50

// Define the structure for exercise logs
typedef struct {
    char name[MAX_NAME_LENGTH];
    char exercise[MAX_EXERCISE_LENGTH];
    int sets;
    int reps;
    float weight;
} Log;

int main() {
    int numLogs;

    // Get the number of logs the user wants to input
    printf("How many exercise logs would you like to enter?\n");
    scanf("%d", &numLogs);

    // Allocate memory for the logs
    Log *logs = (Log*) malloc(sizeof(Log) * numLogs);

    // Loop through each log and get the user's input
    for (int i = 0; i < numLogs; i++) {
        printf("Enter your name for log number %d:\n", i+1);
        scanf("%s", logs[i].name);
        printf("Enter the exercise name for log number %d:\n", i+1);
        scanf("%s", logs[i].exercise);;
        printf("Enter the number of sets for log number %d:\n", i+1);
        scanf("%d", &logs[i].sets);
        printf("Enter the number of reps for log number %d:\n", i+1);
        scanf("%d", &logs[i].reps);
        printf("Enter the weight for log number %d:\n", i+1);
        scanf("%f", &logs[i].weight);
    }

    // Print out each log
    for (int i = 0; i < numLogs; i++) {
        printf("Name: %s\n", logs[i].name);
        printf("Exercise: %s\n", logs[i].exercise);
        printf("Sets: %d\n", logs[i].sets);
        printf("Reps: %d\n", logs[i].reps);
        printf("Weight: %.2f\n", logs[i].weight);
    }

    // Free the allocated memory
    free(logs);

    return 0;
}