//FormAI DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generateRandomNumber()
{
    srand(time(NULL)); // Setting seed for rand() function
    return rand() % 100 + 1; // Generating random number between 1 and 100
}

// Function to check if user input is valid and return the integer value
int getValidUserInput(char* message)
{
    int input;
    do {
        printf("%s: ", message);
        scanf("%d", &input);
        if (input < 1 || input > 100)
        {
            printf("Invalid input! Enter a number between 1 and 100.\n");
        }
    } while (input < 1 || input > 100);
    return input;
}

// Function to check if user wins or loses and return the result
int checkResult(int randomNumber, int guess)
{
    if (guess == randomNumber)
    {
        printf("Congratulations! You have guessed the correct number.\n");
        return 1;
    }
    else if (guess < randomNumber)
    {
        printf("Your guess is lower than the random number. Try again.\n");
        return 0;
    }
    else
    {
        printf("Your guess is higher than the random number. Try again.\n");
        return 0;
    }
}

// Main function to play the game
int main()
{
    int randomNumber = generateRandomNumber(); // Generating a random number between 1 and 100
    int guess, attempts = 0; // Initializing guess and attempts variables
    
    printf("Welcome to the Guessing Game!\n");
    
    do {
        guess = getValidUserInput("Enter your guess"); // Getting user input for guess
        attempts++; // Increasing attempts count
    } while (!checkResult(randomNumber, guess)); // Loop until user wins
    
    printf("You took %d attempts to guess the number %d.\n", attempts, randomNumber); // Printing total attempts
    
    return 0;
}