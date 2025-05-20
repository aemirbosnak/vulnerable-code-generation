//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100

typedef struct {
    char name[50];
    int duration;
    int calories_burned;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration (in minutes): ");
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

int main() {
    printf("Welcome to the Fitness Tracker 3000!\n");

    char choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("A) Add a workout\n");
        printf("B) Display workouts\n");
        printf("C) Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case 'A':
            add_workout();
            break;
        case 'B':
            display_workouts();
            break;
        case 'C':
            printf("Exiting Fitness Tracker 3000...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 'C');

    return 0;
}