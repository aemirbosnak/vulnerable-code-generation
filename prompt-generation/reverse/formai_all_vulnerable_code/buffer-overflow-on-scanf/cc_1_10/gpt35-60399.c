//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for menu items
struct item 
{
    char itemName[100];
    int itemPrice;
};

// function to add menu items
int addItem(struct item menu[], int count)
{
    char name[100];
    int price;
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%d", &price);
    strcpy(menu[count].itemName, name);
    menu[count].itemPrice = price;
    return count + 1;
}

// function to display menu
void displayMenu(struct item menu[], int count)
{
    printf("------ MENU ------\n");
    for (int i = 0; i < count; i++) 
    {
        printf("%d. %s - $%d\n", i+1, menu[i].itemName, menu[i].itemPrice);
    }
    printf("\n");
}

// function to calculate bill
int calculateBill(struct item menu[], int choices[], int count)
{
    int total = 0;
    printf("------ BILL ------\n");
    for (int i = 0; i < count; i++) 
    {
        if (choices[i] != 0) 
        {
            printf("%s - $%d\n", menu[i].itemName, menu[i].itemPrice);
            total += menu[i].itemPrice * choices[i];
        }
    }
    printf("Total: $%d\n", total);
    return total;
}

// main function
int main()
{
    struct item menu[10];
    int choices[10] = {0};
    int count = 0;
    int option;
    while (1) 
    {
        printf("------ C CAFE BILLING SYSTEM ------\n");
        printf("1. Add item\n2. Display menu\n3. Place order\n4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) 
        {
            case 1:
                count = addItem(menu, count);
                break;
            case 2:
                displayMenu(menu, count);
                break;
            case 3:
                calculateBill(menu, choices, count);
                memset(choices, 0, sizeof(choices));
                count = 0;
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
        printf("\n");
    }
    return 0;
}