//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100

typedef struct {
    char name[50];
    int duration;
    int calories_burned;
    time_t start_time;
    time_t end_time;
} Workout;

int main() {
    int choice, i, num_workouts = 0;
    char file_name[20];
    FILE *fp;
    Workout workouts[MAX_WORKOUTS];

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter a filename to save your workouts: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (1) {
        printf("\n1. Add a workout\n2. View workout history\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_workouts >= MAX_WORKOUTS) {
                    printf("Maximum number of workouts reached.\n");
                    break;
                }
                printf("Enter workout name: ");
                scanf("%s", workouts[num_workouts].name);
                printf("Enter workout duration (in seconds): ");
                scanf("%d", &workouts[num_workouts].duration);
                workouts[num_workouts].calories_burned = (int) ((double) workouts[num_workouts].duration / 60 * (double) 3.5);
                time(&workouts[num_workouts].start_time);
                workouts[num_workouts].end_time = workouts[num_workouts].start_time;
                num_workouts++;
                break;
            case 2:
                printf("\nWorkout history:\n");
                for (i = 0; i < num_workouts; i++) {
                    printf("%s\t%d seconds\t%d calories burned\n", workouts[i].name, workouts[i].duration, workouts[i].calories_burned);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}