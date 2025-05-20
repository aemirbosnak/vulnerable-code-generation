//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEDICINE 100

struct medicine {
    char name[50];
    int quantity;
    float price;
};

int count = 0;
struct medicine medicineList[MAX_MEDICINE];

int getMenuChoice() {
    int choice;
    printf("\n-----MEDICAL STORE MANAGEMENT SYSTEM-----\n");
    printf("\n1. Add Medicine");
    printf("\n2. Update Medicine");
    printf("\n3. Delete Medicine");
    printf("\n4. Search Medicine");
    printf("\n5. Display Medicine List");
    printf("\n6. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addMedicine() {
    if (count == MAX_MEDICINE) {
        printf("\nMemory is full. Cannot add more medicine.\n");
        return;
    }
    struct medicine newMedicine;
    printf("\nEnter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("\nEnter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("\nEnter medicine price: ");
    scanf("%f", &newMedicine.price);
    medicineList[count] = newMedicine;
    count++;
    printf("\nMedicine added successfully.\n");
}

void updateMedicine() {
    if (count == 0) {
        printf("\nMedicine list is empty. Cannot update medicine.\n");
        return;
    }
    char name[50];
    printf("\nEnter medicine name to update: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicineList[i].name, name) == 0) {
            printf("\nEnter new quantity: ");
            scanf("%d", &medicineList[i].quantity);
            printf("\nEnter new price: ");
            scanf("%f", &medicineList[i].price);
            printf("\nMedicine updated successfully.\n");
            return;
        }
    }
    printf("\nMedicine not found. Cannot update medicine.\n");
}

void deleteMedicine() {
    if (count == 0) {
        printf("\nMedicine list is empty. Cannot delete medicine.\n");
        return;
    }
    char name[50];
    printf("\nEnter medicine name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicineList[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                medicineList[j] = medicineList[j+1];
            }
            count--;
            printf("\nMedicine deleted successfully.\n");
            return;
        }
    }
    printf("\nMedicine not found. Cannot delete medicine.\n");
}

void searchMedicine() {
    if (count == 0) {
        printf("\nMedicine list is empty. Cannot search medicine.\n");
        return;
    }
    char name[50];
    printf("\nEnter medicine name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicineList[i].name, name) == 0) {
            printf("\nMedicine name: %s", medicineList[i].name);
            printf("\nMedicine quantity: %d", medicineList[i].quantity);
            printf("\nMedicine price: %.2f\n", medicineList[i].price);
            return;
        }
    }
    printf("\nMedicine not found.\n");
}

void displayMedicineList() {
    if (count == 0) {
        printf("\nMedicine list is empty.\n");
        return;
    }
    printf("\n-----MEDICINE LIST-----\n");
    for (int i = 0; i < count; i++) {
        printf("\nMedicine name: %s", medicineList[i].name);
        printf("\nMedicine quantity: %d", medicineList[i].quantity);
        printf("\nMedicine price: %.2f\n", medicineList[i].price);
    }
}

int main() {
    while (1) {
        int choice = getMenuChoice();
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                updateMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                displayMedicineList();
                break;
            case 6:
                printf("\nExiting...Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}