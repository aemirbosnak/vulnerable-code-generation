//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
} Medicine;

int numMedicines = 0;
Medicine medicines[MAX_MEDICINES];

void addMedicine() {
    if (numMedicines >= MAX_MEDICINES) {
        printf("Medicine storage is full!\n");
        return;
    }
    
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf(" %[^\n]", newMedicine.name);
    printf("Enter manufacturer: ");
    scanf(" %[^\n]", newMedicine.manufacturer);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    
    medicines[numMedicines++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (numMedicines == 0) {
        printf("No medicines in the store.\n");
        return;
    }

    printf("Available Medicines:\n");
    printf("%-30s %-25s %-10s %-10s\n", "Name", "Manufacturer", "Quantity", "Price");
    for (int i = 0; i < numMedicines; i++) {
        printf("%-30s %-25s %-10d %-10.2f\n",
               medicines[i].name,
               medicines[i].manufacturer,
               medicines[i].quantity,
               medicines[i].price);
    }
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found: %s, Manufacturer: %s, Quantity: %d, Price: %.2f\n",
                   medicines[i].name,
                   medicines[i].manufacturer,
                   medicines[i].quantity,
                   medicines[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void updateMedicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Current Quantity: %d\n", medicines[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Current Price: %.2f\n", medicines[i].price);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < numMedicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            numMedicines--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                updateMedicine();
                break;
            case 5: 
                deleteMedicine();
                break;
            case 6: 
                printf("Exiting the system. Thank you!\n");
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}