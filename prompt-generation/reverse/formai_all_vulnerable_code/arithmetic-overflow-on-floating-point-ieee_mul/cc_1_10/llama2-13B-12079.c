//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAX_NUMBER 1000000

int main() {
    char name[MAX_LENGTH];
    int age;
    double height;
    double weight;
    double iq;

    printf("Welcome to the Satisfied Soulmate Finder!\n");

    // Ask for the user's name
    printf("What is your name? ");
    fgets(name, MAX_LENGTH, stdin);

    // Ask for the user's age
    printf("How old are you? ");
    scanf("%d", &age);

    // Ask for the user's height
    printf("How tall are you? ");
    scanf("%lf", &height);

    // Ask for the user's weight
    printf("How heavy are you? ");
    scanf("%lf", &weight);

    // Ask for the user's IQ
    printf("What is your IQ? ");
    scanf("%lf", &iq);

    // Calculate the user's BMI
    double bmi = weight / (height * height);

    // Calculate the user's desirability score
    double desirability = iq * 0.3 + bmi * 0.5 + age * 0.2;

    // Output the user's results
    printf("You are a %s level satisfier! Your desirability score is %lf.\n",
           desirability < 0.5 ? "low" : desirability < 0.75 ? "medium" : "high", desirability);

    return 0;
}