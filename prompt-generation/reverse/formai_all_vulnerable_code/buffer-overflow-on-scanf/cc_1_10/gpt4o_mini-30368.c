//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine store[MAX_MEDICINES];
int medCount = 0;

// Function prototypes
void addMedicine();
void modifyMedicine();
void deleteMedicine();
void displayMedicines();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Modify Medicine\n");
        printf("3. Delete Medicine\n");
        printf("4. Display Medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                modifyMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                displayMedicines();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addMedicine() {
    if (medCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines, storage is full!\n");
        return;
    }

    Medicine newMed;
    printf("Enter medicine name: ");
    fgets(newMed.name, sizeof(newMed.name), stdin);
    newMed.name[strcspn(newMed.name, "\n")] = 0; // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &newMed.quantity);
    printf("Enter price: ");
    scanf("%f", &newMed.price);
    clearInputBuffer();

    store[medCount++] = newMed;
    printf("Medicine added successfully!\n");
}

void modifyMedicine() {
    char name[50];
    printf("Enter the name of the medicine to modify: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    for (int i = 0; i < medCount; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("Current quantity: %d, Current price: %.2f\n", store[i].quantity, store[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &store[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &store[i].price);
            clearInputBuffer();
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter the name of the medicine to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    for (int i = 0; i < medCount; i++) {
        if (strcmp(store[i].name, name) == 0) {
            for (int j = i; j < medCount - 1; j++) {
                store[j] = store[j + 1];
            }
            medCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void displayMedicines() {
    if (medCount == 0) {
        printf("No medicines available!\n");
        return;
    }

    printf("\nList of Medicines:\n");
    printf("%-30s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < medCount; i++) {
        printf("%-30s %-10d %-10.2f\n", store[i].name, store[i].quantity, store[i].price);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n') {} // Clear the input buffer
}