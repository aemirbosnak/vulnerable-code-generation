//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char itemName[30];
    float price;
    int qty;
} Item;

void addItem(Item[], int*);
void viewCart(Item[], int*);
void generateBill(Item[], int*);

int main()
{
    int choice, itemNum = 0;
    Item cart[100];

    while(1)
    {
        printf("Welcome to the Cafe Billing System!\n");
        printf("1. Add item to cart\n");
        printf("2. View cart\n");
        printf("3. Generate bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addItem(cart, &itemNum);
                break;
            case 2:
                viewCart(cart, &itemNum);
                break;
            case 3:
                generateBill(cart, &itemNum);
                break;
            case 4:
                printf("Thank you for using Cafe Billing System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}

void addItem(Item cart[], int *itemNum)
{
    char itemName[30];
    float itemPrice;
    int itemQty;

    printf("Enter item name: ");
    scanf("%s", itemName);
    printf("Enter item price: ");
    scanf("%f", &itemPrice);
    printf("Enter item quantity: ");
    scanf("%d", &itemQty);

    strcpy(cart[*itemNum].itemName, itemName);
    cart[*itemNum].price = itemPrice;
    cart[*itemNum].qty = itemQty;

    (*itemNum)++;

    printf("Item added to cart!\n");
}

void viewCart(Item cart[], int *itemNum)
{
    float totalAmount = 0;

    if(*itemNum == 0)
    {
        printf("Your cart is empty!\n");
        return;
    }

    printf("Items in your cart:\n");
    printf("S.No.\tItem Name\tQuantity\tPrice\n");
    for(int i = 0; i < *itemNum; i++)
    {
        printf("%d.\t%s\t\t%d\t\t%.2f\n", i+1, cart[i].itemName, cart[i].qty, cart[i].price);
        totalAmount += cart[i].price * cart[i].qty;
    }

    printf("Total amount: %.2f\n", totalAmount);
}

void generateBill(Item cart[], int *itemNum)
{
    float totalAmount = 0;

    if(*itemNum == 0)
    {
        printf("Your cart is empty!\n");
        return;
    }

    printf("Items in your cart:\n");
    printf("S.No.\tItem Name\tQuantity\tPrice\t\tAmount\n");
    for(int i = 0; i < *itemNum; i++)
    {
        printf("%d.\t%s\t\t%d\t\t%.2f\t\t%.2f\n", i+1, cart[i].itemName, cart[i].qty, cart[i].price, cart[i].price * cart[i].qty);
        totalAmount += cart[i].price * cart[i].qty;
    }

    printf("Total amount: %.2f\n", totalAmount);

    printf("Thank you for using Cafe Billing System!\n");

    *itemNum = 0;
}