//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_EXERCISE_NAME_LENGTH 50

typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH];
    int caloriesBurned;
} Exercise;

void printMenu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add Exercise\n");
    printf("2. View Exercises\n");
    printf("3. Track Workout\n");
    printf("4. View History\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    Exercise exercises[MAX_EXERCISES];
    int numExercises = 0;
    char input[100];

    srand(time(0));

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(numExercises >= MAX_EXERCISES) {
                    printf("Sorry, you have reached the maximum number of exercises.\n");
                } else {
                    printf("Enter the name of the exercise: ");
                    scanf("%s", input);
                    strcpy(exercises[numExercises].name, input);
                    printf("Enter the number of calories burned: ");
                    scanf("%d", &exercises[numExercises].caloriesBurned);
                    numExercises++;
                }
                break;
            case 2:
                if(numExercises == 0) {
                    printf("Sorry, there are no exercises to view.\n");
                } else {
                    printf("List of Exercises:\n");
                    for(int i=0; i<numExercises; i++) {
                        printf("%s - %d calories\n", exercises[i].name, exercises[i].caloriesBurned);
                    }
                }
                break;
            case 3:
                if(numExercises == 0) {
                    printf("Sorry, there are no exercises to track.\n");
                } else {
                    int exerciseChoice;
                    printf("Enter the number of the exercise you want to track: ");
                    scanf("%d", &exerciseChoice);

                    if(exerciseChoice >= 0 && exerciseChoice < numExercises) {
                        printf("You burned %d calories doing %s.\n", exercises[exerciseChoice].caloriesBurned, exercises[exerciseChoice].name);
                    } else {
                        printf("Invalid exercise choice.\n");
                    }
                }
                break;
            case 4:
                if(numExercises == 0) {
                    printf("Sorry, there is no workout history.\n");
                } else {
                    printf("Workout History:\n");
                    for(int i=0; i<numExercises; i++) {
                        printf("%s - %d calories\n", exercises[i].name, exercises[i].caloriesBurned);
                    }
                }
                break;
            case 5:
                printf("Exiting Fitness Tracker...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);

    return 0;
}