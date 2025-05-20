//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int choice;
    int riddle_answer;
    srand(time(NULL));

    printf("Greetings traveler, what is your name?\n");
    scanf("%s", name);
    printf("Welcome %s to the game of the Cryptic Labyrinth!\n\n", name);
    printf("You find yourself in a dark and eerie maze. You have no idea how you got here, but you know you must find a way out.\n\n");
    printf("You have come across a fork in the path, one path is dark and ominous while the other seems a bit more inviting. Which do you choose? (1 or 2)\n\n");

    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("You chose the dark path. As you walk you hear whispers coming from the walls. You get the feeling you're being watched.\n\n");
    }
    else if(choice == 2)
    {
        printf("You chose the brighter path. As you walk you come across a riddle on the wall.\n\n");
        printf("What has a heart that doesn't beat?\n");
        printf("1. A deck of cards\n");
        printf("2. A forest\n");
        printf("3. A rock\n");

        scanf("%d", &riddle_answer);
        if(riddle_answer == 2)
        {
            printf("You got the riddle right. You feel a jolt of energy and a path opens up before you.\n\n");
        }
        else
        {
            printf("The answer is incorrect. The walls start closing in and you're crushed to death.\nGame Over.\n\n");
            return 0;
        }
    }

    int monster_health = rand() % 50 + 50;
    int player_health = 100;
    printf("As you continue down the path, you're suddenly attacked by a monster with %d health!\n\n", monster_health);
    printf("What will you do?\n");
    printf("1. Attack\n");
    printf("2. Run away\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("You attack the monster and deal 20 damage!");
            monster_health -= 20;

            if(monster_health <= 0)
            {
                printf("The monster has been defeated! You continue through the maze");
            }
            else
            {
                printf("The monster fights back and deals 10 damage to you.");
                player_health -= 10;
            }
            break;
        case 2:
            printf("You run away, but the monster chases after you and deals 30 damage.");
            player_health -= 30;
            break;
        default:
            printf("Invalid choice. You stand there and the monster gets a free hit dealing 15 damage to you.");
            player_health -= 15;
            break;
    }

    if(player_health <= 0)
    {
        printf("You have died. Game Over.\n\n");
        return 0;
    }

    printf("You continue down the maze and come across a chest. What will you do?\n");
    printf("1. Open the chest.\n");
    printf("2. Leave the chest alone.\n");

    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("You open the chest and find a sword that increases your attack power!");
    }
    else
    {
        printf("You leave the chest alone and continue through the maze.");
    }

    printf("After much wandering, you finally come across the exit to the maze. Congratulations! You have made it to the end of the Cryptic Labyrinth!\n\n");
    printf("Thanks for playing, %s!", name);

    return 0;
}