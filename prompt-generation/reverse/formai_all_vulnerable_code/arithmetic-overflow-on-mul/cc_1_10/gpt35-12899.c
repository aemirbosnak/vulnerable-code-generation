//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch, quantity, price, total = 0, grand_total = 0;
    char name[20];

    printf("\n\n Welcome to Happy Café!\n");
    printf("---------------------------------\n\n");
    printf("Menu:\n\n");
    printf("1. Coffee           Rs. 50\n");
    printf("2. Tea              Rs. 40\n");
    printf("3. Sandwich         Rs. 100\n");
    printf("4. Cake             Rs. 150\n");
    printf("5. Burger           Rs. 120\n\n");

    do {
        printf("Enter your choice [1-5]: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                price = 50;
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                total = price * quantity;
                printf("\n Added Coffee x %d to your bill.\n\n", quantity);
                break;

            case 2:
                price = 40;
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                total = price * quantity;
                printf("\n Added Tea x %d to your bill.\n\n", quantity);
                break;

            case 3:
                price = 100;
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                total = price * quantity;
                printf("\n Added Sandwich x %d to your bill.\n\n", quantity);
                break;

            case 4:
                price = 150;
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                total = price * quantity;
                printf("\n Added Cake x %d to your bill.\n\n", quantity);
                break;

            case 5:
                price = 120;
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                total = price * quantity;
                printf("\n Added Burger x %d to your bill.\n\n", quantity);
                break;

            default:
                printf("\n Invalid choice! Please try again.\n\n");
                break;
        }

        printf("Enter your name: ");
        scanf("%s", &name);
        printf("Price for %d item(s) is Rs. %d\n", quantity, total);
        grand_total += total;

        printf("\nDo you want to order another item? [y/n]: ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            printf("\n\n Thank you for your order!\n");
            printf("---------------------------------\n");
            printf("Customer name: %s\n", name);
            printf("Total amount: Rs. %d\n", grand_total);
            printf("Have a Happy day! :)\n");
            printf("---------------------------------\n");
            break;
        }

    } while (ch != 0);

    return 0;
}