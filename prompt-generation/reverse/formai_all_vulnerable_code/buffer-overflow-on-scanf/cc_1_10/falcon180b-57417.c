//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    int choice;
    int player_health = 100;
    int alien_health = 100;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the alien invasion.\n");
    printf("Choose your weapon:\n");
    printf("1. Laser gun\n");
    printf("2. Plasma rifle\n");
    printf("3. Rocket launcher\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have chosen the laser gun.\n");
            break;
        case 2:
            printf("You have chosen the plasma rifle.\n");
            break;
        case 3:
            printf("You have chosen the rocket launcher.\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    int weapon_damage = rand() % 21 + 10;
    printf("Your weapon deals %d damage.\n", weapon_damage);

    while(player_health > 0 && alien_health > 0) {
        printf("You encounter an alien.\n");
        int alien_attack = rand() % 21 + 10;
        printf("The alien attacks you with %d damage.\n", alien_attack);
        player_health -= alien_attack;

        if(player_health <= 0) {
            printf("You have been defeated by the alien.\n");
            return 0;
        }

        printf("You attack the alien with your %s.\n", (choice == 1)? "laser gun" : (choice == 2)? "plasma rifle" : "rocket launcher");
        alien_health -= weapon_damage;

        if(alien_health <= 0) {
            printf("You have defeated the alien.\n");
            return 0;
        }
    }
}