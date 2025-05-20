//FormAI DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int generate_random_number(void);
int calculate_sum(int num1, int num2);
int calculate_difference(int num1, int num2);

int main()
{
    // initialize variables
    int num1, num2, sum, diff, guess;

    printf("Welcome to the math game!\n\n");

    // generate random numbers between 1 and 100
    num1 = generate_random_number();
    num2 = generate_random_number();

    // calculate the sum and difference of the numbers
    sum = calculate_sum(num1, num2);
    diff = calculate_difference(num1, num2);

    // print out the numbers and ask the player to guess the product
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("What is the product of %d and %d?\n", num1, num2);
    scanf("%d", &guess);

    // check if the player's guess was correct
    if (guess == num1 * num2)
    {
        printf("Congratulations! You guessed the correct answer.\n");
    }
    else
    {
        printf("Sorry, the correct answer was %d.\n", num1 * num2);
    }

    return 0;
}

/*
 * Function to generate a random number between 1 and 100
 */
int generate_random_number(void)
{
    srand(time(NULL));  // seed the random number generator
    return (rand() % 100) + 1;  // return a random number between 1 and 100
}

/*
 * Function to calculate the sum of two numbers
 */
int calculate_sum(int num1, int num2)
{
    return num1 + num2;
}

/*
 * Function to calculate the difference between two numbers
 */
int calculate_difference(int num1, int num2)
{
    return abs(num1 - num2);
}