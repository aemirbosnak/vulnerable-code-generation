//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    int player_attack = rand() % 10 + 1;
    int enemy_attack = rand() % 10 + 1;

    printf("Welcome to the space adventure!\n");
    printf("You are a space warrior with %d health points.\n", player_health);
    printf("Your attack power is %d.\n", player_attack);

    int choice;
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n2. Defend\n3. Heal\n4. Check health\n5. Check enemy health\n6. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enemy_health -= player_attack;
                if(enemy_health <= 0) {
                    printf("You have defeated the enemy!\n");
                    break;
                }
                else {
                    printf("You attacked the enemy and dealt %d damage.\n", player_attack);
                    printf("The enemy has %d health left.\n", enemy_health);
                }
                break;
            case 2:
                player_health -= enemy_attack;
                if(player_health <= 0) {
                    printf("You have been defeated by the enemy.\n");
                    break;
                }
                else {
                    printf("You defended yourself and took %d damage.\n", enemy_attack);
                    printf("You have %d health left.\n", player_health);
                }
                break;
            case 3:
                player_health += rand() % 10 + 1;
                printf("You healed yourself and gained %d health.\n", player_health - 100);
                break;
            case 4:
                printf("Your current health is %d.\n", player_health);
                break;
            case 5:
                printf("The enemy's current health is %d.\n", enemy_health);
                break;
            case 6:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}