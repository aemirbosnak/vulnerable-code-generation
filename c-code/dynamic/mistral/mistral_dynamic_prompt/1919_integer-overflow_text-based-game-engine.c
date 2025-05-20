#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void game() {
    char name[BUFFER_SIZE];
    int health = 100;
    int maxHealth = 100;

    printf("Welcome to Dungeon Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while (1) {
        printf("%s, you have %d health left. Enter a command:\n", name, health);
        char command[BUFFER_SIZE];
        scanf("%s", command);

        if (strcmp(command, "attack") == 0) {
            int target;
            printf("Enter the ID of the monster you want to attack: ");
            scanf("%d", &target);

            if (target > maxHealth || target < 1) {
                printf("Invalid ID.\n");
                continue;
            }

            health += 10; // OVERFLOW VULNERABILITY HERE
            maxHealth += 10; // OVERFLOW VULNERABILITY HERE
            printf("You attack the monster and gain 10 health.\n");

        } else if (strcmp(command, "run") == 0) {
            health -= 10;
            printf("You run away and lose 10 health.\n");

        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye, %s! Hope you had fun!\n", name);
            return;

        } else {
            printf("Invalid command.\n");
        }

        if (health <= 0) {
            printf("%s, you have died.\n", name);
            return;
        }
    }
}

int main() {
    game();
    return 0;
}
