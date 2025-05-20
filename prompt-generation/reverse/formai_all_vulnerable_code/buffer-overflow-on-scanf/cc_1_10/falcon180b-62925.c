//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000.00

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    double price;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;
    char choice;

    while (1) {
        printf("Welcome to the Medical Store Management System!\n");
        printf("Please select an option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_items >= MAX_ITEMS) {
                    printf("Sorry, the system is full. Please remove an item first.\n");
                } else {
                    printf("Enter the name of the item:\n");
                    scanf("%s", items[num_items].name);
                    printf("Enter the category of the item:\n");
                    scanf("%s", items[num_items].category);
                    printf("Enter the quantity of the item:\n");
                    scanf("%d", &items[num_items].quantity);
                    printf("Enter the price of the item:\n");
                    scanf("%lf", &items[num_items].price);
                    num_items++;
                    printf("Item added successfully!\n");
                }
                break;
            case '2':
                if (num_items == 0) {
                    printf("Sorry, there are no items to remove.\n");
                } else {
                    printf("Enter the name of the item to remove:\n");
                    scanf("%s", items[num_items - 1].name);
                    num_items--;
                    printf("Item removed successfully!\n");
                }
                break;
            case '3':
                printf("Displaying items:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("Name: %s\n", items[i].name);
                    printf("Category: %s\n", items[i].category);
                    printf("Quantity: %d\n", items[i].quantity);
                    printf("Price: $%.2f\n\n", items[i].price);
                }
                break;
            case '4':
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}