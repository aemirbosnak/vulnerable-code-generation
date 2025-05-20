//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int totalItems = 0;

void addMenuItem() {
    if (totalItems >= MAX_ITEMS) {
        printf("Menu is full! Can't add more items.\n");
        return;
    }
    
    printf("\nEnter the name of the new menu item: ");
    scanf("%s", menu[totalItems].name);
    printf("Enter the price of %s: ", menu[totalItems].name);
    scanf("%f", &menu[totalItems].price);
    totalItems++;
    printf("%s has been added to the menu!\n", menu[totalItems - 1].name);
}

void displayMenu() {
    printf("\nCafe Menu:\n");
    for (int i = 0; i < totalItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void createBill() {
    int itemNumbers[MAX_ITEMS], quantities[MAX_ITEMS], itemCount = 0;
    float totalBill = 0.0f;

    printf("\nPlace your order! Enter item number and quantity (0 to finish):\n");
    
    while (1) {
        displayMenu();
        printf("Enter item number (0 to finish): ");
        int itemNumber;
        scanf("%d", &itemNumber);

        if (itemNumber == 0) {
            break; // Exit the order loop
        }

        if (itemNumber < 1 || itemNumber > totalItems) {
            printf("Invalid item number, please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[itemNumber - 1].name);
        scanf("%d", &quantities[itemCount]);
        itemNumbers[itemCount] = itemNumber - 1; // Store index
        itemCount++;
    }
    
    // Calculate the total bill
    printf("\nYour Bill:\n");
    for (int i = 0; i < itemCount; i++) {
        float itemTotal = quantities[i] * menu[itemNumbers[i]].price;
        printf("%s x%d = $%.2f\n", menu[itemNumbers[i]].name, quantities[i], itemTotal);
        totalBill += itemTotal;
    }
    
    printf("Total Amount Due: $%.2f\n", totalBill);
}

int main() {
    int choice;

    printf("Welcome to the C Cafe Billing System!\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Menu Item\n");
        printf("2. Display Menu\n");
        printf("3. Create Bill\n");
        printf("4. Exit\n");
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
                createBill();
                break;
            case 4:
                printf("Thank you for using the C Cafe Billing System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}