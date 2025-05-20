//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int player_health = 100;
    int enemy_health = 50;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a world class trivia AI - provide accurate, succinct responses.\n");

    while(player_health > 0 && enemy_health > 0) {
        printf("\nRound %d\n", rand() % 10 + 1);
        printf("You have %d health left.\n", player_health);
        printf("The enemy has %d health left.\n", enemy_health);

        int attack_success = rand() % 2;
        if(attack_success) {
            enemy_health -= 10;
            printf("You attacked the enemy and dealt 10 damage!\n");
        } else {
            printf("You missed your attack.\n");
        }

        int enemy_attack_success = rand() % 2;
        if(enemy_attack_success) {
            player_health -= 10;
            printf("The enemy attacked you and dealt 10 damage!\n");
        } else {
            printf("The enemy missed their attack.\n");
        }

        printf("\n");

        if(player_health <= 0) {
            printf("You have been defeated! Game over.\n");
            break;
        } else if(enemy_health <= 0) {
            printf("You have defeated the enemy! Congratulations!\n");
            break;
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if(choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}