//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 1000
#define MAX_DISTANCE 1000

typedef struct {
    char name[50];
    int steps;
    float distance;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    char input[100];
    printf("Enter workout name: ");
    scanf("%s", input);
    strcpy(workouts[num_workouts].name, input);
    printf("Enter number of steps: ");
    scanf("%d", &workouts[num_workouts].steps);
    printf("Enter distance in meters: ");
    scanf("%f", &workouts[num_workouts].distance);
    num_workouts++;
}

void print_workouts() {
    printf("Workout Name | Steps | Distance\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s | %d | %.2f\n", workouts[i].name, workouts[i].steps, workouts[i].distance);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Print workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                print_workouts();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
    return 0;
}