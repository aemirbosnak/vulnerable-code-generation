//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

// Structure to represent a menu item
typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

// Structure to represent an order
typedef struct {
    MenuItem item;
    int quantity;
} Order;

// Function declarations
void initializeMenu(MenuItem menu[]);
void displayMenu(MenuItem menu[]);
float calculateTotal(Order orders[], int orderCount);
void takeOrder(Order orders[], int *orderCount, MenuItem menu[], int menuSize);
void printBill(Order orders[], int orderCount);

int main() {
    MenuItem menu[MAX_ITEMS];
    Order orders[MAX_ITEMS];
    int orderCount = 0;

    // Initialize the menu
    initializeMenu(menu);

    int choice;
    do {
        printf("\n=== Cafe Billing System ===\n");
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Print Bill\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(menu);
                break;
            case 2:
                takeOrder(orders, &orderCount, menu, MAX_ITEMS);
                break;
            case 3:
                printBill(orders, orderCount);
                break;
            case 4:
                printf("Thank you for using the Cafe Billing System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize the menu with sample items
void initializeMenu(MenuItem menu[]) {
    menu[0] = (MenuItem){1, "Coffee", 2.50};
    menu[1] = (MenuItem){2, "Tea", 1.75};
    menu[2] = (MenuItem){3, "Sandwich", 4.00};
    menu[3] = (MenuItem){4, "Cake", 3.00};
    menu[4] = (MenuItem){5, "Juice", 2.00};
}

// Function to display the menu to the user
void displayMenu(MenuItem menu[]) {
    printf("\nCafe Menu:\n");
    printf("ID\tName\t\tPrice\n");
    printf("---------------------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu[i].id != 0) {
            printf("%d\t%s\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
        }
    }
}

// Function to take orders from the user
void takeOrder(Order orders[], int *orderCount, MenuItem menu[], int menuSize) {
    int itemId, quantity;
    
    printf("Enter the Item ID to order (0 to stop): ");
    while (1) {
        scanf("%d", &itemId);
        if (itemId == 0) break; // Stop ordering on 0

        if (itemId >= 1 && itemId <= menuSize && menu[itemId - 1].id != 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            if (*orderCount < MAX_ITEMS) {
                orders[*orderCount] = (Order){menu[itemId - 1], quantity};
                (*orderCount)++;
            } else {
                printf("Order limit reached!\n");
            }
        } else {
            printf("Invalid item ID! Please try again.\n");
        }
        printf("Enter the Item ID to order (0 to stop): ");
    }
}

// Function to calculate the total amount for the order
float calculateTotal(Order orders[], int orderCount) {
    float total = 0;
    for (int i = 0; i < orderCount; i++) {
        total += orders[i].item.price * orders[i].quantity;
    }
    return total;
}

// Function to print the final bill
void printBill(Order orders[], int orderCount) {
    printf("\n===== Your Bill =====\n");
    printf("Item\t\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%s\t\t%d\t\t%.2f\n", orders[i].item.name, orders[i].quantity, 
               (orders[i].item.price * orders[i].quantity));
    }
    float total = calculateTotal(orders, orderCount);
    printf("----------------------------------------------\n");
    printf("Total Amount: %.2f\n", total);
    printf("========================\n");
}