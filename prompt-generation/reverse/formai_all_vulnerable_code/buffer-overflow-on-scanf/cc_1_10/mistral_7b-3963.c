//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Warehouse is full.\n");
        return;
    }
    strcpy(warehouse[num_items].name, name);
    warehouse[num_items].quantity = quantity;
    num_items++;
}

void remove_item(char *name) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                warehouse[j] = warehouse[j+1];
            }
            num_items--;
            return;
        }
    }
    printf("Error: Item not found in the warehouse.\n");
}

void display_inventory() {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    char command[10];
    char name[MAX_NAME_LEN];
    int quantity, index;

    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            break;
        }
        switch (*command) {
            case 'a':
                scanf("%s%d", name, &quantity);
                add_item(name, quantity);
                break;
            case 'r':
                scanf("%s", name);
                remove_item(name);
                break;
            case 'i':
                display_inventory();
                break;
            case 'l':
                scanf("%s%d", name, &quantity);
                for (int i = 0; i < num_items; i++) {
                    if (strcmp(warehouse[i].name, name) == 0) {
                        if (warehouse[i].quantity < quantity) {
                            printf("Error: Not enough units of %s in the warehouse.\n", name);
                            continue;
                        }
                        warehouse[i].quantity -= quantity;
                        printf("%d units of %s loaded.\n", quantity, name);
                        break;
                    }
                }
                break;
            default:
                printf("Error: Unknown command.\n");
        }
    }

    return 0;
}