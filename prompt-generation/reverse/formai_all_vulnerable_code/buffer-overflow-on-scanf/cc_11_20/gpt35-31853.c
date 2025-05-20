//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Seed random number generator
    int currentRoom = 1;
    int health = 100;
    int attack = 10;
    int alienHealth = 50;
    int alienAttack = 5;
    char choice;

    printf("Welcome to Procedural Space Adventure!\n");
    printf("-------------------------------------\n");
    printf("You wake up from cryosleep to find yourself stranded on a spaceship.\n");

    while (health > 0 && currentRoom < 5) //Game loop
    {
        printf("-------------------------------------\n");
        printf("You are currently in room %d\n", currentRoom);
        printf("Health: %d\n", health);

        switch (currentRoom)
        {
            case 1:
                printf("You are in the main control room.\n");
                printf("There is a door to your left and a door to your right.\n");
                printf("Which direction do you want to go? (L/R): ");
                scanf(" %c", &choice);
                if (choice == 'L')
                {
                    printf("You entered the engine room.\n");
                    currentRoom = 2;
                    health -= 10;
                }
                else if (choice == 'R')
                {
                    printf("You entered the medical bay.\n");
                    currentRoom = 3;
                    health += 10;
                }
                break;
            case 2:
                printf("You are in the engine room.\n");
                printf("There is a control panel on the wall.\n");
                printf("Do you want to activate the engines? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y')
                {
                    printf("The engines roar to life and you feel the ship start to move.\n");
                    currentRoom = 4;
                }
                else if (choice == 'N')
                {
                    printf("Nothing happens.\n");
                }
                break;
            case 3:
                printf("You are in the medical bay.\n");
                printf("There is a first aid kit on the wall.\n");
                printf("Do you want to use it? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y')
                {
                    printf("You patch yourself up and feel better.\n");
                    health += 10;
                }
                else if (choice == 'N')
                {
                    printf("You leave the first aid kit alone.\n");
                }
                break;
            case 4:
                printf("You are in the cargo bay.\n");
                printf("There is an alien blocking your way to the escape pod.\n");
                printf("Do you want to fight it? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y')
                {
                    printf("You attack the alien!\n");
                    alienHealth -= attack;
                    printf("The alien's health is %d.\n", alienHealth);
                    if (alienHealth <= 0)
                    {
                        printf("You defeated the alien! You escape the spaceship and win the game!\n");
                        return 0;
                    }
                    printf("The alien attacks you.\n");
                    health -= alienAttack;
                    printf("Your health is %d.\n", health);
                    if (health <= 0)
                    {
                        printf("You died. Game over.\n");
                        return 0;
                    }
                }
                else if (choice == 'N')
                {
                    printf("You run back to the engine room.\n");
                    printf("The alien follows you and attacks you.\n");
                    health -= alienAttack;
                    printf("Your health is %d.\n", health);
                    if (health <= 0)
                    {
                        printf("You died. Game over.\n");
                        return 0;
                    }
                }
                break;
            default:
                printf("Invalid room number.\n");
                return 1;
        }
    }
    printf("You reach the escape pod and win the game!\n");
    return 0;
}