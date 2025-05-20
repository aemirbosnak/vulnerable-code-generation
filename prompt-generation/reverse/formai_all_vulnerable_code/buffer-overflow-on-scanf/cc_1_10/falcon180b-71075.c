//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_STEPS 1000

typedef struct {
    char name[50];
    int steps;
    int calories;
    int distance;
    time_t start_time;
    time_t end_time;
    int duration;
} Workout;

void add_workout(Workout* workouts, int num_workouts) {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);
    workouts[num_workouts].steps = 0;
    workouts[num_workouts].calories = 0;
    workouts[num_workouts].distance = 0;
    workouts[num_workouts].start_time = time(NULL);
    workouts[num_workouts].end_time = 0;
    workouts[num_workouts].duration = 0;
    num_workouts++;
}

void update_workout(Workout* workouts, int num_workouts) {
    printf("Enter workout name: ");
    char name[50];
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < num_workouts; i++) {
        if (strcmp(workouts[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Workout not found.\n");
        return;
    }
    workouts[index].steps += MAX_STEPS;
    workouts[index].calories += 100;
    workouts[index].distance += 10;
    workouts[index].end_time = time(NULL);
    workouts[index].duration = workouts[index].end_time - workouts[index].start_time;
}

void display_workouts(Workout* workouts, int num_workouts) {
    printf("Workout Name | Steps | Calories | Distance | Duration\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s | %d | %d | %d | %d seconds\n", workouts[i].name, workouts[i].steps, workouts[i].calories, workouts[i].distance, workouts[i].duration);
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    while (num_workouts < MAX_WORKOUTS) {
        printf("1. Add workout\n2. Update workout\n3. Display workouts\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_workout(workouts, num_workouts);
                break;
            case 2:
                update_workout(workouts, num_workouts);
                break;
            case 3:
                display_workouts(workouts, num_workouts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}