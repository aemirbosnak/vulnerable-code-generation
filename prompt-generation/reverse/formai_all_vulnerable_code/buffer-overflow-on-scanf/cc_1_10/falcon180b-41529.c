//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct exercise {
    char name[20];
    int duration;
    int calories_burned;
};

void add_exercise(struct exercise *exercise_list, int index, char *name, int duration, int calories_burned) {
    strcpy(exercise_list[index].name, name);
    exercise_list[index].duration = duration;
    exercise_list[index].calories_burned = calories_burned;
}

void display_exercise(struct exercise *exercise_list, int index) {
    printf("Name: %s\n", exercise_list[index].name);
    printf("Duration: %d minutes\n", exercise_list[index].duration);
    printf("Calories burned: %d\n", exercise_list[index].calories_burned);
}

int main() {
    struct exercise exercise_list[MAX_SIZE];
    int num_exercises = 0;

    printf("Welcome to the Fitness Tracker!\n");
    while (num_exercises < MAX_SIZE) {
        printf("Enter the name of an exercise: ");
        char name[20];
        scanf("%s", name);

        printf("Enter the duration of the exercise in minutes: ");
        int duration;
        scanf("%d", &duration);

        printf("Enter the number of calories burned during the exercise: ");
        int calories_burned;
        scanf("%d", &calories_burned);

        add_exercise(exercise_list, num_exercises, name, duration, calories_burned);
        num_exercises++;
    }

    printf("Here are the exercises you entered:\n");
    for (int i = 0; i < num_exercises; i++) {
        display_exercise(exercise_list, i);
    }

    return 0;
}