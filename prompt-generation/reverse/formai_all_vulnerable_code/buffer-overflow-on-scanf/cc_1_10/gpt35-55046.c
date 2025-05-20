//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//declare global variables
char player_name[20];
int player_score = 0;
int player_health = 100;

//declare function headers
void game_intro();
void game_instructions();
void game_play();
void game_end();

int main()
{
    game_intro();
    game_instructions();
    game_play();
    game_end();

    return 0;
}

//function to introduce the game and get player name
void game_intro()
{
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    fgets(player_name, 20, stdin);
    printf("\nHello %s! Let's begin.\n\n", player_name);
}

//function to display game instructions
void game_instructions()
{
    printf("Instructions:\n");
    printf("You will be presented with a series of choices.\n");
    printf("Each choice will lead to a different outcome.\n");
    printf("Your goal is to complete the game with the highest score and health possible.\n");
    printf("Let's begin!\n\n");
}

//function to play the game
void game_play()
{
    char choice;
    bool game_running = true;

    printf("You wake up in a dark room. You have no idea how you got here.\n");
    printf("You see a door and a window. Which do you choose? (d/w): ");

    while (game_running)
    {
        scanf(" %c", &choice);
        choice = tolower(choice);

        switch (choice)
        {
            case 'd':
                printf("You try the door, but it's locked. You need to find a key.\n");
                player_score += 10;
                break;

            case 'w':
                printf("You try the window, but it's too high to reach.\n");
                player_health -= 10;
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                continue;
        }

        printf("Your score is now %d and health is %d.\n", player_score, player_health);

        if (player_health <= 0)
        {
            printf("Oh no! You have died. Game over.\n");
            game_running = false;
            break;
        }

        printf("You see a key on a table. Do you take it? (y/n): ");

        scanf(" %c", &choice);
        choice = tolower(choice);

        switch (choice)
        {
            case 'y':
                printf("You take the key.\n");
                player_score += 10;
                break;

            case 'n':
                printf("You leave the key on the table.\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                continue;
        }

        printf("Your score is now %d.\n", player_score);

        printf("You use the key to unlock the door and escape.\n");
        player_score += 10;

        printf("Congratulations! You have completed the game with a score of %d and health of %d.\n", player_score, player_health);
        game_running = false;
    }
}

//function to end the game and display the final score and health
void game_end()
{
    printf("Thank you for playing the Text-Based Adventure Game, %s!\n", player_name);
    printf("Your final score is %d and health is %d.\n", player_score, player_health);
}