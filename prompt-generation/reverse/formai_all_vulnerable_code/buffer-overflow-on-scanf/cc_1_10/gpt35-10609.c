//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include<stdio.h>

//Function declaration
void printMenu();
void placeOrder();
void viewOrders();

//Global variables
int orderCount = 0;
float totalSales = 0;

//Structure to hold order information
struct Order {
    int orderNumber;
    char itemName[30];
    float itemPrice;
    int itemQty;
} orders[20];

//Main function
int main() {
    int choice;
    printf("Welcome to C Cafe Billing System!\n");
    do {
        printf("\nEnter your choice:\n");
        printf("1. Place an order\n");
        printf("2. View all orders\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            placeOrder();
            break;
        case 2:
            viewOrders();
            break;
        case 3:
            printf("Thank you for visiting C Cafe Billing System!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while(choice != 3);
    return 0;
}

//Function to display the menu
void printMenu() {
    printf("\n********** Menu **********\n");
    printf("1. Coffee           $2.50\n");
    printf("2. Tea              $1.50\n");
    printf("3. Sandwich         $4.50\n");
}

//Function to place an order
void placeOrder() {
    //local variables
    int itemChoice, itemQty;
    struct Order newOrder;
    printMenu();
    printf("\nEnter the item number: ");
    scanf("%d", &itemChoice);
    printf("Enter the item quantity: ");
    scanf("%d", &itemQty);
    switch(itemChoice) {
    case 1:
        newOrder.itemPrice = 2.50;
        sprintf(newOrder.itemName, "Coffee");
        break;
    case 2:
        newOrder.itemPrice = 1.50;
        sprintf(newOrder.itemName, "Tea");
        break;
    case 3:
        newOrder.itemPrice = 4.50;
        sprintf(newOrder.itemName, "Sandwich");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        return;
    }
    newOrder.orderNumber = ++orderCount;
    newOrder.itemQty = itemQty;
    orders[orderCount-1] = newOrder;
    printf("\nThe order has been placed successfully!\n");
    totalSales += (newOrder.itemPrice * newOrder.itemQty);
}

//Function to view all orders
void viewOrders() {
    int i;
    if(orderCount == 0) {
        printf("\nNo orders placed yet!\n");
        return;
    }
    printf("\nOrder No.\tItem Name\tQuantity\tPrice\n");
    for(i=0; i<orderCount; i++) {
        printf("%d\t\t%s\t\t%d\t\t$%.2f\n", orders[i].orderNumber, orders[i].itemName, orders[i].itemQty, (orders[i].itemPrice * orders[i].itemQty));
    }
    printf("Total Sales: $%.2f\n", totalSales);
}