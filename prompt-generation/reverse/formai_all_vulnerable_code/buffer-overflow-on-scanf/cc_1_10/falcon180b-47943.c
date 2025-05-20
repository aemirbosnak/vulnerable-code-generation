//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define structure for menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Function to display menu
void displayMenu(MenuItem menu[], int size) {
    printf("Welcome to our Cafe!\n");
    printf("---------------------\n");
    for(int i=0; i<size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take order
void takeOrder(MenuItem menu[], int size, float total) {
    int choice;
    printf("Please enter your choice:\n");
    scanf("%d", &choice);
    total += menu[choice-1].price;
    printf("Your order has been placed. Thank you!\n");
    printf("Total cost: $%.2f\n", total);
}

// Function to calculate tax
float calculateTax(float total) {
    float tax = 0.10 * total;
    return tax;
}

// Function to print receipt
void printReceipt(float total, float tax) {
    printf("RECEIPT\n");
    printf("---------------------\n");
    printf("Total cost: $%.2f\n", total);
    printf("Tax: $%.2f\n", tax);
    printf("---------------------\n");
    printf("Thank you for your visit!\n");
}

int main() {
    // Define menu items
    MenuItem menu[] = {{"Coffee", 2.50}, {"Tea", 3.00}, {"Cake", 4.50}, {"Sandwich", 5.00}};
    int size = sizeof(menu)/sizeof(menu[0]);

    // Initialize total cost
    float total = 0.00;

    // Display menu
    displayMenu(menu, size);

    // Take order
    takeOrder(menu, size, total);

    // Calculate tax
    float tax = calculateTax(total);

    // Print receipt
    printReceipt(total, tax);

    return 0;
}