//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to hold menu item details
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} MenuItem;

// Function prototypes
void displayMenu(MenuItem menu[], int itemCount);
float calculateBill(MenuItem menu[], int itemCount);

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {1, "Espresso", 3.00},
        {2, "Cappuccino", 4.00},
        {3, "Latte", 4.50},
        {4, "Mocha", 5.00},
        {5, "Tea", 2.50},
        {6, "Sandwich", 5.50},
        {7, "Cookie", 1.50},
        {8, "Muffin", 2.00}
    };
    
    int itemCount = 8;
    char choice;
    float totalBill = 0;

    printf("Welcome to the Cafe Billing System!\n");

    do {
        displayMenu(menu, itemCount);
        
        int selectedItem;
        printf("Select an item by entering its ID (1-%d) or 0 to exit: ", itemCount);
        scanf("%d", &selectedItem);

        if (selectedItem >= 1 && selectedItem <= itemCount) {
            printf("Enter quantity for %s: ", menu[selectedItem - 1].name);
            scanf("%d", &menu[selectedItem - 1].quantity);
            totalBill += menu[selectedItem - 1].price * menu[selectedItem - 1].quantity;
            printf("\nAdded %d x %s to your bill.\n", menu[selectedItem - 1].quantity, menu[selectedItem - 1].name);
        } else if (selectedItem == 0) {
            printf("Exiting the order selection.\n");
        } else {
            printf("Invalid item ID. Please try again.\n");
        }

        printf("Do you want to add another item? (y/n): ");
        getchar(); // To consume the newline character left in buffer
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nGenerating your bill...\n");
    printf("---------------------------------------------\n");
    printf("Item\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        if (menu[i].quantity > 0) {
            printf("%s\t\t%d\t\t%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }

    printf("---------------------------------------------\n");
    printf("Total Bill Amount: $%.2f\n", totalBill);
    printf("Thank you for visiting! Come again!\n");

    return 0;
}

// Function to display the cafe menu
void displayMenu(MenuItem menu[], int itemCount) {
    printf("\nAvailable Menu Items:\n");
    printf("---------------------------------------------\n");
    printf("ID\tItem\t\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("---------------------------------------------\n");
}

// Function to calculate the total bill
float calculateBill(MenuItem menu[], int itemCount) {
    float total = 0;
    for (int i = 0; i < itemCount; i++) {
        total += menu[i].price * menu[i].quantity;
    }
    return total;
}