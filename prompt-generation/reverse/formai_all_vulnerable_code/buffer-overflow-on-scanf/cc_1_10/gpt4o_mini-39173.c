//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    char itemName[NAME_LENGTH];
    int quantity;
} OrderItem;

MenuItem menu[MAX_ITEMS];
OrderItem order[MAX_ITEMS];
int menuCount = 0;
int orderCount = 0;

void addMenuItem() {
    if (menuCount < MAX_ITEMS) {
        printf("Enter the name of the menu item: ");
        scanf("%s", menu[menuCount].name);
        printf("Enter the price of the item: ");
        scanf("%f", &menu[menuCount].price);
        menuCount++;
        printf("Menu item added successfully!\n");
    } else {
        printf("Menu is full! Cannot add more items.\n");
    }
}

void displayMenu() {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void takeOrder() {
    char choice[NAME_LENGTH];
    int quantity;

    while (1) {
        printf("Enter the name of the item to order or 'done' to finish: ");
        scanf("%s", choice);
        if (strcmp(choice, "done") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < menuCount; i++) {
            if (strcmp(menu[i].name, choice) == 0) {
                found = 1;
                printf("How many would you like to order? ");
                scanf("%d", &quantity);
                strcpy(order[orderCount].itemName, menu[i].name);
                order[orderCount].quantity = quantity;
                orderCount++;
                printf("Order added: %s x%d\n", menu[i].name, quantity);
                break;
            }
        }

        if (!found) {
            printf("Item not found in the menu. Please try again.\n");
        }
    }
}

void printBill() {
    float total = 0.0;
    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < orderCount; i++) {
        for (int j = 0; j < menuCount; j++) {
            if (strcmp(order[i].itemName, menu[j].name) == 0) {
                float itemTotal = order[i].quantity * menu[j].price;
                printf("%s x%d - $%.2f\n", order[i].itemName, order[i].quantity, itemTotal);
                total += itemTotal;
            }
        }
    }
    printf("------------------\n");
    printf("Total Amount: $%.2f\n", total);
}

int main() {
    int choice;

    printf("Welcome to the Brave Cafe Billing System!\n");
    
    while (1) {
        printf("\n1. Add Menu Item\n2. Display Menu\n3. Take Order\n4. Print Bill\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMenuItem();
                break;
            case 2:
                displayMenu();
                break;
            case 3:
                takeOrder();
                break;
            case 4:
                printBill();
                break;
            case 5:
                printf("Thank you for using the Brave Cafe Billing System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}