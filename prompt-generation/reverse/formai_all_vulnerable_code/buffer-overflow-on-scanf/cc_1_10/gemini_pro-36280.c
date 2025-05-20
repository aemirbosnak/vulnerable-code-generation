//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int product_id;
    char product_name[50];
    int quantity;
    float price;
    struct node *next;
} node;

node *head = NULL;

void add_product()
{
    node *new_node = (node *)malloc(sizeof(node));
    printf("Enter product ID: ");
    scanf("%d", &new_node->product_id);
    printf("Enter product name: ");
    scanf("%s", new_node->product_name);
    printf("Enter quantity: ");
    scanf("%d", &new_node->quantity);
    printf("Enter price: ");
    scanf("%f", &new_node->price);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        node *current_node = head;
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    printf("Product added successfully!\n");
}

void display_products()
{
    if (head == NULL)
    {
        printf("No products to display\n");
    }
    else
    {
        node *current_node = head;
        printf("Product ID\tProduct Name\tQuantity\tPrice\n");
        while (current_node != NULL)
        {
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", current_node->product_id, current_node->product_name, current_node->quantity, current_node->price);
            current_node = current_node->next;
        }
    }
}

void search_product()
{
    int product_id;
    printf("Enter product ID to search: ");
    scanf("%d", &product_id);

    node *current_node = head;
    while (current_node != NULL)
    {
        if (current_node->product_id == product_id)
        {
            printf("Product found!\n");
            printf("Product ID: %d\n", current_node->product_id);
            printf("Product Name: %s\n", current_node->product_name);
            printf("Quantity: %d\n", current_node->quantity);
            printf("Price: %.2f\n", current_node->price);
            return;
        }
        current_node = current_node->next;
    }

    printf("Product not found!\n");
}

void delete_product()
{
    int product_id;
    printf("Enter product ID to delete: ");
    scanf("%d", &product_id);

    if (head == NULL)
    {
        printf("No products to delete\n");
    }
    else if (head->product_id == product_id)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        printf("Product deleted successfully!\n");
    }
    else
    {
        node *current_node = head;
        node *previous_node = NULL;
        while (current_node != NULL)
        {
            if (current_node->product_id == product_id)
            {
                previous_node->next = current_node->next;
                free(current_node);
                printf("Product deleted successfully!\n");
                return;
            }
            previous_node = current_node;
            current_node = current_node->next;
        }

        printf("Product not found!\n");
    }
}

void update_product()
{
    int product_id;
    printf("Enter product ID to update: ");
    scanf("%d", &product_id);

    node *current_node = head;
    while (current_node != NULL)
    {
        if (current_node->product_id == product_id)
        {
            printf("Enter new product name: ");
            scanf("%s", current_node->product_name);
            printf("Enter new quantity: ");
            scanf("%d", &current_node->quantity);
            printf("Enter new price: ");
            scanf("%f", &current_node->price);
            printf("Product updated successfully!\n");
            return;
        }
        current_node = current_node->next;
    }

    printf("Product not found!\n");
}

int main()
{
    int choice;
    do
    {
        printf("\nProduct Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Display products\n");
        printf("3. Search a product\n");
        printf("4. Delete a product\n");
        printf("5. Update a product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                update_product();
                break;
            case 6:
                printf("Exiting the program");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}