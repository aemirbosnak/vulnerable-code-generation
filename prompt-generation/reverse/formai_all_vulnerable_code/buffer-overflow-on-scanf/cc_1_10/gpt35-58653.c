//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Structure for items present in the warehouse
typedef struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} Item;

int main() {
    // Declare variables and initialize them with default value
    int i, n = 0, option = 0;
    char search_name[MAX_SIZE];
    float total_price = 0.00;
    Item items[MAX_SIZE];

    // Welcome message for the user
    printf("Welcome to the Warehouse Management System!\n");

    // Infinite loop for options
    while (1) {
        // Display menu options
        printf("\nMenu Options:\n");
        printf("1. Add Item\n");
        printf("2. Search Item\n");
        printf("3. Display All Items\n");
        printf("4. Exit\n");
        printf("\nChoose an option: ");
        scanf("%d", &option);

        // Switch case based on user option
        switch(option) {
            case 1: // Add Item
                printf("\nEnter item details:\n");
                printf("Name: ");
                scanf("%s", items[n].name);
                printf("Quantity: ");
                scanf("%d", &items[n].quantity);
                printf("Price: ");
                scanf("%f", &items[n].price);

                // Increment the counter for item added
                n++;
                printf("\nItem has been added successfully!\n");
                break;

            case 2: // Search Item
                printf("\nEnter name of item to search: ");
                scanf("%s", search_name);

                // Loop through all items to search for matching name
                for (i = 0; i < n; i++) {
                    if (strcmp(items[i].name, search_name) == 0) {
                        printf("\nItem found:\n");
                        printf("Name: %s\n", items[i].name);
                        printf("Quantity: %d\n", items[i].quantity);
                        printf("Price: %.2f\n", items[i].price);
                        break;
                    }
                }

                // Item not found
                if (i == n) {
                    printf("\nItem not found.\n");
                }
                break;

            case 3: // Display All Items
                printf("\nAll items in the warehouse:\n");
                for (i = 0; i < n; i++) {
                    printf("%d. Name: %s\tQuantity: %d\tPrice: %.2f\n", i+1, items[i].name, items[i].quantity, items[i].price);
                    total_price += items[i].quantity * items[i].price;
                }
                printf("\nTotal value of all items in warehouse: %.2f\n", total_price);
                break;

            case 4: // Exit
                printf("\nThank you for using Warehouse Management System!\n");
                exit(0);

            default: // Invalid Option
                printf("\nInvalid option selected. Please try again.\n");
                break;
        }
    }
    return 0;
}