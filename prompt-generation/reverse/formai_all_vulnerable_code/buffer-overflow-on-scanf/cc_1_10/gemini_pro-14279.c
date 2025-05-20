//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_LOCATION_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char location[MAX_LOCATION_LEN];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, char *location, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Warehouse is full.\n");
        return;
    }

    strcpy(inventory[num_items].name, name);
    strcpy(inventory[num_items].location, location);
    inventory[num_items].quantity = quantity;

    num_items++;
}

void remove_item(char *name) {
    int i;

    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_items) {
        printf("Error: Item not found.\n");
        return;
    }

    for (; i < num_items - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    num_items--;
}

void print_inventory() {
    int i;

    for (i = 0; i < num_items; i++) {
        printf("%s\t%s\t%d\n", inventory[i].name, inventory[i].location, inventory[i].quantity);
    }
}

int main() {
    char command[50];
    char name[MAX_NAME_LEN];
    char location[MAX_LOCATION_LEN];
    int quantity;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %s %d", name, location, &quantity);
            add_item(name, location, quantity);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s", name);
            remove_item(name);
        } else if (strcmp(command, "print") == 0) {
            print_inventory();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}