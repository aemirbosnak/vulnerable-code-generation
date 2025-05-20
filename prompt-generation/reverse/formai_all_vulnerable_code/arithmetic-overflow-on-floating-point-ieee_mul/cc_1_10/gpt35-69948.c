//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
// Romeo and Juliet: A Fitness Tracker Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to display today's workout plan
void displayWorkoutPlan(char day[]) {
    if (strcmp(day, "Monday") == 0) {
        printf("Today's workout: Chest and Triceps\n");
    } else if (strcmp(day, "Tuesday") == 0) {
        printf("Today's workout: Back and Biceps\n");
    } else if (strcmp(day, "Wednesday") == 0) {
        printf("Today's workout: Legs\n");
    } else if (strcmp(day, "Thursday") == 0) {
        printf("Today's workout: Shoulders and Abs\n");
    } else if (strcmp(day, "Friday") == 0) {
        printf("Today's workout: Arms\n");
    } else {
        printf("Sorry, invalid input.\n");
    }
}

// Function to calculate body mass index
float calculateBMI(float height, float weight) {
    float bmi = weight / (height * height);
    return bmi;
}

int main() {
    char name[20];
    float weight;
    float height;
    char day[10];
    char input;

    printf("Oh my life is my foe’s debt!\n"); 
    printf("What is thy name? "); 
    scanf("%s", name);

    printf("What is thy weight in pounds, %s? ", name); 
    scanf("%f", &weight);

    printf("What is thy height in inches, %s? ", name); 
    scanf("%f", &height);

    printf("What day of the week is it, %s? ", name); 
    scanf("%s", day);

    displayWorkoutPlan(day);

    float bmi = calculateBMI(height/39.37, weight/2.205);
    printf("Thy body mass index is %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("Thou art underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25.0) {
        printf("Thou art at a healthy weight.\n");
    } else if (bmi >= 25.0 && bmi < 30.0) {
        printf("Thou art overweight.\n");
    } else {
        printf("Thou art obese.\n");
    }

    printf("Would thou like to track thy daily steps taken, y or n? "); 
    scanf(" %c", &input);

    if (tolower(input) == 'y') {
        int steps;
        printf("How many steps have thou taken today? "); 
        scanf("%d", &steps);
        printf("Thou hast taken %d steps today. Excellent!\n", steps);
    } else if (tolower(input) == 'n') {
        printf("As thou wish, farewell!\n");
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}