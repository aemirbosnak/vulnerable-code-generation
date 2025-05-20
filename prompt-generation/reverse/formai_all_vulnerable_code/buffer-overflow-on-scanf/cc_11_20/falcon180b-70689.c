//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Declare an array of items
Item items[MAX_ITEMS];

int main() {
    int choice, i;
    char input[100];

    // Initialize the number of items to zero
    int num_items = 0;

    // Display the main menu
    printf("Medical Store Management System\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Update item\n");
    printf("4. Display items\n");
    printf("5. Exit\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Perform the selected operation
    switch(choice) {
        case 1:
            // Add an item
            printf("Enter the name of the item: ");
            scanf("%s", input);
            strcpy(items[num_items].name, input);

            printf("Enter the quantity of the item: ");
            scanf("%d", &items[num_items].quantity);

            printf("Enter the price of the item: ");
            scanf("%f", &items[num_items].price);

            num_items++;
            break;

        case 2:
            // Remove an item
            printf("Enter the name of the item to remove: ");
            scanf("%s", input);

            for(i=0; i<num_items; i++) {
                if(strcmp(items[i].name, input) == 0) {
                    num_items--;
                    break;
                }
            }

            break;

        case 3:
            // Update an item
            printf("Enter the name of the item to update: ");
            scanf("%s", input);

            for(i=0; i<num_items; i++) {
                if(strcmp(items[i].name, input) == 0) {
                    printf("Enter the new quantity of the item: ");
                    scanf("%d", &items[i].quantity);

                    printf("Enter the new price of the item: ");
                    scanf("%f", &items[i].price);

                    break;
                }
            }

            break;

        case 4:
            // Display items
            printf("List of items:\n");

            for(i=0; i<num_items; i++) {
                printf("%s - %d units - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
            }

            break;

        case 5:
            // Exit the program
            exit(0);

        default:
            // Invalid choice
            printf("Invalid choice!\n");
    }

    return 0;
}