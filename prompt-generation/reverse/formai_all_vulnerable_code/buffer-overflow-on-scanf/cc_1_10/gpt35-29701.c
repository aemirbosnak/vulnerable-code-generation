//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_MEDS 100
#define MAX_QTY 1000

// Define struct for medicine
typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Function to display menu
void displayMenu() {
    printf("===== MEDICAL STORE MANAGEMENT SYSTEM =====\n\n");
    printf("1. Add Medicine\n");
    printf("2. Sell Medicine\n");
    printf("3. View Medicine\n");
    printf("4. Display Total Sales\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

// Function to add medicine
void addMedicine(Medicine meds[], int *numMeds) {
    // Check if max limit is reached
    if (*numMeds == MAX_MEDS) {
        printf("Maximum limit reached. Cannot add more medicines.\n\n");
        return;
    }

    // Get details from user
    printf("Enter name of medicine: ");
    scanf("%s", meds[*numMeds].name);
    printf("Enter price of medicine: ");
    scanf("%f", &meds[*numMeds].price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &meds[*numMeds].quantity);
    printf("Medicine added successfully!\n\n");

    // Increment medicine count
    (*numMeds)++;
}

// Function to sell medicine
void sellMedicine(Medicine meds[], int numMeds, float *totalSales) {
    // Check if no medicines are available
    if (numMeds == 0) {
        printf("No medicines available for sale.\n\n");
        return;
    }

    // Get name from user
    char name[50];
    printf("Enter name of medicine to sell: ");
    scanf("%s", name);

    // Search for medicine in inventory
    int index = -1;
    for (int i = 0; i < numMeds; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If medicine not found
    if (index == -1) {
        printf("Medicine not found.\n\n");
        return;
    }

    // Get quantity from user
    int qty;
    printf("Enter quantity of medicine to sell: ");
    scanf("%d", &qty);

    // Check if quantity is valid
    if (qty <= 0 || qty > meds[index].quantity) {
        printf("Invalid quantity.\n\n");
        return;
    }

    // Update inventory and total sales
    meds[index].quantity -= qty;
    *totalSales += meds[index].price * qty;

    printf("Medicine sold successfully!\n\n");
}

// Function to view medicines
void viewMedicines(Medicine meds[], int numMeds) {
    // Check if no medicines are available
    if (numMeds == 0) {
        printf("No medicines available.\n\n");
        return;
    }

    // Display medicine details
    printf("Name\t\tPrice\t\tQuantity\n");
    for (int i = 0; i < numMeds; i++) {
        printf("%s\t\t%.2f\t\t%d\n", meds[i].name, meds[i].price, meds[i].quantity);
    }

    printf("\n");
}

int main() {
    // Declare variables
    Medicine meds[MAX_MEDS];
    int numMeds = 0;
    float totalSales = 0.0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine(meds, &numMeds);
                break;
            case 2:
                sellMedicine(meds, numMeds, &totalSales);
                break;
            case 3:
                viewMedicines(meds, numMeds);
                break;
            case 4:
                printf("Total Sales: %.2f\n\n", totalSales);
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}