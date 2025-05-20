//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct item {
    char name[20];
    int quantity;
    float price;
} item_t;

item_t items[MAX_ITEMS];

void init_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].quantity = 0;
        items[i].price = 0.0f;
    }
}

void add_item(char *name, int quantity, float price) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Warehouse is full!\n");
}

void update_item(char *name, int quantity) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = quantity;
            return;
        }
    }

    printf("Error: Item not found!\n");
}

void list_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s: %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    init_items();

    // Multiplayer interaction
    char command[20];
    printf("Enter command (add, update, list): ");
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
        char name[20];
        int quantity;
        float price;
        printf("Enter item name: ");
        scanf("%s", name);
        printf("Enter item quantity: ");
        scanf("%d", &quantity);
        printf("Enter item price: ");
        scanf("%f", &price);
        add_item(name, quantity, price);
    } else if (strcmp(command, "update") == 0) {
        char name[20];
        int quantity;
        printf("Enter item name: ");
        scanf("%s", name);
        printf("Enter new item quantity: ");
        scanf("%d", &quantity);
        update_item(name, quantity);
    } else if (strcmp(command, "list") == 0) {
        list_items();
    } else {
        printf("Error: Invalid command.\n");
    }

    return 0;
}