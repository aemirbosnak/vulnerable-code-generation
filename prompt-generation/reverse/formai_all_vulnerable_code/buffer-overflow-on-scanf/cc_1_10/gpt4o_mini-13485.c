//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold medicine details
typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int stock;
} Medicine;

// Function prototypes
void addMedicine(Medicine inventory[], int *count);
void displayMedicines(Medicine inventory[], int count);
void searchMedicine(Medicine inventory[], int count);
void updateStock(Medicine inventory[], int count);
void deleteMedicine(Medicine inventory[], int *count);

int main() {
    Medicine inventory[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- VIRTUAL MEDICAL STORE MANAGEMENT SYSTEM ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Stock\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                displayMedicines(inventory, count);
                break;
            case 3:
                searchMedicine(inventory, count);
                break;
            case 4:
                updateStock(inventory, count);
                break;
            case 5:
                deleteMedicine(inventory, &count);
                break;
            case 6:
                printf("Exiting the system. Thank you for using the Virtual Medical Store!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void addMedicine(Medicine inventory[], int *count) {
    printf("Enter Medicine ID: ");
    scanf("%d", &inventory[*count].id);
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]", inventory[*count].name);
    printf("Enter Manufacturer Name: ");
    scanf(" %[^\n]", inventory[*count].manufacturer);
    printf("Enter Price: ");
    scanf("%f", &inventory[*count].price);
    printf("Enter Stock Quantity: ");
    scanf("%d", &inventory[*count].stock);
    (*count)++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(Medicine inventory[], int count) {
    if(count == 0) {
        printf("No medicines available in the inventory.\n");
        return;
    }
    printf("\n--- MEDICINE INVENTORY ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Manufacturer: %s\n", inventory[i].manufacturer);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Stock: %d\n", inventory[i].stock);
        printf("---------------------------\n");
    }
}

void searchMedicine(Medicine inventory[], int count) {
    int id, found = 0;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Medicine found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Manufacturer: %s\n", inventory[i].manufacturer);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Stock: %d\n", inventory[i].stock);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine with ID %d not found.\n", id);
    }
}

void updateStock(Medicine inventory[], int count) {
    int id, newStock, found = 0;
    printf("Enter Medicine ID to update stock: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Current stock of %s: %d\n", inventory[i].name, inventory[i].stock);
            printf("Enter new stock quantity: ");
            scanf("%d", &newStock);
            inventory[i].stock = newStock;
            printf("Stock updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine with ID %d not found.\n", id);
    }
}

void deleteMedicine(Medicine inventory[], int *count) {
    int id, found = 0;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Medicine deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine with ID %d not found.\n", id);
    }
}