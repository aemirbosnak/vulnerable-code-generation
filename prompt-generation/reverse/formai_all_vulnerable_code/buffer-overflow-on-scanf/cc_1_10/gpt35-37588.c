//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 1000

typedef struct {
    int id;
    char name[100];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int numMedicines = 0;

// function prototypes
void addMedicine();
void displayMedicines();
void searchMedicine();
void sellMedicine();

int main() {
    int choice;
    do {
        printf("Welcome to the Medical Store Management System!\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
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
                searchMedicine();
                break;
            case 4:
                sellMedicine();
                break;
            case 5:
                printf("Thanks for using the Medical Store Management System!");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

void addMedicine() {
    if (numMedicines == MAX_MEDICINES) {
        printf("Medicine store is full!\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine details:\n");
    printf("ID: ");
    scanf("%d", &newMedicine.id);
    printf("Name: ");
    scanf("%s", newMedicine.name);
    printf("Quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Price: ");
    scanf("%f", &newMedicine.price);

    medicines[numMedicines++] = newMedicine;
}

void displayMedicines() {
    if (numMedicines == 0) {
        printf("Medicine store is empty!\n");
        return;
    }

    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < numMedicines; i++) {
        Medicine current = medicines[i];
        printf("%d\t%s\t%d\t\t%.2f\n", current.id, current.name, current.quantity, current.price);
    }
}

void searchMedicine() {
    if (numMedicines == 0) {
        printf("Medicine store is empty!\n");
        return;
    }

    int searchId;
    printf("Enter medicine ID to search: ");
    scanf("%d", &searchId);

    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        Medicine current = medicines[i];
        if (current.id == searchId) {
            printf("ID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%.2f\n", current.id, current.name, current.quantity, current.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void sellMedicine() {
    if (numMedicines == 0) {
        printf("Medicine store is empty!\n");
        return;
    }

    int sellId;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &sellId);

    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        Medicine *current = &medicines[i];
        if (current->id == sellId) {
            printf("Enter quantity to sell: ");
            int sellQuantity;
            scanf("%d", &sellQuantity);
            if (sellQuantity > current->quantity) {
                printf("Insufficient stock!\n");
            } else {
                current->quantity -= sellQuantity;
                printf("Total price: %.2f\n", sellQuantity * current->price);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}