//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Item;

typedef struct {
    Item items[100];
    int count;
} Store;

void addItem(Store *store, char *name, int stock, float price) {
    if (store->count >= 100) {
        printf("Store is full.\n");
        return;
    }

    strcpy(store->items[store->count].name, name);
    store->items[store->count].stock = stock;
    store->items[store->count].price = price;
    store->count++;
}

void displayStore(Store store) {
    printf("*** STORE INVENTORY ***\n");

    for (int i = 0; i < store.count; i++) {
        printf("%s - Stock: %d, Price: %.2f\n", store.items[i].name, store.items[i].stock, store.items[i].price);
    }
}

int main() {
    Store myStore;
    char input[100];

    while (1) {
        printf("\n1. Add item\n2. Display store\n3. Quit\nEnter choice: ");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            char name[50];
            int stock, price;

            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter stock: ");
            scanf("%d", &stock);
            printf("Enter price: ");
            scanf("%f", &price);

            addItem(&myStore, name, stock, price);
        } else if (strcmp(input, "2") == 0) {
            displayStore(myStore);
        } else if (strcmp(input, "3") == 0) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}