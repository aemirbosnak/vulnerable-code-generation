//MISTRAL-7B DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100
#define MAX_TRIES 10

void print_menu();
int get_random_number();
int compare_numbers(int player_guess, int secret_number);
void print_hint(int hint);

int main()
{
    int secret_number, player_guess, hint, tries = 0;

    srand(time(NULL));
    secret_number = get_random_number();

    print_menu();

    while (tries < MAX_TRIES)
    {
        scanf("%d", &player_guess);

        tries++;

        hint = compare_numbers(player_guess, secret_number);

        printf("Hint: ");
        print_hint(hint);

        printf("\n");
    }

    printf("Game Over! The number was %d.\n", secret_number);

    return 0;
}

void print_menu()
{
    printf("--------------------------------------------\n");
    printf("| Welcome to the Number Guessing Game!     |\n");
    printf("| You have %d tries to guess a number.     |\n", MAX_TRIES);
    printf("| The number is between 1 and 100.          |\n");
    printf("--------------------------------------------\n");
}

int get_random_number()
{
    return rand() % (MAX_NUMBER + 1) + MIN_NUMBER;
}

int compare_numbers(int player_guess, int secret_number)
{
    if (player_guess < secret_number)
        return 1;

    if (player_guess > secret_number)
        return 2;

    return 0; // The numbers are equal
}

void print_hint(int hint)
{
    switch (hint)
    {
        case 1:
            printf("Too Low\n");
            break;
        case 2:
            printf("Too High\n");
            break;
        default:
            printf("Invalid hint\n");
            break;
    }
}