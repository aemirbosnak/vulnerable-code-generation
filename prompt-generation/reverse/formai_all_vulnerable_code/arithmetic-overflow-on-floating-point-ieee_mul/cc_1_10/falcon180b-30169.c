//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct User {
    char name[30];
    int age;
    double weight;
    double height;
    double bmi;
    int steps;
    int calories;
    time_t last_updated;
};

void create_user(struct User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (in kg): ");
    scanf("%lf", &user->weight);
    printf("Enter your height (in cm): ");
    scanf("%lf", &user->height);
    user->bmi = user->weight / (user->height * user->height);
    user->steps = 0;
    user->calories = 0;
    user->last_updated = time(NULL);
}

void update_user(struct User* user) {
    printf("Welcome back, %s!\n", user->name);
    printf("Your BMI is: %.2lf\n", user->bmi);
    printf("You have taken %d steps and burned %d calories.\n", user->steps, user->calories);
    time_t now = time(NULL);
    if (difftime(now, user->last_updated) > 3600) {
        user->steps = 0;
        user->calories = 0;
        user->last_updated = now;
        printf("Your activity data has been reset.\n");
    }
}

void track_steps(struct User* user) {
    int steps;
    double calories;
    printf("Enter the number of steps you took: ");
    scanf("%d", &steps);
    user->steps += steps;
    calories = steps * 0.0175;
    user->calories += calories;
    printf("You have taken %d steps and burned %d calories.\n", user->steps, user->calories);
}

int main() {
    struct User user;
    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Create user\n");
        printf("2. Update user\n");
        printf("3. Track steps\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_user(&user);
                break;
            case 2:
                update_user(&user);
                break;
            case 3:
                track_steps(&user);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}