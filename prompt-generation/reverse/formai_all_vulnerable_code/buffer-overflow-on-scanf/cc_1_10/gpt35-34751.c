//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int getRandomNumber()
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

// Function to find the absolute difference between two numbers
int getAbsoluteDifference(int number1, int number2)
{
    // If number1 is greater than number2, return number1 - number2
    if (number1 > number2)
        return number1 - number2;

    // If number2 is greater than number1, return number2 - number1
    else if (number2 > number1)
        return number2 - number1;

    // If both numbers are equal, return 0
    else
        return 0;
}

// Main function
int main()
{
    int number1 = getRandomNumber();
    int number2 = getRandomNumber();

    printf("Welcome to the Math Exercise Program!\n");

    printf("\nHere's your exercise:\n");

    printf("\nWhat is the absolute difference between %d and %d?\n", number1, number2);

    int userAnswer;

    printf("\nEnter your answer: ");
    scanf("%d", &userAnswer);

    int correctAnswer = getAbsoluteDifference(number1, number2);

    if (userAnswer == correctAnswer)
    {
        printf("\nCongratulations! Your answer is correct!\n");
    }
    else
    {
        printf("\nSorry, your answer is incorrect.\n");
        printf("The correct answer is: %d\n", correctAnswer);
    }

    printf("\nThank you for using the Math Exercise Program!\n");

    return 0;
}