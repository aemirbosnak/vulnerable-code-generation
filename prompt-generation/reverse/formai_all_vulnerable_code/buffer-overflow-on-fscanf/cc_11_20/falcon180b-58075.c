//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LENGTH 50

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
    int caloriesBurned;
    time_t startTime;
    time_t endTime;
} Workout;

int main() {
    int numWorkouts = 0;
    Workout workouts[MAX_WORKOUTS];
    char input[100];
    FILE *workoutFile;

    // Open workout file
    workoutFile = fopen("workouts.txt", "r");
    if (workoutFile == NULL) {
        printf("Error: could not open workout file.\n");
        return 1;
    }

    // Read workouts from file
    while (fscanf(workoutFile, "%s %d %d %ld %ld\n", workouts[numWorkouts].name, &workouts[numWorkouts].duration, &workouts[numWorkouts].caloriesBurned, &workouts[numWorkouts].startTime, &workouts[numWorkouts].endTime)!= EOF) {
        numWorkouts++;
    }
    fclose(workoutFile);

    while (1) {
        printf("Fitness Tracker Menu:\n");
        printf("1. Start a workout\n");
        printf("2. End a workout\n");
        printf("3. View workout history\n");
        printf("4. Exit\n");
        scanf("%d", &numWorkouts);

        switch (numWorkouts) {
        case 1:
            printf("Enter workout name: ");
            scanf("%s", input);
            strcpy(workouts[numWorkouts].name, input);
            time(&workouts[numWorkouts].startTime);
            break;
        case 2:
            printf("Enter workout name: ");
            scanf("%s", input);
            for (int i = 0; i < numWorkouts; i++) {
                if (strcmp(workouts[i].name, input) == 0) {
                    time(&workouts[i].endTime);
                    workouts[i].duration = difftime(workouts[i].endTime, workouts[i].startTime);
                    break;
                }
            }
            break;
        case 3:
            printf("\nWorkout History:\n");
            for (int i = 0; i < numWorkouts; i++) {
                printf("%s\t%d minutes\t%d calories\n", workouts[i].name, workouts[i].duration / 60, workouts[i].caloriesBurned);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}