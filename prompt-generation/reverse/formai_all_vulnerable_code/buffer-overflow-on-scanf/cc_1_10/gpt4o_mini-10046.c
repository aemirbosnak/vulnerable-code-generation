//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Item;

void printBill(Item items[], int itemCount, float total) {
    printf("\n\n=================== Cafe Billing System ===================\n");
    printf("Item Name                      Quantity         Price\n");
    printf("-----------------------------------------------------------\n");
    
    for (int i = 0; i < itemCount; i++) {
        printf("%-30s %-15d $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    
    printf("-----------------------------------------------------------\n");
    printf("Total Amount:                                    $%.2f\n", total);
    printf("Thank you for visiting our cafe! Have a great day!\n");
    printf("===========================================================\n");
}

void showMenu() {
    printf("\nWelcome to Happy Cafe!\n");
    printf("Here are the delicious items we have for you:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $2.00\n");
    printf("3. Sandwich - $5.00\n");
    printf("4. Cake - $3.50\n");
    printf("5. Juice - $2.50\n");
    printf("6. Exit\n");
}

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    float total = 0.0;
    int choice;

    while (1) {
        showMenu();
        printf("Please enter the number of the item you want to order (1-6): ");
        scanf("%d", &choice);
        
        if (choice == 6) {
            printf("Exiting the cafe, happy to serve you!\n");
            break;
        }
        
        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Please choose again.\n");
            continue;
        }

        char *itemNames[] = {"Coffee", "Tea", "Sandwich", "Cake", "Juice"};
        float itemPrices[] = {2.50, 2.00, 5.00, 3.50, 2.50};

        // Process order
        printf("How many would you like to order? ");
        int quantity;
        scanf("%d", &quantity);
        
        strcpy(items[itemCount].name, itemNames[choice - 1]);
        items[itemCount].price = itemPrices[choice - 1];
        items[itemCount].quantity = quantity;

        total += items[itemCount].price * quantity;
        itemCount++;

        printf("Added %d %s(s) to your order!\n", quantity, items[itemCount - 1].name);
    }
    
    if (itemCount > 0) {
        printBill(items, itemCount, total);
    } else {
        printf("No items ordered. Come back soon!\n");
    }

    return 0;
}