//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int player_health = 100;
    int enemy_health = 100;
    int player_attack, enemy_attack, player_choice;
    srand(time(0));
    printf("Welcome to the Dungeon!\n");
    printf("You have to defeat the evil monster to escape.\n");
    printf("You have a health of 100 and the monster also has a health of 100.\n");
    printf("\n");

    while(player_health>0 && enemy_health>0) {
        printf("Your Health: %d\n", player_health);
        printf("Monster's Health: %d\n", enemy_health);
        printf("\n");
        printf("What will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("\n");
        scanf("%d", &player_choice);

        player_attack = rand()%30 + 1;
        enemy_attack = rand()%30 + 1;

        switch(player_choice) {
            case 1: {
                printf("You attack the monster!\n");
                enemy_health -= player_attack;
                printf("You dealt %d damage.\n", player_attack);
                if(enemy_health<=0) {
                    printf("You have defeated the monster!\n");
                    break;
                }
                printf("\n");
                printf("The monster attacks you!\n");
                player_health -= enemy_attack;
                printf("You received %d damage.\n", enemy_attack);
                if(player_health<=0) {
                    printf("You died. Game Over!\n");
                    exit(0);
                }
                printf("\n");
                break;
            }
            case 2: {
                printf("You defend the monster's attack!\n");
                printf("You receive no damage.\n");
                enemy_health -= (player_attack/2);
                if(enemy_health<=0) {
                    printf("You have defeated the monster!\n");
                    break;
                }
                printf("\n");
                printf("The monster attacks you!\n");
                player_health -= (enemy_attack/2);
                printf("You received %d damage.\n", (enemy_attack/2));
                if(player_health<=0) {
                    printf("You died. Game Over!\n");
                    exit(0);
                }
                printf("\n");
                break;
            }
            default: {
                printf("Invalid Choice. Try Again.\n");
                printf("\n");
                break;
            }
        }
    }

    printf("Congratulations! You escaped the dungeon!\n");
    return 0;
}