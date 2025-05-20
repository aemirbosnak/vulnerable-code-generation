//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int player_health = 100;
    int enemy_health = 100;
    int attack_power = 10;
    int defense_power = 10;
    int player_attack = 0;
    int enemy_attack = 0;
    int player_defense = 0;
    int enemy_defense = 0;

    srand(time(NULL));

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the evil alien.\n");
    printf("Your spaceship has landed on Planet X, where the alien is hiding.\n");
    printf("Are you ready to begin your adventure? (y/n)\n");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("You have entered the alien's lair.\n");
        printf("The alien is waiting for you in the next room.\n");
        printf("Do you want to attack the alien or defend yourself?\n");
        scanf("%c", &choice);

        if (choice == 'a' || choice == 'A') {
            player_attack = rand() % attack_power + 1;
            enemy_attack = rand() % attack_power + 1;
            player_defense = rand() % defense_power + 1;
            enemy_defense = rand() % defense_power + 1;

            if (player_attack > enemy_defense) {
                enemy_health -= player_attack;
            } else if (enemy_attack > player_defense) {
                player_health -= enemy_attack;
            } else {
                printf("Both attacks were blocked.\n");
            }

            printf("You have %d health left.\n", player_health);
            printf("The alien has %d health left.\n", enemy_health);

            if (player_health <= 0) {
                printf("You have been defeated by the alien.\n");
                return 0;
            } else if (enemy_health <= 0) {
                printf("You have defeated the alien and completed your mission.\n");
                return 0;
            }
        } else if (choice == 'd' || choice == 'D') {
            player_defense = rand() % defense_power + 1;
            enemy_defense = rand() % defense_power + 1;

            if (player_defense > enemy_attack) {
                printf("You have successfully defended yourself.\n");
            } else {
                printf("You were hit by the alien's attack.\n");
                player_health -= enemy_attack;
            }

            printf("You have %d health left.\n", player_health);
            printf("The alien has %d health left.\n", enemy_health);

            if (player_health <= 0) {
                printf("You have been defeated by the alien.\n");
                return 0;
            } else if (enemy_health <= 0) {
                printf("You have defeated the alien and completed your mission.\n");
                return 0;
            }
        }
    } else {
        printf("You have decided to leave Planet X and return home.\n");
    }

    return 0;
}