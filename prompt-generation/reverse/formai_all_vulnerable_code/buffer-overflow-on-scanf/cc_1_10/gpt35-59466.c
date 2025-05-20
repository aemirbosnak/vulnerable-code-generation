//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the coolest game ever!\n");
    printf("You are about to embark on a thrilling adventure where you will need to slay dragons, loot treasure, and become a hero!\n");

    int player_health = 100;
    int dragon_health = 150;
    int player_damage = 25;
    int dragon_damage = 20;
    int player_gold = 0;

    printf("Your starting health is %d\n", player_health);
    printf("You have no gold to start with\n");

    char choice;

    while (player_health > 0 && dragon_health > 0) {
        printf("Do you want to attack the dragon or flee?\n");
        scanf(" %c", &choice);

        if (choice == 'a') {
            printf("You attack the dragon and deal %d damage!\n", player_damage);
            dragon_health -= player_damage;

            if (dragon_health <= 0) {
                printf("You slay the dragon and win the game!\n");
                player_gold += 200;
                printf("You earn 200 gold for your victory!\n");
                break;
            }

            printf("The dragon retaliates and deals %d damage!\n", dragon_damage);
            player_health -= dragon_damage;

            if (player_health <= 0) {
                printf("The dragon kills you and you lose the game!\n");
                break;
            }
        } else if (choice == 'f') {
            printf("You run away, but the dragon chases you down and deals %d damage!\n", dragon_damage);
            player_health -= dragon_damage;

            if (player_health <= 0) {
                printf("The dragon kills you and you lose the game!\n");
                break;
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    if (player_gold > 0) {
        printf("You have %d gold in your pocket!\n", player_gold);
    }

    return 0;
}