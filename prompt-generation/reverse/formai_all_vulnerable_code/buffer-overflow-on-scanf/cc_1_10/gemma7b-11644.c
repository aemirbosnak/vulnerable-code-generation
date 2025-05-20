//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

void print_menu()
{
    printf("Welcome to the C Cafe!\n");
    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Water\n");
    printf("5. Soda\n");
}

int main()
{
    char item_selected;
    float price;

    print_menu();

    scanf("%c", &item_selected);

    switch (item_selected)
    {
        case '1':
            price = 2.50;
            break;
        case '2':
            price = 3.00;
            break;
        case '3':
            price = 3.50;
            break;
        case '4':
            price = 2.00;
            break;
        case '5':
            price = 2.25;
            break;
        default:
            printf("Invalid item selection.\n");
            return 1;
    }

    printf("Your item: %c\n", item_selected);
    printf("Price: %.2f\n", price);

    return 0;
}