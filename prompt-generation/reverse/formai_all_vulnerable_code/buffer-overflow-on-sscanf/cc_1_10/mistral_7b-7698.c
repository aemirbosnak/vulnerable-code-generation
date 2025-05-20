//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEMS 100
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(char* name, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("The Baker Street Irregulars inventory is full.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].quantity = quantity;
    num_items++;
}

void remove_item(char* name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                strcpy(items[j].name, items[j+1].name);
                items[j].quantity = items[j+1].quantity;
            }
            num_items--;
            return;
        }
    }

    printf("There is no item with the name %s in the inventory.\n", name);
}

void print_inventory() {
    printf("\nThe Baker Street Irregulars current inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d\n", items[i].name, items[i].quantity);
    }
}

int main() {
    char command[50], name[MAX_ITEM_NAME_LENGTH];
    int quantity, index;

    while (1) {
        printf("\nEnter a command (add/remove/quit/print): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "quit") == 0) {
            break;
        }

        sscanf(command, "%s %s %d", command, name, &quantity);

        if (strcmp(command, "add") == 0) {
            add_item(name, quantity);
        } else if (strcmp(command, "remove") == 0) {
            remove_item(name);
        } else if (strcmp(command, "print") == 0) {
            print_inventory();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}