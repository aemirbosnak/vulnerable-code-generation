//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int itemCount = 0;

void addItem(const char *name, float price) {
    strcpy(menu[itemCount].name, name);
    menu[itemCount].price = price;
    itemCount++;
}

void printMenu() {
    printf("\n----- Cafe Menu -----\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("---------------------\n");
}

void generateInvoice(int *order, int orderCount, float total) {
    printf("\n----- Invoice -----\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%s - $%.2f\n", menu[order[i]].name, menu[order[i]].price);
    }
    printf("Total amount: $%.2f\n", total);
    printf("-------------------\n");
}

float calculateTotal(int *order, int orderCount) {
    float total = 0;
    for (int i = 0; i < orderCount; i++) {
        total += menu[order[i]].price;
    }
    return total;
}

int main() {
    // Initialize menu items
    addItem("Coffee", 3.00);
    addItem("Tea", 2.50);
    addItem("Sandwich", 5.00);
    addItem("Pastry", 4.00);
    addItem("Cake", 5.50);
    addItem("Juice", 2.00);

    // Display the menu
    printMenu();

    int order[MAX_ITEMS];
    int orderCount = 0;
    int choice;

    while (1) {
        printf("\nEnter the item number to order (0 to finish): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= itemCount) {
            order[orderCount++] = choice - 1; // Save the order (0-indexed)
            printf("Added %s to your order.\n", menu[choice - 1].name);
        } else {
            printf("Invalid choice. Please select a valid item number.\n");
        }
    }

    if (orderCount > 0) {
        float total = calculateTotal(order, orderCount);
        generateInvoice(order, orderCount, total);
    } else {
        printf("No items ordered.\n");
    }

    return 0;
}