//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing medicine data
struct Medicine {
    char name[50];
    float price;
    int quantity;
};

// Function prototypes
void addMedicine();
void sellMedicine();
void updateMedicine();
void viewMedicineList();

// Global variables
struct Medicine inventory[100];
int inventoryCount = 0;

// Main function
int main() {
    int choice = 0;
    printf("*** Welcome to the Medical Store Management System ***\n");
    while(choice != 5) {
        printf("\nPlease select an option:\n");
        printf("1. Add a new medicine\n");
        printf("2. Sell a medicine\n");
        printf("3. Update medicine information\n");
        printf("4. View medicine list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                sellMedicine();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                viewMedicineList();
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void addMedicine() {
    struct Medicine medicine;
    printf("\nEnter the name of the medicine: ");
    scanf("%s", medicine.name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicine.price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicine.quantity);
    inventory[inventoryCount] = medicine;
    inventoryCount++;
    printf("\nMedicine information added successfully.\n");
}

void sellMedicine() {
    char medicineName[50];
    int quantity;
    printf("\nEnter the name of the medicine: ");
    scanf("%s", medicineName);
    int found = 0;
    for(int i = 0; i < inventoryCount; i++) {
        if(strcmp(medicineName, inventory[i].name) == 0) {
            found = 1;
            printf("Enter the quantity to sell: ");
            scanf("%d", &quantity);
            if(quantity > inventory[i].quantity) {
                printf("Error: Not enough quantity available.\n");
            } else {
                inventory[i].quantity -= quantity;
                printf("Total cost: %.2f\n", inventory[i].price * quantity);
                printf("Medicine sold successfully.\n");
            }
            break;
        }
    }
    if(found == 0) {
        printf("Error: Medicine not found.\n");
    }
}

void updateMedicine() {
    char medicineName[50];
    printf("\nEnter the name of the medicine: ");
    scanf("%s", medicineName);
    int found = 0;
    for(int i = 0; i < inventoryCount; i++) {
        if(strcmp(medicineName, inventory[i].name) == 0) {
            found = 1;
            printf("Enter the new price of the medicine: ");
            scanf("%f", &inventory[i].price);
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &inventory[i].quantity);
            printf("\nMedicine information updated successfully.\n");
            break;
        }
    }
    if(found == 0) {
        printf("Error: Medicine not found.\n");
    }
}

void viewMedicineList() {
    printf("\nMedicine List:\n");
    printf("%-30s%-15s%-10s\n", "Name", "Price", "Quantity");
    for(int i = 0; i < inventoryCount; i++) {
        printf("%-30s%-15.2f%-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}