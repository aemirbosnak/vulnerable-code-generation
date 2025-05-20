//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Item
{
    int id, quantity;
    char name[50], date[15];
    float cost_price, selling_price;
};

int count = 0;
struct Item items[MAX];

void addItem()
{
    if (count == MAX)
    {
        printf("Inventory full\n");
        return;
    }

    struct Item newItem;

    printf("Enter item id: ");
    scanf("%d", &newItem.id);

    printf("Enter item name: ");
    scanf("%s", newItem.name);

    printf("Enter cost price: ");
    scanf("%f", &newItem.cost_price);

    printf("Enter selling price: ");
    scanf("%f", &newItem.selling_price);

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter date [mm-dd-yyyy]: ");
    scanf("%s", newItem.date);

    items[count] = newItem;
    count++;

    printf("Item added successfully\n");
}

void searchItem()
{
    int search_id;
    printf("Enter item id to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < count; i++)
    {
        if (items[i].id == search_id)
        {
            printf("Item found:\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n", items[i].name);
            printf("Cost price: %.2f\n", items[i].cost_price);
            printf("Selling price: %.2f\n", items[i].selling_price);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Date: %s\n", items[i].date);
            return;
        }
    }

    printf("Item not found\n");
}

void displayInventory()
{
    if (count == 0)
    {
        printf("Inventory is empty\n");
        return;
    }

    printf("\nID\tName\tCost Price\tSelling Price\tQuantity\tDate\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t$%.2f\t\t$%.2f\t\t%d\t%s\n", items[i].id, items[i].name, items[i].cost_price, items[i].selling_price, items[i].quantity, items[i].date);
    }
}

void sellItem()
{
    int sell_id, sell_quantity;
    printf("Enter item id to sell: ");
    scanf("%d", &sell_id);

    for (int i = 0; i < count; i++)
    {
        if (items[i].id == sell_id)
        {
            printf("Enter quantity to sell: ");
            scanf("%d", &sell_quantity);

            if (items[i].quantity < sell_quantity)
            {
                printf("Insufficient quantity\n");
                return;
            }

            float total_cost = items[i].cost_price * sell_quantity;
            float total_sell = items[i].selling_price * sell_quantity;
            printf("Total cost price: $%.2f\n", total_cost);
            printf("Total selling price: $%.2f\n", total_sell);
            printf("Profit: $%.2f\n", total_sell - total_cost);

            items[i].quantity -= sell_quantity;

            printf("Item sold successfully\n");

            if (items[i].quantity == 0)
            {
                for (int j = i; j < count - 1; j++)
                {
                    items[j] = items[j + 1];
                }
                count--;
            }

            return;
        }
    }

    printf("Item not found\n");
}

int main()
{
    int choice = 0;

    while (1)
    {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Search item\n");
        printf("3. Display inventory\n");
        printf("4. Sell item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addItem();
            break;
        case 2:
            searchItem();
            break;
        case 3:
            displayInventory();
            break;
        case 4:
            sellItem();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}