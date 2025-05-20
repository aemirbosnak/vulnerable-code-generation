//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    // Welcome to the Energetic Arithmetic Program
    printf("\nWelcome to the Energetic Arithmetic Program!\n");

    // Get the user's name
    printf("What's your name?\n");
    char name[20];
    scanf("%s", name);

    // Greet the user
    printf("Hi %s! Let's do some math!\n", name);

    // Seed the random number generator
    srand(time(NULL));

    // Generate two random numbers between 1 and 100
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    // Let the user know what the numbers are
    printf("Your first number is %d and your second number is %d\n", num1, num2);

    // Add the two numbers
    int sum = num1 + num2;
    printf("The sum of your numbers is %d\n", sum);

    // Subtract the second number from the first number
    int difference = num1 - num2;
    printf("If you subtract %d from %d, you get %d\n", num2, num1, difference);

    // Multiply the two numbers
    int product = num1 * num2;
    printf("The product of your numbers is %d\n", product);

    // Divide the first number by the second number
    float quotient = (float)num1 / (float)num2;
    printf("When you divide %d by %d, you get %.2f\n", num1, num2, quotient);

    // Take the square root of the first number
    float sq_root = sqrt(num1);
    printf("The square root of %d is %.2f\n", num1, sq_root);

    // Round the quotient to the nearest integer
    int rounded = round(quotient);
    printf("Rounding %.2f to the nearest integer gives you %d\n", quotient, rounded);

    // Goodbye message
    printf("\nThanks for using the Energetic Arithmetic Program, %s! Have a great day!\n", name);

    return 0;
}