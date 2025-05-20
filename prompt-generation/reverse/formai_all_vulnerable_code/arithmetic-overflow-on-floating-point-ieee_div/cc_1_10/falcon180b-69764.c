//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char name[20];
    int age;
    double weight, height, bmi;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);

    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Calculate BMI\n");
        printf("2. Set fitness goals\n");
        printf("3. Track progress\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Please enter your weight in kg: ");
                scanf("%lf", &weight);
                printf("Please enter your height in cm: ");
                scanf("%lf", &height);
                bmi = weight / (height * height);
                printf("Your BMI is: %.2lf\n", bmi);
                break;

            case 2:
                printf("Please enter your fitness goal: ");
                scanf("%s", name);
                printf("Your fitness goal has been set to %s.\n", name);
                break;

            case 3:
                printf("Please enter your weight in kg: ");
                scanf("%lf", &weight);
                printf("Please enter your height in cm: ");
                scanf("%lf", &height);
                bmi = weight / (height * height);
                printf("Your BMI is: %.2lf\n", bmi);
                break;

            case 4:
                printf("Thank you for using the Fitness Tracker! Goodbye, %s!\n", name);
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}