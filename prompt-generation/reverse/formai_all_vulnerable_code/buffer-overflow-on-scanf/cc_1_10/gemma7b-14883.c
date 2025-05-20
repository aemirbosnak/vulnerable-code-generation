//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, score = 0, lives = 3;
    char name[20];

    printf("Welcome to the 'Mystery Mansion' game, %s!\n", name);
    printf("You have 3 lives and a score of 0.\n");

    while (lives > 0)
    {
        printf("What do you want to do? (1) Search the hallway, (2) Examine the painting, (3) Use your crystal ball\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Search the hallway code
                printf("You searched the hallway and found a hidden key.\n");
                score++;
                break;
            case 2:
                // Examine the painting code
                printf("You examined the painting and discovered a secret message.\n");
                score++;
                break;
            case 3:
                // Use the crystal ball code
                printf("You used your crystal ball and saw a vision of the future.\n");
                score++;
                break;
            default:
                // Invalid input code
                printf("Invalid input. Please try again.\n");
        }

        printf("Your score is now %d.\n", score);

        if (score == 5)
        {
            printf("Congratulations, you have solved the mystery!\n");
            break;
        }
    }

    if (lives == 0)
    {
        printf("Game over. Sorry, %s. You ran out of lives.\n", name);
    }

    return 0;
}