//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char category[30];
    float price;
    int quantity;
} Medicine;

Medicine stock[MAX_MEDICINES];
int totalMedicines = 0;

void addMedicine();
void viewMedicines();
void sellMedicine();
void searchMedicine();
void updateMedicine();
void printMenu();

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: sellMedicine(); break;
            case 4: searchMedicine(); break;
            case 5: updateMedicine(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Please try again.\n"); break;
        }
    }
    return 0;
}

void printMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Update Medicine\n");
    printf("6. Exit\n");
}

void addMedicine() {
    if (totalMedicines < MAX_MEDICINES) {
        Medicine newMedicine;
        printf("Enter medicine name: ");
        scanf("%s", newMedicine.name);
        printf("Enter category: ");
        scanf("%s", newMedicine.category);
        printf("Enter price: ");
        scanf("%f", &newMedicine.price);
        printf("Enter quantity: ");
        scanf("%d", &newMedicine.quantity);

        stock[totalMedicines++] = newMedicine;
        printf("Medicine added successfully!\n");
    } else {
        printf("Stock is full! Cannot add more medicines.\n");
    }
}

void viewMedicines() {
    printf("\n--- List of Medicines ---\n");
    for (int i = 0; i < totalMedicines; i++) {
        printf("Name: %s, Category: %s, Price: %.2f, Quantity: %d\n",
               stock[i].name, stock[i].category, stock[i].price, stock[i].quantity);
    }
}

void sellMedicine() {
    char name[50];
    int quantity;
    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < totalMedicines; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            if (stock[i].quantity >= quantity) {
                stock[i].quantity -= quantity;
                printf("Sold %d of %s. Total cost: %.2f\n", quantity, stock[i].name, stock[i].price * quantity);
            } else {
                printf("Insufficient stock! Available quantity: %d\n", stock[i].quantity);
            }
            return;
        }
    }
    printf("Medicine not found!\n");
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    for (int i = 0; i < totalMedicines; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            printf("Found: Name: %s, Category: %s, Price: %.2f, Quantity: %d\n",
                   stock[i].name, stock[i].category, stock[i].price, stock[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void updateMedicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);

    for (int i = 0; i < totalMedicines; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &stock[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &stock[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}