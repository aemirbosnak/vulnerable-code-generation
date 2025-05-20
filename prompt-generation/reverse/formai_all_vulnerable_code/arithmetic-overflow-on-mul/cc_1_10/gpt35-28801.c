//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining a structure for serving Cafe Orders
struct CafeOrder {
    int orderNumber; //Order ID
    char itemName[50]; //Item Name
    int price; //Item Price
    int quantity; //Item Quantity
    int totalAmount; //Total Amount of the Order
};

//Function for calculating the total amount of the order
int calculateTotal(int price, int quantity) {
    int total = price * quantity;
    return total;
}

//Function for printing the Cafe Order Receipt
void printReceipt(struct CafeOrder order) {
    printf("----------------------Cafe Order Receipt------------------------\n");
    printf("Order Number: %d\n", order.orderNumber);
    printf("Item Name: %s\n", order.itemName);
    printf("Price per Item: Rs. %d\n", order.price);
    printf("Quantity: %d\n", order.quantity);
    printf("Total Amount: Rs. %d\n", order.totalAmount);
    printf("------------------------------------------------------------------\n");
}

int main() {

    int orderNum = 0; //Variable for generating unique order number
    struct CafeOrder newOrder; //Creating a new CafeOrder structure
    int cont = 1; //Variable for loop continuation
    int choice; //Variable for user's choice

    //Continuously taking orders until user chooses to stop
    while(cont) {
        orderNum++; //Incrementing order number for every new order
        newOrder.orderNumber = orderNum; //Assigning the new order number to the order struct

        printf("Enter the Item Name: ");
        scanf("%s", newOrder.itemName); //Taking Item Name as input

        printf("Enter the Price per Item: ");
        scanf("%d", &newOrder.price); //Taking Price per Item as input

        printf("Enter the Quantity: ");
        scanf("%d", &newOrder.quantity); //Taking Quantity as input

        newOrder.totalAmount = calculateTotal(newOrder.price, newOrder.quantity); //Calculating Total Amount of the order

        printReceipt(newOrder); //Printing the Cafe Order Receipt

        printf("Do you want to place another Cafe Order?\n");
        printf("1. Yes\n2. No\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); //Asking user for continuation choice

        if(choice == 2) {
            cont = 0; //Setting loop continuation flag as false to exit the loop
        }

    }

    return 0;
}