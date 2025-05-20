//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generator

    // introduction
    printf("Welcome to the Secret Island Adventure Game!\n");
    printf("You are stranded on a mysterious island with no way off.\n");
    printf("Your mission is to uncover the secret of the island and find a way to escape.\n\n");

    // initialize variables for game
    int health = 100;
    int strength = 10;
    int agility = 5;
    int intelligence = 5;
    int items = 0;

    // start of game loop
    while(health > 0)
    {
        // generate a random event
        int event = rand() % 3;

        if(event == 0) // explore
        {
            printf("You explore the island and come across a cave.\n");
            printf("Do you want to enter the cave? (yes/no) ");

            char input[10];
            scanf("%s", input);

            if(strcmp(input, "yes") == 0)
            {
                printf("You enter the cave and find a treasure chest!\n");
                printf("You gain an item!\n");
                items++;
            }
            else
            {
                printf("You decide not to enter the cave and continue exploring.\n");
            }
        }
        else if(event == 1) // fight
        {
            printf("You encounter a fierce bear on the island!\n");
            printf("Do you want to fight it? (yes/no) ");

            char input[10];
            scanf("%s", input);

            if(strcmp(input, "yes") == 0)
            {
                int enemy_strength = rand() % 20 + 1;
                int enemy_health = rand() % 50 + 50;

                while(health > 0 && enemy_health > 0)
                {
                    enemy_health -= strength;
                    printf("You hit the bear for %d damage.\n", strength);

                    if(enemy_health <= 0)
                    {
                        printf("You defeat the bear!\n");
                        printf("You gain strength!\n");
                        strength += 5;
                        break;
                    }

                    health -= enemy_strength;
                    printf("The bear hits you for %d damage.\n", enemy_strength);

                    if(health <= 0)
                    {
                        printf("You are defeated by the bear.\n");
                        break;
                    }
                }
            }
            else
            {
                printf("You decide not to fight the bear and continue exploring.\n");
            }
        }
        else // puzzle
        {
            printf("You come across a mysterious artifact on the island.\n");
            printf("Do you want to investigate it? (yes/no) ");

            char input[10];
            scanf("%s", input);

            if(strcmp(input, "yes") == 0)
            {
                printf("You study the artifact and realize it is a puzzle!\n");
                printf("The puzzle requires you to answer a riddle.\n");
                printf("Here is the riddle:\n");
                printf("What has a heart that doesn't beat?\n");

                char answer[20];
                scanf("%s", answer);

                if(strcmp(answer, "artichoke") == 0)
                {
                    printf("You solve the puzzle and gain intelligence!\n");
                    intelligence += 5;
                }
                else
                {
                    printf("You fail to solve the puzzle.\n");
                }
            }
            else
            {
                printf("You decide not to investigate the artifact and continue exploring.\n");
            }
        }

        // update health based on fatigue
        health -= rand() % 10 + 1;

        // check if player has enough items to win
        if(items >= 3)
        {
            printf("You have found enough items to escape the island!\n");
            printf("Congratulations, you win!\n");
            break;
        }
    }

    // display final stats
    printf("Final Stats:\n");
    printf("Health: %d\n", health);
    printf("Strength: %d\n", strength);
    printf("Agility: %d\n", agility);
    printf("Intelligence: %d\n", intelligence);
    printf("Items: %d\n", items);

    return 0;
}