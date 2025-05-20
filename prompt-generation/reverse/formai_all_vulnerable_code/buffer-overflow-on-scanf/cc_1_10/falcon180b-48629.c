//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int (*exercise)(void);
} Exercise;

int pushups(void) {
    printf("Doing pushups...\n");
    return 1;
}

int situps(void) {
    printf("Doing situps...\n");
    return 1;
}

int squats(void) {
    printf("Doing squats...\n");
    return 1;
}

int plank(void) {
    printf("Doing plank...\n");
    return 1;
}

int main(int argc, char *argv[]) {
    Exercise exercises[] = {{"Pushups", pushups}, {"Situps", situps}, {"Squats", squats}, {"Plank", plank}};
    int num_exercises = sizeof(exercises) / sizeof(Exercise);
    int exercise_index;

    srand(time(NULL));

    printf("Welcome to the Claude Shannon Fitness Tracker!\n");
    printf("You have %d exercises to choose from:\n", num_exercises);

    for (int i = 0; i < num_exercises; i++) {
        printf("%d. %s\n", i + 1, exercises[i].name);
    }

    scanf("%d", &exercise_index);

    if (exercise_index >= 1 && exercise_index <= num_exercises) {
        exercises[exercise_index - 1].exercise();
    } else {
        printf("Invalid exercise choice.\n");
    }

    return 0;
}