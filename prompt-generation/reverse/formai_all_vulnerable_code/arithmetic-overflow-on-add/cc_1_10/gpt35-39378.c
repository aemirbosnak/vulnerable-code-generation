//FormAI DATASET v1.0 Category: Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Declare the functions */
void greet();
void menu();
int generateRandomNumber(int min, int max);
void startGame();
void playGame(int guess, int answer);
void gameOver(int answer);

/* Main Function */
int main()
{
    greet();
    menu();
    return 0;
}

/* Greeting Function */
void greet()
{
    printf("Welcome, detective.\n");
    printf("You are about to embark on a dangerous case.\n");
    printf("You have been tasked with solving the mystery of the lost diamond.\n");
    printf("To begin, choose an option from the menu.\n\n");
}

/* Menu Function */
void menu()
{
    int choice;
    
    printf("1. Start Game\n");
    printf("2. Exit Game\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            startGame();
            break;
        case 2:
            printf("Goodbye, detective.\n");
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            menu();
            break;
    }
}

/* Start Game Function */
void startGame()
{
    int min, max, range;
    
    printf("First, we need to set the range for the random number.\n");
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);
    
    range = max - min;
    
    if(range < 10)
    {
        printf("The range is too small. Please choose a larger range.\n");
        startGame();
    }
    else
    {
        int answer = generateRandomNumber(min, max);
        playGame(1, answer);
    }
}

/* Generate Random Number Function */
int generateRandomNumber(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

/* Play Game Function */
void playGame(int guess, int answer)
{
    int new_guess = guess;
    int num_guesses = 0;
    
    while(new_guess != answer)
    {
        printf("You are in the middle of the investigation, detective.\n");
        printf("You must guess the number between 1 and 100.\n");
        printf("You have %d guesses left.\n", (10 - num_guesses));
        printf("Enter your guess: ");
        scanf("%d", &new_guess);
        
        if(new_guess == answer)
        {
            printf("Congratulations, detective.\n");
            printf("You have discovered the lost diamond and solved the case.\n");
            printf("You are a true mastermind.\n");
            menu();
        }
        else if(num_guesses == 9)
        {
            gameOver(answer);
        }
        else if(new_guess < answer)
        {
            printf("The number is higher than your guess.\n");
            num_guesses++;
        }
        else
        {
            printf("The number is lower than your guess.\n");
            num_guesses++;
        }
    }
}

/* Game Over Function */
void gameOver(int answer)
{
    char choice[2];
    
    printf("Game Over, detective.\n");
    printf("You failed to solve the mystery of the lost diamond.\n");
    printf("The answer was %d.\n", answer);
    printf("Do you want to play again? (Y/N): ");
    scanf("%s", choice);
    
    if(strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
    {
        menu();
    }
    else
    {
        printf("Goodbye, detective.\n");
        exit(0);
    }
}