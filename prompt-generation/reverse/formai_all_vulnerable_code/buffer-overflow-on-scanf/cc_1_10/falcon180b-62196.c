//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 10
#define MAX_REPS 100
#define MAX_SETS 10
#define MAX_DURATION 100

typedef struct {
    char name[50];
    int reps;
    int sets;
} Exercise;

typedef struct {
    char name[50];
    Exercise exercises[MAX_EXERCISES];
    int duration;
} Workout;

int main() {
    Workout workouts[MAX_WORKOUTS];
    int numWorkouts = 0;
    char choice;

    do {
        printf("Fitness Tracker\n");
        printf("Enter choice:\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numWorkouts >= MAX_WORKOUTS) {
                    printf("Maximum number of workouts reached.\n");
                } else {
                    printf("Enter workout name: ");
                    scanf("%s", workouts[numWorkouts].name);
                    numWorkouts++;
                }
                break;
            case '2':
                printf("Workouts:\n");
                for(int i = 0; i < numWorkouts; i++) {
                    printf("%s\n", workouts[i].name);
                }
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');

    return 0;
}