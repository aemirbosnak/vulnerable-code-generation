//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include<stdio.h>
#include<string.h>

typedef struct Menu
{
    char itemName[20];
    int itemPrice;
}Menu;

typedef struct BillItem
{
    char itemName[20];
    int itemPrice;
    int quantity;
    int total;
}BillItem;

void addItem(Menu *menu, BillItem *bill, char name[], int quantity);

int main()
{
    Menu menu[5] = {{"Coffee", 50}, {"Tea", 30}, {"Sandwich", 70}, {"Muffin", 40}, {"Brownie", 60}};
    BillItem bill[20];
    int itemCount = 0;
    char choice[10];
    int quantity;

    printf("Welcome to C Cafe\n");
    printf("-----------------\n");

    do
    {
        printf("\nMenu:\n-----\n");
        printf("1. Coffee - Rs. 50\n2. Tea - Rs. 30\n3. Sandwich - Rs. 70\n4. Muffin - Rs. 40\n5. Brownie - Rs. 60\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice);

        if(strcmp(choice, "1") == 0)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addItem(&menu[0], &bill[itemCount], menu[0].itemName, quantity);
            itemCount++;
        }
        else if(strcmp(choice, "2") == 0)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addItem(&menu[1], &bill[itemCount], menu[1].itemName, quantity);
            itemCount++;
        }
        else if(strcmp(choice, "3") == 0)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addItem(&menu[2], &bill[itemCount], menu[2].itemName, quantity);
            itemCount++;
        }
        else if(strcmp(choice, "4") == 0)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addItem(&menu[3], &bill[itemCount], menu[3].itemName, quantity);
            itemCount++;
        }
        else if(strcmp(choice, "5") == 0)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addItem(&menu[4], &bill[itemCount], menu[4].itemName, quantity);
            itemCount++;
        }
        else if(strcmp(choice, "6") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }while(1);

    int totalAmount = 0;

    printf("\nBill:\n-----\n");
    printf("%-20s %-10s %-10s %-10s\n", "Item", "Price", "Quantity", "Total");

    for(int i=0; i<itemCount; i++)
    {
        printf("%-20s %-10d %-10d %-10d\n", bill[i].itemName, bill[i].itemPrice, bill[i].quantity, bill[i].total);

        totalAmount += bill[i].total;
    }

    printf("\nTotal Amount: Rs. %d\n", totalAmount);

    return 0;
}

void addItem(Menu *menu, BillItem *bill, char name[], int quantity)
{
    strcpy(bill->itemName, name);
    bill->itemPrice = menu->itemPrice;
    bill->quantity = quantity;
    bill->total = menu->itemPrice * quantity;
}