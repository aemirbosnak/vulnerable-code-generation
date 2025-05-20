//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 10000
#define MAX_CALORIES 5000
#define MAX_DISTANCE 10.0
#define MAX_HEARTRATE 200

struct Workout {
    char type[50];
    int duration;
    int steps;
    int calories;
    double distance;
    int heartrate;
    time_t start_time;
    time_t end_time;
};

void addWorkout(struct Workout workouts[], int num_workouts) {
    printf("Enter workout type (running, walking, cycling, swimming, etc.): ");
    scanf("%s", workouts[num_workouts].type);

    printf("Enter workout duration in seconds: ");
    scanf("%d", &workouts[num_workouts].duration);

    printf("Enter number of steps: ");
    scanf("%d", &workouts[num_workouts].steps);

    printf("Enter number of calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);

    printf("Enter distance covered in meters: ");
    scanf("%lf", &workouts[num_workouts].distance);

    printf("Enter average heart rate: ");
    scanf("%d", &workouts[num_workouts].heartrate);

    time(&workouts[num_workouts].start_time);
}

void displayWorkouts(struct Workout workouts[], int num_workouts) {
    printf("Workout Summary:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("Workout %d:\n", i+1);
        printf("Type: %s\n", workouts[i].type);
        printf("Duration: %d seconds\n", workouts[i].duration);
        printf("Steps: %d\n", workouts[i].steps);
        printf("Calories burned: %d\n", workouts[i].calories);
        printf("Distance covered: %.2lf meters\n", workouts[i].distance);
        printf("Average heart rate: %d beats per minute\n", workouts[i].heartrate);
        printf("Start time: %s\n", ctime(&workouts[i].start_time));
        printf("End time: %s\n\n", ctime(&workouts[i].end_time));
    }
}

int main() {
    struct Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    while (num_workouts < MAX_WORKOUTS) {
        addWorkout(workouts, num_workouts);
        num_workouts++;
    }

    return 0;
}