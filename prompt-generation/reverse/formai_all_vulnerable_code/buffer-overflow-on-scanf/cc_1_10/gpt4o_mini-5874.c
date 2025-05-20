//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 150

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine store[MAX_PRODUCTS];
int productCount = 0;

void displayMenu();
void addMedicine();
void viewMedicines();
void updateMedicine();
void removeMedicine();
void searchMedicine();
int validateMenuChoice(int choice);

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (validateMenuChoice(choice)) {
            switch (choice) {
                case 1:
                    addMedicine();
                    break;
                case 2:
                    viewMedicines();
                    break;
                case 3:
                    updateMedicine();
                    break;
                case 4:
                    removeMedicine();
                    break;
                case 5:
                    searchMedicine();
                    break;
                case 6:
                    printf("Exiting the program.\n");
                    break;
                default:
                    printf("Invalid choice, please try again.\n");
            }
        } else {
            printf("Invalid menu choice. Please select a valid option.\n");
        }
        
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n---- Medical Store Management ----\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Remove Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
}

void addMedicine() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Cannot add more medicines, storage is full.\n");
        return;
    }
    
    Medicine med;
    med.id = productCount + 1; // Assigning a unique ID.
    
    printf("Enter medicine name: ");
    scanf(" %[^\n]", med.name);
    printf("Enter medicine description: ");
    scanf(" %[^\n]", med.description);
    printf("Enter medicine price: ");
    scanf("%f", &med.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &med.quantity);
    
    store[productCount++] = med; // Store medication in array.
    printf("Medicine added successfully.\n");
}

void viewMedicines() {
    if (productCount == 0) {
        printf("No medicines available currently.\n");
        return;
    }
    
    printf("\nAvailable Medicines:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Description: %s, Price: %.2f, Quantity: %d\n",
               store[i].id, store[i].name, store[i].description, store[i].price, store[i].quantity);
    }
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > productCount) {
        printf("Invalid Medicine ID.\n");
        return;
    }

    Medicine *med = &store[id - 1];
    printf("Updating Medicine ID: %d\n", med->id);
    printf("Current Name: %s, Enter new Name (or press enter to keep unchanged): ", med->name);
    char newName[NAME_LENGTH];
    scanf(" %[^\n]", newName);
    if (strlen(newName) > 0) {
        strcpy(med->name, newName);
    }

    printf("Current Description: %s, Enter new Description (or press enter to keep unchanged): ", med->description);
    char newDesc[DESC_LENGTH];
    scanf(" %[^\n]", newDesc);
    if (strlen(newDesc) > 0) {
        strcpy(med->description, newDesc);
    }
    
    printf("Enter new Price (or enter -1 to keep unchanged): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice >= 0) {
        med->price = newPrice;
    }
    
    printf("Enter new Quantity (or enter -1 to keep unchanged): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity >= 0) {
        med->quantity = newQuantity;
    }

    printf("Medicine updated successfully.\n");
}

void removeMedicine() {
    int id;
    printf("Enter medicine ID to remove: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Invalid Medicine ID.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        store[i] = store[i + 1]; // Shift the medicines down
    }
    productCount--; // Decrease product count
    printf("Medicine removed successfully.\n");
}

void searchMedicine() {
    char name[NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]", name);
    
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("Found Medicine: ID: %d, Name: %s, Description: %s, Price: %.2f, Quantity: %d\n",
                   store[i].id, store[i].name, store[i].description, store[i].price, store[i].quantity);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No medicine found with the name '%s'.\n", name);
    }
}

int validateMenuChoice(int choice) {
    return (choice >= 1 && choice <= 6);
}