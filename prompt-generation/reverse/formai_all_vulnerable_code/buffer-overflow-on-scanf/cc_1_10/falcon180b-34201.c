//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int gold = 0;
    int room = 1;

    // Initialize random seed
    srand(time(NULL));

    // Print starting message
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark room with a door to the north.\n");
    printf("What would you like to do?\n");

    // Main game loop
    while (health > 0) {
        printf("You have %d health and %d gold.\n", health, gold);
        printf("You are in room %d.\n", room);
        printf("What would you like to do?\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You go north through the door.\n");
                if (rand() % 2 == 0) {
                    printf("You find a treasure chest containing 10 gold!\n");
                    gold += 10;
                } else {
                    printf("You are attacked by a monster and lose 10 health!\n");
                    health -= 10;
                }
                break;
            case 2:
                printf("You go south through the door.\n");
                if (rand() % 2 == 0) {
                    printf("You find a potion that restores 10 health!\n");
                    health += 10;
                } else {
                    printf("You fall into a pit and lose 10 health!\n");
                    health -= 10;
                }
                break;
            case 3:
                printf("You exit the game.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    // Print ending message
    if (health <= 0) {
        printf("You have died.\n");
    } else {
        printf("You have won the game!\n");
    }

    return 0;
}