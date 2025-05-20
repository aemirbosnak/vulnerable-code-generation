//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    int attack_damage = rand() % 11 + 5;
    int defense_points = rand() % 11 + 5;
    int player_attack = attack_damage;
    int enemy_attack = rand() % 11 + 5;
    int enemy_defense = defense_points;
    int player_defense = defense_points;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a brave space warrior with %d health points.\n", player_health);
    printf("Your attack power is %d and your defense is %d.\n", player_attack, player_defense);
    printf("You encounter an evil alien with %d health points.\n", enemy_health);
    printf("The alien's attack power is %d and its defense is %d.\n", enemy_attack, enemy_defense);

    int player_choice;
    printf("What will you do?\n");
    printf("1. Attack\n");
    printf("2. Defend\n");
    scanf("%d", &player_choice);

    if (player_choice == 1) {
        if (player_attack > enemy_defense) {
            enemy_health -= player_attack - enemy_defense;
            printf("You attacked the alien and dealt %d damage!\n", player_attack - enemy_defense);
        } else {
            printf("Your attack was blocked by the alien's defense.\n");
        }
    } else if (player_choice == 2) {
        if (player_defense > enemy_attack) {
            printf("You successfully defended against the alien's attack!\n");
        } else {
            player_health -= enemy_attack - player_defense;
            printf("The alien attacked you and dealt %d damage!\n", enemy_attack - player_defense);
        }
    } else {
        printf("Invalid choice.\n");
    }

    if (player_health <= 0) {
        printf("You have been defeated by the alien.\n");
        return 0;
    } else if (enemy_health <= 0) {
        printf("You have defeated the alien!\n");
        return 0;
    }

    return 0;
}