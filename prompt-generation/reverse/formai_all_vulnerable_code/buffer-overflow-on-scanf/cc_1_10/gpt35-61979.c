//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print out spaceship status
void printStatus(int health, int fuel, int ammo, int shields) {
    printf("\n==================\n");
    printf("   SHIP STATUS\n");
    printf("==================\n");
    printf("Health: %d\n", health);
    printf("Fuel: %d\n", fuel);
    printf("Ammo: %d\n", ammo);
    printf("Shields: %d\n", shields);
    printf("==================\n\n");
}

// function for battle with alien ship
int alienBattle(int health, int fuel, int ammo, int shields) {

    printf("\nYou encounter an alien ship!\n");

    // randomize alien strength and ammo
    int alienHealth = rand() % 80 + 20;
    int alienAmmo = rand() % 30 + 10;

    while (health > 0 && alienHealth > 0) {
        // player attack
        int playerHit = rand() % 20 + 10;
        int alienDefend = rand() % 10 + 5;
        printf("You attack the alien for %d damage!\n", playerHit - alienDefend);
        alienHealth -= (playerHit - alienDefend);

        // alien attack
        if (alienAmmo > 0) {
            int alienHit = rand() % 20 + 10;
            int playerDefend = rand() % 15 + 10;
            printf("The alien attacks you for %d damage!\n", alienHit - playerDefend);
            health -= (alienHit - playerDefend);
            alienAmmo -= 1;
        } else {
            printf("The alien tries to attack but it's out of ammo!\n");
        }

        printStatus(health, fuel, ammo, shields);

        // check if player and alien both alive
        if (health <= 0) {
            printf("Your ship was destroyed by the alien!\n");
            break;
        } else if (alienHealth <= 0) {
            printf("You defeated the alien and gained some ammo!\n");
            ammo += rand() % 30 + 10;
        }
    }

    return health;
}

// main function
int main() {
    // seed randomizer
    srand(time(0));

    printf("Welcome to Procedural Space Adventure!\n\n");

    // initialize spaceship stats
    int health = 100;
    int fuel = 1000;
    int ammo = 50;
    int shields = 100;

    // start game loop
    while (health > 0) {
        printf("What would you like to do?\n");
        printf("1. Fly to a new planet\n");
        printf("2. Rest and recover\n");
        printf("3. Attack an alien ship\n");
        printf("4. Quit game\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You fly to a new planet!\n");
                // deduct fuel for travel
                fuel -= rand() % 500 + 200;
                // randomize event on planet
                int event = rand() % 3;
                if (event == 0) {
                    printf("You discover a cache of ammo on the planet!\n");
                    ammo += rand() % 30 + 10;
                } else if (event == 1) {
                    printf("You encounter a hostile alien on the planet!\n");
                    health = alienBattle(health, fuel, ammo, shields);
                } else {
                    printf("You find nothing of interest on the planet.\n");
                }
                break;

            case 2:
                printf("You rest and recover!\n");
                // restore health and shields
                health = 100;
                shields = 100;
                break;

            case 3:
                printf("You encounter an alien ship!\n");
                health = alienBattle(health, fuel, ammo, shields);
                break;

            case 4:
                printf("Thanks for playing Procedural Space Adventure!\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

        // deduct fuel for action
        fuel -= rand() % 200 + 100;
        // check if fuel and shield reached critical level
        if (fuel <= 0) {
            printf("You ran out of fuel and are now stranded!\n");
            health = 0;
        } else if (shields <= 0) {
            printf("Your shields have been depleted and your ship is vulnerable!\n");
        }

        printStatus(health, fuel, ammo, shields);
    }

    printf("Game over!\n");
    return 0;
}