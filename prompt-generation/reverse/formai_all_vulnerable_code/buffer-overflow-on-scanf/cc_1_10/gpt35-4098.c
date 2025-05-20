//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void start_game();
void show_instructions();
void game_over();
void win_game();

// Global variables
char player_name[20];
int player_health = 100;
int player_score = 0;

int main()
{
    printf("Welcome to Adventure Game!\n\n");

    printf("What is your name?\n");
    scanf("%s", player_name);

    printf("Hello, %s! Are you ready to start the game? (y/n)\n", player_name);

    char start_choice;
    scanf(" %c", &start_choice);

    if(start_choice == 'y')
    {
        start_game();
    }
    else
    {
        printf("Okay, bye %s!\n", player_name);
    }

    return 0;
}

void start_game()
{
    printf("\n\nGreat! Let's start the game!\n\n");

    printf("You are standing in front of a dark forest. There are two paths - left and right.\n");
    printf("Which path do you choose? (l/r)\n");

    char path_choice;
    scanf(" %c", &path_choice);

    if(path_choice == 'l')
    {
        printf("\n\nYou chose the left path.\n");

        printf("You see a river flowing in front of you. You can either swim through it or find another way around. What do you choose? (swim/around)\n");

        char river_choice[10];
        scanf("%s", river_choice);

        if(strcmp(river_choice, "swim") == 0)
        {
            printf("\n\nYou tried to swim but you got attacked by a crocodile and lost 20 health points.\n");

            player_health -= 20;

            printf("Your current health: %d\n", player_health);

            if(player_health <= 0)
            {
                game_over();
            }
            else
            {
                printf("You managed to survive and came out on the other side of the river.\n");

                printf("You see a treasure chest placed just a few feet away from you. What do you do? (open/leave)\n");

                char treasure_choice[10];
                scanf("%s", treasure_choice);

                if(strcmp(treasure_choice, "open") == 0)
                {
                    printf("\n\nYou opened the treasure chest and found a rare gem worth 50 points!\n");

                    player_score += 50;

                    printf("Your current score: %d\n", player_score);

                    printf("You move on and reach a village. You see a group of people gathered in the town square. What do you do? (join/ignore)\n");

                    char village_choice[10];
                    scanf("%s", village_choice);

                    if(strcmp(village_choice, "join") == 0)
                    {
                        printf("\n\nYou joined the group and discovered that they were planning a rebellion against the village chief who was a cruel dictator.\n");

                        printf("You participated in the rebellion and helped the group overthrow the village chief.\n");

                        win_game();
                    }
                    else
                    {
                        printf("\n\nYou decided to ignore the group and moved on with your adventure.\n");

                        printf("You eventually reached the end of the forest and found a way out.\n");

                        printf("You won the game! Your final score: %d\n", player_score);
                    }
                }
                else
                {
                    printf("\n\nYou decided to leave the treasure chest and moved on with your adventure.\n");

                    printf("You eventually reached the end of the forest and found a way out.\n");

                    printf("You won the game! Your final score: %d\n", player_score);
                }
            }
        }
        else
        {
            printf("\n\nYou decided to go around the river and took a longer route.\n");

            printf("You see a treasure chest placed just a few feet away from you. What do you do? (open/leave)\n");

            char treasure_choice[10];
            scanf("%s", treasure_choice);

            if(strcmp(treasure_choice, "open") == 0)
            {
                printf("\n\nYou opened the treasure chest and found a rare gem worth 50 points!\n");

                player_score += 50;

                printf("Your current score: %d\n", player_score);

                printf("You move on and reach a village. You see a group of people gathered in the town square. What do you do? (join/ignore)\n");

                char village_choice[10];
                scanf("%s", village_choice);

                if(strcmp(village_choice, "join") == 0)
                {
                    printf("\n\nYou joined the group and discovered that they were planning a rebellion against the village chief who was a cruel dictator.\n");

                    printf("You participated in the rebellion and helped the group overthrow the village chief.\n");

                    win_game();
                }
                else
                {
                    printf("\n\nYou decided to ignore the group and moved on with your adventure.\n");

                    printf("You eventually reached the end of the forest and found a way out.\n");

                    printf("You won the game! Your final score: %d\n", player_score);
                }
            }
            else
            {
                printf("\n\nYou decided to leave the treasure chest and moved on with your adventure.\n");

                printf("You eventually reached the end of the forest and found a way out.\n");

                printf("You won the game! Your final score: %d\n", player_score);
            }
        }
    }
    else
    {
        printf("\n\nYou chose the right path.\n");

        printf("You see a bear in front of you. What do you do? (fight/run)\n");

        char bear_choice[10];
        scanf("%s", bear_choice);

        if(strcmp(bear_choice, "fight") == 0)
        {
            printf("\n\nYou fought the bear and got injured. You lost 30 health points.\n");

            player_health -= 30;

            printf("Your current health: %d\n", player_health);

            if(player_health <= 0)
            {
                game_over();
            }
            else
            {
                printf("You managed to defeat the bear and move on with your adventure.\n");

                printf("You see a treasure chest placed just a few feet away from you. What do you do? (open/leave)\n");

                char treasure_choice[10];
                scanf("%s", treasure_choice);

                if(strcmp(treasure_choice, "open") == 0)
                {
                    printf("\n\nYou opened the treasure chest and found a rare gem worth 50 points!\n");

                    player_score += 50;

                    printf("Your current score: %d\n", player_score);

                    printf("You move on and reach a village. You see a group of people gathered in the town square. What do you do? (join/ignore)\n");

                    char village_choice[10];
                    scanf("%s", village_choice);

                    if(strcmp(village_choice, "join") == 0)
                    {
                        printf("\n\nYou joined the group and discovered that they were planning a rebellion against the village chief who was a cruel dictator.\n");

                        printf("You participated in the rebellion and helped the group overthrow the village chief.\n");

                        win_game();
                    }
                    else
                    {
                        printf("\n\nYou decided to ignore the group and moved on with your adventure.\n");

                        printf("You eventually reached the end of the forest and found a way out.\n");

                        printf("You won the game! Your final score: %d\n", player_score);
                    }
                }
                else
                {
                    printf("\n\nYou decided to leave the treasure chest and moved on with your adventure.\n");

                    printf("You eventually reached the end of the forest and found a way out.\n");

                    printf("You won the game! Your final score: %d\n", player_score);
                }
            }
        }
        else
        {
            printf("\n\nYou decided to run away from the bear. You took a longer route.\n");

            printf("You see a treasure chest placed just a few feet away from you. What do you do? (open/leave)\n");

            char treasure_choice[10];
            scanf("%s", treasure_choice);

            if(strcmp(treasure_choice, "open") == 0)
            {
                printf("\n\nYou opened the treasure chest and found a rare gem worth 50 points!\n");

                player_score += 50;

                printf("Your current score: %d\n", player_score);

                printf("You move on and reach a village. You see a group of people gathered in the town square. What do you do? (join/ignore)\n");

                char village_choice[10];
                scanf("%s", village_choice);

                if(strcmp(village_choice, "join") == 0)
                {
                    printf("\n\nYou joined the group and discovered that they were planning a rebellion against the village chief who was a cruel dictator.\n");

                    printf("You participated in the rebellion and helped the group overthrow the village chief.\n");

                    win_game();
                }
                else
                {
                    printf("\n\nYou decided to ignore the group and moved on with your adventure.\n");

                    printf("You eventually reached the end of the forest and found a way out.\n");

                    printf("You won the game! Your final score: %d\n", player_score);
                }
            }
            else
            {
                printf("\n\nYou decided to leave the treasure chest and moved on with your adventure.\n");

                printf("You eventually reached the end of the forest and found a way out.\n");

                printf("You won the game! Your final score: %d\n", player_score);
            }
        }
    }
}

void game_over()
{
    printf("\n\nGame over, %s!\n", player_name);

    printf("Your final score: %d\n", player_score);
}

void win_game()
{
    printf("\n\nCongratulations, %s! You won the game!\n", player_name);

    printf("Your final score: %d\n", player_score);
}