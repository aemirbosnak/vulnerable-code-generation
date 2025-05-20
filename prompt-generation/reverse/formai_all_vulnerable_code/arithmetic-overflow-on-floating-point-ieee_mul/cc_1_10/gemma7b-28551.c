//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MENU_SIZE 5
#define ITEM_NAME_SIZE 20

typedef struct Item
{
    char name[ITEM_NAME_SIZE];
    float price;
    int quantity;
} Item;

Item items[MENU_SIZE] =
{
    {"Coffee", 5.0, 10},
    {"Tea", 3.0, 8},
    {"Juice", 4.0, 12},
    {"Smoothie", 6.0, 6},
    {"Water", 2.0, 14}
};

void display_menu()
{
    printf("*** Cafe Menu ***\n");
    for (int i = 0; i < MENU_SIZE; i++)
    {
        printf("%s - %f\n", items[i].name, items[i].price);
    }
}

void calculate_total(int item_index, float quantity)
{
    Item item = items[item_index];
    float total = item.price * quantity;
    printf("Total: %f\n", total);
}

int main()
{
    display_menu();

    int item_index;
    float quantity;

    printf("Enter item index: ");
    scanf("%d", &item_index);

    printf("Enter quantity: ");
    scanf("%f", &quantity);

    calculate_total(item_index, quantity);

    return 0;
}