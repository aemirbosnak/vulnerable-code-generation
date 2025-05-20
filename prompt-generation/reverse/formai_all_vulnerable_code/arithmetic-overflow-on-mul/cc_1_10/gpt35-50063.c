//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char username[20];
    int age;
    float height, weight, bmi, min_bmi = 18.5, max_bmi = 25.0;
    int calories_needed;
    int minutes_exercised = 0, calories_burned;
    int choice;
    time_t now;
    struct tm *local;

    printf("Welcome to the Fitness Tracker\n");
    printf("Please enter your name: ");
    scanf("%s", username);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your height in meters: ");
    scanf("%f", &height);
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    bmi = weight / (height * height);
    printf("\nYour BMI is: %.2f\n", bmi);

    if (bmi < min_bmi) {
        printf("Your BMI is below the healthy range.\n");
        calories_needed = 2500;
    } else if (bmi > max_bmi) {
        printf("Your BMI is above the healthy range.\n");
        calories_needed = 2000;
    } else {
        printf("Your BMI is within the healthy range.\n");
        calories_needed = 2200;
    }

    printf("\nDaily calorie goal: %d\n\n", calories_needed);

    while (1) {
        printf("What would you like to do?\n");
        printf("(1) Record exercise\n");
        printf("(2) See progress\n");
        printf("(3) Quit\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nHow many minutes did you exercise? ");
                scanf("%d", &minutes_exercised);
                calories_burned = 10 * minutes_exercised;
                printf("Calories burned: %d\n\n", calories_burned);

                now = time(NULL);
                local = localtime(&now);
                printf("Recorded at: %s", asctime(local));
                break;
            case 2:
                if (minutes_exercised == 0) {
                    printf("\nNo exercise recorded yet.\n\n");
                } else {
                    printf("\nMinutes exercised: %d\n", minutes_exercised);
                    printf("Calories burned: %d\n", calories_burned);
                    printf("Remaining calories to reach goal: %d\n\n", calories_needed - calories_burned);
                }
                break;
            case 3:
                printf("\nThank you for using the Fitness Tracker. Goodbye, %s!\n", username);
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}