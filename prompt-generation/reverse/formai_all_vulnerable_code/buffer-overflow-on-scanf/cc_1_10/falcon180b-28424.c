//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int player_health = 100;
    int enemy_health = 50;

    char player_attack = 'S';
    char enemy_attack = 'K';

    int player_score = 0;
    int enemy_score = 0;

    char game_status = 'P';

    while(game_status!= 'E') {
        system("clear");

        printf("\nPlayer Health: %d\n", player_health);
        printf("Enemy Health: %d\n", enemy_health);
        printf("Player Score: %d\n", player_score);
        printf("Enemy Score: %d\n", enemy_score);

        if(game_status == 'P') {
            printf("\nYour Turn\n");

            char player_choice;
            scanf("%c", &player_choice);

            if(player_choice == player_attack) {
                enemy_health -= 10;
                if(enemy_health <= 0) {
                    printf("\nYou Win!!!\n");
                    game_status = 'E';
                }
            } else {
                printf("\nMissed\n");
            }
        } else {
            int random_number = rand() % 2;

            if(random_number == 0) {
                enemy_score += 10;
                printf("\nEnemy Scores!!!\n");
            } else {
                printf("\nMissed\n");
            }
        }

        if(player_health <= 0) {
            printf("\nYou Lose!!!\n");
            game_status = 'E';
        }
    }

    return 0;
}