//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>

// Constants for menu items
#define ITEM_COUNT 5
#define MAX_ORDER 10

// Structure to hold item details
typedef struct {
    char name[30];
    float price;
} MenuItem;

// Function prototypes
void displayMenu(MenuItem menu[]);
void takeOrder(MenuItem menu[], int order[], int quantity[], int *itemCount);
void calculateBill(MenuItem menu[], int order[], int quantity[], int itemCount);
void printReceipt(MenuItem menu[], int order[], int quantity[], int itemCount, float total);

int main() {
    // Define the menu
    MenuItem menu[ITEM_COUNT] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Sandwich", 4.00},
        {"Cake", 3.50},
        {"Juice", 2.00}
    };

    int order[MAX_ORDER];
    int quantity[MAX_ORDER];
    int itemCount = 0;
    char anotherOrder = 'y';

    printf("\n🎉 Welcome to Happy Cafe! 🎉\n");
    
    // Display the menu
    displayMenu(menu);

    // Order taking loop
    while (anotherOrder == 'y' && itemCount < MAX_ORDER) {
        takeOrder(menu, order, quantity, &itemCount);
        printf("Would you like to order another item? (y/n): ");
        scanf(" %c", &anotherOrder);
        anotherOrder = (anotherOrder == 'y' || anotherOrder == 'Y') ? 'y' : 'n';
    }

    // Calculate and print the bill
    calculateBill(menu, order, quantity, itemCount);

    return 0;
}

// Function to display the menu
void displayMenu(MenuItem menu[]) {
    printf("\n🌟 Our Menu 🌟\n");
    for (int i = 0; i < ITEM_COUNT; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

// Function to take order from the user
void takeOrder(MenuItem menu[], int order[], int quantity[], int *itemCount) {
    int choice, qty;
    printf("Please enter the number of the item you want to order: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > ITEM_COUNT) {
        printf("🚫 Invalid choice! Please try again.\n");
        return;
    }

    printf("How many of %s would you like? ", menu[choice - 1].name);
    scanf("%d", &qty);

    if (qty < 1) {
        printf("🚫 Invalid quantity! Please try again.\n");
        return;
    }

    order[*itemCount] = choice - 1; // Store index of the item
    quantity[*itemCount] = qty; // Store the quantity
    (*itemCount)++;
    printf("🎉 You ordered %d of %s! 🎉\n", qty, menu[choice - 1].name);
}

// Function to calculate the total bill
void calculateBill(MenuItem menu[], int order[], int quantity[], int itemCount) {
    float total = 0.0;
    printf("\n🧾 Your Receipt 🧾\n");
    printf("-----------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        float itemTotal = menu[order[i]].price * quantity[i];
        total += itemTotal;
        printf("%s x %d - $%.2f\n", menu[order[i]].name, quantity[i], itemTotal);
    }
    
    printf("-----------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("🎊 Thank you for visiting Happy Cafe! 🎊\n");
}