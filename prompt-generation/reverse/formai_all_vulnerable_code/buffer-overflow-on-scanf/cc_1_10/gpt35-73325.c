//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem {
    char name[50];
    int price;
};

struct Order {
    char item[50];
    int quantity;
    int cost;
};

void printMainMenu() {
    printf("\nWelcome to Cafe Billing System\n");
    printf("1. Order\n");
    printf("2. View Order\n");
    printf("3. Make Payment\n");
    printf("4. Exit\n");
}

void printMenu(struct MenuItem menu[], int count) {
    printf("\nMenu: \n");
    printf("-------------------\n");
    for(int i=0; i<count; i++) {
        printf("%d. %s - $%d\n", i+1, menu[i].name, menu[i].price);
    }
}

int getMenuChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void takeOrder(struct MenuItem menu[], int count, struct Order orders[], int *orderCount, int *totalCost) {
    printMenu(menu, count);
    int itemChoice, quantity;

    printf("\nEnter 0 to stop ordering.\n");
    do {
        printf("\nEnter item number: ");
        scanf("%d", &itemChoice);
        if(itemChoice) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            int cost = menu[itemChoice-1].price * quantity;
            *totalCost += cost;

            // add order to orders array
            strcpy(orders[*orderCount].item, menu[itemChoice-1].name);
            orders[*orderCount].quantity = quantity;
            orders[*orderCount].cost = cost;
            (*orderCount)++;
        }
    } while(itemChoice);

    printf("\nOrder placed successfully!\n");
}

void viewOrder(struct Order orders[], int orderCount, int totalCost) {
    printf("\nOrders: \n");
    printf("-------------------\n");
    for(int i=0; i<orderCount; i++) {
        printf("%d. %s - %d x $%d = $%d\n", i+1, orders[i].item, orders[i].quantity, orders[i].cost/orders[i].quantity, orders[i].cost);
    }
    printf("Total cost: $%d\n", totalCost);
}

int main() {
    struct MenuItem menu[] = {
        {"Cappuccino", 4},
        {"Latte", 4},
        {"Mocha", 5},
        {"Espresso", 3}
    };

    struct Order orders[100];
    int orderCount = 0, totalCost = 0;

    int choice;
    do {
        printMainMenu();
        choice = getMenuChoice();

        switch(choice) {
            case 1:
                takeOrder(menu, 4, orders, &orderCount, &totalCost);
                break;
            case 2:
                viewOrder(orders, orderCount, totalCost);
                break;
            case 3:
                printf("\nPayment amount: $%d\n", totalCost);
                printf("Payment received, thank you for visiting our cafe!\n");
                totalCost = 0;
                orderCount = 0;
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}