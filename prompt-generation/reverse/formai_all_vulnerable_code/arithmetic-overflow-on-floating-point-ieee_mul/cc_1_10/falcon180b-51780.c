//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
    float total_price;
} item;

void add_item(item *items, int num_items) {
    printf("Enter name of item: ");
    scanf("%s", items[num_items].name);
    printf("Enter price per unit: ");
    scanf("%f", &items[num_items].price);
    printf("Enter quantity: ");
    scanf("%d", &items[num_items].quantity);
    items[num_items].total_price = items[num_items].price * items[num_items].quantity;
    num_items++;
}

void display_items(item *items, int num_items) {
    printf("Item Name\tPrice\tQuantity\tTotal Price\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\t%.2f\n", items[i].name, items[i].price, items[i].quantity, items[i].total_price);
    }
}

void delete_item(item *items, int num_items) {
    printf("Enter name of item to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            num_items--;
            for (int j = i; j < num_items; j++) {
                items[j] = items[j+1];
            }
            break;
        }
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;
    int choice;

    do {
        printf("1. Add item\n2. Display items\n3. Delete item\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, num_items);
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                delete_item(items, num_items);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}