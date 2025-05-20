//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#define MAX_ORDERS 10

// Order structure definition
typedef struct {
    int orderID;
    char item[20];
    float price;
} Order;

// Global variables declaration
Order orders[MAX_ORDERS];
int numOrders = 0;

// Function prototypes
void addOrder(char item[], float price);
void printBill();

int main() {
    char inputItem[20];
    float inputPrice;

    while (1) {
        printf("\nWelcome to Café Chaos Billing System!\n");
        printf("Please enter ITEM name or 'q' to QUIT: ");
        scanf("%s", inputItem);

        if (strcmp(inputItem, "q") == 0) {
            break;
        }

        printf("Enter ITEM price: ");
        scanf("%f", &inputPrice);

        addOrder(inputItem, inputPrice);

        printf("\nOrder added successfully! Total orders: %d\n", numOrders);
    }

    printBill();

    return 0;
}

void addOrder(char item[], float price) {
    if (numOrders < MAX_ORDERS) {
        orders[numOrders].orderID = numOrders + 1;
        strcpy(orders[numOrders].item, item);
        orders[numOrders].price = price;
        numOrders++;
    } else {
        printf("\nError: Maximum number of orders reached!\n");
    }
}

void printBill() {
    float totalBill = 0;

    printf("\n========= CAFÉ CHAOS BILLING SYSTEM =========\n");
    printf("\nORDER ID | ITEM              | PRICE\n");

    for (int i = 0; i < numOrders; i++) {
        printf("\n%d       | %s           | %.2f", orders[i].orderID, orders[i].item, orders[i].price);
        totalBill += orders[i].price;
    }

    printf("\n========= END OF BILL =========\n");
    printf("\nTotal Bill: %.2f", totalBill);
}