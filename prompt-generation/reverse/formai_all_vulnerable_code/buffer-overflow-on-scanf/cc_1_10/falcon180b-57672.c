//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_TIME 60 * 60

typedef struct {
    int id;
    char name[50];
    int duration;
    time_t start_time;
    time_t end_time;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration (in seconds): ");
    scanf("%d", &workouts[num_workouts].duration);

    time(&workouts[num_workouts].start_time);
    workouts[num_workouts].end_time = workouts[num_workouts].start_time + workouts[num_workouts].duration;

    num_workouts++;
}

void view_workouts() {
    printf("ID\tName\tDuration (seconds)\tStart Time\tEnd Time\n");

    for (int i = 0; i < num_workouts; i++) {
        printf("%d\t%s\t%d\t%s\t%s\n", workouts[i].id, workouts[i].name, workouts[i].duration, ctime(&workouts[i].start_time), ctime(&workouts[i].end_time));
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                view_workouts();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}