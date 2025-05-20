//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void warehouse_management(int item_id, int quantity, char* item_name)
{
    int i = 0;
    int stock_quantity = 0;
    char* stock_name = NULL;

    FILE* file_ptr = fopen("warehouse.txt", "r");

    // Read the stock quantity and name from the file
    while (fscanf(file_ptr, "%d %s", &stock_quantity, stock_name) != EOF)
    {
        if (stock_quantity > 0)
        {
            i++;
            if (strcmp(stock_name, item_name) == 0)
            {
                stock_quantity++;
                break;
            }
        }
    }

    fclose(file_ptr);

    // If the item is not found, add it to the file
    if (i == 0)
    {
        file_ptr = fopen("warehouse.txt", "a");
        fprintf(file_ptr, "%d %s\n", item_id, item_name);
        fclose(file_ptr);
    }

    // Update the item quantity
    file_ptr = fopen("warehouse.txt", "w");
    fprintf(file_ptr, "Item ID: %d\n", item_id);
    fprintf(file_ptr, "Item Name: %s\n", item_name);
    fprintf(file_ptr, "Quantity: %d\n", quantity);
    fclose(file_ptr);

    printf("Item updated successfully!\n");
}

int main()
{
    warehouse_management(1, 10, "ABC");
    warehouse_management(2, 5, "XYZ");
    warehouse_management(3, 7, "ABC");

    return 0;
}