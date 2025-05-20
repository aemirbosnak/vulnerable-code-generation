//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[30];
    int age, weight;
    float height;

    printf("Welcome to C Fitness Tracker\n\n");

    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your weight in pounds: ");
    scanf("%d", &weight);

    printf("Please enter your height in inches: ");
    scanf("%f", &height);

    printf("\nThank you, %s, for entering your information.\n", name);

    float bmi = (weight * 703) / (height * height);

    printf("Your BMI is: %.2f\n", bmi);

    if(bmi < 18.5) {
        printf("You are underweight. Please consult with a doctor to develop a plan to safely gain weight.\n");
    } else if(bmi >= 18.5 && bmi < 25) {
        printf("Your weight is within a healthy range.\n");
    } else if(bmi >= 25 && bmi < 30) {
        printf("You are overweight. Please consult with a doctor to develop a plan to safely lose weight.\n");
    } else {
        printf("You are obese. Please consult with a doctor to develop a plan to safely lose weight.\n");
    }

    printf("\nWould you like to track your fitness journey for the next month? [yes/no]\n");

    char response[5];
    fgets(response, sizeof(response), stdin);

    if(strcmp(response, "yes\n") == 0) {

        printf("\nGreat! Let's track your weight and activity for the next month.\n");

        printf("\nPlease enter your weight at the beginning of the month: ");
        scanf("%d", &weight);

        printf("Day 1 - How many minutes did you workout today? ");
        int minutesWorkedOut;
        scanf("%d", &minutesWorkedOut);

        weight -= (minutesWorkedOut / 30);

        printf("\nYour weight after day 1 is %d pounds.\n", weight);

        printf("Day 2 - How many minutes did you workout today? ");
        scanf("%d", &minutesWorkedOut);

        weight -= (minutesWorkedOut / 30);

        printf("\nYour weight after day 2 is %d pounds.\n", weight);

        printf("Day 3 - How many minutes did you workout today? ");
        scanf("%d", &minutesWorkedOut);

        weight -= (minutesWorkedOut / 30);

        printf("\nYour weight after day 3 is %d pounds.\n", weight);

        printf("Day 4 - How many minutes did you workout today? ");
        scanf("%d", &minutesWorkedOut);

        weight -= (minutesWorkedOut / 30);

        printf("\nYour weight after day 4 is %d pounds.\n", weight);

        printf("Day 5 - How many minutes did you workout today? ");
        scanf("%d", &minutesWorkedOut);

        weight -= (minutesWorkedOut / 30);

        printf("\nYour weight after day 5 is %d pounds.\n", weight);

        printf("Day 6 - How many minutes did you workout today? ");
        scanf("%d", &minutesWorkedOut);

        weight -= (minutesWorkedOut / 30);

        printf("\nYour weight after day 6 is %d pounds.\n", weight);

        printf("Day 7 - How many minutes did you workout today? ");
        scanf("%d", &minutesWorkedOut);

        weight -= (minutesWorkedOut / 30);

        printf("\nYour weight after day 7 is %d pounds.\n", weight);

        printf("\nThe first week is over. Please continue to track your fitness journey for the next 3 weeks.\n");
    } else {
        printf("\nThank you for using C Fitness Tracker. We hope to assist you in the future.\n");
    }

    return 0;
}