//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    int price;
} Item;

int main() {
    int choice;
    char input[MAX_NAME_LEN];
    Item items[MAX_ITEMS];
    int num_items = 0;

    do {
        printf("Welcome to the Medieval Product Inventory System!\n");
        printf("Please choose an option:\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Update item\n");
        printf("4. Delete item\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the item: ");
                scanf("%s", input);
                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, input) == 0) {
                        printf("Item already exists!\n");
                        break;
                    }
                }
                if (num_items >= MAX_ITEMS) {
                    printf("Inventory is full!\n");
                } else {
                    printf("Enter the description of the item: ");
                    scanf("%s", items[num_items].description);
                    printf("Enter the quantity of the item: ");
                    scanf("%d", &items[num_items].quantity);
                    printf("Enter the price of the item: ");
                    scanf("%d", &items[num_items].price);
                    num_items++;
                    printf("Item added successfully!\n");
                }
                break;
            case 2:
                printf("Name\tDescription\tQuantity\tPrice\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%s\t%s\t%d\t%d\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
                }
                break;
            case 3:
                printf("Enter the name of the item to update: ");
                scanf("%s", input);
                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, input) == 0) {
                        printf("Enter the new description of the item: ");
                        scanf("%s", items[i].description);
                        printf("Enter the new quantity of the item: ");
                        scanf("%d", &items[i].quantity);
                        printf("Enter the new price of the item: ");
                        scanf("%d", &items[i].price);
                        printf("Item updated successfully!\n");
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter the name of the item to delete: ");
                scanf("%s", input);
                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, input) == 0) {
                        for (int j = i; j < num_items - 1; j++) {
                            items[j] = items[j + 1];
                        }
                        num_items--;
                        printf("Item deleted successfully!\n");
                        break;
                    }
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}