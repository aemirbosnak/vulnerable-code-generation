//Falcon2-11B DATASET v1.0 Category: Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    ROCK,
    PAPER,
    SCISSORS
} game_type;

void print_instructions();
void print_results(int user_choice, int computer_choice);
game_type random_choice();

int main()
{
    int user_choice;
    game_type computer_choice;
    srand(time(0));

    print_instructions();

    do {
        printf("Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
        scanf("%d", &user_choice);

        computer_choice = random_choice();

        print_results(user_choice, computer_choice);
    } while (user_choice!= 1 && user_choice!= 2 && user_choice!= 3);

    return 0;
}

void print_instructions()
{
    printf("Welcome to Rock, Paper, Scissors! \n");
    printf("Rules: \n");
    printf(" - Rock beats Scissors \n");
    printf(" - Scissors beats Paper \n");
    printf(" - Paper beats Rock \n");
    printf(" - Ties are possible! \n");
    printf("\nPress any key to continue...");
    getchar();
}

void print_results(int user_choice, int computer_choice)
{
    if (user_choice == computer_choice) {
        printf("It's a tie!\n");
    } else if ((user_choice == ROCK && computer_choice == PAPER) || (user_choice == PAPER && computer_choice == SCISSORS) || (user_choice == SCISSORS && computer_choice == ROCK)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

game_type random_choice()
{
    game_type choice;
    srand(time(0));

    switch (rand() % 3) {
        case 0:
            choice = ROCK;
            break;
        case 1:
            choice = PAPER;
            break;
        case 2:
            choice = SCISSORS;
            break;
    }

    return choice;
}