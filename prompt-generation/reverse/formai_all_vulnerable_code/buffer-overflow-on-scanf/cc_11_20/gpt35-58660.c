//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int age;
    int choice;
    int coins = 0;
    int health = 50;
    int energy = 10;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name adventurer?\n");
    scanf("%s", name);
    printf("Greetings %s, how old are you?\n", name);
    scanf("%d", &age);
    printf("Wonderful! Let's begin our journey %s!\n\n", name);

    while(health > 0)
    {
        printf("What adventure would you like to pursue?\n");
        printf("1. Explore the Dark Forest\n");
        printf("2. Enter the Haunted Mansion\n");
        printf("3. Visit the Abandoned Mine\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("You enter the Dark Forest...\n");
                printf("You come across a lost traveler, what do you do?\n");
                printf("1. Keep moving\n");
                printf("2. Help the traveler\n");
                scanf("%d", &choice);

                if(choice == 2)
                {
                    printf("You help the traveler and they reward you with 10 coins!\n");
                    coins += 10;
                    printf("Coins: %d\n", coins);
                }

                printf("As you continue to explore the forest, you encounter a dangerous wild animal!\n");
                printf("You can either...\n");
                printf("1. Fight the animal\n");
                printf("2. Run away\n");
                scanf("%d", &choice);

                if(choice == 1) //Fighting the animal
                {
                    printf("You fight the animal...\n");
                    energy -= 5;
                    if(energy <= 0)
                    {
                        printf("You do not have enough energy to fight...\n");
                        health -= 25;
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                    }
                    else
                    {
                        printf("You defeat the animal and earn 20 coins!\n");
                        coins += 20;
                        printf("Coins: %d\n", coins);
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                    }
                }
                else if(choice == 2) //Running away
                {
                    printf("You run away from the animal...\n");
                    energy -= 2;
                    if(energy <= 0)
                    {
                        printf("You do not have enough energy to run...\n");
                        health -= 10;
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                    }
                    else
                    {
                        printf("You successfully escape from the animal and continue exploring the forest...\n");
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                    }
                }
                break;
            case 2:
                printf("You enter the Haunted Mansion...\n");
                printf("You hear strange noises coming from upstairs, do you investigate?\n");
                printf("1. Investigate\n");
                printf("2. Leave the mansion\n");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("You go upstairs to investigate...\n");
                    printf("You are greeted by a ghost!\n");
                    printf("You can either...\n");
                    printf("1. Confront the ghost\n");
                    printf("2. Run away\n");
                    scanf("%d", &choice);

                    if(choice == 1) //Confronting the ghost
                    {
                        printf("You confront the ghost...\n");
                        health -= 20;
                        printf("You lose 20 health...\n");
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                        printf("The ghost disappears, revealing a hidden treasure chest!\n");
                        printf("You open the chest and find 50 coins!\n");
                        coins += 50;
                        printf("Coins: %d\n", coins);
                    }
                    else if(choice == 2) //Running away
                    {
                        printf("You run away from the ghost...\n");
                        energy -= 5;
                        if(energy <= 0)
                        {
                            printf("You do not have enough energy to run...\n");
                            health -= 10;
                            printf("Health: %d\n", health);
                            printf("Energy: %d\n\n", energy);
                        }
                        else
                        {
                            printf("You successfully escape from the ghost and find a small amount of coins on your way out!\n");
                            coins += 10;
                            printf("Coins: %d\n", coins);
                            printf("Health: %d\n", health);
                            printf("Energy: %d\n\n", energy);
                        }
                    }
                }
                else if(choice == 2) //Leaving the mansion
                {
                    printf("You decide not to investigate and leave the mansion...\n");
                    energy -=1;
                    if(energy <= 0)
                    {
                        printf("You do not have enough energy to leave the mansion...\n");
                        health -= 5;
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                    }
                    else
                    {
                        printf("You continue on your journey...\n");
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                    }
                }
                break;
            case 3:
                printf("You enter the Abandoned Mine...\n");
                printf("You come across a group of miners who are looking for help, will you help them?\n");
                printf("1. Help the miners\n");
                printf("2. Ignore the miners and continue exploring\n");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("You help the miners by finding valuable ores and they reward you with 25 coins!\n");
                    coins +=25;
                    printf("Coins: %d\n", coins);
                }

                printf("As you continue to explore the mine, you fall into a dark pit!\n");
                printf("You can either...\n");
                printf("1. Try to climb up\n");
                printf("2. Call for help\n");
                scanf("%d", &choice);

                if(choice == 1) //Climbing up the pit
                {
                    printf("You try to climb up the pit...\n");
                    energy -= 10;
                    if(energy <= 0)
                    {
                        printf("You do not have enough energy to climb up...\n");
                        health -=15;
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                    }
                    else
                    {
                        printf("You successfully climb up the pit and find a large amount of coins on your way out!\n");
                        coins += 40;
                        printf("Coins: %d\n", coins);
                        printf("Health: %d\n", health);
                        printf("Energy: %d\n\n", energy);
                    }
                }
                else if(choice == 2) //Calling for help
                {
                    printf("You call for help and a group of miners come to your rescue!\n");
                    printf("They reward you with 25 coins for helping them earlier!\n");
                    coins += 25;
                    printf("Coins: %d\n", coins);
                    printf("Health: %d\n", health);
                    printf("Energy: %d\n\n", energy);
                }
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    printf("You have lost all your health and have died on your adventure.\n");
    printf("Thanks for playing %s, come back soon!", name);

    return 0;
}