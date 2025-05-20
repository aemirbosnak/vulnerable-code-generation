//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

void generate_number(int *number);
void print_number(int number);
int compare_numbers(int player_number, int computer_number);
void print_result(int player_number, int computer_number, int result);

int main()
{
    int player_number, computer_number;
    int tries = 0;

    srand(time(NULL));
    generate_number(&computer_number);

    while (tries < MAX_TRIES)
    {
        printf("\nPlayer, enter your guess: ");
        scanf("%d", &player_number);

        tries++;

        int result = compare_numbers(player_number, computer_number);
        print_result(player_number, computer_number, result);
    }

    printf("\nGame Over! Computer wins this time.\n");
    return 0;
}

void generate_number(int *number)
{
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void print_number(int number)
{
    printf("Number: %d\n", number);
}

int compare_numbers(int player_number, int computer_number)
{
    if (player_number > computer_number)
    {
        printf("Lower!\n");
        return -1;
    }
    else if (player_number < computer_number)
    {
        printf("Higher!\n");
        return 1;
    }
    else
    {
        printf("Congratulations! You've guessed the number.\n");
        return 0;
    }
}

void print_result(int player_number, int computer_number, int result)
{
    if (result == -1)
    {
        print_number(computer_number);
        printf(" is the correct number. Try again.\n");
    }
    else if (result == 1)
    {
        printf("Your number, %d, is incorrect. Computer's number: %d\n", player_number, computer_number);
    }
    else
    {
        printf("Congratulations! You've guessed the number, %d, correctly.\n", computer_number);
    }
}