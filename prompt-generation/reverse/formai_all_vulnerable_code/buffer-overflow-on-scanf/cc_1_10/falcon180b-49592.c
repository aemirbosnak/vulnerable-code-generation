//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} item;

void add_item(item *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);
    (*num_items)++;
}

void display_items(item *items, int num_items) {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void search_item(item *items, int num_items) {
    printf("\nEnter item name to search: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("\nItem found:\n");
            printf("%s - $%.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
        }
    }
}

void update_item(item *items, int num_items) {
    printf("\nEnter item name to update: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("\nEnter new item name: ");
            scanf("%s", items[i].name);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
        }
    }
}

void delete_item(item *items, int *num_items) {
    printf("\nEnter item name to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < *num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < *num_items - 1; j++) {
                items[j] = items[j+1];
            }
            (*num_items)--;
        }
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    add_item(items, &num_items);
    display_items(items, num_items);
    search_item(items, num_items);
    update_item(items, num_items);
    delete_item(items, &num_items);

    return 0;
}