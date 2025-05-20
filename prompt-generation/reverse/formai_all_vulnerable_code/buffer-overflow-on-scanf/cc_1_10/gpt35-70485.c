//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float price = 0.0f;
    float total = 0.0f;
    int choice = 0;
    int item_count = 0;
    char response;

    const char* menu[] = {
        "1. Coffee",
        "2. Caffe Latte",
        "3. Cappuccino",
        "4. Iced Coffee",
        "5. Espresso",
        "6. Hot Chocolate",
        "7. Exit",
    };

    const float prices[] = {
        1.50f,
        2.50f,
        3.00f,
        2.00f,
        3.00f,
        2.50f,
        0.0f,
    };

    printf("Welcome to the C Cafe!\n");
    printf("What can I get for you today?\n\n");

    do {
        for (int i = 0; i < 7; i++) {
            printf("%s ($%.2f)\n", menu[i], prices[i]);
        }
        printf("\n");

        printf("Enter your selection: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            printf("Invalid selection. Please try again.\n\n");
            continue;
        }

        if (choice == 7) {
            printf("Thanks for stopping by! Your total is $%.2f.\n", total);
            break;
        }

        printf("How many would you like? ");
        scanf("%d", &item_count);

        if (item_count < 1) {
            printf("Invalid quantity. Please try again.\n\n");
            continue;
        }

        price = item_count * prices[choice - 1];
        total += price;

        printf("Your total so far is $%.2f.\n\n", total);

        printf("Would you like to order more? (y/n) ");
        scanf(" %c", &response);

        if (response == 'n') {
            printf("Thanks for stopping by! Your total is $%.2f.\n", total);
            break;
        }

        printf("\n");

    } while (choice != 7);

    return 0;
}