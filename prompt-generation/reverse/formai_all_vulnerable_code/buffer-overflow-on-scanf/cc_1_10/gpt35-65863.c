//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char itemName[20];
    int quantity;
    float price;
} Menu;

typedef struct {
    int tableNumber;
    char itemName[20];
    int quantity;
    float price;
} Order;

void displayMenu(Menu menu[], int menuSize);
void displayOrder(Order order[], int orderSize, float totalBill);

int main() {
    Menu menu[] = {{"Coffee", 100, 1.50},
                   {"Tea", 80, 1.00},
                   {"Burger", 50, 3.00},
                   {"Fries", 70, 2.00},
                   {"Cake", 20, 2.50}};

    int tableNumber, menuItem, quantity;
    float totalBill = 0.0;
    char chkChoice;

    Order order[10];
    int orderSize = 0;

    do {
        printf("Enter table number: ");
        scanf("%d", &tableNumber);

        displayMenu(menu, 5);

        printf("\nEnter item number and quantity: ");
        scanf("%d %d", &menuItem, &quantity);

        strcpy(order[orderSize].itemName, menu[menuItem-1].itemName);
        order[orderSize].tableNumber = tableNumber;
        order[orderSize].quantity = quantity;
        order[orderSize].price = menu[menuItem-1].price * quantity;
        orderSize++;

        totalBill += order[orderSize-1].price;

        printf("Do you want to add more items? (y/n): ");
        scanf(" %c", &chkChoice);

    } while (chkChoice == 'y');

    displayOrder(order, orderSize, totalBill);

    return 0;
}

void displayMenu(Menu menu[], int menuSize) {
    printf("\nMenu:\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d. %-10s_qty: %d_price: $%.2f\n", i+1, menu[i].itemName, menu[i].quantity, menu[i].price);
    }
}

void displayOrder(Order order[], int orderSize, float totalBill) {
    printf("\nOrder:\n");
    for (int i = 0; i < orderSize; i++) {
        printf("Table: %d - %s x %d - $%.2f\n", order[i].tableNumber, order[i].itemName, order[i].quantity, order[i].price);
    }
    printf("Total bill: $%.2f\n", totalBill);
}