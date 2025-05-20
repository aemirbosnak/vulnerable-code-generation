//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define PRICE_COFFEE 20.0
#define PRICE_TEA 15.0
#define PRICE_SODA 25.0

struct Item
{
    char name[20];
    int qty;
    float price;
};

int main()
{
    float total_price = 0.0;
    int total_qty = 0;
    struct Item items[10];

    int choice, qty, count = 0;
    char name[20];

    printf("Welcome to the C Cafe Billing System.\n");

    do
    {
        printf("\nWhat would you like to order?\n");
        printf("1. Coffee - Rs. %.1f\n", PRICE_COFFEE);
        printf("2. Tea - Rs. %.1f\n", PRICE_TEA);
        printf("3. Soda - Rs. %.1f\n", PRICE_SODA);
        printf("4. Done ordering\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            strcpy(items[count].name, "Coffee");
            items[count].price = PRICE_COFFEE;
            break;
        case 2:
            strcpy(items[count].name, "Tea");
            items[count].price = PRICE_TEA;
            break;
        case 3:
            strcpy(items[count].name, "Soda");
            items[count].price = PRICE_SODA;
            break;
        case 4:
            continue;
        default:
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &qty);

        items[count].qty = qty;

        total_qty += qty;
        total_price += (qty * items[count].price);

        printf("%d %s added to order.\n", qty, items[count].name);

        count++;

    } while (choice != 4);

    printf("\n-----BILL-----\n");
    printf("Qty\tName\tPrice\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%.1f\n", items[i].qty, items[i].name, items[i].price * items[i].qty);
    }

    printf("----------------\n");
    printf("Total\t\t%.1f\n", total_price);
    printf("Total Qty\t%d\n", total_qty);

    return 0;
}