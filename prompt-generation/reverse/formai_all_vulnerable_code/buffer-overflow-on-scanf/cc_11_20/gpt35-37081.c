//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Space Adventure game */

int main() {
    // initialize random seed
    srand(time(NULL));

    // define player stats
    int player_health = 100;
    int player_shields = 50;
    int player_ammo = 25;

    // define possible enemies
    char* enemies[] = {"Alien", "Robot", "Meteor"};

    // define possible items
    char* items[] = {"Medkit", "Shield recharge", "Ammo refill"};

    // initialize game loop
    while(player_health > 0) {
        // generate random enemy
        int enemy_index = rand() % 3;
        char* enemy = enemies[enemy_index];

        // generate random item
        int item_index = rand() % 3;
        char* item = items[item_index];

        // print game status
        printf("You have encountered a %s!\n", enemy);
        printf("Your shields are at %d%%.\n", player_shields);
        printf("Your ammo is at %d.\n", player_ammo);

        // init player choice
        int player_choice;

        // prompt player for action
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Use item\n");
        printf("3. Run away\n");

        // get player choice
        scanf("%d", &player_choice);

        // handle player action
        if(player_choice == 1) {
            // attack enemy
            int damage = rand() % 10 + 1;
            printf("You attack the %s and deal %d damage.\n", enemy, damage);

            // reduce enemy health
            player_ammo--;
            if(player_ammo < 0) {
                player_ammo = 0;
            }

            // check if enemy is defeated
            if(damage >= 5) {
                printf("You have defeated the %s!\n", enemy);

                // give loot
                printf("You found a %s!\n", item);
                if(item_index == 0) {
                    player_health += 20;
                    if(player_health > 100) {
                        player_health = 100;
                    }
                    printf("Your health is now at %d.\n", player_health);
                } else if(item_index == 1) {
                    player_shields += 20;
                    if(player_shields > 100) {
                        player_shields = 100;
                    }
                    printf("Your shields are now at %d%%.\n", player_shields);
                } else if(item_index == 2) {
                    player_ammo += 10;
                    printf("Your ammo is now at %d.\n", player_ammo);
                }
            } else {
                // calculate enemy damage
                int enemy_damage = rand() % 5 + 1;

                // reduce player health
                player_health -= enemy_damage;
                printf("The %s attacks you for %d damage.\n", enemy, enemy_damage);

                if(player_health <= 0) {
                    printf("Game over, you have been defeated!\n");
                    return 0;
                }
            }
        } else if(player_choice == 2) {
            // use item
            if(item_index == 0) {
                player_health += 20;
                if(player_health > 100) {
                    player_health = 100;
                }
                printf("You used a medkit and your health is now at %d.\n", player_health);
            } else if(item_index == 1) {
                player_shields += 20;
                if(player_shields > 100) {
                    player_shields = 100;
                }
                printf("You used a shield recharge and your shields are now at %d%%.\n", player_shields);
            } else if(item_index == 2) {
                player_ammo += 10;
                printf("You used an ammo refill and your ammo is now at %d.\n", player_ammo);
            }
        } else if(player_choice == 3) {
            // run away
            printf("You run away from the %s.\n", enemy);
        } else {
            // invalid choice
            printf("Invalid choice, please enter a number between 1 and 3.\n");
        }

        // add line break
        printf("\n");
    }

    // player has lost all health
    printf("Game over, you have been defeated!\n");

    return 0;
}