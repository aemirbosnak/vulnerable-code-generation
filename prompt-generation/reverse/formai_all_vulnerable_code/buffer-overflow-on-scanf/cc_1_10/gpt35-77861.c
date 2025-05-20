//FormAI DATASET v1.0 Category: Data validation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

bool isNumeric(char input[]) {
    int index = 0;

    // check for negative sign at beginning of input
    if (input[0] == '-') {
        index = 1;
    }

    // check if input is a numeric value
    for (; input[index] != '\0'; index++) {
        if (!isdigit(input[index])) {
            return false;
        }
    }

    return true;
}

int main() {
    char input[MAX_INPUT_SIZE];
    int age;
    float height;
    bool validInput;

    printf("Welcome to the program!\n");

    // get user input for age
    do {
        validInput = true;

        printf("Enter your age: ");
        scanf("%s", input);

        // check if age input is numeric and between 0 and 120
        if (!isNumeric(input) || atoi(input) < 0 || atoi(input) > 120) {
            printf("Invalid input. Please enter a numeric value between 0 and 120.\n");
            validInput = false;
        }
    } while (!validInput);

    age = atoi(input); // convert input string to integer

    // get user input for height
    do {
        validInput = true;

        printf("Enter your height in meters: ");
        scanf("%s", input);

        // check if height input is numeric and greater than 0
        if (!isNumeric(input) || atof(input) <= 0) {
            printf("Invalid input. Please enter a numeric value greater than 0.\n");
            validInput = false;
        }
    } while (!validInput);

    height = atof(input); // convert input string to float

    printf("Thank you for using the program!\n");
    printf("Your age is %d and your height is %.2f meters.\n", age, height);

    return 0;
}