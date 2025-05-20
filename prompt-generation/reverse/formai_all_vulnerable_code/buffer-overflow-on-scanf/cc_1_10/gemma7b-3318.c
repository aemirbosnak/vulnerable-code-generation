//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item
{
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];

void add_item(char* name, float price, int quantity)
{
    int i = 0;
    for (; i < MAX_ITEMS && items[i].name[0] != '\0'; i++)
    {
        ;
    }

    strcpy(items[i].name, name);
    items[i].price = price;
    items[i].quantity = quantity;
}

void print_items()
{
    int i = 0;
    for (; items[i].name[0] != '\0'; i++)
    {
        printf("%s - %.2f, %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

int calculate_total(int quantity, float price)
{
    return quantity * price;
}

void generate_bill()
{
    printf("------------------------------------------------------------------------\n");
    printf("C Cafe Billing System\n");
    printf("------------------------------------------------------------------------\n");
    print_items();
    printf("------------------------------------------------------------------------\n");
    printf("Total: %.2f\n", calculate_total(items[0].quantity, items[0].price));
    printf("------------------------------------------------------------------------\n");
    printf("Please pay the bill: $");
    float payment = 0.0f;
    scanf("%f", &payment);
    if (payment < calculate_total(items[0].quantity, items[0].price))
    {
        printf("Insufficient funds. Please try again.\n");
    }
    else
    {
        printf("Thank you for your payment. Have a nice day.\n");
    }
}

int main()
{
    add_item("Coffee", 2.50, 2);
    add_item("Tea", 3.00, 1);
    add_item("Juice", 4.00, 3);

    generate_bill();

    return 0;
}