//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu() {
    printf("\n**Menu:**\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothie\n");
    printf("5. Snack\n");
    printf("Please select an item:");
}

int main() {
    char item_selected;
    float total_price = 0;

    display_menu();
    scanf("%c", &item_selected);

    switch (item_selected) {
        case '1':
            total_price += 5.0;
            printf("You selected Coffee. Price: $5.0\n");
            break;
        case '2':
            total_price += 3.5;
            printf("You selected Tea. Price: $3.5\n");
            break;
        case '3':
            total_price += 4.0;
            printf("You selected Juice. Price: $4.0\n");
            break;
        case '4':
            total_price += 6.0;
            printf("You selected Smoothie. Price: $6.0\n");
            break;
        case '5':
            total_price += 2.0;
            printf("You selected Snack. Price: $2.0\n");
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            break;
    }

    printf("Total price: $%.2f\n", total_price);
    printf("Thank you for your order. Have a nice day!\n");

    return 0;
}