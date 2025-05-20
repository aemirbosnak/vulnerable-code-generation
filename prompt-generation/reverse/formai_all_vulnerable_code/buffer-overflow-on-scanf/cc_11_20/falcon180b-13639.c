//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct item {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
};

int main() {
    char choice;
    struct item items[MAX_ITEMS];
    int num_items = 0;

    do {
        printf("Welcome to the Cafe Billing System\n");
        printf("Please choose an option:\n");
        printf("1. Add item\n2. Remove item\n3. Update item\n4. Display items\n5. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if (num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter item price: ");
                    scanf("%s", items[num_items].price);
                    printf("Enter item quantity: ");
                    scanf("%d", &items[num_items].quantity);
                    num_items++;
                }
                break;
            case '2':
                if (num_items == 0) {
                    printf("No items to remove.\n");
                } else {
                    printf("Enter item name to remove: ");
                    scanf("%s", items[num_items-1].name);
                    num_items--;
                }
                break;
            case '3':
                if (num_items == 0) {
                    printf("No items to update.\n");
                } else {
                    printf("Enter item name to update: ");
                    scanf("%s", items[num_items-1].name);
                    printf("Enter new item price: ");
                    scanf("%s", items[num_items-1].price);
                    printf("Enter new item quantity: ");
                    scanf("%d", &items[num_items-1].quantity);
                }
                break;
            case '4':
                if (num_items == 0) {
                    printf("No items to display.\n");
                } else {
                    printf("Item Name\tItem Price\tItem Quantity\n");
                    for (int i = 0; i < num_items; i++) {
                        printf("%s\t%s\t%d\n", items[i].name, items[i].price, items[i].quantity);
                    }
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '5');

    return 0;
}