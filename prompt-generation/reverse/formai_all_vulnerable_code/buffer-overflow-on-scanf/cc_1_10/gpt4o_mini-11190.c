//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50
#define CODE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine store[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine();
void viewMedicines();
void searchMedicine();
void updateMedicine();
void deleteMedicine();

int main() {
    int choice;

    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: updateMedicine(); break;
            case 5: deleteMedicine(); break;
            case 6: printf("Exiting the system. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Database is full!\n");
        return;
    }

    Medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter medicine code: ");
    scanf("%s", m.code);
    printf("Enter medicine price: ");
    scanf("%f", &m.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m.quantity);

    store[medicine_count++] = m;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicine_count == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\n--- List of Medicines ---\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("Name: %s, Code: %s, Price: %.2f, Quantity: %d\n", 
               store[i].name, store[i].code, store[i].price, store[i].quantity);
    }
}

void searchMedicine() {
    char code[CODE_LENGTH];
    printf("Enter medicine code to search: ");
    scanf("%s", code);

    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(store[i].code, code) == 0) {
            printf("Medicine found: Name: %s, Price: %.2f, Quantity: %d\n", 
                   store[i].name, store[i].price, store[i].quantity);
            return;
        }
    }

    printf("Medicine with code %s not found.\n", code);
}

void updateMedicine() {
    char code[CODE_LENGTH];
    printf("Enter medicine code to update: ");
    scanf("%s", code);

    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(store[i].code, code) == 0) {
            printf("Updating medicine: %s\n", store[i].name);
            printf("Enter new price: ");
            scanf("%f", &store[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &store[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }

    printf("Medicine with code %s not found.\n", code);
}

void deleteMedicine() {
    char code[CODE_LENGTH];
    printf("Enter medicine code to delete: ");
    scanf("%s", code);

    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(store[i].code, code) == 0) {
            for (int j = i; j < medicine_count - 1; j++) {
                store[j] = store[j + 1];
            }
            medicine_count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }

    printf("Medicine with code %s not found.\n", code);
}