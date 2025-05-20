//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold the details of the medicines
typedef struct {
    char name[20];
    float price;
    int quantity;
} Medicine;

// Function to add new medicine to inventory
void addNewMedicine(Medicine inventory[], int* inventorySize) {
    char name[20];
    float price;
    int quantity;

    printf("Enter name of medicine: ");
    scanf("%s", name);
    printf("Enter price of medicine: ");
    scanf("%f", &price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &quantity);

    // Add new medicine to inventory
    Medicine newMedicine;
    strcpy(newMedicine.name, name);
    newMedicine.price = price;
    newMedicine.quantity = quantity;
    inventory[*inventorySize] = newMedicine;
    (*inventorySize)++;

    printf("New medicine added successfully.\n");
}

// Function to update the stock of medicine
void updateMedicineStock(Medicine inventory[], int inventorySize) {
    char name[20];
    int quantity;

    printf("Enter name of medicine to update: ");
    scanf("%s", name);
    printf("Enter quantity to add: ");
    scanf("%d", &quantity);

    // Update stock
    int i;
    for(i=0; i<inventorySize; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            inventory[i].quantity += quantity;
            printf("Stock updated successfully.\n");
            return;
        }
    }

    printf("Medicine not found in inventory.\n");
}

// Function to search medicine in inventory
void searchMedicine(Medicine inventory[], int inventorySize) {
    char name[20];

    printf("Enter name of medicine to search: ");
    scanf("%s", name);

    // Search medicine
    int i;
    for(i=0; i<inventorySize; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            printf("Name: %s\n", inventory[i].name);
            printf("Price: Rs. %.2f\n", inventory[i].price);
            printf("Stock: %d\n", inventory[i].quantity);
            return;
        }
    }

    printf("Medicine not found in inventory.\n");
}

// Function to display inventory
void displayInventory(Medicine inventory[], int inventorySize) {
    int i;
    printf("Inventory\n");
    printf("-----------------------------------------------------\n");
    printf("Name\t\tPrice\t\tStock\n");
    printf("-----------------------------------------------------\n");

    for(i=0; i<inventorySize; i++) {
        printf("%s\t\tRs. %.2f\t\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    int choice;
    int inventorySize = 0;
    Medicine inventory[100];

    do {
        // Display menu
        printf("\nMedical Store Management System\n");
        printf("1. Add New Medicine to Inventory\n");
        printf("2. Update Medicine Stock\n");
        printf("3. Search Medicine\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addNewMedicine(inventory, &inventorySize);
                break;

            case 2:
                updateMedicineStock(inventory, inventorySize);
                break;

            case 3:
                searchMedicine(inventory, inventorySize);
                break;

            case 4:
                displayInventory(inventory, inventorySize);
                break;

            case 5:
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    } while(choice != 5);

    return 0;
}