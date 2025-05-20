//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototypes
void showMenu();
int calculateRandomNumber();
void guessNumber(int randomNumber);

int main()
{
    showMenu();

    return 0;
}

//Displays the main menu options
void showMenu()
{
    int option;

    printf("---Guess the Number Game---\n");
    printf("\n1. Start Game");
    printf("\n2. Exit Game");
    printf("\nEnter Option: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            guessNumber(calculateRandomNumber());
            break;
        case 2:
            printf("\nThank you for playing!");
            break;
        default:
            printf("\nInvalid option. Please select again.");
            showMenu();
            break;
    }
}

//Generates a random number between 1 and 100
int calculateRandomNumber()
{
    srand(time(NULL));

    return (rand() % 100) + 1;
}

//Prompts the user to guess the number and provides feedback after each attempt
void guessNumber(int randomNumber)
{
    int guess, attempts=1;

    printf("\nGuess a number between 1 and 100: ");
    scanf("%d", &guess);

    while(guess != randomNumber)
    {
        if(guess < randomNumber)
        {
            printf("\nToo low. Guess again: ");
            scanf("%d", &guess);
            attempts++;
        }
        else
        {
            printf("\nToo high. Guess again: ");
            scanf("%d", &guess);
            attempts++;
        }
    }

    printf("\nCongrats! You guessed the number %d in %d attempts.", randomNumber, attempts);

    showMenu();
}