//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>

// Structure to hold item details
struct Item {
    char name[30];
    float price;
};

// Function declarations
void displayMenu(struct Item menu[], int size);
int findItemIndex(struct Item menu[], int size, int choice);
void calculateBill(struct Item menu[], int size);

int main() {
    // Define menu items
    struct Item menu[] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Sandwich", 3.00},
        {"Pastry", 2.00},
        {"Biscuits", 1.50},
        {"Cake", 2.50}
    };
    
    int menuSize = sizeof(menu) / sizeof(menu[0]);
    char continueBilling = 'y';

    printf("Welcome to the Cafe Billing System!\n");
    
    while (continueBilling == 'y') {
        calculateBill(menu, menuSize);
        
        printf("Do you want to create another bill? (y/n): ");
        scanf(" %c", &continueBilling);
    }

    printf("Thank you for visiting!\n");
    
    return 0;
}

// Function to display the menu
void displayMenu(struct Item menu[], int size) {
    printf("\nMenu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to find item index from the menu
int findItemIndex(struct Item menu[], int size, int choice) {
    if (choice < 1 || choice > size) {
        return -1; // Invalid choice
    }
    return choice - 1; // Convert to zero-based index
}

// Function to calculate and print the bill
void calculateBill(struct Item menu[], int size) {
    int order[10] = {0}; // Store quantities of up to 10 items
    int itemChoice;
    char addMore;

    displayMenu(menu, size);
    
    do {
        printf("Select an item by number: ");
        scanf("%d", &itemChoice);
        
        int index = findItemIndex(menu, size, itemChoice);
        
        if (index != -1) {
            printf("Enter quantity for %s: ", menu[index].name);
            scanf("%d", &order[index]);
        } else {
            printf("Invalid selection. Please try again.\n");
        }

        printf("Do you want to add more items? (y/n): ");
        scanf(" %c", &addMore);
        
    } while (addMore == 'y');

    // Calculate total bill
    float totalBill = 0.0;
    printf("\nBill Details:\n");
    for (int i = 0; i < size; i++) {
        if (order[i] > 0) {
            float cost = order[i] * menu[i].price;
            printf("%s: %d x $%.2f = $%.2f\n", menu[i].name, order[i], menu[i].price, cost);
            totalBill += cost;
        }
    }

    printf("Total Bill: $%.2f\n", totalBill);
    printf("Thank you and enjoy your meal!\n");
}