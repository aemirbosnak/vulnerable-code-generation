//FormAI DATASET v1.0 Category: Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds) {
    long pause;
    clock_t now, then;
  
    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause) {
        now = clock();
    }
}
  
int main() {
    int player_health = 100;
    int enemy_health = 100;
    int player_attack, enemy_attack;
    int turn = 1;
    int victory = 0;
  
    srand(time(NULL));
  
    printf("Welcome to the Cyberpunk Arena!\n\n");
    printf("You are facing a deadly enemy, and must fight for your life!\n\n");

    while (victory == 0) {
        printf("-----\n");

        if (turn == 1) {
            printf("Your turn!\n");
            printf("Choose your attack (1-3):\n");
            printf("1. Quick Slash\n");
            printf("2. Power Strike\n");
            printf("3. Maelstrom\n");

            scanf("%d", &player_attack);

            switch (player_attack) {
                case 1:
                    printf("You use Quick Slash!\n");
                    enemy_health -= 10;
                    delay(1000);
                    break;
                case 2:
                    printf("You use Power Strike!\n");
                    enemy_health -= 20;
                    delay(1000);
                    break;
                case 3:
                    printf("You use Maelstrom!\n");
                    enemy_health -= 30;
                    delay(1000);
                    break;
                default:
                    printf("Invalid choice!\n");
                    delay(1000);
                    continue;
            }

            if (enemy_health <= 0) {
                victory = 1;
                break;
            }

            turn = 2;
            printf("-----\n");
        }
        else {
            printf("Enemy's turn!\n");

            enemy_attack = rand() % 3 + 1;

            switch (enemy_attack) {
                case 1:
                    printf("Enemy uses Quick Slash!\n");
                    player_health -= 10;
                    delay(1000);
                    break;
                case 2:
                    printf("Enemy uses Power Strike!\n");
                    player_health -= 20;
                    delay(1000);
                    break;
                case 3:
                    printf("Enemy uses Maelstrom!\n");
                    player_health -= 30;
                    delay(1000);
                    break;
                default:
                    printf("Invalid choice!\n");
                    delay(1000);
                    continue;
            }

            if (player_health <= 0) {
                printf("You have been defeated...\n");
                break;
            }

            turn = 1;
            printf("-----\n");
        }

        printf("Player health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);
    }

    if (victory == 1) {
        printf("Congratulations! You have defeated your enemy and saved your life.\n");
    }

    return 0;
}