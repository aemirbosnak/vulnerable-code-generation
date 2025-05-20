//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

void addMedicine(medicine *med, int *size) {
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]%*c", med->name);
    printf("Enter Quantity: ");
    scanf("%d", &med->quantity);
    printf("Enter Price: ");
    scanf("%f", &med->price);
    (*size)++;
}

void displayMedicine(medicine *med, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

void searchMedicineByName(medicine *med, int size) {
    char name[50];
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]%*c", name);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("%s\t%d\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void searchMedicineByPriceRange(medicine *med, int size) {
    float minPrice, maxPrice;
    printf("Enter Minimum Price: ");
    scanf("%f", &minPrice);
    printf("Enter Maximum Price: ");
    scanf("%f", &maxPrice);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (med[i].price >= minPrice && med[i].price <= maxPrice) {
            printf("%s\t%d\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No medicines found in that price range!\n");
    }
}

void sellMedicine(medicine *med, int *size) {
    char name[50];
    int quantity;
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]%*c", name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(med[i].name, name) == 0) {
            if (med[i].quantity >= quantity) {
                med[i].quantity -= quantity;
                printf("Medicine sold successfully!\n");
                found = 1;
            } else {
                printf("Insufficient quantity!\n");
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

int main() {
    medicine med[100];
    int choice, size = 0;
    do {
        printf("\n\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicine\n");
        printf("3. Search Medicine by Name\n");
        printf("4. Search Medicine by Price Range\n");
        printf("5. Sell Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(med, &size);
                break;
            case 2:
                displayMedicine(med, size);
                break;
            case 3:
                searchMedicineByName(med, size);
                break;
            case 4:
                searchMedicineByPriceRange(med, size);
                break;
            case 5:
                sellMedicine(med, &size);
                break;
        }
    } while (choice != 6);
    return 0;
}