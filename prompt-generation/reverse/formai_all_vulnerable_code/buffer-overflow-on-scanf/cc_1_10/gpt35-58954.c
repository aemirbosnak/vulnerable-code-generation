//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for medicine
struct Medicine {
    char name[50];
    int quantity;
    float price;
};

// Function declarations
void addMedicine();
void displayMedicines();
void searchMedicine();
void sellMedicine();

// Global variables
struct Medicine medicines[50];
int count = 0;

int main() {
    int choice;

    // Loop for menu
    while(1) {
        printf("\n*** MEDICAL STORE MANAGEMENT SYSTEM ***\n\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                sellMedicine();
                break;
            case 5:
                printf("\nThank you for using Medical Store Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add medicine
void addMedicine() {
    char name[50];
    int quantity;
    float price;

    printf("\nEnter the medicine name: ");
    scanf("%s", name);

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    printf("Enter the price: ");
    scanf("%f", &price);

    // Add medicine to array
    strcpy(medicines[count].name, name);
    medicines[count].quantity = quantity;
    medicines[count].price = price;

    count++;

    printf("\nMedicine added successfully!\n");
}

// Function to display medicines
void displayMedicines() {
    int i;

    printf("\nList of Medicines\n\n");

    // Header
    printf("%-20s%-20s%-20s\n", "Medicine Name", "Quantity", "Price");

    // Loop over array
    for(i = 0; i < count; i++) {
        printf("%-20s%-20d%-20.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Function to search medicine
void searchMedicine() {
    char name[50];
    int i;

    printf("\nEnter the medicine name: ");
    scanf("%s", name);

    // Loop over array
    for(i = 0; i < count; i++) {
        // If name matches
        if(strcmp(medicines[i].name, name) == 0) {
            printf("\nMedicine found!\n");
            printf("%-20s%-20s%-20s\n", "Medicine Name", "Quantity", "Price");
            printf("%-20s%-20d%-20.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }

    printf("\nMedicine not found!\n");
}

// Function to sell medicine
void sellMedicine() {
    char name[50];
    int quantity;
    int i;

    printf("\nEnter the medicine name: ");
    scanf("%s", name);

    // Loop over array
    for(i = 0; i < count; i++) {
        // If name matches
        if(strcmp(medicines[i].name, name) == 0) {
            printf("\nEnter the quantity: ");
            scanf("%d", &quantity);

            // If quantity is available
            if(quantity <= medicines[i].quantity) {
                medicines[i].quantity -= quantity;

                printf("\nMedicine sold successfully!\n");
                return;
            }
            else {
                printf("\nSorry, the quantity entered is not available.\nPlease try again later.\n");
                return;
            }
        }
    }

    printf("\nMedicine not found!\n");
}