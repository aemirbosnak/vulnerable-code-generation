//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int stock;
    struct product *next;
} product;

product *head = NULL;

void add_product(char *name, int stock);
void remove_product(char *name);
void view_inventory();

int main() {
    char command[10], name[50];
    int stock, choice;

    while (1) {
        printf("Enter command (add/remove/view/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter product stock: ");
            scanf("%d", &stock);
            add_product(name, stock);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            remove_product(name);
        } else if (strcmp(command, "view") == 0) {
            view_inventory();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

void add_product(char *name, int stock) {
    product *new_product = (product *) malloc(sizeof(product));

    if (new_product == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    strcpy(new_product->name, name);
    new_product->stock = stock;
    new_product->next = head;
    head = new_product;

    printf("Product added successfully.\n");
}

void remove_product(char *name) {
    product *current = head, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Product removed successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: Product not found in inventory.\n");
}

void view_inventory() {
    product *current = head;

    printf("\nCurrent inventory:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->stock);
        current = current->next;
    }
}