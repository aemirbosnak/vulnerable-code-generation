//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

struct user {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
};

void create_user(struct user *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight in kg: ");
    scanf("%f", &user->weight);
    printf("Enter your height in cm: ");
    scanf("%f", &user->height);
    user->bmi = user->weight / (user->height * user->height);
}

void display_user(struct user user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %0.2f kg\n", user.weight);
    printf("Height: %0.2f cm\n", user.height);
    printf("BMI: %0.2f\n", user.bmi);
}

void calculate_calories(struct user user, float distance, float time) {
    float calories = (0.0175 * user.weight) * distance * (time / 60);
    printf("Calories burned: %0.2f\n", calories);
}

int main() {
    struct user user;
    create_user(&user);

    int choice;
    while(1) {
        printf("\nFitness Tracker\n");
        printf("1. Display user information\n");
        printf("2. Calculate calories burned\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_user(user);
                break;
            case 2:
                printf("Enter distance in meters: ");
                float distance;
                scanf("%f", &distance);
                printf("Enter time in minutes: ");
                float time;
                scanf("%f", &time);
                calculate_calories(user, distance, time);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}