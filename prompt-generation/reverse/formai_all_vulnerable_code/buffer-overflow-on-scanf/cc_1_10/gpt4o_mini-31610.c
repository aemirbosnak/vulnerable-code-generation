//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int itemCode;
    char itemName[MAX_NAME_LENGTH];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n** Welcome to the Peaceful Cafe **\n");
    printf("Here’s our menu for today:\n");
    printf("--------------------------------------------------\n");
    printf("| Item Code | Item Name           | Price (Rs) |\n");
    printf("--------------------------------------------------\n");
    for(int i = 0; i < itemCount; i++) {
        printf("| %-10d | %-20s | %-10.2f |\n", menu[i].itemCode, menu[i].itemName, menu[i].price);
    }
    printf("--------------------------------------------------\n");
}

float calculateTotal(float prices[], int quantities[], int itemCount) {
    float total = 0.0;
    for(int i = 0; i < itemCount; i++) {
        total += prices[i] * quantities[i];
    }
    return total;
}

void printReceipt(MenuItem menu[], int quantities[], int itemCount, float totalAmount) {
    printf("\n** Your Receipt **\n");
    printf("--------------------------------------------------\n");
    printf("| Item Name           | Quantity | Price (Rs) |\n");
    printf("--------------------------------------------------\n");
    for(int i = 0; i < itemCount; i++) {
        if(quantities[i] > 0) {
            printf("| %-20s | %-8d | %-10.2f |\n", menu[i].itemName, quantities[i], menu[i].price * quantities[i]);
        }
    }
    printf("--------------------------------------------------\n");
    printf("Total Amount: Rs %.2f\n", totalAmount);
    printf("Thank you for visiting the Peaceful Cafe!\n");
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {1, "Coffee", 50.0},
        {2, "Tea", 30.0},
        {3, "Sandwich", 70.0},
        {4, "Cake", 90.0},
        {5, "Juice", 40.0}
    };
    
    int itemCount = 5;
    float prices[MAX_ITEMS] = {0.0};
    int quantities[MAX_ITEMS] = {0};
    int choice;
    
    displayMenu(menu, itemCount);
    
    printf("Please enter the item code to order (0 to finish): ");
    while(1) {
        scanf("%d", &choice);
        
        if(choice == 0) {
            break; // End ordering
        }
        
        if(choice < 1 || choice > itemCount) {
            printf("Invalid item code. Please try again.\n");
            continue;
        }
        
        printf("How many would you like to order? ");
        int quantity;
        scanf("%d", &quantity);
        
        if(quantity < 0) {
            printf("Invalid quantity. Please try again.\n");
            continue;
        }
        
        quantities[choice - 1] += quantity;
        printf("%d of %s added to your order.\n", quantity, menu[choice - 1].itemName);
    }

    for(int i = 0; i < itemCount; i++) {
        prices[i] = menu[i].price; // Store prices corresponding to menu items
    }
    
    float totalAmount = calculateTotal(prices, quantities, itemCount);
    printReceipt(menu, quantities, itemCount, totalAmount);

    return 0;
}