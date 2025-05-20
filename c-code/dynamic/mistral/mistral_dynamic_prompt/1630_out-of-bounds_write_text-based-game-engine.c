#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game_over(const char* message) {
    printf("%s\n", message);
    exit(0);
}

void player_action(char* action, int* inventory, int* gold, char* inventory_str) {
    if (strcmp(action, "pick_up") == 0 && inventory[0] < 10) {
        inventory[0]++;
        strcat(inventory_str, " Stone ");
        *gold -= 50;
    } else if (strcmp(action, "use_item") == 0 && inventory[0] > 0) {
        inventory[0]--;
        printf("Used a stone.\n");
    } else if (strcmp(action, "buy_item") == 0 && *gold > 50) {
        *gold -= 50;
        inventory[0]++;
        strcat(inventory_str, " Stone ");
    } else {
        printf("Invalid action.\n");
    }
}

int main() {
        char action[20];
        int inventory[11];
        int gold = 1000;
        char inventory_str[100];

        printf("Welcome to the Stone Mining Adventure!\n");
        printf("Your starting gold: %d\n", gold);

        while (1) {
            printf("> ");
            scanf("%s", action);
            player_action(action, inventory, &gold, inventory_str);
        }

        game_over("Game over. Thank you for playing!");

        return 0;
    }
