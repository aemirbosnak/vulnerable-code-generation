//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* struct to hold warehouse item details */

struct item_details
{
    char name[50];
    int quantity;
    float price;
};

/* struct to hold the warehouse details */

struct warehouse
{
    int warehouse_id;
    char location[50];
    struct item_details item[50];
    int item_count;
    float revenue;
};

/* function to add item to warehouse */

void add_item(struct warehouse *w)
{
    printf("\nEnter the name of the item: ");
    scanf("%s", w->item[w->item_count].name);

    printf("\nEnter the quantity of the item: ");
    scanf("%d", &w->item[w->item_count].quantity);

    printf("\nEnter the price of the item: ");
    scanf("%f", &w->item[w->item_count].price);

    w->item_count++;

    printf("\nItem added successfully!\n");
}

/* function to remove item from warehouse */

void remove_item(struct warehouse *w)
{
    int choice, i;

    printf("\nEnter the number of the item you want to remove: \n");

    for(i = 0; i < w->item_count; i++)
    {
        printf("\n%d: %s\n", i+1, w->item[i].name);
    }

    scanf("%d", &choice);

    for(i = choice; i < w->item_count; i++)
    {
        w->item[i-1] = w->item[i];
    }

    w->item_count--;

    printf("\nItem removed successfully!\n");
}

/* function to display warehouse details */

void display_details(struct warehouse w)
{
    int i;

    printf("\nWarehouse ID: %d\n", w.warehouse_id);
    printf("Location: %s\n", w.location);
    printf("Total items: %d\n", w.item_count);

    printf("\nItem details:\n");

    for(i = 0; i < w.item_count; i++)
    {
        printf("%d. %s - Quantity: %d, Price: %.2f\n", i+1, w.item[i].name, w.item[i].quantity, w.item[i].price);
    }
}

/* function to calculate warehouse revenue */

void calculate_revenue(struct warehouse *w)
{
    int i;

    w->revenue = 0;

    for(i = 0; i < w->item_count; i++)
    {
        w->revenue += (w->item[i].quantity * w->item[i].price);
    }

    printf("\nTotal revenue: %.2f\n", w->revenue);
}

/* main function */

int main()
{
    int choice;
    struct warehouse w;

    printf("\nEnter warehouse ID: ");
    scanf("%d", &w.warehouse_id);

    printf("\nEnter warehouse location: ");
    scanf("%s", w.location);

    w.item_count = 0;

    while(1)
    {
        printf("\n1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display details\n");
        printf("4. Calculate revenue\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_item(&w);
                break;
            case 2:
                remove_item(&w);
                break;
            case 3:
                display_details(w);
                break;
            case 4:
                calculate_revenue(&w);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}