//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void Sherlock_Billing_System()
{
    // Define variables
    int item_num = 0;
    char item_name[20];
    float item_price = 0.0;
    float total_amount = 0.0;
    char customer_name[20];

    // Get customer name
    printf("What is the customer's name? ");
    scanf("%s", customer_name);

    // Loop to get item information
    while (1)
    {
        printf("Enter item name: ");
        scanf("%s", item_name);

        // Check if item name is valid
        if (strcmp(item_name, "q") == 0)
        {
            break;
        }

        printf("Enter item price: ");
        scanf("%f", &item_price);

        // Add item to the bill
        item_num++;
        total_amount += item_price;
    }

    // Calculate total amount
    total_amount += total_amount * 0.1; // 10% service charge

    // Print the bill
    printf("\n*** Sherlock Holmes' C Cafe Billing System ***\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Item No. | Item Name | Price | Quantity | Total Amount |\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < item_num; i++)
    {
        printf("%d | %s | %.2f | 1 | %.2f |\n", i + 1, item_name[i], item_price, total_amount);
    }

    printf("\nTotal Amount: %.2f\n", total_amount);
    printf("Thank you for your visit, %s. Please enjoy your tea.\n", customer_name);
}

int main()
{
    Sherlock_Billing_System();
    return 0;
}