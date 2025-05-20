//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the ultimate rock-paper-scissors game!\n");
    printf("Enter your choice:\n1 for ROCK\n2 for PAPER\n3 for SCISSORS\n");

    int user_choice, computer_choice, result;
    srand(time(NULL));
    computer_choice = rand() % 3 + 1;
    scanf("%d", &user_choice);

    while (user_choice < 1 || user_choice > 3)
    {
        printf("Invalid input! Enter a number between 1 and 3:\n");
        scanf("%d", &user_choice);
    }

    switch (user_choice)
    {
    case 1:
        printf("You chose ROCK!\n");
        break;
    case 2:
        printf("You chose PAPER!\n");
        break;
    case 3:
        printf("You chose SCISSORS!\n");
        break;
    }

    switch (computer_choice)
    {
    case 1:
        printf("The computer chose ROCK!\n");
        break;
    case 2:
        printf("The computer chose PAPER!\n");
        break;
    case 3:
        printf("The computer chose SCISSORS!\n");
        break;
    }

    if (user_choice == computer_choice)
    {
        printf("It's a draw!\n");
        result = 0;
    }
    else if ((user_choice == 1 && computer_choice == 3) || (user_choice == 2 && computer_choice == 1) || (user_choice == 3 && computer_choice == 2))
    {
        printf("YOU WIN!\n");
        result = 1;
    }
    else
    {
        printf("YOU LOSE!\n");
        result = -1;
    }

    printf("Would you like to play again? Enter y for YES or n for NO:\n");
    char play_again;
    scanf("%s", &play_again);

    while (play_again != 'y' && play_again != 'n')
    {
        printf("Invalid input! Enter y for YES or n for NO:\n");
        scanf("%s", &play_again);
    }

    if (play_again == 'y')
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Welcome to the ultimate rock-paper-scissors game!\n");
        printf("Enter your choice:\n1 for ROCK\n2 for PAPER\n3 for SCISSORS\n");
        main(); // Recursive call to play again
    }
    else
    {
        printf("Thanks for playing!\n");
    }

    return 0;
}