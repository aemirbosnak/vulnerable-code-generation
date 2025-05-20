//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct Item
{
    char name[20];
    int quantity;
    float price;
};

void manageInventory(struct Item items[], int size)
{
    printf("Items:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    printf("Enter item name:");
    char item_name[20];
    scanf("%s", item_name);

    int item_quantity = 0;
    printf("Enter item quantity:");
    scanf("%d", &item_quantity);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(items[i].name, item_name) == 0)
        {
            items[i].quantity += item_quantity;
            printf("Item quantity updated.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

int main()
{
    struct Item items[] = {
        {"Apple", 10, 1.20},
        {"Banana", 5, 0.80},
        {"Orange", 7, 1.00}
    };

    manageInventory(items, 3);

    return 0;
}