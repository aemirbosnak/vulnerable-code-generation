//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine medicineList[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines.\n");
        return;
    }
    
    Medicine newMedicine;
    
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter manufacturer: ");
    scanf("%s", newMedicine.manufacturer);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);

    medicineList[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }
    
    printf("Available Medicines:\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d. %s | %s | $%.2f | Quantity: %d\n", i + 1, 
                medicineList[i].name, 
                medicineList[i].manufacturer, 
                medicineList[i].price, 
                medicineList[i].quantity);
    }
}

void sellMedicine() {
    if (medicineCount == 0) {
        printf("No medicines available for sale.\n");
        return;
    }
    
    int choice, quantity;
    displayMedicines();
    
    printf("Select medicine number to sell: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > medicineCount) {
        printf("Invalid choice.\n");
        return;
    }
    
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    
    if (quantity > medicineList[choice - 1].quantity) {
        printf("Not enough stock available.\n");
    } else {
        medicineList[choice - 1].quantity -= quantity;
        printf("Sold %d units of %s.\n", quantity, medicineList[choice - 1].name);
    }
}

void restockMedicine() {
    if (medicineCount == 0) {
        printf("No medicines available to restock.\n");
        return;
    }
    
    int choice, additionalQuantity;
    displayMedicines();
    
    printf("Select medicine number to restock: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > medicineCount) {
        printf("Invalid choice.\n");
        return;
    }
    
    printf("Enter quantity to add: ");
    scanf("%d", &additionalQuantity);
    
    medicineList[choice - 1].quantity += additionalQuantity;
    printf("Restocked %d units of %s.\n", additionalQuantity, medicineList[choice - 1].name);
}

void deleteMedicine() {
    if (medicineCount == 0) {
        printf("No medicines available to delete.\n");
        return;
    }
    
    int choice;
    displayMedicines();
    
    printf("Select medicine number to delete: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > medicineCount) {
        printf("Invalid choice.\n");
        return;
    }
    
    for (int i = choice - 1; i < medicineCount - 1; i++) {
        medicineList[i] = medicineList[i + 1];
    }
    
    medicineCount--;
    printf("Medicine deleted successfully.\n");
}

int main() {
    int option;
    while (1) {
        printf("\n==== Medical Store Management ====\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Restock Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: sellMedicine(); break;
            case 4: restockMedicine(); break;
            case 5: deleteMedicine(); break;
            case 6: exit(0);
            default: printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}