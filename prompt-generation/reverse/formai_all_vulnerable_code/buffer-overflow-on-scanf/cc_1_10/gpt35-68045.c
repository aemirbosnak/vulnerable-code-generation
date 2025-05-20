//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    int player_health = 100;
    int monster_health = 50;
    int player_damage = 20;
    int monster_damage = 10;
    char input[20];

    printf("Welcome, adventurer! What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s! You are about to embark on a dangerous journey. Are you ready?\n", name);

    while (player_health > 0 && monster_health > 0) {
        printf("\nYou encounter a monster!\n");
        printf("Your health: %d\n", player_health);
        printf("Monster health: %d\n", monster_health);

        printf("What do you want to do? (attack/run)\n");
        scanf("%s", input);

        if (strcmp(input, "attack") == 0) {
            printf("You attack the monster!\n");
            monster_health -= player_damage;
            printf("The monster takes %d damage.\n", player_damage);

            printf("The monster attacks you!\n");
            player_health -= monster_damage;
            printf("You take %d damage.\n", monster_damage);
        } else if (strcmp(input, "run") == 0) {
            printf("You attempt to run away!\n");

            if (rand() % 2 == 0) {
                printf("You successfully escape!\n");
                break;
            } else {
                printf("The monster caught you!\n");
                printf("The monster attacks you!\n");
                player_health -= monster_damage;
                printf("You take %d damage.\n", monster_damage);
            }
        } else {
            printf("Invalid input. Try again.\n");
        }
    }

    if (player_health <= 0) {
        printf("\nYou have been defeated. Game over.\n");
    } else if (monster_health <= 0) {
        printf("\nYou have defeated the monster! Congratulations!\n");
    }

    return 0;
}