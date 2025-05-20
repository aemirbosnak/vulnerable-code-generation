//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, score = 0, lives = 3;
    char name[20];

    printf("Welcome to the Amazing Quest of Captain Squibbles!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Greetings, %s! You have a score of %d and %d lives.\n", name, score, lives);

    while (lives > 0)
    {
        printf("What do you want to do? (1) Attack, (2) Defend, (3) Eat a banana, (4) Consult a wizard:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You attacked the evil villain! He is now a smoldering pile of ash.\n");
                score++;
                break;
            case 2:
                printf("You defended against the villain's attack. He is confused and bewildered.\n");
                break;
            case 3:
                printf("You ate a banana and gained a point. You now have a score of %d.\n", score);
                score++;
                break;
            case 4:
                printf("You consulted a wizard who gave you a riddle. The answer to the riddle is: What has a neck but no head?\n");
                printf("The answer is a bottle. You are now cleverer than the villain.\n");
                score++;
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        printf("Your score is now %d and you have %d lives remaining.\n", score, lives);

        if (score >= 5)
        {
            printf("Congratulations, %s! You have won the Amazing Quest of Captain Squibbles!\n", name);
            lives = 0;
        }
    }

    if (lives == 0)
    {
        printf("Sorry, %s. You have lost the Amazing Quest of Captain Squibbles.\n", name);
    }

    return 0;
}