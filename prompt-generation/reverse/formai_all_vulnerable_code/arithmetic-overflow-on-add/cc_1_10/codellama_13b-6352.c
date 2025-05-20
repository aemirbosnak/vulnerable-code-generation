//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
// Ada Lovelace Fitness Tracker

#include <stdio.h>
#include <stdlib.h>

struct exercise {
    char name[32];
    int duration;
    int calories_burned;
};

struct user {
    char name[32];
    int age;
    float weight;
    float height;
    float bmi;
    struct exercise exercises[10];
    int num_exercises;
};

void print_menu() {
    printf("Ada Lovelace Fitness Tracker\n");
    printf("1. Add Exercise\n");
    printf("2. View Exercises\n");
    printf("3. Calculate BMI\n");
    printf("4. Exit\n");
}

void add_exercise(struct user *user) {
    printf("Enter exercise name: ");
    scanf("%s", user->exercises[user->num_exercises].name);
    printf("Enter duration (in minutes): ");
    scanf("%d", &user->exercises[user->num_exercises].duration);
    printf("Enter calories burned: ");
    scanf("%d", &user->exercises[user->num_exercises].calories_burned);
    user->num_exercises++;
}

void view_exercises(struct user *user) {
    for (int i = 0; i < user->num_exercises; i++) {
        printf("Exercise %d: %s\n", i + 1, user->exercises[i].name);
        printf("Duration: %d minutes\n", user->exercises[i].duration);
        printf("Calories burned: %d\n", user->exercises[i].calories_burned);
        printf("\n");
    }
}

void calculate_bmi(struct user *user) {
    float bmi = user->weight / (user->height * user->height);
    printf("BMI: %f\n", bmi);
}

int main() {
    struct user user;
    int choice;

    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &user.weight);
    printf("Enter your height (in meters): ");
    scanf("%f", &user.height);
    user.num_exercises = 0;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_exercise(&user);
                break;
            case 2:
                view_exercises(&user);
                break;
            case 3:
                calculate_bmi(&user);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}