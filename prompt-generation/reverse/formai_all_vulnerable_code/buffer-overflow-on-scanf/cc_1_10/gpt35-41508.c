//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char itemName[20];
    int itemPrice;
};

struct Order {
    struct Item orderedItem;
    int quantity;
};

struct Bill {
    char customerName[50];
    struct Order* orderList;
    int numOrders;
    int totalAmount;
};

void printMenu() {
    printf("-----------------------\n");
    printf(" Welcome to Cafe Delight\n");
    printf("-----------------------\n");
    printf(" 1. Coffee   - $3\n");
    printf(" 2. Tea      - $2\n");
    printf(" 3. Sandwich - $5\n");
    printf(" 4. Pizza    - $10\n");
    printf("-----------------------\n");
}

int getPrice(int choice) {
    switch (choice) {
        case 1: return 3;
        case 2: return 2;
        case 3: return 5;
        case 4: return 10;
        default: return 0;
    }
}

int main() {
    struct Bill customerBill;
    printf("Enter customer name: ");
    fgets(customerBill.customerName, 50, stdin);
    customerBill.numOrders = 0;
    customerBill.totalAmount = 0;
    customerBill.orderList = NULL;

    printf("Welcome, %s", customerBill.customerName);
    printf("-----------------------\n");

    int choice;
    while (1) {
        printMenu();
        printf("Enter item choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            // Exit the loop
            break;
        }

        struct Order newOrder;
        strcpy(newOrder.orderedItem.itemName, "");
        newOrder.orderedItem.itemPrice = 0;
        newOrder.quantity = 0;

        int price = getPrice(choice);
        if (price == 0) {
            printf("Invalid choice, please try again\n\n");
            continue;
        } else {
            printf("Enter quantity: ");
            scanf("%d", &newOrder.quantity);
            newOrder.orderedItem.itemPrice = price;
            switch (choice) {
                case 1:
                strcpy(newOrder.orderedItem.itemName, "Coffee");
                break;

                case 2:
                strcpy(newOrder.orderedItem.itemName, "Tea");
                break;

                case 3:
                strcpy(newOrder.orderedItem.itemName, "Sandwich");
                break;

                case 4:
                strcpy(newOrder.orderedItem.itemName, "Pizza");
                break;
            }

            customerBill.numOrders++;
            customerBill.orderList = realloc(customerBill.orderList, customerBill.numOrders * sizeof(struct Order));
            customerBill.orderList[customerBill.numOrders - 1] = newOrder;
            customerBill.totalAmount += (price * newOrder.quantity);

            printf("\n%s %d x $%d = $%d\n\n", newOrder.orderedItem.itemName, newOrder.quantity, newOrder.orderedItem.itemPrice, price * newOrder.quantity);
        }
    }

    printf("\n\n-----------------------\n");
    printf("\n\nName: %s\n\n", customerBill.customerName);
    printf("Total Amount: $%d\n\n", customerBill.totalAmount);
    printf("Order List: \n");

    for (int i = 0; i < customerBill.numOrders; i++) {
        printf("%s %d x $%d = $%d\n", customerBill.orderList[i].orderedItem.itemName, customerBill.orderList[i].quantity, customerBill.orderList[i].orderedItem.itemPrice, customerBill.orderList[i].quantity * customerBill.orderList[i].orderedItem.itemPrice);
    }

    printf("\n\n");
    return 0;
}