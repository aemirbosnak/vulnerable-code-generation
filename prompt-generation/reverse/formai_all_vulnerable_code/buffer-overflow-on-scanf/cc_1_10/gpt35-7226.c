//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player_health = 10;
int enemy_health = 10;

int roll_dice() {
    srand(time(NULL));
    int roll = rand() % 6 + 1;
    return roll;
}

void player_turn() {
    int player_roll = roll_dice();
    printf("You rolled a %d\n", player_roll);
    if(player_roll == 1) {
        printf("You missed the enemy!\n");
    } else {
        enemy_health -= player_roll;
        printf("You hit the enemy for %d damage! Enemy Health: %d\n", player_roll, enemy_health);
        if(enemy_health <= 0) {
            printf("You won!\n");
            exit(0);
        }
    }
}

void enemy_turn() {
    int enemy_roll = roll_dice();
    printf("Enemy rolled a %d\n", enemy_roll);
    if(enemy_roll == 1) {
        printf("The enemy missed you!\n");
    } else {
        player_health -= enemy_roll;
        printf("The enemy hit you for %d damage! Health: %d\n", enemy_roll, player_health);
        if(player_health <= 0) {
            printf("You lost!\n");
            exit(0);
        }
    }
}

int main(int argc, char* argv[]) {
    printf("Welcome to Brave Battle!\n");
    while(1) {
        printf("------------------------\n");
        printf("Player Health: %d | Enemy Health: %d\n", player_health, enemy_health);
        printf("------------------------\n");
        printf("1. Roll Dice\n");
        printf("2. Quit Game\n");
        printf("> ");
        int input;
        scanf("%d", &input);
        switch(input) {
            case 1:
                player_turn();
                enemy_turn();
                break;
            case 2:
                printf("Thanks for playing!\n");
                exit(0);
                break;
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
    }
    return 0;
}