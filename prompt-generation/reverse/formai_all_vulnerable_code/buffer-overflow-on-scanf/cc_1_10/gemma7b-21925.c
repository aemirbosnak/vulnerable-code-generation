//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the Warehouse Management System structure
struct WarehouseManagementSystem
{
    char item_name[50];
    int item_quantity;
    float item_price;
    struct WarehouseManagementSystem* next;
};

// Function to insert a new item into the warehouse management system
void insert_item(struct WarehouseManagementSystem** head)
{
    // Allocate memory for the new item
    struct WarehouseManagementSystem* new_item = (struct WarehouseManagementSystem*)malloc(sizeof(struct WarehouseManagementSystem));

    // Get the item name, quantity, and price from the user
    printf("Enter item name: ");
    scanf("%s", new_item->item_name);

    printf("Enter item quantity: ");
    scanf("%d", &new_item->item_quantity);

    printf("Enter item price: ");
    scanf("%f", &new_item->item_price);

    // Insert the new item into the linked list
    if (*head == NULL)
    {
        *head = new_item;
    }
    else
    {
        (*head)->next = new_item;
        *head = new_item;
    }
}

// Function to search for an item in the warehouse management system
void search_item(struct WarehouseManagementSystem* head)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item in the linked list
    struct WarehouseManagementSystem* current_item = head;
    while (current_item)
    {
        if (strcmp(current_item->item_name, item_name) == 0)
        {
            // Print the item details
            printf("Item name: %s\n", current_item->item_name);
            printf("Item quantity: %d\n", current_item->item_quantity);
            printf("Item price: %.2f\n", current_item->item_price);
            break;
        }
        current_item = current_item->next;
    }

    // If the item is not found, print an error message
    if (current_item == NULL)
    {
        printf("Item not found.\n");
    }
}

// Function to update the item quantity in the warehouse management system
void update_item_quantity(struct WarehouseManagementSystem* head)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item in the linked list
    struct WarehouseManagementSystem* current_item = head;
    while (current_item)
    {
        if (strcmp(current_item->item_name, item_name) == 0)
        {
            // Get the new item quantity from the user
            int new_quantity;
            printf("Enter new item quantity: ");
            scanf("%d", &new_quantity);

            // Update the item quantity
            current_item->item_quantity = new_quantity;

            break;
        }
        current_item = current_item->next;
    }

    // If the item is not found, print an error message
    if (current_item == NULL)
    {
        printf("Item not found.\n");
    }
}

// Function to delete an item from the warehouse management system
void delete_item(struct WarehouseManagementSystem* head)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item in the linked list
    struct WarehouseManagementSystem* current_item = head;
    struct WarehouseManagementSystem* previous_item = NULL;
    while (current_item)
    {
        if (strcmp(current_item->item_name, item_name) == 0)
        {
            // If the item is the first item in the list, update the head of the list
            if (previous_item == NULL)
            {
                head = current_item->next;
            }
            // Otherwise, delete the item from the list
            else
            {
                previous_item->next = current_item->next;
            }

            free(current_item);
            break;
        }
        previous_item = current_item;
        current_item = current_item->next;
    }

    // If the item is not found, print an error message
    if (current_item == NULL)
    {
        printf("Item not found.\n");
    }
}

int main()
{
    // Create a head of the warehouse management system
    struct WarehouseManagementSystem* head = NULL;

    // Insert some items into the warehouse management system
    insert_item(&head);
    insert_item(&head);
    insert_item(&head);

    // Search for an item in the warehouse management system
    search_item(head);

    // Update the item quantity in the warehouse management system
    update_item_quantity(head);

    // Delete an item from the warehouse management system
    delete_item(head);

    return 0;
}