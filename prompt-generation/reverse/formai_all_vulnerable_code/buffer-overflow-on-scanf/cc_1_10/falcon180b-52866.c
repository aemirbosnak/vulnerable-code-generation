//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 50
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 1000

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: maximum number of workouts reached\n");
        return;
    }
    
    char name[MAX_WORKOUT_NAME_LENGTH];
    printf("Enter workout name: ");
    scanf("%s", name);
    strcpy(workouts[num_workouts].name, name);

    int duration;
    printf("Enter workout duration in seconds: ");
    scanf("%d", &duration);
    workouts[num_workouts].duration = duration;

    num_workouts++;
}

void display_workouts() {
    if (num_workouts == 0) {
        printf("No workouts added yet\n");
        return;
    }

    printf("Workout Name\tDuration (seconds)\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\t%d\n", workouts[i].name, workouts[i].duration);
    }
}

void delete_workout() {
    if (num_workouts == 0) {
        printf("No workouts added yet\n");
        return;
    }

    int index;
    printf("Enter index of workout to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_workouts) {
        printf("Error: invalid index\n");
        return;
    }

    num_workouts--;
    for (int i = index; i < num_workouts; i++) {
        strcpy(workouts[i].name, workouts[i+1].name);
        workouts[i].duration = workouts[i+1].duration;
    }
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        printf("\n");
        printf("1. Add workout\n");
        printf("2. Display workouts\n");
        printf("3. Delete workout\n");
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
            delete_workout();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Error: invalid choice\n");
        }
    }

    return 0;
}