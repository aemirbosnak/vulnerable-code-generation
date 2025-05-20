//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure to store medicine details
struct medicine {
    char name[50];
    int id;
    float price;
    int quantity;
};

// Function declaration
void addMedicine(struct medicine inventory[], int *count);
void updateMedicine(struct medicine inventory[], int count);
void printInventory(struct medicine inventory[], int count);
void sellMedicine(struct medicine inventory[], int count);

int main() {
    struct medicine inventory[100]; // Creating an inventory array to store medicines
    int count = 0;
    int choice;

    do {
        // Displaying the menu
        printf("\n===== Medical Store Management System =====\n");
        printf("1. Add a new medicine to inventory\n");
        printf("2. Update medicine details\n");
        printf("3. Print inventory\n");
        printf("4. Sell medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine(inventory, &count); // Call addMedicine() function
                break;
            case 2:
                updateMedicine(inventory, count); // Call updateMedicine() function
                break;
            case 3:
                printInventory(inventory, count); // Call printInventory() function
                break;
            case 4:
                sellMedicine(inventory, count); // Call sellMedicine() function
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Function to add a new medicine to inventory
void addMedicine(struct medicine inventory[], int *count) {
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*count].name);

    printf("Enter the ID of the medicine: ");
    scanf("%d", &inventory[*count].id);

    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*count].price);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*count].quantity);

    printf("Medicine added successfully!\n");

    (*count)++; // Incrementing the count of medicines in the inventory
}

// Function to update the details of a medicine
void updateMedicine(struct medicine inventory[], int count) {
    int id, found = 0;

    printf("Enter the ID of the medicine to be updated: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(inventory[i].id == id) { // Checking if the medicine exists or not
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &inventory[i].quantity);

            printf("Medicine updated successfully!\n");

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Medicine with ID %d not found!\n", id);
    }
}

// Function to print the inventory
void printInventory(struct medicine inventory[], int count) {
    printf("\n===== MEDICAL STORE INVENTORY =====\n");
    printf("ID\tMEDICINE\t\tPRICE\tQUANTITY\n");
    printf("-------------------------------------------------\n");

    for(int i=0; i<count; i++) { 
        printf("%d\t%s\t\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to sell a medicine
void sellMedicine(struct medicine inventory[], int count) {
    int id, quantity;
    int found = 0;

    printf("Enter the ID of the medicine to be sold: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(inventory[i].id == id) { // Checking if the medicine exists or not
            printf("Enter the quantity of the medicine to be sold: ");
            scanf("%d", &quantity);

            if(inventory[i].quantity < quantity) { // Checking if the quantity entered is available or not
                printf("Sorry! Only %d units of %s available.\n", inventory[i].quantity, inventory[i].name);
            } else {
                printf("Total cost: %.2f\n", inventory[i].price * quantity);
                inventory[i].quantity -= quantity;
                printf("%d units of %s sold successfully!\n", quantity, inventory[i].name);
            }

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Medicine with ID %d not found!\n", id);
    }
}