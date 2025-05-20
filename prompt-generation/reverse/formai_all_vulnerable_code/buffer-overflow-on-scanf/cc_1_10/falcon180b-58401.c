//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    int item_id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Item;

void add_item(Item items[], int num_items) {
    printf("Enter item ID: ");
    scanf("%d", &items[num_items].item_id);

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item description: ");
    scanf("%s", items[num_items].description);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    num_items++;
}

void print_items(Item items[], int num_items) {
    printf("\nItem ID\tName\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%s\t%d\t%.2f\n", items[i].item_id, items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        add_item(items, num_items);
        printf("\nDo you want to add another item? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    print_items(items, num_items);

    return 0;
}