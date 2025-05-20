//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed random number generator

    int ship_health = 100;
    int enemy_health = 100;

    printf("Welcome to the Procedural Space Adventure!\n");

    printf("You are the captain of the starship, Romeo and Juliet. Your mission is to defeat the enemy ship, named Capulet, and save the galaxy!\n");

    printf("Let's begin...\n\n");

    while(ship_health > 0 && enemy_health > 0)
    {
        int player_attack = rand() % 10 + 1;
        int enemy_attack = rand() % 10 + 1;

        printf("\nYour ship health: %d\n", ship_health);
        printf("Enemy ship health: %d\n\n", enemy_health);

        printf("Choose your attack...\n");
        printf("1. Phasers\n");
        printf("2. Quantum Torpedoes\n");

        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("You fire phasers...\n");
                enemy_health -= player_attack * 2;
                break;
            case 2:
                printf("You launch quantum torpedoes...\n");
                enemy_health -= player_attack * 3;
                break;
            default:
                printf("Invalid choice. You lose your turn.\n");
                break;
        }

        if(enemy_health <= 0)
        {
            printf("\nCongratulations! You have defeated the enemy ship and saved the galaxy!\n");
            break;
        }

        printf("The enemy ship retaliates...\n");
        ship_health -= enemy_attack;

        if(ship_health <= 0)
        {
            printf("\nYou have been defeated. The enemy ship, Capulet, has taken over the galaxy.\n");
            break;
        }
    }

    return 0;
}