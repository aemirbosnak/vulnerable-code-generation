//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 99

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int top = 0;

void error(const char *msg) {
    fprintf(stderr, "%s: %s\n", __func__, msg);
    exit(1);
}

void push_product(const char *name, int quantity) {
    if (top >= MAX_PRODUCTS)
        error("Inventory is full");
    strcpy(inventory[top].name, name);
    inventory[top].quantity = quantity;
    top++;
}

void pop_product() {
    if (top <= 0)
        error("Inventory is empty");
    top--;
}

void print_inventory() {
    for (int i = 0; i < top; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main(void) {
    char cmd[100];
    char name[MAX_NAME_LEN];
    int quantity, action;

    while (1) {
        printf("> ");
        fgets(cmd, sizeof(cmd), stdin);
        sscanf(cmd, "%s %n", cmd, &quantity);

        if (*cmd == 'q' || *cmd == 'Q') {
            print_inventory();
            exit(0);
        }

        if (sscanf(cmd, "%s %n %d %n", name, &quantity, &action, &quantity) != 3) {
            fprintf(stderr, "Invalid command: %s\n", cmd);
            continue;
        }

        switch (action) {
        case 'a':
            push_product(name, quantity);
            break;
        case 'r':
            for (int i = 0; i < top; i++) {
                if (strcmp(inventory[i].name, name) == 0) {
                    inventory[i].quantity += quantity;
                    break;
                }
            }
            break;
        case 't':
            for (int i = 0; i < top; i++) {
                if (strcmp(inventory[i].name, name) == 0) {
                    inventory[i].quantity -= quantity;
                    if (inventory[i].quantity < 0) {
                        fprintf(stderr, "Insufficient quantity: %s\n", name);
                        break;
                    }
                    break;
                }
            }
            break;
        default:
            fprintf(stderr, "Invalid action: %c\n", action);
            continue;
        }
    }

    return 0;
}