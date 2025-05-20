//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

// Structure to hold menu items
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

// Structure to hold an order
typedef struct {
    MenuItem item;
    int quantity;
} Order;

// Function prototypes
void displayMenu(MenuItem menu[], int itemCount);
void takeOrder(Order orders[], int *orderCount, MenuItem menu[], int itemCount);
void printBill(Order orders[], int orderCount);
void findMenuItemByName(MenuItem menu[], int itemCount, const char* name, MenuItem *item);

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Espresso", 2.00},
        {"Latte", 3.50},
        {"Cappuccino", 3.00},
        {"Tea", 1.50},
        {"Sandwich", 5.00},
        {"Pastry", 2.50},
        {"Juice", 2.00}
    };
    
    int itemCount = 7;
    Order orders[MAX_ITEMS];
    int orderCount = 0;
    int choice;

    printf("Welcome to the C Cafe Billing System!\n");

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Print Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(menu, itemCount);
                break;
            case 2:
                takeOrder(orders, &orderCount, menu, itemCount);
                break;
            case 3:
                printBill(orders, orderCount);
                break;
            case 4:
                printf("Thank you for visiting C Cafe!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\nCafe Menu:\n");
    printf("------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("------------------------------\n");
}

void takeOrder(Order orders[], int *orderCount, MenuItem menu[], int itemCount) {
    char choice[MAX_NAME_LENGTH];

    printf("Enter the name of the item you want to order (or type 'done' to finish): ");
    while (1) {
        scanf("%s", choice);
        if (strcmp(choice, "done") == 0) {
            break;
        }

        MenuItem item;
        findMenuItemByName(menu, itemCount, choice, &item);

        if (strlen(item.name) > 0) {
            int quantity;
            printf("Enter quantity for %s: ", item.name);
            scanf("%d", &quantity);

            orders[*orderCount].item = item;
            orders[*orderCount].quantity = quantity;
            (*orderCount)++;

            printf("Added %s (x%d) to your order.\n", item.name, quantity);
        } else {
            printf("Item not found in the menu. Please try again.\n");
        }
        printf("Enter the name of the item you want to order (or type 'done' to finish): ");
    }
}

void printBill(Order orders[], int orderCount) {
    float total = 0.0;

    printf("\n----- Your Bill -----\n");
    for (int i = 0; i < orderCount; i++) {
        float itemTotal = orders[i].item.price * orders[i].quantity;
        total += itemTotal;
        printf("%s (x%d) - $%.2f\n", orders[i].item.name, orders[i].quantity, itemTotal);
    }
    
    printf("------------------------------\n");
    printf("Total: $%.2f\n", total);
    printf("------------------------------\n");
}

void findMenuItemByName(MenuItem menu[], int itemCount, const char* name, MenuItem *item) {
    item->name[0] = '\0';  // Reset item name
    for (int i = 0; i < itemCount; i++) {
        if (strcasecmp(menu[i].name, name) == 0) {
            *item = menu[i];
            return;
        }
    }
}