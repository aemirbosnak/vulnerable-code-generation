//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include<stdio.h>
#include<string.h>

int main()
{
    char player[20];
    char answer;
    int health = 100;
    int armor = 20;
    int attack = 10;
    int damage_taken;
    int enemy_damage;
    int potion_count = 3;
    int enemy_health = 50;
    int walk;
    int run;
    int fight;
    int boss_fight;
    int amount_of_gold = 0;

    printf("Welcome to Text-Based Adventure Game!\n");
    printf("What is your name, adventurer?\n");
    scanf("%s", player);
    printf("\nGreetings, %s! You are about to embark on an epic adventure!\n", player);

    printf("\nYou find yourself in a mystical forest. You have a long journey ahead of you and it will not be easy!\n");
    printf("In the forest, you see a strange looking figure.\n");
    printf("The figure calls out to you. Do you want to approach the figure? [y/n]: ");
    scanf(" %c", &answer);

    if (answer == 'y') {
        printf("\nThe figure approaches you.\n");
        printf("He tells you that he is the guardian of the forest and that you must prove yourself worthy.\n");
        printf("He tells you that the first challenge is to walk 10 miles in the forest without stopping.\n");

        for (walk = 1; walk <= 10; walk++) {
            printf("\nYou have walked %d mile(s) so far.\n", walk);
        }
        printf("\nCongratulations! You have passed the first challenge!\n");

        printf("\nThe guardian tells you that the second challenge is to run 5 miles in the forest without stopping.\n");

        for (run = 1; run <= 5; run++) {
            printf("\nYou have run %d mile(s) so far.\n", run);
            if (run == 3) {
                printf("\nYou have tripped on a branch and have taken some damage.\n");
                damage_taken = 10;
                health = health - damage_taken;
                printf("Your health is now %d.\n", health);
            }
        }

        if (health <= 0) {
            printf("\nYou have failed the second challenge and have died.\n");
            return 0;
        }

        printf("\nCongratulations! You have passed the second challenge!\n");
        printf("\nThe guardian tells you that the third challenge is to fight a monster!\n");
        printf("The monster has %d health and does %d damage per hit.\n", enemy_health, enemy_damage);

        printf("Do you want to fight the monster? [y/n]: ");
        scanf(" %c", &answer);

        if (answer == 'y') {
            while (enemy_health > 0) {
                printf("\nYour health is %d and the enemy's health is %d.\n", health, enemy_health);
                printf("What do you want to do?\n");
                printf("1. Attack\n");
                printf("2. Use potion (%d potions left)\n", potion_count);
                scanf(" %d", &fight);
                if (fight == 1) {
                    enemy_health = enemy_health - attack;
                    printf("\nYou hit the enemy for %d damage.\n", attack);
                    if (enemy_health <= 0) {
                        printf("\nCongratulations! You have defeated the monster!\n");
                        amount_of_gold = amount_of_gold + 50;
                        printf("You have gained 50 gold.\n");
                        printf("Your total amount of gold is now %d.\n", amount_of_gold);
                        break;
                    }
                    damage_taken = enemy_damage;
                    health = health - damage_taken;
                    printf("\nThe enemy hits you for %d damage.\n", enemy_damage);
                    printf("Your health is now %d.\n", health);
                    if (health <= 0) {
                        printf("\nYou have died.\n");
                        return 0;
                    }
                }
                else if (fight == 2) {
                    if (potion_count > 0) {
                        health = health + 20;
                        printf("\nYou use a potion and gain 20 health.\n");
                        potion_count--;
                    }
                    else {
                        printf("\nYou do not have any potions left.\n");
                    }
                }
            }
        }
        else {
            printf("\nYou have failed the third challenge and have died.\n");
            return 0;
        }
    }
    else {
        printf("\nYou have failed the first challenge and have died.\n");
        return 0;
    }

    printf("\nCongratulations! You have passed all the challenges and have completed the game!\n");

    return 0;
}