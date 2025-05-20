//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int choice;
    int age, weight, height;
    char name[50];
    float bmi;
    time_t now;
    struct tm *t;

    printf("Welcome to the Fitness Tracker!\n");
    printf("What is your name? ");
    scanf("%s", name);

    printf("How old are you? ");
    scanf("%d", &age);

    printf("What is your weight in pounds? ");
    scanf("%d", &weight);

    printf("What is your height in inches? ");
    scanf("%d", &height);

    bmi = (float) weight / (height * height);

    t = localtime(&now);
    printf("Today's date is %s\n", asctime(t));

    printf("\nYour BMI is %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are normal weight.\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    printf("\nWhat would you like to do?\n");
    printf("1. Calculate BMI again\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            main();
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}