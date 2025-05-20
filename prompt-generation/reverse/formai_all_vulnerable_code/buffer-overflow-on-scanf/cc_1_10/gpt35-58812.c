//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declaration
int predictYourFortune();

int main()
{
    // welcome message
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");

    // read player name
    char player[20];
    scanf("%s", player);

    printf("Hello %s! Let's see what the future holds for you...\n", player);

    // initialize random seed
    srand(time(NULL));

    // main game loop
    while (1)
    {
        // get player input
        printf("\nPress 1 to get your fortune, 2 to challenge a friend, or 3 to quit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // predict your fortune
                predictYourFortune();
                break;

            case 2:
                // challenge a friend
                printf("Please enter your friend's name: ");

                // read friend's name
                char friend[20];
                scanf("%s", friend);

                // predict both fortunes
                int playerFortune = predictYourFortune();
                int friendFortune = predictYourFortune();

                // determine winner
                printf("\n%s's fortune: %d\n", player, playerFortune);
                printf("%s's fortune: %d\n", friend, friendFortune);

                if (playerFortune > friendFortune)
                {
                    printf("%s wins!\n", player);
                }
                else if (playerFortune < friendFortune)
                {
                    printf("%s wins!\n", friend);
                }
                else
                {
                    printf("It's a tie!\n");
                }
                break;

            case 3:
                // quit game
                printf("Thanks for playing the Automated Fortune Teller!\n");
                return 0;

            default:
                // invalid input
                printf("Invalid input, please try again.\n");
                break;
        }
    }
}

int predictYourFortune()
{
    // pick a random number between 1 and 10
    int fortune = rand() % 10 + 1;

    // predict the fortune
    switch (fortune)
    {
        case 1:
            printf("Your fortune is: You will have great success in your career.\n");
            break;
        case 2:
            printf("Your fortune is: You will meet the love of your life soon.\n");
            break;
        case 3:
            printf("Your fortune is: You will have a long and healthy life.\n");
            break;
        case 4:
            printf("Your fortune is: You will travel to foreign lands and have amazing experiences.\n");
            break;
        case 5:
            printf("Your fortune is: You will become wealthy beyond your wildest dreams.\n");
            break;
        case 6:
            printf("Your fortune is: You will find true happiness and contentment.\n");
            break;
        case 7:
            printf("Your fortune is: You will have a large and loving family.\n");
            break;
        case 8:
            printf("Your fortune is: You will receive recognition and fame for your achievements.\n");
            break;
        case 9:
            printf("Your fortune is: You will overcome great obstacles and emerge victorious.\n");
            break;
        case 10:
            printf("Your fortune is: You will find peace and serenity in your life.\n");
            break;
    }

    return fortune;
}