//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int romeo_health = 100;
    int juliet_health = 100;
    int ghost_health = 100;
    int ghost_damage = 10;
    int sword_damage = 20;
    int potion_heal = 30;
    int current_room = 1;
    int romeo_room = 1;
    int juliet_room = 10;
    int ghost_room = 0;
    char romeo_action[50];
    char juliet_action[50];
    char ghost_action[50];

    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are Romeo, and your goal is to find Juliet and escape the haunted house together.\n");
    printf("Juliet is waiting for you in room 10, but be careful! There is a ghost haunting the house.\n");
    printf("The ghost moves randomly between rooms, and will attack you if it finds you.\n");
    printf("You have a sword that deals 20 damage, and you can find potions that heal 30 health.\n");
    printf("Good luck!\n\n");

    while (romeo_health > 0) {
        printf("You are in room %d.\n", current_room);
        printf("What would you like to do? (move, attack, use potion)\n");
        scanf("%s", romeo_action);

        if (strcmp(romeo_action, "move") == 0) {
            printf("You move to the next room.\n");
            current_room++;

            if (current_room == juliet_room) {
                printf("You found Juliet! You both escape the haunted house together.\n");
                return 0;
            }

            if (current_room == ghost_room) {
                printf("The ghost attacks you! You lose %d health.\n", ghost_damage);
                romeo_health -= ghost_damage;
                ghost_room = 0;
            }

            if (current_room > 10 && current_room < 20) {
                printf("You find a potion! You gain %d health.\n", potion_heal);
                romeo_health += potion_heal;
            }
        } else if (strcmp(romeo_action, "attack") == 0) {
            printf("You prepare to attack.\n");
        } else if (strcmp(romeo_action, "use potion") == 0) {
            printf("You use a potion and gain %d health.\n", potion_heal);
            romeo_health += potion_heal;
        }

        if (current_room == ghost_room) {
            printf("The ghost sees you! It attacks you.\n");
            romeo_health -= ghost_damage;
        }

        if (romeo_health <= 0) {
            printf("You died.\n");
            return 0;
        }

        if (current_room == juliet_room) {
            printf("You found Juliet! You both escape the haunted house together.\n");
            return 0;
        }
    }

    return 0;
}