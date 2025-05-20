//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_REPS 100
#define MAX_DURATION 1000

typedef struct {
    char name[50];
    int reps;
    int duration;
} Exercise;

int main() {
    int numExercises = 0;
    Exercise exercises[MAX_EXERCISES];
    char choice;

    srand(time(NULL));

    do {
        printf("Welcome to the Fitness Tracker!\n\n");
        printf("Please choose an option:\n");
        printf("1. Add Exercise\n");
        printf("2. View Exercises\n");
        printf("3. Start Workout\n");
        printf("4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (numExercises >= MAX_EXERCISES) {
                    printf("Sorry, you have reached the maximum number of exercises.\n");
                } else {
                    printf("Enter the name of the exercise:\n");
                    scanf("%s", exercises[numExercises].name);
                    printf("Enter the number of reps:\n");
                    scanf("%d", &exercises[numExercises].reps);
                    printf("Enter the duration (in seconds):\n");
                    scanf("%d", &exercises[numExercises].duration);
                    numExercises++;
                }
                break;

            case '2':
                if (numExercises == 0) {
                    printf("No exercises added yet.\n");
                } else {
                    printf("List of Exercises:\n");
                    for (int i = 0; i < numExercises; i++) {
                        printf("%s - %d reps - %d seconds\n", exercises[i].name, exercises[i].reps, exercises[i].duration);
                    }
                }
                break;

            case '3':
                if (numExercises == 0) {
                    printf("No exercises added yet.\n");
                } else {
                    int totalDuration = 0;
                    for (int i = 0; i < numExercises; i++) {
                        totalDuration += exercises[i].duration;
                    }
                    printf("Starting workout...\n");
                    for (int i = 0; i < numExercises; i++) {
                        printf("Doing %s for %d seconds...\n", exercises[i].name, exercises[i].duration);
                        sleep(exercises[i].duration);
                    }
                    printf("Workout complete! Total duration: %d seconds.\n", totalDuration);
                }
                break;

            case '4':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}