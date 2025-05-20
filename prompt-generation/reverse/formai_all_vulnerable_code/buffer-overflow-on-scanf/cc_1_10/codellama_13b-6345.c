//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100
#define MAX_NAME_LEN 25
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
    int quantity;
} StockItem;

void addStock(StockItem *items, int *stockCount, char *name, int price) {
    if (*stockCount >= MAX_STOCK) {
        printf("Cannot add more items, stock is full.\n");
        return;
    }
    strcpy(items[*stockCount].name, name);
    items[*stockCount].price = price;
    items[*stockCount].quantity = 0;
    *stockCount += 1;
}

void removeStock(StockItem *items, int *stockCount, char *name) {
    for (int i = 0; i < *stockCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i] = items[*stockCount - 1];
            *stockCount -= 1;
            return;
        }
    }
    printf("Item not found.\n");
}

void updateStock(StockItem *items, int *stockCount, char *name, int quantity) {
    for (int i = 0; i < *stockCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity += quantity;
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    StockItem items[MAX_STOCK];
    int stockCount = 0;
    char name[MAX_NAME_LEN];
    int price;
    int quantity;
    char command;

    while (1) {
        printf("Enter command (a)dd, (r)emove, (u)pdate, or (q)uit: ");
        scanf(" %c", &command);

        if (command == 'a') {
            printf("Enter name and price: ");
            scanf("%s %d", name, &price);
            addStock(items, &stockCount, name, price);
        } else if (command == 'r') {
            printf("Enter name: ");
            scanf("%s", name);
            removeStock(items, &stockCount, name);
        } else if (command == 'u') {
            printf("Enter name and quantity: ");
            scanf("%s %d", name, &quantity);
            updateStock(items, &stockCount, name, quantity);
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}