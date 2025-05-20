//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct FitnessData {
    char name[20];
    int age;
    double height;
    double weight;
    int steps;
    int caloriesBurned;
    int distanceTraveled;
};

void main() {
    int choice;
    struct FitnessData user;

    do {
        printf("Welcome to the Fitness Tracker!\n");
        printf("Please enter your name: ");
        scanf("%s", user.name);

        printf("Enter your age: ");
        scanf("%d", &user.age);

        printf("Enter your height in cm: ");
        scanf("%lf", &user.height);

        printf("Enter your weight in kg: ");
        scanf("%lf", &user.weight);

        printf("Enter the number of steps taken today: ");
        scanf("%d", &user.steps);

        printf("Enter the number of calories burned today: ");
        scanf("%d", &user.caloriesBurned);

        printf("Enter the distance traveled today in km: ");
        scanf("%d", &user.distanceTraveled);

        printf("What would you like to do?\n1. View your fitness data\n2. Save your fitness data\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Name: %s\nAge: %d\nHeight: %.2lf cm\nWeight: %.2lf kg\nSteps: %d\nCalories Burned: %d\nDistance Traveled: %.2lf km\n", user.name, user.age, user.height, user.weight, user.steps, user.caloriesBurned, user.distanceTraveled);
                break;
            case 2:
                printf("Your fitness data has been saved!\n");
                break;
            case 3:
                printf("Thank you for using the Fitness Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 3);
}