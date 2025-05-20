//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int count = 0;

void add_item(char *name, int qty) {
    if (count >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }
    strcpy(warehouse[count].name, name);
    warehouse[count].quantity = qty;
    count++;
}

void remove_item(char *name) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            for (; i < count - 1; i++) {
                warehouse[i] = warehouse[i + 1];
            }
            count--;
            return;
        }
    }
    printf("Item not found in the warehouse!\n");
}

void view_items() {
    int i;
    printf("Items in the warehouse:\n");
    for (i = 0; i < count; i++) {
        printf("%s: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    char cmd[20], name[50], temp[50];
    int qty, i;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("Enter command (add/remove/view/quit): ");
        scanf("%s", cmd);

        if (strcmp(cmd, "quit") == 0) {
            break;
        }

        switch (*cmd) {
        case 'a':
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &qty);
            add_item(name, qty);
            break;

        case 'r':
            printf("Enter item name: ");
            scanf("%s", name);
            remove_item(name);
            break;

        case 'v':
            view_items();
            break;

        default:
            printf("Invalid command!\n");
        }
    }

    return 0;
}