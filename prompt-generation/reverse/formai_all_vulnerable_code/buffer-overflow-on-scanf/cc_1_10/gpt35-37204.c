//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int quantity;
    float price;
    char name[50];
} Product;

typedef struct {
    int id;
    int quantity;
} Order;

void display_menu()
{
    printf("-----------------------\n");
    printf("1. Add product\n");
    printf("2. Display all products\n");
    printf("3. Place order\n");
    printf("4. Display all orders\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

int add_product(Product* products, int product_count)
{
    Product new_product;

    printf("Enter the product name: ");
    scanf("%s", new_product.name);

    printf("Enter the product price: ");
    scanf("%f", &new_product.price);

    printf("Enter the product quantity: ");
    scanf("%d", &new_product.quantity);

    new_product.id = product_count + 1;

    products[product_count] = new_product;

    printf("Product added successfully!\n");

    return ++product_count;
}

void display_products(Product* products, int product_count)
{
    printf("ID |\tProduct Name |\tPrice |\tQuantity\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < product_count; i++)
    {
        printf("%d |\t%s\t | $%.2f |\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int place_order(Product* products, int product_count, Order* orders, int order_count)
{
    Order new_order;

    printf("Enter the product ID: ");
    scanf("%d", &new_order.id);

    printf("Enter the product quantity: ");
    scanf("%d", &new_order.quantity);

    for (int i = 0; i < product_count; i++)
    {
        if (products[i].id == new_order.id)
        {
            if (products[i].quantity >= new_order.quantity)
            {
                products[i].quantity -= new_order.quantity;
                new_order.quantity = new_order.quantity * products[i].price;
                orders[order_count] = new_order;
                printf("Order placed successfully!\n");
                return ++order_count;
            }
            else
            {
                printf("Sorry, we do not have enough products in stock!\n");
                return order_count;
            }
        }
    }

    printf("Invalid product ID!\n");
    return order_count;
}

void display_orders(Product* products, Order* orders, int product_count, int order_count)
{
    printf("Product |\tPrice |\tQuantity\n");
    printf("-----------------------------\n");

    for (int i = 0; i < order_count; i++)
    {
        for (int j = 0; j < product_count; j++)
        {
            if (orders[i].id == products[j].id)
            {
                printf("%s\t | $%.2f |\t%d\n", products[j].name, products[j].price, orders[i].quantity);
            }
        }
    }
}

int main(void)
{
    Product products[20];
    Order orders[20];
    int product_count = 0;
    int order_count = 0;
    int choice;

    do {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                product_count = add_product(products, product_count);
                break;

            case 2:
                display_products(products, product_count);
                break;

            case 3:
                order_count = place_order(products, product_count, orders, order_count);
                break;

            case 4:
                display_orders(products, orders, product_count, order_count);
                break;

            case 5:
                printf("Exiting the program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 5);

    return 0;
}