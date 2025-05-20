//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    int quantity;
    float price;
} Item;

void add_item(Item* inventory, int* total_items)
{
    printf("Enter item name: ");
    char name[50];
    scanf("%s", name);
    
    printf("Enter quantity: ");
    int quantity;
    scanf("%d", &quantity);
    
    printf("Enter price: ");
    float price;
    scanf("%f", &price);
    
    Item new_item = {0};
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;
    
    inventory[*total_items] = new_item;
    (*total_items)++;
    
    printf("Item added successfully!\n");
}

void remove_item(Item* inventory, int* total_items, char* name_to_remove)
{
    for(int i = 0; i < *total_items; i++)
    {
        if(strcmp(inventory[i].name, name_to_remove) == 0)
        {
            inventory[i] = inventory[(*total_items) - 1];
            (*total_items)--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void search_item(Item* inventory, int total_items, char* name_to_search)
{
    for(int i = 0; i < total_items; i++)
    {
        if(strcmp(inventory[i].name, name_to_search) == 0)
        {
            printf("%s - Quantity: %d, Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void display_inventory(Item* inventory, int total_items)
{
    printf("Current inventory:\n");
    for(int i = 0; i < total_items; i++)
    {
        printf("%s - Quantity: %d, Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main()
{
    Item inventory[100] = {0};
    int total_items = 0;
    
    while(1)
    {
        printf("Enter operation:\n1. Add item\n2. Remove item\n3. Search item\n4. Display inventory\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                add_item(inventory, &total_items);
                break;
            case 2:
                printf("Enter item name to remove: ");
                char name_to_remove[50];
                scanf("%s", name_to_remove);
                remove_item(inventory, &total_items, name_to_remove);
                break;
            case 3:
                printf("Enter item name to search: ");
                char name_to_search[50];
                scanf("%s", name_to_search);
                search_item(inventory, total_items, name_to_search);
                break;
            case 4:
                display_inventory(inventory, total_items);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}