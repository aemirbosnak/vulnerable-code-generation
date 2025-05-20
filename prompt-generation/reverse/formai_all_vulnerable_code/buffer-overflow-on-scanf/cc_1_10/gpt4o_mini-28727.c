//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
} Medicine;

void displayMedicines(Medicine med[], int count);
void addMedicine(Medicine med[], int *count);
void searchMedicine(Medicine med[], int count);
void purchaseMedicine(Medicine med[], int count);
void showMenu();

int main() {
    Medicine medications[MAX_MEDICINES];
    int count = 0;
    int choice;

    while (1) {
        showMenu();
        printf("Choose thy fate: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medications, &count);
                break;
            case 2:
                displayMedicines(medications, count);
                break;
            case 3:
                searchMedicine(medications, count);
                break;
            case 4:
                purchaseMedicine(medications, count);
                break;
            case 5:
                printf("Farewell, dear healer!\n");
                exit(0);
            default:
                printf("Alas! Such choice is unknown!\n");
                break;
        }
    }
    return 0;
}

void showMenu() {
    printf("\n--- The Medical Store of Verona ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Purchase Medicine\n");
    printf("5. Exit\n");
}

void addMedicine(Medicine med[], int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Alas! The stock is full. No more additions!\n");
        return;
    }
    printf("Enter the name of the medicine: ");
    scanf("%s", med[*count].name);
    printf("Enter the manufacturer of the medicine: ");
    scanf("%s", med[*count].manufacturer);
    printf("Enter the quantity: ");
    scanf("%d", &med[*count].quantity);
    printf("Enter the price: ");
    scanf("%f", &med[*count].price);
    (*count)++;
    printf("Oh joyous day! The medicine hath been added!\n");
}

void displayMedicines(Medicine med[], int count) {
    if (count == 0) {
        printf("The shelves are empty, not a remedy in sight!\n");
        return;
    }
    printf("\n--- Displaying All Medicines ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Manufacturer: %s, Quantity: %d, Price: %.2f\n", med[i].name, med[i].manufacturer, med[i].quantity, med[i].price);
    }
}

void searchMedicine(Medicine med[], int count) {
    char name[50];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("Found: %s by %s, Quantity: %d, Price: %.2f\n", med[i].name, med[i].manufacturer, med[i].quantity, med[i].price);
            return;
        }
    }
    printf("O woe! The medicine thou seekest is not in this kingdom.\n");
}

void purchaseMedicine(Medicine med[], int count) {
    char name[50];
    int qty;
    printf("Enter the name of the medicine to purchase: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("Enter quantity to purchase: ");
            scanf("%d", &qty);
            if (qty > med[i].quantity) {
                printf("Alas! Not enough stock to fulfill this order!\n");
            } else {
                med[i].quantity -= qty;
                printf("Purchased %d of '%s'. Thou art wiser now!\n", qty, med[i].name);
            }
            return;
        }
    }
    printf("O woe! The medicine thou seekest is not in this kingdom.\n");
}