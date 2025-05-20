//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

struct Menu
{
    int ItemID;
    char ItemName[50];
    float ItemPrice;
};
struct Menu Cafe[100];

struct Order
{
    int OrderID;
    int ItemID;
    int Quantity;
    float TotalPrice;
};
struct Order Bill[100];

int MenuCount = 0, OrderCount = 0;

void CreateMenu()
{
    printf("Enter the number of items in the menu: ");
    scanf("%d", &MenuCount);
    
    for(int i = 0; i < MenuCount; i++)
    {
        printf("\nEnter details of item %d\n", i+1);
        Cafe[i].ItemID = i+1;
        printf("Item Name: ");
        scanf("%s", Cafe[i].ItemName);
        printf("Price: ");
        scanf("%f", &Cafe[i].ItemPrice);
    }
    printf("\nMenu Created Succesfully\n");
}

void PlaceOrder()
{
    int ItemID, Quantity;
    float TotalBill = 0;
    printf("Enter Customer Order ID: ");
    scanf("%d", &Bill[OrderCount].OrderID);
    
    while(1)
    {
        printf("\nEnter Item ID to add to order (Enter 0 to stop): ");
        scanf("%d", &ItemID);
        if(ItemID == 0) break;
        
        printf("Enter quantity: ");
        scanf("%d", &Quantity);
        
        // Check if ItemID exists in menu
        int index = -1;
        for(int i = 0; i < MenuCount; i++)
        {
            if(Cafe[i].ItemID == ItemID)
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            printf("Invalid ItemID. Please select an item from the menu.\n");
            continue;
        }
        
        Bill[OrderCount].ItemID = ItemID;
        Bill[OrderCount].Quantity = Quantity;
        Bill[OrderCount].TotalPrice = Quantity * Cafe[index].ItemPrice;
        TotalBill += Bill[OrderCount].TotalPrice;
        
        printf("%s (Quantity - %d) added to order.\n", Cafe[index].ItemName, Quantity);
    }
    
    Bill[OrderCount].TotalPrice = TotalBill;
    printf("Order Placed Succesfully!\nTotal Bill Amount: %.2f\n", TotalBill);
    OrderCount++;
}

void DisplayMenu()
{
    printf("\nMenu:\n");
    printf("ID   Name\t\tPrice\n");
    for(int i = 0; i < MenuCount; i++)
    {
        printf("%02d.  %-20s  $%.2f\n", Cafe[i].ItemID, Cafe[i].ItemName, Cafe[i].ItemPrice);
    }
}

void DisplayOrders()
{
    float GrandTotal = 0;
    printf("\nOrder Details:\n");
    printf("Customer Order ID\tItemID\tQuantity\tTotal Price\n");
    for(int i = 0; i < OrderCount; i++)
    {
        printf("%d\t\t\t%d\t%d\t\t%.2f\n", Bill[i].OrderID, Bill[i].ItemID, Bill[i].Quantity, Bill[i].TotalPrice);
        GrandTotal += Bill[i].TotalPrice;
    }
    printf("\nTotal Sales:\t\t\t\t\t$%.2f\n", GrandTotal);
}

int main()
{
    int choice = 0;
    do
    {
        printf("\n\n============================\n");
        printf("Welcome to Cafe Billing System\n");
        printf("1. Create Menu\n");
        printf("2. Place Order\n");
        printf("3. Display Menu\n");
        printf("4. Display Orders\n");
        printf("5. Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: CreateMenu(); break;
            case 2: PlaceOrder(); break;
            case 3: DisplayMenu(); break;
            case 4: DisplayOrders(); break;
            case 5: printf("Exiting..."); exit(0);
            default: printf("Invalid option. Please try again.\n");
        }
    } while(1);
    return 0;
}