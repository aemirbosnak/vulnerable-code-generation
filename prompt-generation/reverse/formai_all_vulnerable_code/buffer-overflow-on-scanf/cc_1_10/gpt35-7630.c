//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare structure for medicine details
struct medicine {
    char name[100];
    int code;
    float price;
    int quantity;
} med[100];

// Function to add medicine to inventory
void addMedicine() {
    int num;
    printf("\nEnter number of medicines to add: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("\nEnter details of medicine #%d: ", i+1);
        printf("\nName: ");
        scanf("%s", med[i].name);
        printf("Code: ");
        scanf("%d", &med[i].code);
        printf("Price: ");
        scanf("%f", &med[i].price);
        printf("Quantity: ");
        scanf("%d", &med[i].quantity);
    }
    printf("\nMedicine added successfully!\n");
}

// Function to search for medicine by code and update quantity
void updateQuantity() {
    int code, qty;
    printf("\nEnter medicine code to update quantity: ");
    scanf("%d", &code);
    for (int i = 0; i < 100; i++) {
        if (med[i].code == code) {
            printf("\nEnter quantity to add: ");
            scanf("%d", &qty);
            med[i].quantity += qty;
            printf("\nQuantity updated successfully!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

// Function to search for medicine by name and display details
void searchMedicine() {
    char name[100];
    int count = 0;
    printf("\nEnter medicine name to search: ");
    scanf("%s", name);
    printf("\nSearched medicine details:\n");
    for (int i = 0; i < 100; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("\nName: %s\nCode: %d\nPrice: %.2f\nQuantity: %d\n", med[i].name, med[i].code, med[i].price, med[i].quantity);
            count++;
        }
    }
    if (count == 0) {
        printf("\nMedicine not found!\n");
    }
}

int main() {
    int choice;
    printf("Welcome to the Medical Store Management System!\n");
    do {
        printf("\n*************************************\n");
        printf("1. Add medicine to inventory\n");
        printf("2. Update medicine quantity\n");
        printf("3. Search medicine by name\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                updateQuantity();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                printf("\nThank you for using the Medical Store Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (1);
    return 0;
}