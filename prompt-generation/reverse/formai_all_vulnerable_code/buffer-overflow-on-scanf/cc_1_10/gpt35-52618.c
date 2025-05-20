//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void print_banner();
int generate_number(int lower, int upper);
void play_game(int number);

int main()
{
    int choice;
    int lower = 1, upper = 20;

    do
    {
        print_banner();
        printf("Enter your choice:\n");
        printf("1. Play the game\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                play_game(generate_number(lower, upper));
                break;
            case 2:
                printf("Thank you for playing the game!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

//function to print game banner
void print_banner()
{
    system("clear"); //clear the terminal
    printf("**************************************\n");
    printf("**** Welcome to Guess the Number ****\n");
    printf("**************************************\n\n");
}

//function to generate a random number within a range
int generate_number(int lower, int upper)
{
    srand(time(NULL)); //seed the random number generator with the current time
    return (rand() % (upper - lower + 1)) + lower;
}

//function to play the game
void play_game(int number)
{
    int guess;
    int count = 0;

    printf("I am thinking of a number between 1 and 20.\n");
    printf("You have 5 chances to guess the number.\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;

        if (guess > number)
        {
            printf("Your guess is too high.\n");
        }
        else if (guess < number)
        {
            printf("Your guess is too low.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d attempts.\n\n", count);
            return;
        }

    } while (count < 5);

    printf("Sorry! The number was %d.\n\n", number);
}