//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int room = 1, coins = 0, keys = 0;
    int health = 100, max_health = 100;
    int sword = 0, ghost_defeated = 0;
    printf("Welcome to the Haunted House Simulator!\n\n");

    while (room <= 10 && health > 0) {
        printf("You are currently in room %d.\n", room);
        int event = rand() % 4;
        switch(event) {
            case 0:
                printf("It's just an empty room. Nothing to see here.\n");
                break;
            case 1:
                printf("You find a chest with %d coins!\n", rand() % 50 + 1);
                coins += rand() % 50 + 1;
                break;
            case 2:
                printf("You find a key!\n");
                keys++;
                break;
            case 3:
                printf("A ghost attacks you!\n");
                if (sword == 1) {
                    printf("But you have a sword and defeat the ghost.\n");
                    ghost_defeated = 1;
                } else {
                    printf("You try to run, but the ghost drains 20 health points.\n");
                    health -= 20;
                }
                break;
        }
        if (ghost_defeated == 1 && room == 10) {
            printf("Congratulations, you made it out of the haunted house with %d coins and %d keys!", coins, keys);
            return 0;
        }
        printf("You have %d health points and %d coins.\n", health, coins);
        if (health < max_health) {
            int heal_chance = rand() % 3;
            if (heal_chance == 0) {
                printf("You find a healing potion and restore 10 health points!\n");
                health += 10;
                if (health > max_health) {
                    health = max_health;
                }
            }
        }
        int choice;
        printf("Enter 1 to continue to the next room or 2 to quit and leave the haunted house.\n");
        scanf("%d", &choice);
        if (choice == 2) {
            printf("You quit the haunted house with %d coins and %d keys.\n", coins, keys);
            return 0;
        }
        room++;
    }
    printf("You have reached the end of the haunted house, but you did not defeat the ghost and cannot escape. GAME OVER.\n");
    return 0;
}