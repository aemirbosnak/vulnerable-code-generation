//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct user {
    char name[50];
    int age;
    int weight;
    int height;
};

struct exercise {
    char name[50];
    int duration;
    int calories;
};

void create_user(struct user *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (in kg): ");
    scanf("%d", &user->weight);
    printf("Enter your height (in cm): ");
    scanf("%d", &user->height);
}

void create_exercise(struct exercise *exercise) {
    printf("Enter the name of the exercise: ");
    scanf("%s", exercise->name);
    printf("Enter the duration of the exercise (in seconds): ");
    scanf("%d", &exercise->duration);
    printf("Enter the number of calories burned during the exercise: ");
    scanf("%d", &exercise->calories);
}

int main() {
    int choice;
    struct user user;
    struct exercise exercise;

    srand(time(0));

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please choose an option:\n");
    printf("1. Create user\n2. Create exercise\n3. Track workout\n4. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            create_user(&user);
            printf("User created successfully!\n");
            break;
        case 2:
            create_exercise(&exercise);
            printf("Exercise created successfully!\n");
            break;
        case 3:
            printf("Please enter the name of the exercise you want to track: ");
            char exercise_name[50];
            scanf("%s", exercise_name);

            if(strcmp(exercise_name, "Running") == 0) {
                int duration = rand() % 601 + 1; // random duration between 1 and 600 seconds
                int calories = (user.weight * 0.1) * duration; // calculate calories burned based on weight and duration
                printf("You burned %d calories while running for %d seconds!\n", calories, duration);
            } else if(strcmp(exercise_name, "Cycling") == 0) {
                int duration = rand() % 301 + 1; // random duration between 1 and 300 seconds
                int calories = (user.weight * 0.15) * duration; // calculate calories burned based on weight and duration
                printf("You burned %d calories while cycling for %d seconds!\n", calories, duration);
            } else {
                printf("Exercise not found.\n");
            }
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}