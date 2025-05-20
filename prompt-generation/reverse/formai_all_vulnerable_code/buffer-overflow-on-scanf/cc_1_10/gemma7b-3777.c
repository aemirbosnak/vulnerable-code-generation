//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>

int main()
{
    // Declare variables
    int item_id;
    char item_name[20];
    int quantity;
    int location;

    // Create a loop to manage items
    while (1)
    {
        // Display menu options
        printf("Please select an option:");
        printf("\n1. Add Item");
        printf("\n2. Update Item");
        printf("\n3. Delete Item");
        printf("\n4. Search Item");
        printf("\n5. Exit");

        // Get user input
        int choice = getchar();

        // Process user input
        switch (choice)
        {
            case 1:
                // Get item name, quantity, and location
                printf("Enter item name:");
                scanf("%s", item_name);

                printf("Enter quantity:");
                scanf("%d", &quantity);

                printf("Enter location:");
                scanf("%d", &location);

                // Add item to warehouse
                printf("Item added successfully!");
                break;

            case 2:
                // Get item id and update quantity
                printf("Enter item id:");
                scanf("%d", &item_id);

                printf("Enter new quantity:");
                scanf("%d", &quantity);

                // Update item quantity
                printf("Item quantity updated successfully!");
                break;

            case 3:
                // Get item id and delete item
                printf("Enter item id:");
                scanf("%d", &item_id);

                // Delete item from warehouse
                printf("Item deleted successfully!");
                break;

            case 4:
                // Get item name and search for item
                printf("Enter item name:");
                scanf("%s", item_name);

                // Search for item and display its details
                printf("Item details:");
                printf("\nItem ID: %d", item_id);
                printf("\nItem Name: %s", item_name);
                printf("\nQuantity: %d", quantity);
                printf("\nLocation: %d", location);
                break;

            case 5:
                // Exit the system
                printf("Thank you for using the warehouse management system. Goodbye!");
                break;

            default:
                // Invalid input
                printf("Invalid input. Please try again.");
                break;
        }

        // Prompt user to continue or exit
        printf("Press any key to continue or enter 'q' to exit:");
        char exit_char = getchar();

        // Check if user wants to exit
        if (exit_char == 'q')
        {
            break;
        }
    }

    return 0;
}