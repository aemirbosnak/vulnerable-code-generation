//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    char choice;

    while(player_health > 0 && enemy_health > 0) {
        printf("You have %d health remaining.\n", player_health);
        printf("The enemy has %d health remaining.\n\n", enemy_health);
        printf("What would you like to do?\n");
        printf("A) Attack\n");
        printf("B) Defend\n");
        printf("C) Rest\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                if(rand() % 2 == 0) {
                    printf("You landed a hit! Enemy health: %d\n", enemy_health);
                    enemy_health -= 10;
                } else {
                    printf("You missed.\n");
                }
                break;
            case 'B':
                if(rand() % 2 == 0) {
                    printf("You successfully defended! You take no damage.\n");
                } else {
                    printf("You failed to defend. You take 5 damage.\n");
                    player_health -= 5;
                }
                break;
            case 'C':
                printf("You rested and regained 5 health.\n");
                player_health += 5;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    if(player_health <= 0) {
        printf("You have been defeated by the enemy.\n");
    } else {
        printf("You have defeated the enemy.\n");
    }

    return 0;
}