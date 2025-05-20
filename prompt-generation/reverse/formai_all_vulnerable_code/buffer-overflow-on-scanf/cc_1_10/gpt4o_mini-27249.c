//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Inventory full!\n");
        return;
    }
    
    Medicine new_medicine;
    printf("Enter medicine ID: ");
    scanf("%d", &new_medicine.id);
    printf("Enter medicine name: ");
    getchar(); // Consume newline character
    fgets(new_medicine.name, NAME_LENGTH, stdin);
    new_medicine.name[strcspn(new_medicine.name, "\n")] = 0; // Remove newline
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);
    
    medicines[medicine_count++] = new_medicine;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicine_count == 0) {
        printf("No medicines available in the store.\n");
        return;
    }
    
    printf("\nMedicine List:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void searchMedicine() {
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            printf("Medicine found: %s, Quantity: %d, Price: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("Medicine with ID %d not found!\n", id);
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            printf("Updating medicine: %s\n", medicines[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine with ID %d not found for update!\n", id);
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < medicine_count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicine_count--;
            printf("Medicine with ID %d has been deleted!\n", id);
            return;
        }
    }
    printf("Medicine with ID %d not found for deletion!\n", id);
}

void displayMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
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
                printf("Exiting the program. Thank you for using the Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}