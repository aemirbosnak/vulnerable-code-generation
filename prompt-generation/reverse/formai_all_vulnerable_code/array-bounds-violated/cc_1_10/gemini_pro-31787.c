//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Structure to store menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Array of menu items
MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Cake", 3.00},
    {"Cookie", 1.50}
};

// Function to display the menu
void displayMenu() {
    printf("Our passionate lovebirds, welcome to our humble cafe!\n\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s (%2.2f)\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

// Function to get the user's order
void getOrder(int *order, int *quantity) {
    int item;
    int qty;
    
    printf("My dearest, what delights your heart today?\n");
    printf("Enter the item number: ");
    scanf("%d", &item);
    
    printf("How many of these would make your day complete? ");
    scanf("%d", &qty);
    
    *order = item - 1;
    *quantity = qty;
}

// Function to calculate the total bill
float calculateBill(int order, int quantity) {
    float total = menu[order].price * quantity;
    return total;
}

// Function to print the bill
void printBill(float total) {
    printf("\nYour hearts' desire comes at a price of %.2f\n", total);
    printf("May this moment be as sweet as our coffee!\n");
}

// Main function
int main() {
    int order;
    int quantity;
    float total;
    
    displayMenu();
    getOrder(&order, &quantity);
    total = calculateBill(order, quantity);
    printBill(total);
    
    return 0;
}