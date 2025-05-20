//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, score = 0, lives = 3;
    char name[20];

    printf("Welcome to the wacky world of Squiggly Bob!\n");
    printf("Please tell me your name: ");
    scanf("%s", name);

    while (lives > 0)
    {
        printf("You are in the wacky kitchen of Squiggly Bob.\n");
        printf("What would you like to do? (1) Eat a banana, (2) Dance with a goat, (3) Play the electric guitar:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You ate a banana and gained 5 points!\n");
                score += 5;
                break;
            case 2:
                printf("You danced with a goat and lost 2 points.\n");
                score -= 2;
                break;
            case 3:
                printf("You played the electric guitar and gained 10 points!\n");
                score += 10;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        if (score >= 100)
        {
            printf("Congratulations, %s! You won the game!\n", name);
            break;
        }
        else if (score < 0)
        {
            printf("Oh no, %s, you lost the game! Better luck next time.\n", name);
            lives--;
        }
    }

    return 0;
}