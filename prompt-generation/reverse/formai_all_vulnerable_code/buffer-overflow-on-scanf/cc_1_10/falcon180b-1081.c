//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_STEPS 10000
#define MAX_DISTANCE 10000

struct exercise {
    char name[50];
    int steps;
    int distance;
};

void add_exercise(struct exercise *exercises, int num_exercises, char name[50], int steps, int distance) {
    int i;
    for (i = 0; i < num_exercises; i++) {
        if (strcmp(exercises[i].name, name) == 0) {
            exercises[i].steps += steps;
            exercises[i].distance += distance;
            return;
        }
    }
    strcpy(exercises[num_exercises].name, name);
    exercises[num_exercises].steps = steps;
    exercises[num_exercises].distance = distance;
    num_exercises++;
}

void print_exercises(struct exercise *exercises, int num_exercises) {
    int i;
    for (i = 0; i < num_exercises; i++) {
        printf("%s: %d steps, %d distance\n", exercises[i].name, exercises[i].steps, exercises[i].distance);
    }
}

int main() {
    int choice, num_exercises = 0;
    char name[50];
    struct exercise exercises[MAX_EXERCISES];

    srand(time(NULL));
    printf("Welcome to the Fitness Tracker 3000!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);

    while (1) {
        printf("\n%s, what would you like to do?\n", name);
        printf("1. Add an exercise\n2. View progress\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the exercise:\n");
                scanf("%s", name);
                printf("Enter the number of steps:\n");
                scanf("%d", &exercises[num_exercises].steps);
                printf("Enter the distance covered in meters:\n");
                scanf("%d", &exercises[num_exercises].distance);
                num_exercises++;
                break;
            case 2:
                printf("\n%s's Progress:\n", name);
                print_exercises(exercises, num_exercises);
                break;
            case 3:
                printf("\n%s, thank you for using the Fitness Tracker 3000! ", name);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}