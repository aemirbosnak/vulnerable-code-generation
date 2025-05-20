//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char quantity[MAX_QUANTITY_LEN];
    char price[MAX_PRICE_LEN];
} Item;

void print_item(const Item *item) {
    printf("Name: %s\n", item->name);
    printf("Quantity: %s\n", item->quantity);
    printf("Price: %s\n", item->price);
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("Enter name, quantity, and price for item (or \"done\" to finish):\n");
        char input[100];
        fgets(input, sizeof(input), stdin);
        char *token = strtok(input, " ");
        if (strcmp(token, "done") == 0) {
            break;
        } else if (num_items >= MAX_ITEMS) {
            printf("Error: Too many items.\n");
            return 1;
        }
        strcpy(items[num_items].name, token);
        token = strtok(NULL, " ");
        strcpy(items[num_items].quantity, token);
        token = strtok(NULL, " ");
        strcpy(items[num_items].price, token);
        num_items++;
    }

    printf("Warehouse inventory:\n");
    for (int i = 0; i < num_items; i++) {
        print_item(&items[i]);
    }

    return 0;
}