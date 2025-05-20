//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int ship_health = 100;
    int enemy_health = 100;
    int damage;
    int player_score = 0;
    int enemy_score = 0;
    char play_again;

    srand(time(NULL));

    printf("Welcome to the Space Adventure!\n");
    printf("You are the captain of a spaceship. Your mission is to defeat the enemy ship.\n");
    printf("Choose your move:\n");
    printf("1. Attack\n2. Defend\n");

    scanf("%d", &choice);

    while(1) {
        if(choice == 1) {
            damage = rand() % 10 + 1;
            printf("You attacked the enemy ship and dealt %d damage!\n", damage);
            enemy_health -= damage;

            if(enemy_health <= 0) {
                printf("Congratulations! You have defeated the enemy ship!\n");
                player_score++;
                break;
            }
        }
        else if(choice == 2) {
            damage = rand() % 10 + 1;
            printf("You defended your ship and reduced the enemy's attack by %d damage!\n", damage);
            ship_health -= damage;

            if(ship_health <= 0) {
                printf("Game Over! The enemy ship has defeated you.\n");
                enemy_score++;
                break;
            }
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }

        if(player_score == 3 || enemy_score == 3) {
            printf("The game is tied. Do you want to play again? (y/n)\n");
            scanf(" %c", &play_again);

            if(play_again == 'n') {
                printf("Thanks for playing!\n");
                exit(0);
            }
            else {
                printf("Resetting game...\n");
                player_score = 0;
                enemy_score = 0;
                ship_health = 100;
                enemy_health = 100;
            }
        }
    }

    return 0;
}