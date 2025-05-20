//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int duration;
    int calories_burned;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration in minutes: ");
    scanf("%d", &workouts[num_workouts].duration);

    printf("Enter calories burned: ");
    scanf("%d", &workouts[num_workouts].calories_burned);

    num_workouts++;
}

void display_workouts() {
    printf("Workout Name\tDuration\tCalories Burned\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\t%d\t%d\n", workouts[i].name, workouts[i].duration, workouts[i].calories_burned);
    }
}

void calculate_total_calories() {
    int total_calories = 0;
    for (int i = 0; i < num_workouts; i++) {
        total_calories += workouts[i].calories_burned;
    }
    printf("Total calories burned: %d\n", total_calories);
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        printf("\n");
        printf("1. Add workout\n");
        printf("2. Display workouts\n");
        printf("3. Calculate total calories burned\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                display_workouts();
                break;
            case 3:
                calculate_total_calories();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}