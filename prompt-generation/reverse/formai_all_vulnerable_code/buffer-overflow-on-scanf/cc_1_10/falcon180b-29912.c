//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 50

typedef struct {
    char name[50];
    int calories;
    int duration;
} workout;

typedef struct {
    char name[50];
    int calories;
} exercise;

int main() {
    system("clear");
    printf("\nWelcome to the Fitness Tracker!\n\n");

    int choice;
    while(true) {
        system("clear");
        printf("\n1. Create new workout\n2. View/Edit existing workout\n3. Create new exercise\n4. View/Edit existing exercise\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Create new workout
                break;
            case 2:
                // View/Edit existing workout
                break;
            case 3:
                // Create new exercise
                break;
            case 4:
                // View/Edit existing exercise
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}