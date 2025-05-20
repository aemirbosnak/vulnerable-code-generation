//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for medicine details
typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

// Array of medicines and their details
Medicine medicines[100];

// Count of medicines in stock
int count = 0;

// Function to add a medicine to stock
void addMedicine() {
    printf("\nEnter Medicine Name: ");
    scanf("%s", medicines[count].name);

    printf("Enter Medicine Quantity: ");
    scanf("%d", &medicines[count].quantity);

    printf("Enter Medicine Price: ");
    scanf("%f", &medicines[count].price);

    count++;
}

// Function to display all medicines in stock
void displayStock() {
    if (count == 0) {
        printf("\nNo Medicines in Stock\n");
        return;
    }

    printf("\nMedicine Name | Quantity | Price\n");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-13s| %-9d| %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Function to search for a medicine in stock
void searchMedicine() {
    if (count == 0) {
        printf("\nNo Medicines in Stock to Search\n");
        return;
    }

    char name[50];
    printf("\nEnter Name of Medicine to Search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("%-13s| %-9d| %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }

    printf("\nMedicine Not Found in Stock\n");
}

// Function to update medicine quantity in stock
void updateMedicine() {
    if (count == 0) {
        printf("\nNo Medicines in Stock to Update\n");
        return;
    }

    char name[50];
    printf("\nEnter Name of Medicine to Update Quantity: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            int quantity;
            printf("\nEnter Updated Quantity: ");
            scanf("%d", &quantity);

            medicines[i].quantity = quantity;
            printf("\nMedicine Quantity Updated\n");
            return;
        }
    }

    printf("\nMedicine Not Found in Stock\n");
}

int main() {
    int choice;
    do {
        printf("\n=========== Medical Store Management ===========\n");
        printf("1. Add Medicine to Stock\n");
        printf("2. Display all Medicines in Stock\n");
        printf("3. Search for a Medicine in Stock\n");
        printf("4. Update Medicine Quantity in Stock\n");
        printf("5. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayStock();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice. Please Try Again.\n");
        }

    } while (choice != 5);

    return 0;
}