//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void play_again(int);

int main()
{
    int choice, score = 0, lives = 3;
    char name[20];

    printf("Welcome to the Quest for the Enchanted Stone!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while (lives > 0)
    {
        printf("You are in a mysterious forest. You hear rustling in the bushes. Do you want to (1) attack, (2) defend, or (3) flee? ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                score++;
                printf("You attacked the rustling bush and it was defeated.\n");
                break;
            case 2:
                printf("You defended against the attack, but the enemy still managed to damage you.\n");
                lives--;
                break;
            case 3:
                printf("You fled into the forest.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    if (lives == 0)
    {
        printf("Game Over. Your score is: %d", score);
    }
    else
    {
        printf("Congratulations! You have won the Quest for the Enchanted Stone. Your score is: %d", score);
    }

    play_again(score);

    return 0;
}

void play_again(int score)
{
    char answer;

    printf("Do you want to play again? (Y/N) ");
    scanf("%c", &answer);

    if (answer == 'Y')
    {
        main();
    }
}