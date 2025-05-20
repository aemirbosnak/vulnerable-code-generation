//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Item{
    char name[30];
    int price;
};

struct Order{
    char itemName[30];
    int quantity;
    int totalPrice;
};

int main(){
    struct Item menu[10] = {{"Coffee", 50}, {"Tea", 40}, {"Sandwich", 70}, {"Burger", 90}, {"Pizza", 150}, {"French Fries", 60}, {"Coke", 30}, {"Smoothie", 100}, {"Pancakes", 80}, {"Omelette", 100}};
    int orderIndex = 0, totalAmount = 0;
    char command[10];

    printf("\t\tWelcome to Cafe Billing System!\n");
    printf("Type 'menu' to see the list of available items.\n");
    printf("Type 'order' to place an order.\n");
    printf("Type 'cancel' to cancel an order.\n");
    printf("Type 'exit' to exit the program.\n");

    struct Order orders[10];

    // Main loop
    while(1){
        printf("\nEnter Command: ");
        gets(command);

        if(strcmp(command, "menu") == 0){
            printf("Available Items:\n");
            for(int i=0;i<10;i++){
                printf("%d. %s - Rs. %d\n", i+1, menu[i].name, menu[i].price);
            }
        }

        else if(strcmp(command, "order") == 0){
            int itemId, quantity;

            printf("Enter ID of item to order: ");
            scanf("%d", &itemId);

            printf("Enter Quantity: ");
            scanf("%d", &quantity);

            int itemIndex = itemId - 1;
            struct Item item = menu[itemIndex];

            // Add order to the array
            struct Order order = {item.name, quantity, item.price*quantity};
            orders[orderIndex] = order;
            orderIndex++;

            // Calculate total amount
            totalAmount += order.totalPrice;

            // Print confirmation
            printf("Order Placed! Total Price: %d\n", order.totalPrice);
        }

        else if(strcmp(command, "cancel") == 0){
            int orderId;
            printf("Enter Order ID to cancel: ");
            scanf("%d", &orderId);

            // Remove order from the array
            struct Order removedOrder = orders[orderId-1];
            totalAmount -= removedOrder.totalPrice;

            for(int i=orderId-1;i<orderIndex-1;i++){
                orders[i] = orders[i+1];
            }

            // Print cancellation confirmation
            printf("Order Cancelled! Refund Amount: %d\n", removedOrder.totalPrice);
            orderIndex--;
        }

        else if(strcmp(command, "exit") == 0){
            printf("Thank you for using Cafe Billing System!\n");
            break;
        }

        else{
            printf("Invalid Command! Try Again.\n");
        }
    }

    // Print Bill
    printf("--------------------\n");
    printf("\t\tCafe Bill\n");
    printf("--------------------\n");
    printf("Item\t\tQuantity\tPrice\n");

    for(int i=0;i<orderIndex;i++){
        struct Order order = orders[i];
        printf("%s\t\t%d\t\t%d\n", order.itemName, order.quantity, order.totalPrice);
    }

    printf("--------------------\n");
    printf("Total Amount: %d\n", totalAmount);

    return 0;
}