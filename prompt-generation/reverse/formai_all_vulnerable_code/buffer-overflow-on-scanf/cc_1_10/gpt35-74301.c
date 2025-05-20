//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>

// function prototypes
void displayMenu();
int calculateBill(int menu[], int quantity[], int size);

int main() {
    int menu[] = {50, 30, 40, 25, 35};  // prices of menu items
    char choices[5][20] = {"Cappuccino", "Latte", "Americano", "Espresso", "Mocha"};  // menu item names
    int quantity[5] = {0};  // quantity of each item ordered
    int size = sizeof(menu) / sizeof(menu[0]);  // number of items on the menu
    int option = 0;  // customer's menu choice
    int bill = 0;  // total bill
    
    printf("*** Welcome to the C Cafe Billing System! ***\n\n");
    
    // loop until the customer finishes ordering
    do {
        displayMenu();
        printf("Enter your choice (1-%d): ", size);
        scanf("%d", &option);
        
        // validate customer's input
        if (option < 1 || option > size) {
            printf("Invalid choice. Please try again.\n\n");
        } else {
            // ask for quantity and update order
            int qty = 0;
            printf("Enter quantity: ");
            scanf("%d", &qty);
            quantity[option-1] += qty;
            printf("Added %d %s to your order.\n\n", qty, choices[option-1]);
        }
    } while (option != size+1);
    
    // calculate the total bill
    bill = calculateBill(menu, quantity, size);
    
    // print the final bill
    printf("Thank you for dining at the C Cafe!\n");
    printf("----------------------------------\n");
    for (int i = 0; i < size; i++) {
        if (quantity[i] > 0) {
            printf("%-12s x %-2d  $%5d\n", choices[i], quantity[i], menu[i]*quantity[i]);
        }
    }
    printf("----------------------------------\n");
    printf("Total bill: $%d\n\n", bill);
    
    return 0;
}

// display the menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Cappuccino      $50\n");
    printf("2. Latte           $30\n");
    printf("3. Americano       $40\n");
    printf("4. Espresso        $25\n");
    printf("5. Mocha           $35\n");
    printf("6. Finish ordering\n\n");
}

// calculate the total bill
int calculateBill(int menu[], int quantity[], int size) {
    int bill = 0;
    for (int i = 0; i < size; i++) {
        bill += menu[i] * quantity[i];
    }
    return bill;
}