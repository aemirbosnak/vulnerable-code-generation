//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu()
{
    printf("----------------------------------------\n");
    printf("  Coffee Menu\n");
    printf("----------------------------------------\n");
    printf("  1. Espresso\t\t\tPrice: $2.50\n");
    printf("  2. Cappuccino\t\tPrice: $3.00\n");
    printf("  3. Latte\t\t\tPrice: $3.50\n");
    printf("  4. Mocha\t\t\tPrice: $4.00\n");
    printf("  5. Macchiato\t\tPrice: $4.50\n");
    printf("  6. Americano\t\tPrice: $5.00\n");
    printf("  7. Cold Brew\t\tPrice: $5.50\n");
    printf("  8. Iced Latte\t\tPrice: $6.00\n");
    printf("  9. Mocha Frappuccino\t\tPrice: $6.50\n");
    printf("  10. Caramel Macchiato\t\tPrice: $7.00\n");
    printf("----------------------------------------\n");
}

int main()
{
    int choice;
    float total = 0.0f;

    displayMenu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            total += 2.50f;
            printf("You selected Espresso.\n");
            break;
        case 2:
            total += 3.00f;
            printf("You selected Cappuccino.\n");
            break;
        case 3:
            total += 3.50f;
            printf("You selected Latte.\n");
            break;
        case 4:
            total += 4.00f;
            printf("You selected Mocha.\n");
            break;
        case 5:
            total += 4.50f;
            printf("You selected Macchiato.\n");
            break;
        case 6:
            total += 5.00f;
            printf("You selected Americano.\n");
            break;
        case 7:
            total += 5.50f;
            printf("You selected Cold Brew.\n");
            break;
        case 8:
            total += 6.00f;
            printf("You selected Iced Latte.\n");
            break;
        case 9:
            total += 6.50f;
            printf("You selected Mocha Frappuccino.\n");
            break;
        case 10:
            total += 7.00f;
            printf("You selected Caramel Macchiato.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    printf("Total: $%.2f\n", total);

    return 0;
}