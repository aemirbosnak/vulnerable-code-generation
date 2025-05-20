//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct User {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
};

void calculateBMI(float weight, float height, float *bmi) {
    *bmi = weight / (height * height);
}

int main() {
    int choice;
    struct User user;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", user.name);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &user.weight);
    printf("Please enter your height in meters: ");
    scanf("%f", &user.height);

    calculateBMI(user.weight, user.height, &user.bmi);

    printf("\nName: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f kg\n", user.weight);
    printf("Height: %f m\n", user.height);
    printf("BMI: %.2f\n\n", user.bmi);

    do {
        printf("1. Log a workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the type of workout (e.g. running, cycling): ");
                scanf("%s", user.name);
                printf("Enter the duration of the workout in minutes: ");
                scanf("%d", &user.age);
                printf("Workout logged!\n\n");
                break;
            case 2:
                printf("Workout history:\n");
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}