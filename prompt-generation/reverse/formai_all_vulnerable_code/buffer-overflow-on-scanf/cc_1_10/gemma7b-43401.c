//Gemma-7B DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice, score = 0, lives = 5;
    char name[20];

    printf("Welcome to the Adventure Game, %s!\n", name);

    while (lives > 0)
    {
        printf("Please choose an option:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Use Item\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                score += 5;
                printf("You attacked the enemy and gained 5 points!\n");
                break;
            case 2:
                score += 2;
                printf("You defended against the enemy and gained 2 points!\n");
                break;
            case 3:
                if (score >= 10)
                {
                    score -= 10;
                    printf("You used an item and gained 10 points!\n");
                }
                else
                {
                    printf("You do not have enough items.\n");
                }
                break;
            default:
                printf("Invalid input.\n");
        }

        if (score >= 100)
        {
            printf("Congratulations, %s! You won the game!\n", name);
            break;
        }
        else if (score < 0)
        {
            printf("Game over, %s. You lost.\n", name);
            lives--;
        }
    }

    return 0;
}