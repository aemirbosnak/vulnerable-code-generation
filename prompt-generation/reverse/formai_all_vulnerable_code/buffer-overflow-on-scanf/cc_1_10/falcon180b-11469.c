//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct workout {
    char name[50];
    int duration;
    int calories;
};

int main() {
    int choice, i;
    char name[50];
    struct workout workouts[100];
    int num_workouts = 0;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a workout\n");
        printf("2. View workouts\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_workouts >= 100) {
                    printf("You have reached the maximum number of workouts. Please delete a workout to add a new one.\n");
                } else {
                    printf("\nEnter workout name: ");
                    scanf("%s", workouts[num_workouts].name);
                    printf("Enter workout duration (in seconds): ");
                    scanf("%d", &workouts[num_workouts].duration);
                    printf("Enter workout calories burned: ");
                    scanf("%d", &workouts[num_workouts].calories);
                    num_workouts++;
                    printf("\nWorkout added successfully!\n");
                }
                break;
            case 2:
                if(num_workouts == 0) {
                    printf("\nNo workouts added yet.\n");
                } else {
                    for(i=0; i<num_workouts; i++) {
                        printf("\nWorkout %d:\n", i+1);
                        printf("Name: %s\n", workouts[i].name);
                        printf("Duration: %d seconds\n", workouts[i].duration);
                        printf("Calories burned: %d\n", workouts[i].calories);
                    }
                }
                break;
            case 3:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}