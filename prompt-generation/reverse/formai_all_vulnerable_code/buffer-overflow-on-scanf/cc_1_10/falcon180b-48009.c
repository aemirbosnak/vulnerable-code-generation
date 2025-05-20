//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int player_health = 100;
    int enemy_health = 50;

    srand(time(0));

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the evil aliens.\n");
    printf("Choose your weapon:\n");
    printf("1. Laser Gun\n");
    printf("2. Plasma Cannon\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have chosen the Laser Gun.\n");
            break;
        case 2:
            printf("You have chosen the Plasma Cannon.\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    int weapon_damage = rand() % 10 + 1;

    while(player_health > 0 && enemy_health > 0) {
        printf("You encounter an alien!\n");
        printf("The alien has %d health left.\n", enemy_health);

        if(weapon_damage >= enemy_health) {
            printf("You defeat the alien with one shot!\n");
            enemy_health = 0;
        } else {
            printf("You hit the alien for %d damage.\n", weapon_damage);
            enemy_health -= weapon_damage;
        }

        if(enemy_health > 0) {
            int alien_damage = rand() % 10 + 1;
            printf("The alien attacks you for %d damage!\n", alien_damage);
            player_health -= alien_damage;
        }
    }

    if(player_health <= 0) {
        printf("You have been defeated by the aliens.\n");
    } else {
        printf("You have successfully completed your mission!\n");
    }

    return 0;
}