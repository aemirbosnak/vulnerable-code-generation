//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the items in the cafe
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Function declarations
void displayMenu(MenuItem items[], int size);
void calculateBill(MenuItem items[], int size);

int main() {
    // Array of menu items
    MenuItem menu[] = {
        {"Espresso", 2.50},
        {"Latte", 3.50},
        {"Cappuccino", 3.00},
        {"Black Coffee", 2.00},
        {"Tea", 1.50},
        {"Sandwich", 5.00},
        {"Salad", 4.00},
        {"Cake", 2.50},
        {"Cookies", 1.00}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    // Let the user interact with the Cafe Billing System
    printf("Welcome to the Curiosity Cafe!\n");
    while (1) {
        int choice;
        printf("\nPlease choose an option:\n");
        printf("1. View Menu\n");
        printf("2. Calculate Bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(menu, menuSize);
                break;
            case 2:
                calculateBill(menu, menuSize);
                break;
            case 3:
                printf("Thank you for visiting Curiosity Cafe! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to display the cafe menu
void displayMenu(MenuItem items[], int size) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
    printf("------------------\n");
}

// Function to calculate the total bill based on user selection
void calculateBill(MenuItem items[], int size) {
    int order[100];
    int quantities[100];
    int count = 0;
    char another;

    do {
        int itemNumber;
        printf("Which item would you like to order? (Enter the item number): ");
        scanf("%d", &itemNumber);

        if (itemNumber < 1 || itemNumber > size) {
            printf("Invalid item number! Please try again.\n");
            continue;
        }

        printf("How many %s would you like to order? ", items[itemNumber - 1].name);
        scanf("%d", &quantities[count]);
        order[count] = itemNumber - 1;  // Store the item index
        count++;

        printf("Would you like to order another item? (y/n): ");
        scanf(" %c", &another);  // Space before %c to consume any newline character
    } while (another == 'y' || another == 'Y');

    // Calculate total
    float total = 0;
    printf("\n--- Your Order ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d x %s - $%.2f\n", quantities[i], items[order[i]].name, items[order[i]].price);
        total += quantities[i] * items[order[i]].price;
    }
    printf("------------------\n");
    printf("Total Bill: $%.2f\n", total);
}