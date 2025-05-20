//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 20
#define MAX_REPS 100
#define MAX_SETS 10
#define MAX_DURATION 1000

typedef struct {
    char name[50];
    int duration;
} workout;

typedef struct {
    char name[50];
    int reps;
    int sets;
} exercise;

workout workouts[MAX_WORKOUTS];
exercise exercises[MAX_EXERCISES];

int main() {
    int choice, i, j;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please choose an option:\n");
    printf("1. Create a new workout\n");
    printf("2. Add an exercise to a workout\n");
    printf("3. View workout details\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the name of the new workout:\n");
            scanf("%s", workouts[0].name);
            printf("Enter the duration of the workout in seconds:\n");
            scanf("%d", &workouts[0].duration);
            break;
        case 2:
            printf("Enter the name of the workout to add an exercise to:\n");
            scanf("%s", workouts[0].name);
            printf("Enter the name of the exercise:\n");
            scanf("%s", exercises[0].name);
            printf("Enter the number of reps:\n");
            scanf("%d", &exercises[0].reps);
            printf("Enter the number of sets:\n");
            scanf("%d", &exercises[0].sets);
            break;
        case 3:
            printf("Enter the name of the workout to view details for:\n");
            scanf("%s", workouts[0].name);
            for(i=0; i<MAX_EXERCISES; i++) {
                if(strcmp(workouts[0].name, exercises[i].name) == 0) {
                    printf("Exercise: %s\n", exercises[i].name);
                    printf("Reps: %d\n", exercises[i].reps);
                    printf("Sets: %d\n", exercises[i].sets);
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}