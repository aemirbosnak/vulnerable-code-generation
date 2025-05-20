//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    int price;
};

struct warehouse {
    struct item items[MAX_ITEMS];
    int size;
};

void print_item(struct item i) {
    printf("%s - %d units at $%d each\n", i.name, i.quantity, i.price);
}

void print_warehouse(struct warehouse w) {
    printf("Warehouse inventory:\n");
    for (int i = 0; i < w.size; i++) {
        print_item(w.items[i]);
    }
}

void add_item(struct warehouse *w, char *name, int quantity, int price) {
    if (w->size == MAX_ITEMS) {
        printf("Warehouse is full\n");
        return;
    }
    strcpy(w->items[w->size].name, name);
    w->items[w->size].quantity = quantity;
    w->items[w->size].price = price;
    w->size++;
    printf("Added %d units of %s to warehouse at $%d each\n", quantity, name, price);
}

void remove_item(struct warehouse *w, char *name, int quantity) {
    for (int i = 0; i < w->size; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            if (w->items[i].quantity < quantity) {
                printf("Not enough %s in warehouse\n", name);
                return;
            }
            w->items[i].quantity -= quantity;
            printf("Removed %d units of %s from warehouse\n", quantity, name);
            if (w->items[i].quantity == 0) {
                printf("%s is now out of stock\n", name);
            }
            return;
        }
    }
    printf("%s not found in warehouse\n", name);
}

int main() {
    struct warehouse w = {0};

    printf("Welcome to warehouse management system\n");
    printf("Type 'help' for list of commands\n");

    while (1) {
        char command[100];
        printf("> ");
        fgets(command, 100, stdin);
        command[strlen(command) - 1] = '\0'; // remove newline character

        if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("add ITEM_NAME QUANTITY PRICE\n");
            printf("remove ITEM_NAME QUANTITY\n");
            printf("inventory\n");
            printf("exit\n");
        }
        else if (strncmp(command, "add ", 4) == 0) {
            char name[MAX_NAME_LENGTH];
            int quantity;
            int price;
            sscanf(command + strlen("add "), "%s %d %d", name, &quantity, &price);
            add_item(&w, name, quantity, price);
        }
        else if (strncmp(command, "remove ", 7) == 0) {
            char name[MAX_NAME_LENGTH];
            int quantity;
            sscanf(command + strlen("remove "), "%s %d", name, &quantity);
            remove_item(&w, name, quantity);
        }
        else if (strcmp(command, "inventory") == 0) {
            print_warehouse(w);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Unknown command\n");
        }
    }

    return 0;
}