//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
    int calories;
    time_t last_updated;
} User;

void create_user(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight in kg: ");
    scanf("%f", &user->weight);
    printf("Enter your height in cm: ");
    scanf("%f", &user->height);
    user->bmi = user->weight / (user->height * user->height);
    user->steps = 0;
    user->calories = 0;
    user->last_updated = time(NULL);
}

void update_user(User *user) {
    printf("Enter your steps: ");
    scanf("%d", &user->steps);
    printf("Enter your calories burned: ");
    scanf("%d", &user->calories);
    user->last_updated = time(NULL);
}

void display_user(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f kg\n", user.weight);
    printf("Height: %f cm\n", user.height);
    printf("BMI: %f\n", user.bmi);
    printf("Steps: %d\n", user.steps);
    printf("Calories burned: %d\n", user.calories);
    printf("Last updated: %s", ctime(&user.last_updated));
}

int main() {
    User user;
    create_user(&user);

    int choice;
    while (1) {
        printf("\n1. Update steps and calories\n2. Display user information\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                update_user(&user);
                break;
            case 2:
                display_user(user);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}