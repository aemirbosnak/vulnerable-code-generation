#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_inventory(int inventory[]) {
    int i;
    printf("\nInventory:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");
}

void add_to_inventory(int inventory[], char input[]) {
    int index = atoi(input);
    if (index >= 0 && index < 10) {
        inventory[index]++;
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    int inventory[10] = {0};
    char input[10];

    while (1) {
        printf("\nEnter action (add <index> or show):\n");
        scanf("%s", input);

        if (!strcmp(input, "add")) {
            printf("Enter index:\n");
            scanf("%s", input);
            add_to_inventory(inventory, input);
            display_inventory(inventory);
        } else if (!strcmp(input, "show")) {
            display_inventory(inventory);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
