//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_QTY_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char qty[MAX_QTY_LEN];
    char price[MAX_PRICE_LEN];
} item;

item items[MAX_ITEMS];
int num_items;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item quantity: ");
    scanf("%s", items[num_items].qty);
    printf("Enter item price: ");
    scanf("%s", items[num_items].price);
    num_items++;
}

void display_items() {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%s\n", items[i].name, items[i].qty, items[i].price);
    }
}

int main() {
    num_items = 0;
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add item\n2. Display items\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}