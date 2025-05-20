//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_QUANTITY 100
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    float price;
} item_t;

item_t items[MAX_ITEMS];
int num_items = 0;

void add_item() {
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

void remove_item() {
    int index;
    printf("Enter item index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_items) {
        num_items--;
        for (int i = index; i < num_items; i++) {
            memcpy(&items[i], &items[i+1], sizeof(item_t));
        }
    } else {
        printf("Invalid index.\n");
    }
}

void display_items() {
    printf("Item Name\tItem Description\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s\t%-40s\t%d\t%1.2f\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add item\n2. Remove item\n3. Display items\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_items();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}