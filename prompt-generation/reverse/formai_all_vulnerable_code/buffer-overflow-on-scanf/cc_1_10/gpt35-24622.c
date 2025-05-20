//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to hold the information of a medicine
struct Medicine {
    char name[50];
    char genericName[50];
    float price;
    int quantity;
};

// Structure to hold the information of a medicine bill
struct Bill {
    char medicineName[50];
    float price;
    int quantity;
};

// Function to display the main menu
void displayMainMenu() {
    printf("1. Add Medicine\n");
    printf("2. Sell Medicine\n");
    printf("3. Generate Report\n");
    printf("4. Exit\n");
}

// Function to add a new medicine to the inventory
void addMedicine(struct Medicine *medicine, int size) {

    // Take input for each medicine field
    printf("Enter Medicine Name: ");
    scanf("%s", medicine[size].name);

    printf("Enter Generic Name: ");
    scanf("%s", medicine[size].genericName);

    printf("Enter Price: ");
    scanf("%f", &medicine[size].price);

    printf("Enter Quantity: ");
    scanf("%d", &medicine[size].quantity);

    printf("Medicine added successfully!\n");
}

// Function to search for a medicine in the inventory
bool searchMedicine(struct Medicine *medicine, int size, char *name) {
    for(int i=0;i<size;i++) {
        if(strcmp(medicine[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

// Function to sell a medicine
void sellMedicine(struct Medicine *medicine, int size, struct Bill *bill, int *billSize) {

    // Take input for medicine name and quantity
    char name[50];
    int quantity;
    printf("Enter Medicine Name: ");
    scanf("%s", name);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    // Search for the medicine in the inventory
    int foundIndex = -1;
    for(int i=0;i<size;i++) {
        if(strcmp(medicine[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }

    // If medicine found and sufficient quantity is available
    if(foundIndex != -1 && medicine[foundIndex].quantity >= quantity) {
        // Add the medicine to the bill
        strcpy(bill[*billSize].medicineName, medicine[foundIndex].name);
        bill[*billSize].price = medicine[foundIndex].price;
        bill[*billSize].quantity = quantity;
        (*billSize)++;

        // Update the medicine quantity in the inventory
        medicine[foundIndex].quantity -= quantity;
        printf("Medicine sold successfully!\n");
    } else {
        printf("Medicine not found or insufficient quantity available\n");
    }
}

// Function to generate a report of all the medicines in the inventory
void generateReport(struct Medicine *medicine, int size) {
    printf("Name\tGeneric Name\tPrice\tQuantity\n");
    for(int i=0;i<size;i++) {
        printf("%s\t%s\t%f\t%d\n", medicine[i].name, medicine[i].genericName, medicine[i].price, medicine[i].quantity);
    }
}

// Main function
int main() {

    // Initialize the initial size of the inventory and bill
    int inventorySize = 0;
    int billSize = 0;

    // Initialize the inventory and bill arrays
    struct Medicine inventory[50];
    struct Bill bill[50];

    int choice;
    do {
        // Display the main menu and take input for the choice
        displayMainMenu();
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add a new medicine to the inventory
                addMedicine(inventory, inventorySize);
                inventorySize++;
                break;
            case 2:
                // Sell a medicine
                sellMedicine(inventory, inventorySize, bill, &billSize);
                break;
            case 3:
                // Generate a report of all the medicines in the inventory
                generateReport(inventory, inventorySize);
                break;
            case 4:
                // Exit the program
                printf("Exiting Program..\n");
                break;
            default:
                // If invalid choice entered
                printf("Invalid Choice..\n");
                break;
        }
    } while(choice != 4);

    return 0;
}