//FormAI DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product
{
    int id; // unique identifier
    char name[50]; // name of the product
    double price; // price of the product
    int quantity; // quantity available in inventory
};

struct product* products; // array of product structures
int num_products = 0; // number of products currently in inventory
int next_id = 1; // the next available ID number for a product

void display_menu()
{
    printf("------------------------------\n");
    printf("PRODUCT INVENTORY SYSTEM MENU\n");
    printf("------------------------------\n\n");
    printf("1. Add product\n");
    printf("2. Edit product\n");
    printf("3. Delete product\n");
    printf("4. Display all products\n");
    printf("5. Search for a product\n");
    printf("6. Exit\n");
}

void add_product()
{
    // increase size of products array
    num_products++;
    products = (struct product*) realloc(products, num_products * sizeof(struct product));
    
    // get inputs for new product
    printf("Enter name: ");
    scanf("%s", products[num_products-1].name);
    printf("Enter price: ");
    scanf("%lf", &products[num_products-1].price);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products-1].quantity);
    
    // set ID for new product and display success message
    products[num_products-1].id = next_id;
    next_id++;
    printf("\nProduct added successfully!\n");
}

void edit_product()
{
    // get ID of product to edit
    int id;
    printf("Enter ID of product to edit: ");
    scanf("%d", &id);
    
    // find product with matching ID
    int found = -1;
    for (int i = 0; i < num_products; i++)
    {
        if (products[i].id == id)
        {
            found = i;
            break;
        }
    }
    
    // if product was found, get new inputs and update values
    if (found >= 0)
    {
        printf("Old name: %s\nNew name: ", products[found].name);
        scanf("%s", products[found].name);
        printf("Old price: %.2f\nNew price: ", products[found].price);
        scanf("%lf", &products[found].price);
        printf("Old quantity: %d\nNew quantity: ", products[found].quantity);
        scanf("%d", &products[found].quantity);
        printf("\nProduct edited successfully!\n");
    }
    else // otherwise display error message
    {
        printf("\nProduct with ID %d not found in inventory.\n", id);
    }
}

void delete_product()
{
    // get ID of product to delete
    int id;
    printf("Enter ID of product to delete: ");
    scanf("%d", &id);
    
    // find product with matching ID
    int found = -1;
    for (int i = 0; i < num_products; i++)
    {
        if (products[i].id == id)
        {
            found = i;
            break;
        }
    }
    
    // if product was found, remove from array and reduce size
    if (found >= 0)
    {
        for (int i = found; i < num_products-1; i++)
        {
            products[i] = products[i+1];
        }
        num_products--;
        products = (struct product*) realloc(products, num_products * sizeof(struct product));
        printf("\nProduct deleted successfully!\n");
    }
    else // otherwise display error message
    {
        printf("\nProduct with ID %d not found in inventory.\n", id);
    }
}

void display_products()
{
    printf("\nPRODUCT INVENTORY:\n\n");
    printf("ID  | NAME                    | PRICE | QUANTITY\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_products; i++)
    {
        printf("%-3d | %-23.23s | $%-4.2f | %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
}

void search_product()
{
    // get name of product to search for
    char name[50];
    printf("Enter name of product to search for: ");
    scanf("%s", name);
    
    // search for matching product and display information
    int found = 0;
    for (int i = 0; i < num_products; i++)
    {
        if (strcmp(products[i].name, name) == 0)
        {
            found = 1;
            printf("\nPRODUCT INFORMATION:\n\n");
            printf("ID: %d\nName: %s\nPrice: $%.2f\nQuantity: %d\n\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            break;
        }
    }
    
    // display error message if product not found
    if (!found)
    {
        printf("\nProduct \"%s\" not found in inventory.\n\n", name);
    }
}

int main()
{
    // allocate memory for initial products array
    products = (struct product*) malloc(sizeof(struct product));
    
    int choice = 0;
    do
    {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1: add_product(); break;
            case 2: edit_product(); break;
            case 3: delete_product(); break;
            case 4: display_products(); break;
            case 5: search_product(); break;
            case 6: printf("\nGoodbye!\n"); break;
            default: printf("\nInvalid choice. Please try again.\n"); break;
        }
    } while (choice != 6);
    
    // free memory allocated for products array
    free(products);
    
    return 0;
}