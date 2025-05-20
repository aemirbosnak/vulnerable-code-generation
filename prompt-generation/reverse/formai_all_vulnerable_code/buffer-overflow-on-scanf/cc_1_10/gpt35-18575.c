//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct Warehouse
{
    int item_code[MAX];
    char item_name[MAX][20];
    int item_count[MAX];
    float item_price[MAX];
    int item_quantity[MAX];
};

struct Warehouse W;

// Function to add items to the warehouse
void add_items(int size)
{
    int i;
    for(i=0; i < size; i++)
    {
        printf("\nEnter Item %d Details: \n", i+1);
        printf("Item Code: ");
        scanf("%d", &W.item_code[i]);
        printf("Item Name: ");
        scanf("%s", W.item_name[i]);
        printf("Item Count: ");
        scanf("%d", &W.item_count[i]);
        printf("Item Price: ");
        scanf("%f", &W.item_price[i]);
        printf("Item Quantity: ");
        scanf("%d", &W.item_quantity[i]);
    }
}


// Function to display all items in the warehouse
void display_all(int size)
{
    int i;
    printf("\n\nItems Available in Warehouse: \n\n");
    printf("------------------------------------\n");
    printf("Item Code\tItem Name\tItem Count\tItem Price\tItem Quantity\n");
    printf("------------------------------------\n");
    for(i=0; i<size; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%d\n", W.item_code[i], W.item_name[i], W.item_count[i], W.item_price[i], W.item_quantity[i]);
    }
    printf("------------------------------------\n");
}

// Function to search for a specific item in the warehouse
void search_item(int size, int code)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(W.item_code[i] == code)
        {
            printf("\nItem Found!\n\n");
            printf("---------------------------\n");
            printf("Item Code: %d\n", W.item_code[i]);
            printf("Item Name: %s\n", W.item_name[i]);
            printf("Item Count: %d\n", W.item_count[i]);
            printf("Item Price: %.2f\n", W.item_price[i]);
            printf("Item Quantity: %d\n", W.item_quantity[i]);
            printf("---------------------------\n");
            break;
        }
    }
    if(i == size)
    {
        printf("\nSorry! Item not found in the warehouse.\n");
    }
}

// Function to update item information in the warehouse
void update_item(int size, int code)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(W.item_code[i] == code)
        {
            printf("\nEnter Item Details: \n");
            printf("Item Name: ");
            scanf("%s", W.item_name[i]);
            printf("Item Price: ");
            scanf("%f", &W.item_price[i]);
            printf("Item Quantity: ");
            scanf("%d", &W.item_quantity[i]);
            printf("\nItem Updated Successfully!\n\n");
            break;
        }
    }
    if(i == size)
    {
        printf("\nSorry! Item not found in the warehouse.\n");
    }
}

// Function to delete an item from the warehouse
void delete_item(int size, int code)
{
    int i, j, flag=0;
    for(i=0; i<size; i++)
    {
        if(W.item_code[i] == code)
        {
            flag = 1;
            for(j=i; j<size-1; j++)
            {
                W.item_code[j] = W.item_code[j+1];
                strcpy(W.item_name[j], W.item_name[j+1]);
                W.item_count[j] = W.item_count[j+1];
                W.item_price[j] = W.item_price[j+1];
                W.item_quantity[j] = W.item_quantity[j+1];
            }
            break;
        }
    }
    if(flag)
    {
        printf("\nItem Deleted Successfully!\n\n");
    }
    else
    {
        printf("\nSorry! Item not found in the warehouse.\n");
    }
}


// Main Function
int main()
{
    int choice, code, size = 0;
    printf("Welcome to the Warehouse Management System!\n\n");

    do
    {
        printf("\n\n1. Add Item(s) to the Warehouse");
        printf("\n2. Display All Items in the Warehouse");
        printf("\n3. Search for an Item in the Warehouse");
        printf("\n4. Update an Item in the Warehouse");
        printf("\n5. Delete an Item from the Warehouse");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nHow many items you want to add: ");
                scanf("%d", &size);
                add_items(size);
                break;
            case 2:
                display_all(size);
                break;
            case 3:
                printf("\nEnter Item Code to Search: ");
                scanf("%d", &code);
                search_item(size, code);
                break;
            case 4:
                printf("\nEnter Item Code to Update: ");
                scanf("%d", &code);
                update_item(size, code);
                break;
            case 5:
                printf("\nEnter Item Code to Delete: ");
                scanf("%d", &code);
                delete_item(size, code);
                size--;
                break;
            case 6:
                printf("\nThank you for using the Warehouse Management System!");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    }while(1);
    return 0;
}