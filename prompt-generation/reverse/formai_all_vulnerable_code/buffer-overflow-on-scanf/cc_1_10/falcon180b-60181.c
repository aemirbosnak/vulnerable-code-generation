//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void game_over();
void start_game();
int get_random_number(int min, int max);

int main() {
    srand(time(0));
    intro();
    start_game();
    return 0;
}

void intro() {
    printf("Welcome to the Cryptic Adventure!\n");
    printf("You find yourself in a dark and mysterious dungeon.\n");
    printf("Your goal is to escape alive!\n");
    printf("Are you ready to begin? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    if (choice!= 'y') {
        game_over();
    }
}

void game_over() {
    printf("Game Over!\n");
    exit(0);
}

void start_game() {
    int player_health = 100;
    int enemy_health = get_random_number(50, 150);
    int player_attack = get_random_number(10, 30);
    int enemy_attack = get_random_number(20, 40);

    while (player_health > 0 && enemy_health > 0) {
        printf("You encounter an enemy!\n");
        printf("Enemy Health: %d\n", enemy_health);
        printf("Your Health: %d\n", player_health);
        int choice;
        printf("What will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enemy_health -= player_attack;
                if (enemy_health <= 0) {
                    printf("You defeated the enemy!\n");
                } else {
                    player_health -= enemy_attack;
                    printf("The enemy attacks you!\n");
                }
                break;
            case 2:
                player_health -= enemy_attack;
                if (player_health <= 0) {
                    printf("You were defeated by the enemy.\n");
                    game_over();
                } else {
                    printf("You defended against the enemy attack.\n");
                }
                break;
            case 3:
                printf("You ran away from the enemy.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}