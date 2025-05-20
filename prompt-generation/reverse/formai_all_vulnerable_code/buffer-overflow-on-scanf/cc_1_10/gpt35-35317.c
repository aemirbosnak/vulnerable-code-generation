//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[30];
    int level = 1;
    int health = 100;
    int enemy_health = 50;
    int attack = 20;
    int enemy_attack = 10;

    printf("Welcome to Dungeon Adventure!\n");
    printf("What is your name, adventurer? ");
    scanf("%s", name);
    printf("\n");

    printf("Greetings, %s! You are about to embark on a perilous journey through the depths of this dungeon.\n\n", name);

    printf("Level %d\n", level);
    printf("%s's health: %d\n", name, health);
    printf("Enemy's health: %d\n", enemy_health);
    printf("\n");

    printf("Press enter to continue.\n");
    getchar();

    while (health > 0 && enemy_health > 0)
    {
        printf("It's your turn!\n");
        enemy_health -= attack;
        printf("You attacked the enemy for %d damage.\n", attack);
        if (enemy_health <= 0)
        {
            printf("Congratulations! You defeated the enemy!\n");
            health += 20;
            printf("%s's health has been restored to %d.\n", name, health);
            enemy_health = 50;
            level++;
            printf("You are now on level %d.\n\n", level);
            printf("Press enter to continue.\n");
            getchar();
        }
        else
        {
            printf("Enemy's turn!\n");
            health -= enemy_attack;
            printf("The enemy attacked you for %d damage.\n", enemy_attack);
            printf("\n");
        }

        printf("Level %d\n", level);
        printf("%s's health: %d\n", name, health);
        printf("Enemy's health: %d\n", enemy_health);
        printf("\n");

        if (health <= 0)
        {
            printf("Game over! You have been defeated by the enemy.\n");
        }
    }

    return 0;
}