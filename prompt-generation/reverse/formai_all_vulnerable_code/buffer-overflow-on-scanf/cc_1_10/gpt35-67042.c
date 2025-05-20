//FormAI DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

struct product
{
    char name[50];
    int id;
    float price;
    int quantity;
};

struct inventory
{
    struct product products[MAX_PRODUCTS];
    int count;
};

void add_product(struct inventory *inv, char *name, int id, float price, int quantity)
{
    if(inv->count == MAX_PRODUCTS)
    {
        printf("Error: Maximum number of products reached!\n");
        return;
    }

    struct product p;
    strcpy(p.name, name);
    p.id = id;
    p.price = price;
    p.quantity = quantity;

    inv->products[inv->count++] = p;

    printf("Product added successfully!\n");
}

void display_inventory(struct inventory inv)
{
    if(inv.count == 0)
    {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Product Name\tID\tPrice\tQuantity\n");
    for(int i=0; i<inv.count; i++)
    {
        struct product p = inv.products[i];
        printf("%s\t\t%d\t%.2f\t%d\n", p.name, p.id, p.price, p.quantity);
    }
}

void update_product_quantity(struct inventory *inv, int id, int quantity)
{
    for(int i=0; i<inv->count; i++)
    {
        if(inv->products[i].id == id)
        {
            inv->products[i].quantity += quantity;
            printf("Product quantity updated successfully!\n");
            return;
        }
    }

    printf("Error: Product with ID %d not found!\n", id);
}

int main()
{
    struct inventory inv;
    inv.count = 0;

    printf("Welcome to the Product Inventory System!\n");

    while(1)
    {
        printf("\nPlease select an option:\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product Quantity\n");
        printf("4. Exit\n");

        int choice, id, quantity;
        float price;
        char name[50];

        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("Enter product name: ");
                    scanf("%s", name);
                    printf("Enter product ID: ");
                    scanf("%d", &id);
                    printf("Enter product price: ");
                    scanf("%f", &price);
                    printf("Enter product quantity: ");
                    scanf("%d", &quantity);

                    add_product(&inv, name, id, price, quantity);
                    break;

            case 2: display_inventory(inv);
                    break;

            case 3: printf("Enter product ID: ");
                    scanf("%d", &id);
                    printf("Enter quantity to add or remove (negative for removal): ");
                    scanf("%d", &quantity);

                    update_product_quantity(&inv, id, quantity);
                    break;

            case 4: printf("Thank you for using the Product Inventory System!\n");
                    exit(0);

            default: printf("Invalid choice, please try again!\n");
        }
    }

    return 0;
}