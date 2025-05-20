//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing cafe items
struct MenuItem{
    int itemCode;
    char itemName[50];
    float itemPrice;
};

// Struct for storing a customer's order
struct Order{
    int tableNumber;
    int numItems;
    struct MenuItem items[10];
};

// Function to display menu
void displayMenu(){
    printf("\n--------------- MENU ---------------\n");
    printf("Item Code\tItem Name\tPrice (Rs.)\n");
    printf("   101  \t   Coffee  \t   50.0   \n");
    printf("   102  \t   Tea     \t   30.0   \n");
    printf("   103  \t   Cake    \t   100.0  \n");
    printf("   104  \t   Sandwich\t   80.0   \n");
    printf("   105  \t   Burger  \t   150.0  \n");
    printf("------------------------------------\n");
}

// Function to handle customer order
void takeOrder(struct Order *order){
    printf("\nEnter table number: ");
    scanf("%d", &order->tableNumber);

    displayMenu();

    printf("\nEnter number of items: ");
    scanf("%d", &order->numItems);

    for(int i=0; i<order->numItems; i++){
        printf("\nEnter item code for item %d: ", i+1);
        scanf("%d", &order->items[i].itemCode);

        // Getting corresponding item name and price
        if(order->items[i].itemCode == 101){
            strcpy(order->items[i].itemName, "Coffee");
            order->items[i].itemPrice = 50.0;
        }
        else if(order->items[i].itemCode == 102){
            strcpy(order->items[i].itemName, "Tea");
            order->items[i].itemPrice = 30.0;
        }
        else if(order->items[i].itemCode == 103){
            strcpy(order->items[i].itemName, "Cake");
            order->items[i].itemPrice = 100.0;
        }
        else if(order->items[i].itemCode == 104){
            strcpy(order->items[i].itemName, "Sandwich");
            order->items[i].itemPrice = 80.0;
        }
        else if(order->items[i].itemCode == 105){
            strcpy(order->items[i].itemName, "Burger");
            order->items[i].itemPrice = 150.0;
        }
        else{
            printf("\nInvalid item code. Please enter a valid code.\n");
            i--;
        }
    }
}

// Function to display customer receipt
void displayReceipt(struct Order order){
    float total = 0;

    printf("\n-------------- RECEIPT --------------\n");
    printf("Table Number: %d\n", order.tableNumber);
    printf("Item Code\tItem Name\tPrice (Rs.)\n");

    for(int i=0; i<order.numItems; i++){
        printf("   %d    \t   %s  \t   %.2f  \n", order.items[i].itemCode, order.items[i].itemName, order.items[i].itemPrice);
        total += order.items[i].itemPrice;
    }

    printf("-------------------------------------\n");
    printf("Total Bill: %.2f Rs.\n", total);
}

// Function to handle payment and generate bill
void generateBill(struct Order *order){
    displayReceipt(*order);

    float amountPaid;
    printf("\nEnter amount paid by the customer: ");
    scanf("%f", &amountPaid);

    float totalBill = 0;
    for(int i=0; i<order->numItems; i++){
        totalBill += order->items[i].itemPrice;
    }

    if(amountPaid >= totalBill){
        float change = amountPaid - totalBill;
        printf("\nChange: %.2f Rs.\n", change);
    }
    else{
        printf("\nAmount paid is not enough to cover the total bill.\n");
    }
}

// Main function
int main()
{
    struct Order order;

    printf("\n\n******* Welcome to Our Cafe *******\n");
    takeOrder(&order);
    generateBill(&order);

    return 0;
}