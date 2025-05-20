//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the quantity of a product in the warehouse
int calculate_quantity(int* arr, int size)
{
    int quantity = 0;
    for(int i = 0; i < size; i++)
    {
        quantity += *(arr + i);
    }
    return quantity;
}

// Function to add a product to the warehouse
void add_product(int* arr, int size, int new_product)
{
    for(int i = 0; i < size; i++)
    {
        if(*(arr + i) == 0)
        {
            *(arr + i) = new_product;
            printf("Product added successfully!\n");
            return;
        }
    }
    printf("Warehouse is full, cannot add product.\n");
}

// Function to remove a product from the warehouse
void remove_product(int* arr, int size, int product_id)
{
    for(int i = 0; i < size; i++)
    {
        if(*(arr + i) == product_id)
        {
            *(arr + i) = 0;
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Product not found in warehouse.\n");
}

// Function to print the current inventory in the warehouse
void print_inventory(int* arr, int size)
{
    printf("Current inventory in warehouse:\n");
    for(int i = 0; i < size; i++)
    {
        if(*(arr + i) != 0)
        {
            printf("Product ID: %d, Quantity: %d\n", i + 1, *(arr + i));
        }
    }
}

int main()
{
    int warehouse[10] = {0};
    int choice, product_id, quantity;
    
    printf("Welcome to the warehouse management system!\n");
    
    do
    {
        printf("\nPlease select an option:\n");
        printf("1. Calculate total quantity in warehouse\n");
        printf("2. Add a new product to the warehouse\n");
        printf("3. Remove a product from the warehouse\n");
        printf("4. Print current inventory\n");
        printf("5. Exit program\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Total quantity in warehouse: %d\n", calculate_quantity(warehouse, 10));
                break;
            case 2:
                printf("Enter product ID to add: ");
                scanf("%d", &product_id);
                printf("Enter quantity to add: ");
                scanf("%d", &quantity);
                add_product(warehouse, 10, quantity);
                break;
            case 3:
                printf("Enter product ID to remove: ");
                scanf("%d", &product_id);
                remove_product(warehouse, 10, product_id);
                break;
            case 4:
                print_inventory(warehouse, 10);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}