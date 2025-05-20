//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define E_OK 0
#define E_FAIL 1
#define E_BAD_INPUT 2
#define E_OUT_OF_MEMORY 3

void handle_error(int error_code) {
    switch (error_code) {
        case E_OK:
            printf("All good! :)\n");
            break;
        case E_FAIL:
            printf("Oops, something went wrong... :(\n");
            break;
        case E_BAD_INPUT:
            printf("Invalid input! :(\n");
            break;
        case E_OUT_OF_MEMORY:
            printf("Out of memory! :O\n");
            break;
        default:
            printf("Unknown error %d :S\n", error_code);
            break;
    }
}

int main() {
    int age;
    float height;
    char name[50];

    // Try to get the user's name
    printf("What's your name? ");
    fgets(name, 50, stdin);
    if (name[0] == '\0') {
        handle_error(E_BAD_INPUT);
        return 1;
    }

    // Try to get the user's age
    printf("How old are you? ");
    scanf("%d", &age);
    if (age < 0 || age > 120) {
        handle_error(E_BAD_INPUT);
        return 1;
    }

    // Try to get the user's height
    printf("How tall are you? ");
    scanf("%f", &height);
    if (height < 0.0f || height > 3.0f) {
        handle_error(E_BAD_INPUT);
        return 1;
    }

    // Do some calculations
    float weight = height * 70;
    float bmi = weight / (height * height);

    // Check if the BMI is valid
    if (bmi < 18.5f || bmi > 30.0f) {
        handle_error(E_BAD_INPUT);
        return 1;
    }

    // Print the results
    printf("Your BMI is %f\n", bmi);

    return 0;
}