//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player_health = 100, enemy_health = 100, potion_count = 3, choice, enemy_choice, damage;
    srand(time(NULL)); //to seed the random number generator

    printf("Welcome to the Text-Based Adventure Game\n");
    printf("----------------------------------------\n");

    while(player_health > 0 && enemy_health > 0)
    {
        printf("\nPlayer Health: %d\nEnemy Health: %d\nNumber of Potions: %d\n\n", player_health, enemy_health, potion_count);
        printf("Choose an action:\n");
        printf("1. Attack\n2. Drink Potion\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nYou attack the enemy!\n");
                damage = rand() % 20 + 10; //generate a random damage between 10 and 30
                enemy_health -= damage;
                printf("You deal %d damage to the enemy!\n", damage);
                if(enemy_health <= 0)
                {
                    printf("\nCongratulations! You have defeated the enemy!\n");
                    break; //exit the loop
                }

                printf("\nThe enemy attacks you!\n");
                enemy_choice = rand() % 2; //generate a random choice between 0 and 1
                switch(enemy_choice)
                {
                    case 0: //enemy attacks with a sword
                        damage = rand() % 15 + 5; //generate a random damage between 5 and 20
                        player_health -= damage;
                        printf("The enemy attacks you with a sword and deals %d damage\n", damage);
                        break;
                    case 1: //enemy attacks with a magic spell
                        damage = rand() % 25 + 10; //generate a random damage between 10 and 35
                        player_health -= damage;
                        printf("The enemy attacks you with a magic spell and deals %d damage\n", damage);
                        break;
                }
                break;

            case 2:
                if(potion_count > 0)
                {
                    printf("\nYou drink a potion!\n");
                    player_health += 20;
                    potion_count--;
                    printf("You restore 20 health points. Current player health: %d\n", player_health);
                }
                else
                    printf("\nYou have no potions left!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }

    }

    if(player_health <= 0)
        printf("\nYou have been defeated!\n");
    return 0;
}