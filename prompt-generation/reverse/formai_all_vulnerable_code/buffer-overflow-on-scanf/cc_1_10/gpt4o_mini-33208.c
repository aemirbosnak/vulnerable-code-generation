//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 5

// Structure to hold item information
typedef struct {
    char name[30];
    float price;
} MenuItem;

// Function prototypes
void displayMenu(MenuItem items[], int size);
void calculateBill(MenuItem items[], int size);
float applyTax(float amount);

int main() {
    MenuItem items[MAX_ITEMS] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Sandwich", 5.00},
        {"Cake", 3.50},
        {"Juice", 2.00}
    };

    int choice;

    do {
        printf("Welcome to the Cafe Billing System\n");
        printf("1. Display Menu\n");
        printf("2. Calculate Bill\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(items, MAX_ITEMS);
                break;
            case 2:
                calculateBill(items, MAX_ITEMS);
                break;
            case 3:
                printf("Thank you for visiting!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

// Function to display the menu
void displayMenu(MenuItem items[], int size) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
    printf("------------------\n");
}

// Function to calculate the bill
void calculateBill(MenuItem items[], int size) {
    int quantities[MAX_ITEMS] = {0};
    char choice;

    printf("\n--- Calculate Your Bill ---\n");

    for (int i = 0; i < size; i++) {
        printf("Enter quantity for %s (or 0 to skip): ", items[i].name);
        scanf("%d", &quantities[i]);
    }

    float total = 0;

    for (int i = 0; i < size; i++) {
        total += items[i].price * quantities[i];
    }

    float tax = applyTax(total);
    float finalTotal = total + tax;

    printf("\n--- Bill Summary ---\n");
    for (int i = 0; i < size; i++) {
        if (quantities[i] > 0) {
            printf("%s x%d = $%.2f\n", items[i].name, quantities[i], items[i].price * quantities[i]);
        }
    }
    printf("Subtotal: $%.2f\n", total);
    printf("Tax (10%%): $%.2f\n", tax);
    printf("Total: $%.2f\n", finalTotal);
    printf("---------------------\n");
}

// Function to apply tax on the total amount
float applyTax(float amount) {
    return amount * 0.10; // 10% tax
}