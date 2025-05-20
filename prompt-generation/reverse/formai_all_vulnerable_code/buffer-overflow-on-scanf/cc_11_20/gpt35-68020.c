//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing medicine information
struct Medicine {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int option;
    int count = 0;
    struct Medicine inventory[100];

    // Temporary variables for adding a new medicine
    char tempName[50];
    int tempQuantity;
    float tempPrice;

    printf("--- Welcome to the Medical Store Management System ---\n");

    do {
        // Menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new medicine\n");
        printf("2. Update medicine quantity\n");
        printf("3. Sell medicine\n");
        printf("4. View inventory\n");
        printf("5. Exit\n");

        // Retrieve option from user
        printf("Enter option number: ");
        scanf("%d", &option);

        // Handle user's option choice
        switch (option) {
            case 1:
                // Add a new medicine
                printf("\nEnter name of new medicine: ");
                scanf("%s", tempName);

                printf("Enter quantity of new medicine: ");
                scanf("%d", &tempQuantity);

                printf("Enter price of new medicine: ");
                scanf("%f", &tempPrice);

                // Add the new medicine to the inventory
                struct Medicine newMedicine;
                strcpy(newMedicine.name, tempName);
                newMedicine.quantity = tempQuantity;
                newMedicine.price = tempPrice;

                inventory[count++] = newMedicine;

                printf("New medicine successfully added to inventory!\n");
                break;

            case 2:
                // Update medicine quantity
                printf("\nEnter the name of the medicine to update quantity for: ");
                scanf("%s", tempName);

                for (int i = 0; i < count; i++) {
                    if (strcmp(inventory[i].name, tempName) == 0) {
                        printf("Enter the new quantity for %s: ", tempName);
                        scanf("%d", &inventory[i].quantity);
                        printf("%s quantity updated successfully!\n", tempName);
                    }
                }

                break;

            case 3:
                // Sell medicine
                printf("\nEnter the name of the medicine to sell: ");
                scanf("%s", tempName);

                for (int i = 0; i < count; i++) {
                    if (strcmp(inventory[i].name, tempName) == 0) {
                        printf("\nHow many units of %s to sell? ", tempName);
                        scanf("%d", &tempQuantity);

                        if (tempQuantity > inventory[i].quantity) {
                            printf("Not enough units available in stock!\n");
                        } else {
                            inventory[i].quantity -= tempQuantity;
                            printf("%d units of %s sold successfully!\n", tempQuantity, tempName);
                        }
                    }
                }

                break;

            case 4:
                // View inventory
                if (count == 0) {
                    printf("\nInventory is empty!\n");
                } else {
                    printf("\n--- Inventory ---\n");
                    printf("%-30s%-15s%-10s\n", "Name", "Quantity", "Price");

                    for (int i = 0; i < count; i++) {
                        printf("%-30s%-15d%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }

                    printf("\n");
                }

                break;

            case 5:
                // Exit program
                printf("\nExiting Medical Store Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option, please try again.\n");
        }
    } while (option != 5);

    return 0;
}