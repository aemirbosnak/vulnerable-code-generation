//FormAI DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store product details
struct product
{
    int id;
    char name[20];
    int quantity;
    float price;
};

// Function to display the product details
void displayProduct(struct product p)
{
    printf("%-5d %-20s %-10d $ %-10.2f\n", p.id, p.name, p.quantity, p.price);
}

// Function to add a new product
void addProduct(struct product *p, int *n)
{
    // Get the details of the new product
    printf("Enter the product id: ");
    scanf("%d", &p[*n].id);
    printf("Enter the product name: ");
    scanf("%s", p[*n].name);
    printf("Enter the product quantity: ");
    scanf("%d", &p[*n].quantity);
    printf("Enter the product price: ");
    scanf("%f", &p[*n].price);

    // Increment the number of products
    (*n)++;
}

// Function to delete a product
void deleteProduct(struct product *p, int *n, int id)
{
    // Find the product with the given id
    int i, index = -1;
    for (i = 0; i < *n; i++)
    {
        if (p[i].id == id)
        {
            index = i;
            break;
        }
    }

    // If the product is found, delete it
    if (index >= 0)
    {
        for (i = index; i < (*n)-1; i++)
        {
            // Shift the products after the deleted product one position to the left
            p[i] = p[i+1];
        }

        // Decrement the number of products
        (*n)--;
    }
    else
    {
        printf("Product with id %d not found!\n", id);
    }
}

int main()
{
    // Declare an array of products
    struct product inventory[100];

    // Initialize the number of products to 0
    int n = 0;

    // Display the menu
    while (1)
    {
        printf("\n1. Display all products\n");
        printf("2. Add a new product\n");
        printf("3. Delete a product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the corresponding action
        switch (choice)
        {
            case 1:
                // Display all products
                printf("\n%-5s %-20s %-10s %s\n", "ID", "Name", "Quantity", "Price");
                int i;
                for (i = 0; i < n; i++)
                {
                    displayProduct(inventory[i]);
                }
                break;
            case 2:
                // Add a new product
                addProduct(inventory, &n);
                break;
            case 3:
                // Delete a product
                printf("Enter the id of the product to be deleted: ");
                int id;
                scanf("%d", &id);
                deleteProduct(inventory, &n, id);
                break;
            case 4:
                // Exit the program
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}