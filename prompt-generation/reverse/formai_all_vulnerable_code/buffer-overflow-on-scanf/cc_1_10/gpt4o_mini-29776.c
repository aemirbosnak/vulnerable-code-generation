//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine medicalStore[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Storage is full.\n");
        return;
    }

    Medicine newMedicine;

    printf("Enter Medicine ID: ");
    scanf("%d", &newMedicine.id);
    
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]", newMedicine.name);
    
    printf("Enter Manufacturer Name: ");
    scanf(" %[^\n]", newMedicine.manufacturer);
    
    printf("Enter Price: ");
    scanf("%f", &newMedicine.price);
    
    printf("Enter Quantity: ");
    scanf("%d", &newMedicine.quantity);

    medicalStore[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available in the store.\n");
        return;
    }

    printf("\nList of Medicines:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tQuantity\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", medicalStore[i].id, medicalStore[i].name, medicalStore[i].manufacturer, medicalStore[i].price, medicalStore[i].quantity);
    }
}

void updateMedicine() {
    int id;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (medicalStore[i].id == id) {
            printf("Updating Medicine: %s\n", medicalStore[i].name);
            printf("Enter new Name: ");
            scanf(" %[^\n]", medicalStore[i].name);
            printf("Enter new Manufacturer Name: ");
            scanf(" %[^\n]", medicalStore[i].manufacturer);
            printf("Enter new Price: ");
            scanf("%f", &medicalStore[i].price);
            printf("Enter new Quantity: ");
            scanf("%d", &medicalStore[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void deleteMedicine() {
    int id;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (medicalStore[i].id == id) {
            for (int j = i; j < medicineCount - 1; j++) {
                medicalStore[j] = medicalStore[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void searchMedicine() {
    int id;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (medicalStore[i].id == id) {
            printf("Medicine found: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
                   medicalStore[i].name, medicalStore[i].manufacturer, medicalStore[i].price, medicalStore[i].quantity);
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void showMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("Exiting the program. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}