//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void inv_game()
{
    int choice, health = 100, score = 0;
    char name[20];

    printf("Welcome to the Invasive Game, %s!\n", name);

    while (health > 0)
    {
        printf("You are in a dark room. You hear a noise. What do you do? (1) Attack, (2) Search, (3) Retreat\n");
        scanf(" %d ", &choice);

        switch (choice)
        {
            case 1:
                printf("You attacked the unknown object. It fought back, but you managed to defeat it.\n");
                score++;
                break;
            case 2:
                printf("You searched the room. You found a key and a weapon.\n");
                score++;
                break;
            case 3:
                printf("You retreated. You left the room and are safe.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        if (choice == 1)
        {
            health -= 20;
        }
        else if (choice == 2)
        {
            health -= 10;
        }

        printf("Your health is %d. Your score is %d.\n", health, score);
    }

    printf("Game over. Your final score is %d.\n", score);
}

int main()
{
    inv_game();

    return 0;
}