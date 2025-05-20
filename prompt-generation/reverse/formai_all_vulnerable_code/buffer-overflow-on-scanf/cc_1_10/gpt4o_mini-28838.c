//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char expiryDate[11];
    int quantity;
    float price;
} Medicine;

Medicine store[MAX_MEDICINES];
int count = 0;

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("Store is full! Cannot add more medicines.\n");
        return;
    }

    Medicine m;
    printf("Enter the medicine name: ");
    scanf("%s", m.name);
    printf("Enter the expiry date (YYYY-MM-DD): ");
    scanf("%s", m.expiryDate);
    printf("Enter the quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter the price: ");
    scanf("%f", &m.price);

    store[count++] = m;
    printf("Medicine added successfully!\n");
    return;
}

void updateMedicine() {
    char name[50];
    printf("Enter the medicine name to update: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("Updating Medicine: %s\n", store[i].name);
            printf("New Expiry Date: ");
            scanf("%s", store[i].expiryDate);
            printf("New Quantity: ");
            scanf("%d", &store[i].quantity);
            printf("New Price: ");
            scanf("%f", &store[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter the medicine name to delete: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                store[j] = store[j + 1];
            }
            count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void displayMedicines() {
    if (count == 0) {
        printf("No medicines in the store.\n");
        return;
    }

    printf("\nMedicines in Store:\n");
    for(int i = 0; i < count; i++) {
        printf("Name: %s, Expiry Date: %s, Quantity: %d, Price: %.2f\n",
               store[i].name, store[i].expiryDate, store[i].quantity, store[i].price);
    }
}

void menu() {
    int choice;
    
    while(1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Update Medicine\n");
        printf("3. Delete Medicine\n");
        printf("4. Display Medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addMedicine(); break;
            case 2: updateMedicine(); break;
            case 3: deleteMedicine(); break;
            case 4: displayMedicines(); break;
            case 5: printf("Exiting the system...\n"); exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}