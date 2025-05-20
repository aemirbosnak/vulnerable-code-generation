//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_CALORIES 1000

struct exercise {
    char name[20];
    int calories;
};

struct exercise exercises[MAX_EXERCISES];
int num_exercises = 0;

void add_exercise(const char *name, int calories) {
    if (num_exercises == MAX_EXERCISES) {
        printf("Maximum number of exercises reached.\n");
        return;
    }

    struct exercise new_exercise;
    strcpy(new_exercise.name, name);
    new_exercise.calories = calories;

    printf("Added %s (%d calories)\n", name, calories);
    exercises[num_exercises] = new_exercise;
    num_exercises++;
}

void remove_exercise(int index) {
    if (index < 0 || index >= num_exercises) {
        printf("Invalid exercise index.\n");
        return;
    }

    for (int i = index; i < num_exercises - 1; i++) {
        exercises[i] = exercises[i + 1];
    }
    num_exercises--;
}

void print_exercises() {
    if (num_exercises == 0) {
        printf("No exercises added yet.\n");
        return;
    }

    printf("Exercises:\n");
    for (int i = 0; i < num_exercises; i++) {
        printf(" %s (%d calories)\n", exercises[i].name, exercises[i].calories);
    }
}

int main() {
    srand(time(NULL));

    printf("Fitness Tracker\n");
    printf("1. Add exercise\n");
    printf("2. Remove exercise\n");
    printf("3. Print exercises\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                printf("Enter exercise name: ");
                char name[20];
                scanf("%s", name);
                printf("Enter exercise calories: ");
                int calories;
                scanf("%d", &calories);
                add_exercise(name, calories);
                break;
            case 2:
                printf("Enter exercise index to remove: ");
                int index;
                scanf("%d", &index);
                remove_exercise(index);
                break;
            case 3:
                print_exercises();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}