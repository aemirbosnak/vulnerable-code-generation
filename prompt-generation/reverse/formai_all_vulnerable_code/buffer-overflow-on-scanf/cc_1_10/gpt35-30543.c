//FormAI DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, result, answer;
    float square_root, power_value, absolute_value;
    char operator;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the math exercise program!\n\n");

    // Loop through 10 math problems
    for (int i = 0; i < 10; i++) {
        // Generate two random integers
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        // Generate a random operator
        switch (rand() % 4) {
            case 0:
                operator = '+';
                result = num1 + num2;
                break;

            case 1:
                operator = '-';
                result = num1 - num2;
                break;

            case 2:
                operator = '*';
                result = num1 * num2;
                break;

            case 3:
                operator = '/';
                // Make sure the result is a whole number
                num1 *= num2;
                result = num1 / num2;
                break;
        }

        // Print the math problem and ask for an answer
        printf("Problem %d: %d %c %d = ", i+1, num1, operator, num2);
        scanf("%d", &answer);

        // Check the answer and provide feedback
        if (answer == result) {
            printf("Correct! Great job!\n\n");
        } else {
            printf("Incorrect. The correct answer is %d. Keep practicing!\n\n", result);
        }
    }

    // Extra credit: ask for a number and perform various math operations on it
    printf("Now, let's do some advanced calculations.\n");
    printf("Enter a number: ");
    scanf("%f", &square_root);

    // Perform square root calculation
    printf("The square root of %f is %f\n", square_root, sqrt(square_root));

    // Perform power calculation
    printf("Enter a power value: ");
    scanf("%f", &power_value);
    printf("%f raised to the power of %f is %f\n", square_root, power_value, pow(square_root, power_value));

    // Perform absolute value calculation
    absolute_value = fabs(square_root);
    printf("The absolute value of %f is %f\n", square_root, absolute_value);

    printf("Thanks for using the math exercise program. Goodbye!\n");

    return 0;
}