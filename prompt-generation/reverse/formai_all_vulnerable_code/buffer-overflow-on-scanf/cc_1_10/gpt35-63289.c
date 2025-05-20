//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information of a medicine 
typedef struct {
    int id;
    char name[20];
    float price;
    int quantity;
} Medicine;

// Function to display menu and get user's choice 
int getMenuChoice() {
    int choice;
    printf("\n\n--- Medical Store Management System ---\n\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicine\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search for Medicine\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new medicine 
void addMedicine(Medicine *medicines, int *medicineCount) {
    Medicine medicine;
    printf("\nEnter ID: ");
    scanf("%d", &medicine.id);
    printf("Enter Name: ");
    scanf("%s", medicine.name);
    printf("Enter Price: ");
    scanf("%f", &medicine.price);
    printf("Enter Quantity: ");
    scanf("%d", &medicine.quantity);
    medicines[*medicineCount] = medicine;
    (*medicineCount)++;
    printf("\nMedicine added successfully!\n");
}

// Function to display all the medicines 
void viewMedicines(Medicine *medicines, int medicineCount) {
    if (medicineCount == 0) {
        printf("\nNo medicines found.\n");
        return;
    }
    printf("\n--- Medicines ---\n\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < medicineCount; i++) {
        Medicine medicine = medicines[i];
        printf("%d\t%s\t\t%.2f\t%d\n", medicine.id, medicine.name, medicine.price, medicine.quantity);
    }
}

// Function to update information of a medicine 
void updateMedicine(Medicine *medicines, int medicineCount) {
    if (medicineCount == 0) {
        printf("\nNo medicines found.\n");
        return;
    }
    int id;
    printf("\nEnter ID of medicine to update: ");
    scanf("%d", &id);
    for (int i = 0; i < medicineCount; i++) {
        Medicine *medicine = &medicines[i];
        if (medicine->id == id) {
            printf("Enter new Name: ");
            scanf("%s", medicine->name);
            printf("Enter new Price: ");
            scanf("%f", &medicine->price);
            printf("Enter new Quantity: ");
            scanf("%d", &medicine->quantity);
            printf("\nMedicine updated successfully!\n");
            return;
        }
    }
    printf("\nMedicine with ID %d not found.\n", id);
}

// Function to delete a medicine 
void deleteMedicine(Medicine *medicines, int *medicineCount) {
    if (*medicineCount == 0) {
        printf("\nNo medicines found.\n");
        return;
    }
    int id;
    printf("\nEnter ID of medicine to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *medicineCount; i++) {
        Medicine *medicine = &medicines[i];
        if (medicine->id == id) {
            for (int j = i + 1; j < *medicineCount; j++) {
                medicines[j-1] = medicines[j];
            }
            (*medicineCount)--;
            printf("\nMedicine deleted successfully!\n");
            return;
        }
    }
    printf("\nMedicine with ID %d not found.\n", id);
}

// Function to search for a medicine by name or ID 
void searchMedicine(Medicine *medicines, int medicineCount) {
    if (medicineCount == 0) {
        printf("\nNo medicines found.\n");
        return;
    }
    char search[20];
    printf("\nEnter name or ID to search: ");
    scanf("%s", search);
    printf("\n--- Search Results ---\n\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < medicineCount; i++) {
        Medicine medicine = medicines[i];
        if (medicine.id == atoi(search) || strstr(medicine.name, search) != NULL) {
            printf("%d\t%s\t\t%.2f\t%d\n", medicine.id, medicine.name, medicine.price, medicine.quantity);
        }
    }
}

int main() {
    Medicine medicines[100];
    int medicineCount = 0;
    int choice;
    while ((choice = getMenuChoice()) != 6) {
        switch (choice) {
            case 1: addMedicine(medicines, &medicineCount); break;
            case 2: viewMedicines(medicines, medicineCount); break;
            case 3: updateMedicine(medicines, medicineCount); break;
            case 4: deleteMedicine(medicines, &medicineCount); break;
            case 5: searchMedicine(medicines, medicineCount); break;
            default: printf("\nInvalid choice. Try again.\n"); break;
        }
    }
    printf("\nExiting Medical Store Management System...\n");
    return 0;
}