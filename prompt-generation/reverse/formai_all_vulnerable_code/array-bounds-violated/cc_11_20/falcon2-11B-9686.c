//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 50

struct item {
    char name[MAX_NAME_LEN];
    int price;
    int quantity;
};

struct item items[MAX_ITEMS];

int main() {
    printf("Welcome to Retro Medical Store Management System!\n");
    int choice;
    while (1) {
        printf("1. Add item\n2. Remove item\n3. Update item\n4. View inventory\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int item_id = 0;
                while (1) {
                    printf("Enter item name: ");
                    scanf("%s", items[item_id].name);
                    if (strcmp(items[item_id].name, "")!= 0) {
                        break;
                    }
                    printf("Invalid input, please try again.\n");
                }
                printf("Enter item price: ");
                scanf("%d", &items[item_id].price);
                printf("Enter item quantity: ");
                scanf("%d", &items[item_id].quantity);
                printf("Item added successfully!\n");
                break;
            }
            case 2: {
                int item_id;
                while (1) {
                    printf("Enter item ID to remove: ");
                    scanf("%d", &item_id);
                    if (item_id >= 0 && item_id < MAX_ITEMS) {
                        break;
                    }
                    printf("Invalid item ID, please try again.\n");
                }
                for (int i = item_id; i < MAX_ITEMS; i++) {
                    strcpy(items[i].name, items[i + 1].name);
                    items[i].price = items[i + 1].price;
                    items[i].quantity = items[i + 1].quantity;
                }
                items[item_id].quantity = -1;
                printf("Item removed successfully!\n");
                break;
            }
            case 3: {
                int item_id;
                while (1) {
                    printf("Enter item ID to update: ");
                    scanf("%d", &item_id);
                    if (item_id >= 0 && item_id < MAX_ITEMS) {
                        break;
                    }
                    printf("Invalid item ID, please try again.\n");
                }
                printf("Enter new item name: ");
                scanf("%s", items[item_id].name);
                printf("Enter new item price: ");
                scanf("%d", &items[item_id].price);
                printf("Enter new item quantity: ");
                scanf("%d", &items[item_id].quantity);
                printf("Item updated successfully!\n");
                break;
            }
            case 4: {
                int item_id = 0;
                printf("Item ID\tName\tPrice\tQuantity\n");
                while (item_id < MAX_ITEMS) {
                    printf("%d\t%s\t%d\t%d\n", item_id + 1, items[item_id].name, items[item_id].price, items[item_id].quantity);
                    item_id++;
                }
                break;
            }
            case 5: {
                printf("Goodbye!\n");
                exit(0);
            }
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}