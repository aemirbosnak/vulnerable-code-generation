//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 100
#define MAX_REPS 100
#define MAX_SETS 100
#define MAX_DURATION 100
#define MAX_DISTANCE 100
#define MAX_CALORIES 100

typedef struct {
    char name[100];
    int reps;
    int sets;
    float weight;
    float distance;
    int calories;
} Exercise;

typedef struct {
    char name[100];
    int duration;
    int distance;
    int calories;
} Workout;

int main() {
    int choice, num_workouts = 0, num_exercises = 0, i, j;
    char input[100];
    Exercise exercises[MAX_EXERCISES];
    Workout workouts[MAX_WORKOUTS];
    time_t start, end;

    printf("Welcome to the Fitness Tracker!\n");
    while(1) {
        printf("\n1. Add Workout\n2. View Workouts\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_workouts >= MAX_WORKOUTS) {
                    printf("Maximum number of workouts reached.\n");
                    break;
                }
                printf("Enter workout name: ");
                scanf("%s", input);
                strcpy(workouts[num_workouts].name, input);
                printf("Enter workout duration (in seconds): ");
                scanf("%d", &workouts[num_workouts].duration);
                printf("Enter workout distance (in meters): ");
                scanf("%d", &workouts[num_workouts].distance);
                printf("Enter workout calories burned: ");
                scanf("%d", &workouts[num_workouts].calories);
                num_workouts++;
                break;

            case 2:
                if(num_workouts == 0) {
                    printf("No workouts added yet.\n");
                    break;
                }
                for(i=0; i<num_workouts; i++) {
                    printf("\nWorkout %d:\n", i+1);
                    printf("Name: %s\n", workouts[i].name);
                    printf("Duration: %d seconds\n", workouts[i].duration);
                    printf("Distance: %d meters\n", workouts[i].distance);
                    printf("Calories burned: %d\n\n", workouts[i].calories);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}