//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int itemCount = 0;

void addItem(const char *name, float price) {
    if (itemCount < MAX_ITEMS) {
        strcpy(menu[itemCount].name, name);
        menu[itemCount].price = price;
        itemCount++;
    } else {
        printf("Menu is full!\n");
    }
}

void displayMenu() {
    printf("\nCafe Menu:\n");
    printf("--------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("--------------------------------\n");
}

float calculateTotal(int *itemsOrdered, int itemCount) {
    float total = 0;
    for (int i = 0; i < itemCount; i++) {
        total += menu[itemsOrdered[i]].price;
    }
    return total;
}

void printBill(int *itemsOrdered, int itemCount) {
    printf("\nYour Bill:\n");
    printf("--------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s - $%.2f\n", menu[itemsOrdered[i]].name, menu[itemsOrdered[i]].price);
    }
    float total = calculateTotal(itemsOrdered, itemCount);
    printf("--------------------------------\n");
    printf("Total: $%.2f\n", total);
}

int main() {
    addItem("Coffee", 2.50);
    addItem("Tea", 1.75);
    addItem("Sandwich", 5.00);
    addItem("Burger", 6.25);
    addItem("Pasta", 7.50);
    addItem("Cake", 3.75);

    int itemsOrdered[MAX_ITEMS];
    int orderCount = 0;
    char choice[3];

    printf("Welcome to the Cafe Billing System!\n");

    do {
        displayMenu();
        printf("Please enter the item number to order (0 to finish): ");
        scanf("%d", &itemsOrdered[orderCount]);
        
        if (itemsOrdered[orderCount] > 0 && itemsOrdered[orderCount] <= itemCount) {
            orderCount++;
        } else if (itemsOrdered[orderCount] == 0) {
            break;
        } else {
            printf("Invalid item number! Please try again.\n");
        }

    } while (orderCount < MAX_ITEMS);

    if (orderCount > 0) {
        printBill(itemsOrdered, orderCount);
    } else {
        printf("No items were ordered.\n");
    }

    printf("\nThank you for visiting the Cafe!\n");
    return 0;
}