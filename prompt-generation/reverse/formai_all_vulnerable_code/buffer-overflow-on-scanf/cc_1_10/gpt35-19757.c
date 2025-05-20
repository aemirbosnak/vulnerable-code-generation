//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void gameLoop();
void explore();
void battle();
void victory();
void gameOver();

int player_hp = 100;
int boss_hp = 150;

int main()
{
    srand(time(0));
    printf("Welcome to the adventure!\n\n");
    printf("You are now on a quest to find the legendary treasure of happiness. Good luck!\n\n");
    gameLoop();
    return 0;
}

void gameLoop()
{
    int choice;
    printf("What would you like to do?\n");
    printf("1. Explore the forest\n2. Battle the boss\n3. Quit game\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        explore();
        break;
    case 2:
        battle();
        break;
    case 3:
        printf("Thanks for playing, see you next time!\n");
        exit(0);
    default:
        printf("Invalid choice, please try again.\n");
        gameLoop();
        break;
    }
}

void explore()
{
    int rand_num = rand() % 3;
    if (rand_num == 0)
    {
        printf("You found a chest filled with gold coins! +50 happiness points!\n");
        printf("Your current happiness level is now 50.\n");
        gameLoop();
    }
    else if (rand_num == 1)
    {
        printf("You stumbled upon a group of friendly animals. They showered you with love and affection!\n");
        printf("+25 happiness points!\n");
        printf("Your current happiness level is now 25.\n");
        gameLoop();
    }
    else
    {
        printf("You got lost in the forest. Your happiness level decreased.\n");
        printf("-10 happiness points.\n");
        player_hp -= 10;
        if (player_hp <= 0)
        {
            gameOver();
        }
        gameLoop();
    }
}

void battle()
{
    printf("You have encountered the boss of the forest! Defeat him to get the treasure of happiness.\n");
    while (player_hp > 0 && boss_hp > 0)
    {
        printf("Your current HP: %d\n", player_hp);
        printf("Boss's current HP: %d\n", boss_hp);
        int damage = rand() % 11;
        boss_hp -= damage;
        printf("You attacked the boss for %d damage!\n", damage);
        if (boss_hp <= 0)
        {
            victory();
        }
        damage = rand() % 16;
        player_hp -= damage;
        printf("The boss attacked you for %d damage!\n", damage);
        if (player_hp <= 0)
        {
            gameOver();
        }
    }
}

void victory()
{
    printf("Congratulations! You have defeated the boss and obtained the treasure of happiness!\n");
    printf("Your happiness level is now 100! You win!\n");
    player_hp = 100;
    boss_hp = 150;
    gameLoop();
}

void gameOver()
{
    printf("Oh no! You have been defeated. Game over.\n");
    printf("Better luck next time!\n");
    player_hp = 100;
    boss_hp = 150;
    gameLoop();
}