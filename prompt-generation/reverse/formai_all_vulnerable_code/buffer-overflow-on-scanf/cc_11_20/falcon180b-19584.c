//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *story[] = {
    "You wake up in a dark, damp dungeon. The air is musty and thick with the scent of decay.",
    "You hear the distant sound of footsteps approaching. A hooded figure emerges from the shadows.",
    "The figure hands you a rusty key and whispers, 'This will unlock your cell. But be warned, danger lurks around every corner.'"
};

int main() {
    srand(time(NULL));
    int choice;
    int dungeon_level = 1;
    int health = 100;

    printf("Welcome to the Dungeon of Doom!\n");
    printf("You find yourself trapped in a dark, damp cell. Your only hope of escape is to navigate through the treacherous dungeon and find the exit.\n");
    printf("But beware! Danger lurks around every corner, and one wrong move could mean certain death.\n");
    printf("Are you ready to begin your journey? (y/n) ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        while (health > 0) {
            printf("\nLevel %d\n", dungeon_level);
            printf("%s", story[dungeon_level - 1]);
            printf("\nWhat do you want to do? ");
            scanf("%c", &choice);

            switch (choice) {
                case 'a':
                    printf("You attack the hooded figure.\n");
                    if (rand() % 2 == 0) {
                        printf("You miss and the figure disappears into the shadows.\n");
                    } else {
                        printf("You hit the figure and it falls to the ground, revealing a hidden passage.\n");
                        dungeon_level++;
                    }
                    break;
                case 'b':
                    printf("You search for a hidden passage.\n");
                    if (rand() % 2 == 0) {
                        printf("You find a secret door and enter a new chamber.\n");
                        dungeon_level++;
                    } else {
                        printf("You don't find anything.\n");
                    }
                    break;
                case 'c':
                    printf("You try to pick the lock on your cell door.\n");
                    if (rand() % 2 == 0) {
                        printf("You successfully pick the lock and escape your cell.\n");
                        dungeon_level++;
                    } else {
                        printf("You fail to pick the lock and remain trapped in your cell.\n");
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
            }

            if (health <= 0) {
                printf("\nYou have died.\n");
                exit(0);
            }
        }

        printf("\nCongratulations! You have escaped the Dungeon of Doom!\n");
    } else {
        printf("\nGoodbye!");
    }

    return 0;
}