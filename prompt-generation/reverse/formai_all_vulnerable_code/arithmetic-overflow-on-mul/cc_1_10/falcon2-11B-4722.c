//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct workout {
    char name[50];
    int duration;
    int calories;
};

int main() {
    struct workout workout;
    struct workout* workouts = malloc(sizeof(struct workout));

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter the name of your workout:\n");
    scanf("%s", workout.name);

    printf("How long did you workout for (in minutes)?\n");
    scanf("%d", &workout.duration);

    int calories = workout.duration * 7; // 7 calories per minute
    workout.calories = calories;

    printf("Congratulations, you burned %d calories!\n", calories);
    printf("Here is a list of your past workouts:\n");

    for(int i = 0; i < 5; i++) {
        workouts[i] = workout;
    }

    for(int i = 0; i < 5; i++) {
        printf("%s: %d minutes - %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }

    printf("Would you like to add another workout? (Y/N)\n");
    char response;
    scanf("%c", &response);

    if(response == 'y' || response == 'Y') {
        printf("Please enter the name of your workout:\n");
        scanf("%s", workout.name);

        printf("How long did you workout for (in minutes)?\n");
        scanf("%d", &workout.duration);

        calories = workout.duration * 7;
        workout.calories = calories;

        printf("Congratulations, you burned %d calories!\n", calories);
        printf("Here is a list of your past workouts:\n");

        for(int i = 0; i < 5; i++) {
            workouts[i] = workout;
        }

        for(int i = 0; i < 5; i++) {
            printf("%s: %d minutes - %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
        }
    }

    free(workouts);
    return 0;
}