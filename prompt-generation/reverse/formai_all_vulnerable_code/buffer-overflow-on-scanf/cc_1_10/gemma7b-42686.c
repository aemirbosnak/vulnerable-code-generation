//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void InventoryManagement()
{
    int item_id, quantity;
    printf("Enter item ID: ");
    scanf("%d", &item_id);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    FILE *fp = fopen("inventory.txt", "a");
    fprintf(fp, "%d, %d\n", item_id, quantity);
    fclose(fp);
}

void OrderManagement()
{
    int item_id, order_quantity;
    printf("Enter item ID: ");
    scanf("%d", &item_id);

    printf("Enter order quantity: ");
    scanf("%d", &order_quantity);

    FILE *fp = fopen("orders.txt", "a");
    fprintf(fp, "%d, %d\n", item_id, order_quantity);
    fclose(fp);
}

void CustomerManagement()
{
    char customer_name[50];
    printf("Enter customer name: ");
    scanf("%s", customer_name);

    FILE *fp = fopen("customers.txt", "a");
    fprintf(fp, "%s\n", customer_name);
    fclose(fp);
}

int main()
{
    int choice;
    printf("Enter choice: 1 for Inventory Management, 2 for Order Management, 3 for Customer Management\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            InventoryManagement();
            break;
        case 2:
            OrderManagement();
            break;
        case 3:
            CustomerManagement();
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}