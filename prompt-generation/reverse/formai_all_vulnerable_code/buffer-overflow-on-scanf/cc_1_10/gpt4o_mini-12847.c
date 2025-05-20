//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char expiryDate[10]; // Format: DD-MM-YYYY
    int quantity;
    float price;
} Medicine;

void addMedicine(Medicine medicines[], int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Medicine store is full! Cannot add more medicines.\n");
        return;
    }
    
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter expiry date (DD-MM-YYYY): ");
    scanf("%s", newMedicine.expiryDate);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    
    medicines[*count] = newMedicine;
    (*count)++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(Medicine medicines[], int count) {
    if (count == 0) {
        printf("No medicines available in the store.\n");
        return;
    }
    
    printf("\nAvailable Medicines:\n");
    printf("---------------------------------------------------\n");
    printf("| %-25s | %-12s | %-8s | %-8s |\n", "Name", "Expiry Date", "Quantity", "Price");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-25s | %-12s | %-8d | %-8.2f |\n", 
               medicines[i].name, medicines[i].expiryDate, medicines[i].quantity, medicines[i].price);
    }
    printf("---------------------------------------------------\n");
}

void searchMedicine(Medicine medicines[], int count) {
    char searchName[50];
    printf("Enter medicine name to search: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("Medicine found: %s | Expiry Date: %s | Quantity: %d | Price: %.2f\n",
                   medicines[i].name, medicines[i].expiryDate, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void sellMedicine(Medicine medicines[], int count) {
    char sellName[50];
    int sellQuantity;
    printf("Enter medicine name to sell: ");
    scanf("%s", sellName);
    printf("Enter quantity to sell: ");
    scanf("%d", &sellQuantity);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, sellName) == 0) {
            if (medicines[i].quantity >= sellQuantity) {
                medicines[i].quantity -= sellQuantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", sellQuantity, medicines[i].name, medicines[i].quantity);
                return;
            } else {
                printf("Not enough stock to sell %d of %s. Available: %d\n", sellQuantity, medicines[i].name, medicines[i].quantity);
                return;
            }
        }
    }
    printf("Medicine not found!\n");
}

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;
    
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                displayMedicines(medicines, count);
                break;
            case 3:
                searchMedicine(medicines, count);
                break;
            case 4:
                sellMedicine(medicines, count);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}