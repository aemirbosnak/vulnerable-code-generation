//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 50
#define MAX_REPS 100
#define MAX_DURATION 100

typedef struct {
    char name[50];
    int reps;
    int duration;
} Workout;

typedef struct {
    char name[50];
    int reps;
    int sets;
    int duration;
} Exercise;

int main() {
    char input[100];
    int choice, i, j, k, l;
    Workout workouts[MAX_WORKOUTS];
    Exercise exercises[MAX_EXERCISES];

    memset(workouts, 0, sizeof(workouts));
    memset(exercises, 0, sizeof(exercises));

    while(1) {
        printf("\nFitness Tracker\n");
        printf("1. Add a workout\n2. Add an exercise\n3. View workouts\n4. View exercises\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter workout name: ");
                scanf("%s", &input);
                for(i=0; i<MAX_WORKOUTS; i++) {
                    if(strcmp(workouts[i].name, "") == 0) {
                        strcpy(workouts[i].name, input);
                        break;
                    }
                }
                if(i == MAX_WORKOUTS) {
                    printf("Maximum number of workouts reached.\n");
                }
                break;
            case 2:
                printf("Enter exercise name: ");
                scanf("%s", &input);
                for(j=0; j<MAX_EXERCISES; j++) {
                    if(strcmp(exercises[j].name, "") == 0) {
                        strcpy(exercises[j].name, input);
                        break;
                    }
                }
                if(j == MAX_EXERCISES) {
                    printf("Maximum number of exercises reached.\n");
                }
                break;
            case 3:
                printf("\nWorkouts:\n");
                for(i=0; i<MAX_WORKOUTS; i++) {
                    if(strcmp(workouts[i].name, "")!= 0) {
                        printf("%s\n", workouts[i].name);
                    }
                }
                break;
            case 4:
                printf("\nExercises:\n");
                for(j=0; j<MAX_EXERCISES; j++) {
                    if(strcmp(exercises[j].name, "")!= 0) {
                        printf("%s\n", exercises[j].name);
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}