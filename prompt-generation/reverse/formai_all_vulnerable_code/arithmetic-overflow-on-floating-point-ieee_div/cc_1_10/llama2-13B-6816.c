//LLAMA2-13B DATASET v1.0 Category: Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    // Initialize variables
    int age = 25;
    int height = 175;
    float weight = 70.5;
    char gender = 'M';

    // Create a random password
    char password[10];
    for (int i = 0; i < 10; i++) {
        password[i] = 'a' + (rand() % 26);
    }

    // Print a welcome message
    printf("Welcome to the Age, Height, and Weight Calculator!\n");

    // Print the current date and time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    char date[50];
    strftime(date, sizeof(date), "%Y-%m-%d", current_time);
    char time[50];
    strftime(time, sizeof(time), "%H:%M:%S", current_time);
    printf("It is currently %s on %s\n", time, date);

    // Prompt the user for their age, height, and weight
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your height in feet: ");
    scanf("%d", &height);
    printf("Please enter your weight in pounds: ");
    scanf("%.2f", &weight);

    // Calculate the BMI
    float bmi = weight / (height * height);
    bmi = bmi * 703;

    // Print the results
    printf("Your BMI is: %.2f\n", bmi);

    // Print a message based on the user's BMI
    if (bmi < 18.5) {
        printf("You are underweight!");
    } else if (bmi < 25) {
        printf("Your weight is within the normal range.");
    } else if (bmi < 30) {
        printf("You are overweight.");
    } else {
        printf("You are obese.");
    }

    // Print a random joke
    printf("And here's a joke for you: %s\n", password);

    return 0;
}