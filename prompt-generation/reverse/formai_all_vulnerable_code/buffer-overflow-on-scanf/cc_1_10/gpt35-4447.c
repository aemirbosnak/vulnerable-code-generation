//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void printMenu();
void printInvoice();
void clearOrder();
int calculateTotal();

// Global Variables
int coffeePrice = 100;
int teaPrice = 50;
int pastryPrice = 75;
int muffinPrice = 60;
int orderCount = 0;
int orderTotal = 0;

typedef struct {
    char item[20];
    int price;
    int quantity;
} Order;

Order orders[10];

int main() {
    printMenu();
    return 0;
}

void printMenu() {
    int choice;
    printf("Welcome to the C Cafe!\n");
    printf("What would you like to order?\n");
    printf("1. Coffee - Rs.%d\n", coffeePrice);
    printf("2. Tea - Rs.%d\n", teaPrice);
    printf("3. Pastry - Rs.%d\n", pastryPrice);
    printf("4. Muffin - Rs.%d\n", muffinPrice);
    printf("5. Clear Order\n");
    printf("6. Print Invoice\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(orders[orderCount].item, "Coffee");
            orders[orderCount].price = coffeePrice;
            printf("How many cups would you like? ");
            scanf("%d", &orders[orderCount].quantity);
            orderCount++;
            printf("Added Coffee to your order.\n");
            break;
        case 2:
            strcpy(orders[orderCount].item, "Tea");
            orders[orderCount].price = teaPrice;
            printf("How many cups would you like? ");
            scanf("%d", &orders[orderCount].quantity);
            orderCount++;
            printf("Added Tea to your order.\n");
            break;
        case 3:
            strcpy(orders[orderCount].item, "Pastry");
            orders[orderCount].price = pastryPrice;
            printf("How many pastries would you like? ");
            scanf("%d", &orders[orderCount].quantity);
            orderCount++;
            printf("Added Pastry to your order.\n");
            break;
        case 4:
            strcpy(orders[orderCount].item, "Muffin");
            orders[orderCount].price = muffinPrice;
            printf("How many muffins would you like? ");
            scanf("%d", &orders[orderCount].quantity);
            orderCount++;
            printf("Added Muffin to your order.\n");
            break;
        case 5:
            clearOrder();
            printf("Order cleared.\n");
            break;
        case 6:
            printInvoice();
            break;
        case 7:
            printf("Thank you for choosing C Cafe!\n");
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
    }

    if (choice != 7) {
        printMenu();
    }
}

void printInvoice() {
    printf("\n\n");
    printf("C Cafe\n");
    printf("=============================\n");
    printf("Item\t\tPrice\tQuantity\tTotal\n");

    for (int i = 0; i < orderCount; i++) {
        int total = orders[i].price * orders[i].quantity;
        printf("%-10s\t%d\t%d\t\t%d\n", orders[i].item, orders[i].price, orders[i].quantity, total);
        orderTotal += total;
    }

    printf("----------------------------\n");
    printf("Total\t\t\t\t\t%d\n", orderTotal);
    printf("----------------------------\n");
    printf("Thank you for your order!\n");

    clearOrder();
}

void clearOrder() {
    orderCount = 0;
    orderTotal = 0;

    for (int i = 0; i < 10; i++) {
        strcpy(orders[i].item, "");
        orders[i].price = 0;
        orders[i].quantity = 0;
    }
}

int calculateTotal(int quantity, int price) {
    return quantity * price;
}