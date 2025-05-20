//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Global variables
int fortuneTeller;
int choice;
char response;

// Function prototypes
void startGame();
void askQuestion();
void printFortune();

int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Start the game
    startGame();

    // Loop until the user quits
    while (choice!= 'q')
    {
        // Ask a question
        askQuestion();

        // Get user response
        scanf(" %c", &response);

        // Print the fortune
        printFortune();
    }

    // Exit the program
    return 0;
}

// Function to start the game
void startGame()
{
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("To start the game, type'start'\n");
    printf("To exit the game, type 'q'\n");

    // Get user input
    scanf(" %c", &choice);

    // Start the game if user input is'start'
    if (choice =='s')
    {
        fortuneTeller = rand() % 5 + 1; // Randomly generate a fortune number between 1 and 5
        printf("Your fortune number is: %d\n", fortuneTeller);
    }

    // Exit the game if user input is 'q'
    else if (choice == 'q')
    {
        printf("Thank you for playing the Automated Fortune Teller!\n");
        return;
    }

    // Ask user to try again if user input is invalid
    else
    {
        printf("Invalid input. Please try again.\n");
    }
}

// Function to ask a question
void askQuestion()
{
    printf("What is your question?\n");

    // Get user input
    scanf(" %c", &response);

    // Print the question
    printf("You asked: %c\n", response);
}

// Function to print the fortune
void printFortune()
{
    switch (fortuneTeller)
    {
        case 1:
            printf("Your fortune is: You will find love.\n");
            break;

        case 2:
            printf("Your fortune is: You will be successful.\n");
            break;

        case 3:
            printf("Your fortune is: You will have good luck.\n");
            break;

        case 4:
            printf("Your fortune is: You will have good health.\n");
            break;

        case 5:
            printf("Your fortune is: You will have a long life.\n");
            break;

        default:
            printf("Your fortune is: You will have a happy life.\n");
    }
}