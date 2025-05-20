//FormAI DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBERS 5 // minimum numbers allowed for exercise
#define MAX_NUMBERS 10 // maximum numbers allowed for exercise

// menu options
enum {
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    QUIT
};

int main() {
    srand(time(NULL)); // seed randomizer with current time

    int option, num1, num2, num3, result; // declare variables

    do {
        // display menu
        printf("\n\n***********************\n");
        printf("*     Math Exercises   *\n");
        printf("***********************\n\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quit\n");
        printf("Enter an option (1-5): ");
        scanf("%d", &option);

        // check for invalid option
        if (option < ADDITION || option > QUIT) {
            printf("\nInvalid option. Please try again.\n");
        } else if (option != QUIT) {
            // generate random numbers
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;
            num3 = rand() % 100 + 1;

            // choose random number of numbers to use
            int num_numbers = rand() % (MAX_NUMBERS - MIN_NUMBERS + 1) + MIN_NUMBERS;

            // declare array to hold random numbers
            int numbers[num_numbers];

            // fill array with random numbers
            for (int i = 0; i < num_numbers; i++) {
                numbers[i] = rand() % 100 + 1;
            }

            // perform calculation based on chosen operation
            switch (option) {
                case ADDITION:
                    // display addition exercise
                    printf("\n");
                    for (int i = 0; i < num_numbers; i++) {
                        printf("%d + ", numbers[i]);
                        result += numbers[i];
                    }
                    printf(" = %d\n", result);
                    break;
                case SUBTRACTION:
                    // display subtraction exercise
                    printf("\n");
                    for (int i = 0; i < num_numbers; i++) {
                        printf("%d - ", numbers[i]);
                        if (i % 2 == 0) {
                            result += numbers[i];
                        } else {
                            result -= numbers[i];
                        }
                    }
                    printf(" = %d\n", result);
                    break;
                case MULTIPLICATION:
                    // display multiplication exercise
                    printf("\n");
                    result = 1;
                    for (int i = 0; i < num_numbers; i++) {
                        printf("%d * ", numbers[i]);
                        result *= numbers[i];
                    }
                    printf(" = %d\n", result);
                    break;
                case DIVISION:
                    // display division exercise
                    printf("\n");
                    result = num1 / num2;
                    printf("%d / %d = %d\n", num1, num2, result);
                    if (num3 != 0) {
                        result /= num3;
                        printf(" / %d = %d\n", num3, result);
                    }
                    break;
            }
        }
    } while (option != QUIT);

    printf("\nThanks for using Math Exercises! Goodbye.\n");

    return 0;
}