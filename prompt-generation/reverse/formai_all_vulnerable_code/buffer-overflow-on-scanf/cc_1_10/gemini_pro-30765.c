//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int quantity, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Warehouse is full.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].quantity = quantity;
    items[num_items].price = price;

    num_items++;
}

void remove_item(char *name) {
    int i;

    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_items) {
        printf("Error: Item not found.\n");
        return;
    }

    for (i++; i < num_items; i++) {
        items[i - 1] = items[i];
    }

    num_items--;
}

void print_items() {
    int i;

    for (i = 0; i < num_items; i++) {
        printf("%s %d %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    char command[50];
    char name[50];
    int quantity;
    float price;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d %f", name, &quantity, &price);
            add_item(name, quantity, price);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s", name);
            remove_item(name);
        } else if (strcmp(command, "print") == 0) {
            print_items();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}