//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    int price;
} Item;

int main() {
    int choice;
    char ch;
    Item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Medieval Product Inventory System!\n\n");
    printf("Please choose an option:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Display items\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                if (num_items >= MAX_ITEMS) {
                    printf("Error: Cannot add more items.\n");
                } else {
                    printf("Enter item name (max %d characters): ", MAX_NAME_LEN - 1);
                    scanf("%s", items[num_items].name);
                    printf("Enter quantity: ");
                    scanf("%d", &items[num_items].quantity);
                    printf("Enter price: ");
                    scanf("%d", &items[num_items].price);
                    num_items++;
                    printf("Item added successfully!\n");
                }
                break;
            case 2:
                if (num_items == 0) {
                    printf("Error: No items to remove.\n");
                } else {
                    printf("Enter item name to remove (max %d characters): ", MAX_NAME_LEN - 1);
                    scanf("%s", ch);
                    for (int i = 0; i < num_items; i++) {
                        if (strcmp(items[i].name, ch) == 0) {
                            printf("Item removed successfully!\n");
                            num_items--;
                            break;
                        }
                    }
                }
                break;
            case 3:
                if (num_items == 0) {
                    printf("Error: No items to display.\n");
                } else {
                    printf("Item List:\n");
                    for (int i = 0; i < num_items; i++) {
                        printf("%s - %d items - %d gold coins\n", items[i].name, items[i].quantity, items[i].price);
                    }
                }
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
    }

    return 0;
}