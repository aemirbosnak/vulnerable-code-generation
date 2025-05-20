//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int health = 100;
    int attack = 8;
    int enemy_health = 50;
    int enemy_attack = 5;

    srand(time(NULL)); // initialize random seed
    
    printf("You have entered the Haunted Castle!\n");
    printf("Your health: %d\n", health);
    printf("Enemy health: %d\n", enemy_health);

    while(health > 0 && enemy_health > 0) {
        int random = rand() % 10 + 1; // generate random number between 1-10

        if(random <= 5) { // you encounter an enemy!
            printf("You have encountered an enemy!\n");

            while(health > 0 && enemy_health > 0) {
                printf("What will you do? (1 = attack, 2 = defend): ");
                int choice;
                scanf("%d", &choice);

                if(choice == 1) { // attack the enemy
                    printf("You attack the enemy and do %d damage!\n", attack);
                    enemy_health -= attack;
                } else { // defend
                    printf("You defend against the enemy's attack!\n");
                    health -= enemy_attack / 2;
                }

                // enemy attacks
                printf("The enemy attacks and does %d damage!\n", enemy_attack);
                health -= enemy_attack;

                printf("Your health: %d\n", health);
                printf("Enemy health: %d\n", enemy_health);
            }

            if(enemy_health <= 0) {
                printf("You have defeated the enemy!\n");
            }
        } else { // you find some loot
            printf("You have found some loot!\n");

            int loot = rand() % 20 + 1; // generate random loot between 1-20
            printf("You found %d gold!\n", loot);
        }
    }

    if(health <= 0) {
        printf("Game over! You have died.\n");
    } else {
        printf("You have successfully escaped the Haunted Castle!\n");
    }

    return 0;
}