//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int player_health = 100;
    int enemy_health = 50;
    int attack_damage = 10;
    int defense_value = 5;
    int player_attack = 0;
    int enemy_attack = 0;
    int player_defense = 0;
    int enemy_defense = 0;
    int player_score = 0;
    int enemy_score = 0;
    char attack_choice;
    char defense_choice;

    srand(time(NULL));

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space warrior fighting against an alien.\n");
    printf("Please choose your attack or defense method:\n");
    printf("A - Attack\nD - Defense\n");
    scanf("%c", &attack_choice);

    while(1) {
        system("clear");
        printf("Round %d\n", ++player_score);
        printf("Your health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);
        printf("Your attack power: %d\n", player_attack);
        printf("Your defense power: %d\n", player_defense);

        if(player_health <= 0 || enemy_health <= 0) {
            break;
        }

        if(attack_choice == 'A' || attack_choice == 'a') {
            player_attack = rand() % 21 + 10;
            enemy_attack = rand() % 21 + 10;
            player_health -= enemy_attack;
            enemy_health -= player_attack;
        } else if(attack_choice == 'D' || attack_choice == 'd') {
            player_defense = rand() % 21 + 5;
            enemy_defense = rand() % 21 + 5;
            if(player_defense > enemy_attack) {
                printf("You successfully defended!\n");
            } else {
                printf("You failed to defend.\n");
                player_health -= enemy_attack - player_defense;
            }
            if(enemy_defense > player_attack) {
                printf("The enemy successfully defended!\n");
            } else {
                printf("The enemy failed to defend.\n");
                enemy_health -= player_attack - enemy_defense;
            }
        }

        if(player_health <= 0) {
            printf("You have been defeated by the enemy.\n");
            break;
        } else if(enemy_health <= 0) {
            printf("You have successfully defeated the enemy.\n");
            break;
        }
    }

    return 0;
}