//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define constant values
#define MAX_ITEMS 10
#define ITEM_NAME_LENGTH 20

// Define item struct
typedef struct {
    char name[ITEM_NAME_LENGTH];
    float price;
    int quantity;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int numItems = 0;

float subtotal = 0.0;
float taxRate = 0.08;
float tax = 0.0;
float total = 0.0;


// Function declarations
void displayMenu();
int findItem(char itemName[]);
void addToOrder(int itemIndex, int quantity);
void printReceipt();


int main() {
    // Add menu items
    MenuItem cheeseBurger = {"Cheeseburger", 5.99, 0};
    MenuItem fries = {"Fries", 2.99, 0};
    MenuItem soda = {"Soda", 1.99, 0};
    
    menu[0] = cheeseBurger;
    menu[1] = fries;
    menu[2] = soda;
    
    numItems = 3;
    
    char choice[ITEM_NAME_LENGTH];
    int itemIndex = -1;
    int quantity = 0;
    do {
        // Display menu and prompt user for input
        displayMenu();
        printf("\nEnter an item name to add to your order (or 'done' to finish order): ");
        scanf("%s", choice);
        
        // Check if user is finished
        if (strcmp(choice, "done") == 0) {
            break;
        }
        
        // Find chosen item on menu
        itemIndex = findItem(choice);
        
        // If item is not found
        if (itemIndex == -1) {
            printf("\nSorry, '%s' is not on the menu.\n", choice);
            continue;
        }
        
        // Prompt user for quantity and add to order
        printf("How many would you like?: ");
        scanf("%d", &quantity);
        
        addToOrder(itemIndex, quantity);
        printf("\nAdded %d %s to your order.\n", quantity, menu[itemIndex].name);
    } while (strcmp(choice, "done") != 0);
    
    // Print receipt
    printReceipt();
    
    return 0;
}


void displayMenu() {
    printf("\n--------Menu--------\n");
    for (int i=0; i<numItems; i++) {
        printf("%d. %-15s $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}


int findItem(char itemName[]) {
    for (int i=0; i<numItems; i++) {
        if (strcmp(itemName, menu[i].name) == 0) {
            return i;
        }
    }
    return -1;
}


void addToOrder(int itemIndex, int quantity) {
    menu[itemIndex].quantity += quantity;
    
    subtotal += menu[itemIndex].price * quantity;
    tax = subtotal * taxRate;
    total = subtotal + tax;
}


void printReceipt() {
    printf("\n-------Receipt-------\n");
    printf("Item\t\tPrice\tQty\tTotal\n");
    for (int i=0; i<numItems; i++) {
        if (menu[i].quantity > 0) {
            printf("%-17s $%.2f\t%d\t$%.2f\n", menu[i].name, menu[i].price, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    printf("\nSubtotal:\t\t\t$%.2f\n", subtotal);
    printf("Tax:\t\t\t\t$%.2f\n", tax);
    printf("Total:\t\t\t\t$%.2f\n", total);
}