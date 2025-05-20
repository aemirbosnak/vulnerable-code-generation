//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void print_menu()
{
    printf("*** Coffee Menu ***\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");
    printf("5. Macchiato\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    float price;

    print_menu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            price = 2.50;
            break;
        case 2:
            price = 3.00;
            break;
        case 3:
            price = 3.50;
            break;
        case 4:
            price = 4.00;
            break;
        case 5:
            price = 4.50;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Your order: %s\n", "Coffee");
    printf("Price: $%.2f\n", price);
    printf("Total: $%.2f\n", price);

    return 0;
}