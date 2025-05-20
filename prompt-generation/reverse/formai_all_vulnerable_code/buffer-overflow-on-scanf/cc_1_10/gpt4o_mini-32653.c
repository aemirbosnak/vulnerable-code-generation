//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100

// Structure to represent a cake order
typedef struct {
    int orderID;
    char customerName[50];
    int bakingTime; // time in minutes
    int completionTime; // time when order is completed
} CakeOrder;

// Function to compare two orders based on arrival time (orderID in this case)
int compareOrders(const void *a, const void *b) {
    return ((CakeOrder *)a)->orderID - ((CakeOrder *)b)->orderID;
}

// Function to calculate and display order completion details using FCFS
void processOrders(CakeOrder orders[], int numOrders) {
    int currentTime = 0; // Represents the current time in bakery
    printf("\nProcessing Cake Orders:\n");
    printf("-------------------------------------------------\n");
    printf("Order ID\tCustomer Name\tBaking Time\tCompletion Time\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < numOrders; i++) {
        currentTime += orders[i].bakingTime; // Increment current time by baking time of the order
        orders[i].completionTime = currentTime; // Set the completion time for the order

        // Displaying the order details
        printf("%d\t\t%s\t\t%d mins\t\t%d mins\n",
               orders[i].orderID,
               orders[i].customerName,
               orders[i].bakingTime,
               orders[i].completionTime);
    }
    printf("-------------------------------------------------\n");
}

int main() {
    CakeOrder orders[MAX_ORDERS];
    int numOrders;

    // Input number of orders
    printf("Welcome to the Bakery Order Management System!\n");
    printf("Enter the number of cake orders: ");
    scanf("%d", &numOrders);
    
    // Input details of each order
    for (int i = 0; i < numOrders; i++) {
        orders[i].orderID = i + 1; // Assigning order ID
        printf("Enter customer name for order %d: ", orders[i].orderID);
        scanf("%s", orders[i].customerName);
        printf("Enter baking time (in minutes) for order %d: ", orders[i].orderID);
        scanf("%d", &orders[i].bakingTime);
    }

    // Sort orders based on order ID to simulate FCFS
    qsort(orders, numOrders, sizeof(CakeOrder), compareOrders);

    // Process the orders and display the results
    processOrders(orders, numOrders);

    printf("All orders have been processed successfully!\n");
    return 0;
}