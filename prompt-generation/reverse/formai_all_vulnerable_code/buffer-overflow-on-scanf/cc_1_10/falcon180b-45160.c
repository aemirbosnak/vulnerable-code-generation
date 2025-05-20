//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Function to print menu
void printMenu(MenuItem menu[], int numItems) {
    printf("=== Cafe Menu ===\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take order and calculate total cost
void takeOrder(MenuItem menu[], int numItems) {
    int choice;
    float totalCost = 0.0;

    printf("Enter the number of the item you want to order:\n");
    scanf("%d", &choice);

    // Check if choice is valid
    if (choice < 1 || choice > numItems) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // Add item to order and calculate total cost
    printf("You ordered %s for $%.2f.\n", menu[choice-1].name, menu[choice-1].price);
    totalCost += menu[choice-1].price;

    printf("Your total cost is $%.2f.\n", totalCost);
}

// Function to handle payment
void payment(float totalCost) {
    printf("Please enter the amount you want to pay:\n");
    float payment;
    scanf("%f", &payment);

    // Check if payment is enough
    if (payment < totalCost) {
        printf("Insufficient payment. Please try again.\n");
        return;
    }

    // Payment successful
    printf("Payment successful. Thank you for your business!\n");
}

int main() {
    // Define menu items
    MenuItem menu[] = {{"Coffee", 2.99}, {"Tea", 1.99}, {"Donut", 0.99}, {"Bagel", 1.49}};
    int numItems = sizeof(menu)/sizeof(MenuItem);

    // Loop until user wants to exit
    while(1) {
        printf("=== Welcome to the Cafe ===\n");
        printf("1. View menu\n2. Place order\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        // Handle user choice
        switch(choice) {
        case 1:
            printMenu(menu, numItems);
            break;
        case 2:
            takeOrder(menu, numItems);
            break;
        case 3:
            printf("Thank you for visiting the Cafe. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}