//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_health = 100, enemy_health = 50;
    int player_attack = 10, enemy_attack = 5;
    int choice, damage;
    char play_again;

    srand(time(NULL));

    do {
        printf("\nYou are a space adventurer! Your mission is to defeat the enemy ship.\n");
        printf("You have %d health points and your attack power is %d.\n", player_health, player_attack);
        printf("The enemy ship has %d health points and its attack power is %d.\n", enemy_health, enemy_attack);
        printf("What would you like to do?\n");
        printf("1. Attack\n2. Defend\n3. Check health status\n4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                damage = player_attack + rand() % 11 - 5;
                if(damage > 0) {
                    enemy_health -= damage;
                    printf("You attacked the enemy ship and dealt %d damage!\n", damage);
                } else {
                    printf("Your attack missed.\n");
                }
                break;
            case 2:
                damage = rand() % 11 - 5;
                if(damage > 0) {
                    player_health -= damage;
                    printf("The enemy ship attacked you and dealt %d damage!\n", damage);
                } else {
                    printf("The enemy ship missed.\n");
                }
                break;
            case 3:
                printf("Your current health is %d.\n", player_health);
                break;
            case 4:
                printf("Thanks for playing! Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if(player_health <= 0 || enemy_health <= 0) {
            printf("\n%s has been defeated!\n", (player_health <= 0)? "You" : "The enemy ship");
            break;
        }

    } while(play_again = tolower(getchar()) == 'y');

    return 0;
}