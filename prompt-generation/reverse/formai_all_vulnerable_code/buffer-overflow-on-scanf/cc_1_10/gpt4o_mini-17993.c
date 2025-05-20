//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine store[MAX_MEDICINES];
int count = 0;

// Function prototypes
void addMedicine();
void displayMedicines();
void searchMedicine();
void displayMenu();

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
                printf("Exiting the program. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Exit\n");
}

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("Cannot add more medicines, the store is full!\n");
        return;
    }

    Medicine newMed;
    printf("Enter medicine name: ");
    scanf("%s", newMed.name);
    printf("Enter manufacturer: ");
    scanf("%s", newMed.manufacturer);
    printf("Enter price: ");
    scanf("%f", &newMed.price);
    printf("Enter quantity: ");
    scanf("%d", &newMed.quantity);

    store[count++] = newMed; // Add new medicine to the store
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (count == 0) {
        printf("No medicines available in the store.\n");
        return;
    }
    
    printf("\nList of Medicines:\n");
    printf("Name\t\tManufacturer\t\tPrice\t\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%.2f\t\t%d\n", store[i].name, store[i].manufacturer, store[i].price, store[i].quantity);
    }
}

void searchMedicine() {
    char searchName[50];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, searchName) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", store[i].name);
            printf("Manufacturer: %s\n", store[i].manufacturer);
            printf("Price: %.2f\n", store[i].price);
            printf("Quantity: %d\n", store[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine '%s' not found in the store.\n", searchName);
    }
}