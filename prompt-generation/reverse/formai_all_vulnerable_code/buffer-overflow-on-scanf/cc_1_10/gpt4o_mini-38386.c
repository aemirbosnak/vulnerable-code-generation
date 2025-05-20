//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
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

Medicine store[MAX_MEDICINES];
int count = 0;

void addMedicine();
void deleteMedicine();
void viewMedicines();
void searchMedicine();
void displayMenu();
void pause();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                deleteMedicine();
                break;
            case 3:
                viewMedicines();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        pause();
    }

    return 0;
}

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("Store is full, cannot add more medicines.\n");
        return;
    }
    
    Medicine newMedicine;
    
    printf("Enter Medicine ID: ");
    scanf("%d", &newMedicine.id);
    
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]", newMedicine.name); // Reads string with spaces
    
    printf("Enter Quantity: ");
    scanf("%d", &newMedicine.quantity);
    
    printf("Enter Price: ");
    scanf("%f", &newMedicine.price);
    
    store[count++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void deleteMedicine() {
    int id, i, found = 0;
    
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
    
    for (i = 0; i < count; i++) {
        if (store[i].id == id) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                store[j] = store[j + 1];
            }
            count--;
            printf("Medicine deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Medicine with ID %d not found.\n", id);
    }
}

void viewMedicines() {
    if (count == 0) {
        printf("No medicines in the store.\n");
        return;
    }
    
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", store[i].id, store[i].name, store[i].quantity, store[i].price);
    }
}

void searchMedicine() {
    int id, found = 0;
    
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (store[i].id == id) {
            printf("Medicine found!\n");
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   store[i].id, store[i].name, store[i].quantity, store[i].price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Medicine with ID %d not found.\n", id);
    }
}

void displayMenu() {
    printf("\n===== Medical Store Management System =====\n");
    printf("1. Add Medicine\n");
    printf("2. Delete Medicine\n");
    printf("3. View Medicines\n");
    printf("4. Search Medicine\n");
    printf("5. Exit\n");
}

void pause() {
    printf("Press Enter to continue...");
    while (getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for user to press Enter
}