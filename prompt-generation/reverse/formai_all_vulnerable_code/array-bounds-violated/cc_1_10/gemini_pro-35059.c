//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the menu items
typedef struct Menu
{
    int itemCode;
    char itemName[50];
    float price;
} Menu;

// Structure to store the order items
typedef struct Order
{
    int itemCode;
    int quantity;
    float price;
} Order;

// Function to display the menu
void displayMenu(Menu menu[], int numItems)
{
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("%d. %s - %.2f\n", menu[i].itemCode, menu[i].itemName, menu[i].price);
    }
}

// Function to take order from the customer
void takeOrder(Order order[], int *numOrders)
{
    int itemCode;
    int quantity;
    float price;

    printf("Enter item code (-1 to quit): ");
    scanf("%d", &itemCode);

    while (itemCode != -1)
    {
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Check if the item code is valid
        int found = 0;
        for (int i = 0; i < *numOrders; i++)
        {
            if (order[i].itemCode == itemCode)
            {
                order[i].quantity += quantity;
                found = 1;
                break;
            }
        }

        // If the item code is not valid, add the item to the order
        if (!found)
        {
            order[*numOrders].itemCode = itemCode;
            order[*numOrders].quantity = quantity;
            (*numOrders)++;
        }

        printf("Enter item code (-1 to quit): ");
        scanf("%d", &itemCode);
    }
}

// Function to calculate the bill
float calculateBill(Order order[], int numOrders)
{
    float totalBill = 0.0;

    for (int i = 0; i < numOrders; i++)
    {
        totalBill += order[i].quantity * order[i].price;
    }

    return totalBill;
}

// Main function
int main()
{
    // Define the menu items
    Menu menu[] =
    {
        {1, "Coffee", 2.5},
        {2, "Tea", 1.5},
        {3, "Juice", 3.0},
        {4, "Sandwich", 4.0},
        {5, "Salad", 5.0},
    };
    int numItems = 5;

    // Display the menu
    displayMenu(menu, numItems);

    // Take order from the customer
    Order order[100];
    int numOrders = 0;
    takeOrder(order, &numOrders);

    // Calculate the bill
    float totalBill = calculateBill(order, numOrders);

    // Print the bill
    printf("Bill:\n");
    for (int i = 0; i < numOrders; i++)
    {
        printf("%d. %s - %d - %.2f\n", i + 1, menu[order[i].itemCode - 1].itemName, order[i].quantity, order[i].quantity * menu[order[i].itemCode - 1].price);
    }
    printf("Total: %.2f\n", totalBill);

    return 0;
}