//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>

int main() {
    // Declare variables
    int medicineID, quantity, price;
    
    // Create a menu
    printf("Welcome to the Retro Medical Store!\n");
    printf("Enter 1 to view the list of available medicines.\n");
    printf("Enter 2 to add a new medicine to the store.\n");
    printf("Enter 3 to remove a medicine from the store.\n");
    printf("Enter 4 to update the quantity of a medicine.\n");
    printf("Enter 5 to update the price of a medicine.\n");
    printf("Enter 6 to print the total value of medicines in the store.\n");
    printf("Enter 7 to exit.\n");
    
    // Read user input
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // Process user input
    switch (choice) {
        case 1:
            // View list of available medicines
            printf("Here is the list of available medicines:\n");
            printf("ID | Name | Quantity | Price\n");
            printf("--------------------------\n");
            break;
        case 2:
            // Add a new medicine to the store
            printf("Enter the medicine ID: ");
            scanf("%d", &medicineID);
            printf("Enter the medicine name: ");
            scanf("%s", &medicineID);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            printf("Enter the price: ");
            scanf("%d", &price);
            printf("Medicine %d added to the store!\n", medicineID);
            break;
        case 3:
            // Remove a medicine from the store
            printf("Enter the medicine ID: ");
            scanf("%d", &medicineID);
            printf("Medicine %d removed from the store!\n", medicineID);
            break;
        case 4:
            // Update the quantity of a medicine
            printf("Enter the medicine ID: ");
            scanf("%d", &medicineID);
            printf("Enter the new quantity: ");
            scanf("%d", &quantity);
            printf("Medicine %d quantity updated to %d!\n", medicineID, quantity);
            break;
        case 5:
            // Update the price of a medicine
            printf("Enter the medicine ID: ");
            scanf("%d", &medicineID);
            printf("Enter the new price: ");
            scanf("%d", &price);
            printf("Medicine %d price updated to %d!\n", medicineID, price);
            break;
        case 6:
            // Print the total value of medicines in the store
            printf("Total value of medicines in the store: $%.2f\n", (double)price * quantity);
            break;
        case 7:
            // Exit the program
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
    
    return 0;
}