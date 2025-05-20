//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50

typedef struct {
    int id;
    char name[MAX_NAME];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int menuCount = 0;

void loadMenu();
void displayMenu();
void placeOrder();
float calculateTotal(int order[], int quantities[], int itemCount);
void printBill(int order[], int quantities[], int itemCount, float total);

int main() {
    int choice;

    loadMenu();

    do {
        printf("\nCafe Billing System\n");
        printf("1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                placeOrder();
                break;
            case 3:
                printf("Thank you for using the Cafe Billing System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void loadMenu() {
    menuCount = 5;
    menu[0] = (MenuItem){1, "Coffee", 2.5};
    menu[1] = (MenuItem){2, "Tea", 1.5};
    menu[2] = (MenuItem){3, "Sandwich", 5.0};
    menu[3] = (MenuItem){4, "Pastry", 3.0};
    menu[4] = (MenuItem){5, "Juice", 4.0};
}

void displayMenu() {
    printf("\nMenu:\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void placeOrder() {
    int order[MAX_ITEMS];
    int quantities[MAX_ITEMS];
    int itemCount = 0;
    char moreItems;

    do {
        int itemId, quantity;
        printf("Enter the item ID to order: ");
        scanf("%d", &itemId);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        if (itemId < 1 || itemId > menuCount) {
            printf("Invalid item ID! Please try again.\n");
            continue;
        }

        order[itemCount] = itemId;
        quantities[itemCount] = quantity;
        itemCount++;

        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &moreItems);
    } while (moreItems == 'y' && itemCount < MAX_ITEMS);

    float total = calculateTotal(order, quantities, itemCount);
    printBill(order, quantities, itemCount, total);
}

float calculateTotal(int order[], int quantities[], int itemCount) {
    float total = 0.0;

    for (int i = 0; i < itemCount; i++) {
        int itemId = order[i];
        int quantity = quantities[i];
        total += menu[itemId - 1].price * quantity;  // Adjust for zero-based index
    }

    return total;
}

void printBill(int order[], int quantities[], int itemCount, float total) {
    printf("\n----- Bill -----\n");
    for (int i = 0; i < itemCount; i++) {
        int itemId = order[i];
        printf("%s x%d - $%.2f\n", menu[itemId - 1].name, quantities[i], menu[itemId - 1].price * quantities[i]);
    }
    printf("----------------\n");
    printf("Total Amount: $%.2f\n", total);
}