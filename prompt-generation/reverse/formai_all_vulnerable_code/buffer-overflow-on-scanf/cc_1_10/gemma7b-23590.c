//Gemma-7B DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, score = 0, lives = 3, game_over = 0;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome to the Adventure Game, %s! You have %d lives and a score of %d.\n", name, lives, score);

    while (!game_over)
    {
        printf("What do you want to do? (1) Attack, (2) Defend, (3) Use Item\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                score++;
                lives--;
                printf("You attacked the enemy and gained %d points. You have %d lives left.\n", score, lives);
                break;
            case 2:
                lives++;
                printf("You defended against the enemy and gained a life. You have %d lives left.\n", lives);
                break;
            case 3:
                if (score > 0)
                {
                    score -= 5;
                    printf("You used an item and lost %d points. Your score is now %d.\n", score, score);
                }
                else
                {
                    printf("You have no items to use.\n");
                }
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        if (lives == 0)
        {
            game_over = 1;
            printf("Game Over! You lose. Your score is %d.\n", score);
        }
    }

    return 0;
}