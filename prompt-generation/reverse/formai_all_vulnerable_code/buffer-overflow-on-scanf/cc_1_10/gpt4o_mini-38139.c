//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 30

typedef struct {
    int itemId;
    char itemName[MAX_NAME_LENGTH];
    float itemPrice;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int menuCount = 0;

void addMenuItem() {
    if (menuCount < MAX_ITEMS) {
        printf("Enter item ID: ");
        scanf("%d", &menu[menuCount].itemId);
        printf("Enter item name: ");
        scanf("%s", menu[menuCount].itemName);
        printf("Enter item price: ");
        scanf("%f", &menu[menuCount].itemPrice);
        menuCount++;
        printf("Item added successfully!\n");
    } else {
        printf("Menu is full! Can't add more items.\n");
    }
}

void displayMenu() {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < menuCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f\n", menu[i].itemId, menu[i].itemName, menu[i].itemPrice);
    }
}

void generateBill() {
    int itemId, quantity;
    float totalAmount = 0.0;
    char choice;

    do {
        printf("Enter item ID to order: ");
        scanf("%d", &itemId);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        for (int i = 0; i < menuCount; i++) {
            if (menu[i].itemId == itemId) {
                totalAmount += menu[i].itemPrice * quantity;
                printf("Added %d x %s to your bill!\n", quantity, menu[i].itemName);
                break;
            }
        }

        printf("Do you wish to add more items? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\n--- Your Bill ---\n");
    printf("Total Amount: %.2f\n", totalAmount);
}

void cafeManager() {
    int choice;
    
    do {
        printf("\n--- Cafe Billing System ---\n");
        printf("1. Add Menu Item\n");
        printf("2. Display Menu\n");
        printf("3. Generate Bill\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMenuItem();
                break;
            case 2:
                displayMenu();
                break;
            case 3:
                generateBill();
                break;
            case 4:
                printf("Thank you! See you next time!\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }
    } while (choice != 4);
}

int main() {
    cafeManager();
    return 0;
}