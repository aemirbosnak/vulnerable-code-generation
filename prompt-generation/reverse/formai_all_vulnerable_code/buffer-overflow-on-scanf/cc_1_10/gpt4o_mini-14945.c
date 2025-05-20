//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: realistic
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

Medicine meds[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Medicine limit reached! Cannot add more medicines.\n");
        return;
    }

    Medicine new_medicine;

    printf("Enter Medicine ID: ");
    scanf("%d", &new_medicine.id);
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]s", new_medicine.name);
    printf("Enter Quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter Price: ");
    scanf("%f", &new_medicine.price);

    meds[medicine_count++] = new_medicine;
    printf("Medicine Added Successfully!\n");
}

void displayMedicines() {
    if (medicine_count == 0) {
        printf("No medicines to display.\n");
        return;
    }
    
    printf("\nAvailable Medicines:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("--\t----\t\t--------\t-----\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", meds[i].id, meds[i].name, meds[i].quantity, meds[i].price);
    }
}

void updateMedicine() {
    int id, found = 0;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < medicine_count; i++) {
        if (meds[i].id == id) {
            found = 1;
            printf("Updating details for %s\n", meds[i].name);
            printf("Updating Quantity (current: %d): ", meds[i].quantity);
            scanf("%d", &meds[i].quantity);
            printf("Updating Price (current: %.2f): ", meds[i].price);
            scanf("%f", &meds[i].price);
            printf("Medicine Updated Successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Medicine ID %d not found.\n", id);
    }
}

void deleteMedicine() {
    int id, found = 0;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < medicine_count; i++) {
        if (meds[i].id == id) {
            found = 1;
            for (int j = i; j < medicine_count - 1; j++) {
                meds[j] = meds[j + 1];
            }
            medicine_count--;
            printf("Medicine ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Medicine ID %d not found.\n", id);
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
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
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}