//FormAI DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player_score = 0;
int computer_score = 0;

char get_player_choice();
int get_computer_choice();
void display_choice(char c, int i);
void update_scores(char player_choice, int computer_choice);
void display_scores();

int main()
{
    srand(time(NULL)); // initialize random seed

    while (1)
    {
        char player_choice = get_player_choice();
        int computer_choice = get_computer_choice();

        display_choice(player_choice, computer_choice);
        update_scores(player_choice, computer_choice);
        display_scores();

        if (player_score >= 5 || computer_score >= 5)
        {
            break;
        }
    }

    if (player_score > computer_score)
    {
        printf("You win!\n");
    }
    else
    {
        printf("Computer wins!\n");
    }

    return 0;
}

char get_player_choice()
{
    char player_choice;

    while (1)
    {
        printf("Enter 'r' for rock, 'p' for paper, or 's' for scissors: ");
        scanf(" %c", &player_choice);

        if (player_choice == 'r' || player_choice == 'p' || player_choice == 's')
        {
            break;
        }

        printf("Invalid choice. Try again.\n");
    }

    return player_choice;
}

int get_computer_choice()
{
    int computer_choice = rand() % 3;

    return computer_choice;
}

void display_choice(char player_choice, int computer_choice)
{
    printf("You chose ");

    switch (player_choice)
    {
        case 'r':
            printf("rock");
            break;
        case 'p':
            printf("paper");
            break;
        case 's':
            printf("scissors");
            break;
        default:
            break;
    }

    printf(". Computer chose ");

    switch (computer_choice)
    {
        case 0:
            printf("rock");
            break;
        case 1:
            printf("paper");
            break;
        case 2:
            printf("scissors");
            break;
        default:
            break;
    }

    printf(".\n");
}

void update_scores(char player_choice, int computer_choice)
{
    if ((player_choice == 'r' && computer_choice == 2) ||
        (player_choice == 'p' && computer_choice == 0) ||
        (player_choice == 's' && computer_choice == 1))
    {
        player_score++;
        printf("You win this round!\n");
    }
    else if ((computer_choice == 0 && player_choice == 's') ||
             (computer_choice == 1 && player_choice == 'r') ||
             (computer_choice == 2 && player_choice == 'p'))
    {
        computer_score++;
        printf("Computer wins this round!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

void display_scores()
{
    printf("Your score: %d\n", player_score);
    printf("Computer's score: %d\n", computer_score);
}