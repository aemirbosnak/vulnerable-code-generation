//LLAMA2-13B DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_VALUE -1000
#define MAX_VALUE 1000

int main() {
    int age, height, weight;
    char name[MAX_LENGTH];
    float average;
    int count = 0;

    // Get the user's name and age
    printf("What is your name? ");
    scanf("%s", name);
    printf("How old are you? ");
    scanf("%d", &age);

    // Calculate the average height and weight
    printf("What is your height? ");
    scanf("%d", &height);
    printf("What is your weight? ");
    scanf("%d", &weight);
    average = (height + weight) / 2;

    // Check if the user's age is within the valid range
    if (age >= MIN_VALUE && age <= MAX_VALUE) {
        // Calculate the BMI and check if it's within the valid range
        float bmi = weight / (height * height);
        if (bmi >= 18.5 && bmi <= 24.9) {
            count++;
            printf("You have a healthy BMI, %s! %d\n", name, count);
        } else if (bmi >= 25 && bmi <= 29.9) {
            count++;
            printf("You have a moderate BMI, %s! %d\n", name, count);
        } else if (bmi >= 30 && bmi <= 39.9) {
            count++;
            printf("You have an obese BMI, %s! %d\n", name, count);
        } else {
            count++;
            printf("You have a severely obese BMI, %s! %d\n", name, count);
        }
    } else {
        printf("Invalid age, %s. Please enter a value between %d and %d.\n", name, MIN_VALUE, MAX_VALUE);
    }

    // Print the final message and exit the program
    printf("You have a healthy BMI, %s! %d\n", name, count);
    return 0;
}