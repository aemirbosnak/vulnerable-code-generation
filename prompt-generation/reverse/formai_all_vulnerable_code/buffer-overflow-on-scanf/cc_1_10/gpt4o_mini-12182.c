//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_SIZE 50

// Structure to hold medicine information
typedef struct {
    char name[NAME_SIZE];
    int quantity;
    float price;
} Medicine;

// Function prototypes
void addMedicine(Medicine *medicines, int *count);
void viewMedicines(const Medicine *medicines, int count);
void sellMedicine(Medicine *medicines, int count);
void menu();

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0, choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                viewMedicines(medicines, count);
                break;
            case 3:
                sellMedicine(medicines, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to display the menu
void menu() {
    printf("\n------ Medical Store Management System ------\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Exit\n");
}

// Function to add medicine
void addMedicine(Medicine *medicines, int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Inventory full!\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    
    // Store the new medicine
    medicines[*count] = newMedicine;
    (*count)++;
    printf("Medicine added successfully!\n");
}

// Function to view medicines
void viewMedicines(const Medicine *medicines, int count) {
    if (count == 0) {
        printf("No medicines in the inventory!\n");
        return;
    }
    
    printf("\n--- Medicines in Inventory ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Function to sell medicine
void sellMedicine(Medicine *medicines, int count) {
    char name[NAME_SIZE];
    int quantity;

    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            if (medicines[i].quantity >= quantity) {
                medicines[i].quantity -= quantity;
                printf("Sold %d units of %s. Remaining quantity is %d.\n", quantity, name, medicines[i].quantity);
                return;
            } else {
                printf("Insufficient quantity for %s. Available stock: %d\n", name, medicines[i].quantity);
                return;
            }
        }
    }
    printf("Medicine %s not found in inventory!\n", name);
}