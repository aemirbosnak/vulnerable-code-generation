//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Set the random seed to ensure "randomness"

    int num1 = rand() % 10 + 1; // Generate a random integer between 1 and 10
    int num2 = rand() % 10 + 1; // Generate another random integer between 1 and 10

    int sum = num1 + num2; // Calculate the sum of the two random numbers
    int difference = abs(num1 - num2); // Calculate the absolute difference of the two random numbers
    int product = num1 * num2; // Calculate the product of the two random numbers
    float quotient = (float)num1 / (float)num2; // Calculate the float division of the two random numbers

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("You will be given two random numbers, and you will have to calculate their sum, difference, product, and quotient.\n");
    printf("Let's get started...\n\n");

    printf("The two random numbers are %d and %d.\n", num1, num2);
    printf("Please calculate the following:\n");
    printf("1. The sum of the two numbers: ");

    int userSum;
    scanf("%d", &userSum);

    if (userSum == sum) {
        printf("Correct!\n");
    } else {
        printf("Sorry, that is incorrect. The correct answer is %d.\n", sum);
    }

    printf("2. The absolute difference of the two numbers: ");

    int userDifference;
    scanf("%d", &userDifference);

    if (userDifference == difference) {
        printf("Correct!\n");
    } else {
        printf("Sorry, that is incorrect. The correct answer is %d.\n", difference);
    }

    printf("3. The product of the two numbers: ");

    int userProduct;
    scanf("%d", &userProduct);

    if (userProduct == product) {
        printf("Correct!\n");
    } else {
        printf("Sorry, that is incorrect. The correct answer is %d.\n", product);
    }

    printf("4. The float division of the two numbers (rounded to two decimal places): ");

    float userQuotient;
    scanf("%f", &userQuotient);

    if (userQuotient - quotient < 0.01 || quotient - userQuotient < 0.01) {
        printf("Correct!\n");
    } else {
        printf("Sorry, that is incorrect. The correct answer is %.2f.\n", quotient);
    }

    printf("\nGreat job! You have completed the Math Exercise Program.\n");

    return 0;
}