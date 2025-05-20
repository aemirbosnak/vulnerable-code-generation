//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_TIME 24*60*60
#define MAX_STEPS 100000
#define MAX_CALORIES 5000

struct exercise {
    char name[50];
    time_t start_time;
    time_t end_time;
    int duration;
    int calories;
};

struct day {
    int steps;
    int calories;
    struct exercise exercises[MAX_EXERCISES];
};

int main() {
    struct day today;
    today.steps = 0;
    today.calories = 0;
    int num_exercises = 0;

    while(1) {
        printf("Enter an exercise (or type 'done' to finish): ");
        scanf("%s", today.exercises[num_exercises].name);
        if(strcmp(today.exercises[num_exercises].name, "done") == 0) {
            break;
        }
        num_exercises++;
    }

    for(int i = 0; i < num_exercises; i++) {
        printf("Enter duration (in seconds) for %s: ", today.exercises[i].name);
        scanf("%d", &today.exercises[i].duration);
        today.exercises[i].calories = (int)(today.exercises[i].duration * 5);
        today.calories += today.exercises[i].calories;
    }

    while(1) {
        printf("Enter number of steps taken today: ");
        scanf("%d", &today.steps);
        if(today.steps <= MAX_STEPS) {
            break;
        }
        printf("Invalid input. Please enter a number between 0 and %d.\n", MAX_STEPS);
    }

    today.calories += today.steps * 5;

    printf("Today's fitness summary:\n");
    printf("Steps taken: %d\n", today.steps);
    printf("Calories burned: %d\n", today.calories);

    for(int i = 0; i < num_exercises; i++) {
        printf("Exercise: %s\n", today.exercises[i].name);
        printf("Duration: %d seconds\n", today.exercises[i].duration);
        printf("Calories burned: %d\n\n", today.exercises[i].calories);
    }

    return 0;
}