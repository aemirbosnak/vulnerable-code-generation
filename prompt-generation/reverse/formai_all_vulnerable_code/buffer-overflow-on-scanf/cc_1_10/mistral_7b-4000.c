//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Item;

typedef struct {
    int id;
    char name[50];
    Item items[10];
    int num_items;
} Store;

void add_item(Store* store, char* name, int stock, float price) {
    if (store->num_items >= 10) {
        printf("Store is full.\n");
        return;
    }
    strcpy(store->items[store->num_items].name, name);
    store->items[store->num_items].stock = stock;
    store->items[store->num_items].price = price;
    store->num_items++;
}

void display_store(Store store) {
    printf("Store ID: %d\n", store.id);
    printf("Name: %s\n", store.name);
    printf("Items:\n");
    for (int i = 0; i < store.num_items; i++) {
        printf("Item %d: %s, Stock: %d, Price: %.2f\n", i + 1, store.items[i].name, store.items[i].stock, store.items[i].price);
    }
}

int main() {
    Store my_store = {.id = 1, .name = "My Medical Store"};
    char item_name[50];
    int item_stock;
    float item_price;

    add_item(&my_store, "Paracetamol", 50, 5.50);
    add_item(&my_store, "Ibuprofen", 30, 7.50);
    add_item(&my_store, "Aspirin", 20, 3.50);
    add_item(&my_store, "Bandage", 25, 1.50);

    display_store(my_store);

    printf("\nAdding new item:\n");
    printf("Name: ");
    scanf("%s", item_name);
    printf("Stock: ");
    scanf("%d", &item_stock);
    printf("Price: ");
    scanf("%f", &item_price);

    add_item(&my_store, item_name, item_stock, item_price);

    display_store(my_store);

    return 0;
}