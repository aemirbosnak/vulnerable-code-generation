//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

//Structure for the menu items
struct Item
{
    int id;
    char name[30];
    float cost;
};

//Structure for the items ordered by the customer
struct Order
{
    int id;
    int quantity;
};

//Function to display the menu
void displayMenu(struct Item menu[], int size)
{
    printf("\n========== MENU ==========\n");
    printf("ID  Item Name\tCost\n");
    for (int i = 0; i < size; i++)
    {
        printf("%-3d %-20s $%.2f\n", menu[i].id, menu[i].name, menu[i].cost);
    }
}

//Function to take the order from the customer
void takeOrder(struct Item menu[], int size, struct Order order[], int *orderIndex)
{
    int option = 1;
    while (option != 0)
    {
        printf("\nEnter the item ID (0 to finish): ");
        scanf("%d", &option);
        if (option == 0)
        {
            break;
        }
        int found = 0;
        for (int i = 0; i < size; i++)
        {
            if (menu[i].id == option)
            {
                found = 1;
                order[*orderIndex].id = option;
                printf("Enter the quantity: ");
                scanf("%d", &order[*orderIndex].quantity);
                (*orderIndex)++;
                break;
            }
        }
        if (!found)
        {
            printf("Invalid ID. Please try again.\n");
        }
    }
}

//Function to calculate the total bill
float calculateBill(struct Item menu[], int size, struct Order order[], int orderSize)
{
    float total = 0;
    for (int i = 0; i < orderSize; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (order[i].id == menu[j].id)
            {
                total += (menu[j].cost * order[i].quantity);
            }
        }
    }
    return total;
}

int main()
{
    //Defining the menu items
    struct Item menu[5] = {
        {1, "Coffee", 2.5},
        {2, "Tea", 2.0},
        {3, "Sandwich", 5.0},
        {4, "Burger", 6.0},
        {5, "Pizza", 8.0}
    };

    int size = sizeof(menu) / sizeof(menu[0]);

    //Defining the orders array
    struct Order orders[50];
    int orderIndex = 0;

    //Displaying the menu
    displayMenu(menu, size);

    //Taking the order from the customer
    takeOrder(menu, size, orders, &orderIndex);

    //Calculating the total bill
    float totalBill = calculateBill(menu, size, orders, orderIndex);

    //Displaying the bill to the customer
    printf("\n========== BILL ==========\n");
    printf("Item\tQuantity\tCost\n");
    for (int i = 0; i < orderIndex; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (orders[i].id == menu[j].id)
            {
                printf("%-20s %-8d $%.2f\n", menu[j].name, orders[i].quantity, menu[j].cost * orders[i].quantity);
                break;
            }
        }
    }
    printf("Total Bill: $%.2f", totalBill);

    return 0;
}