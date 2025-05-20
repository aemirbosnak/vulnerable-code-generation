//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    printf("Welcome to the Coffee Cafe!\n");
    printf("--------------------\n");
    printf("Please select an item: (1) Coffee, (2) Tea, (3) Juice\n");
    int item_no;
    scanf("%d", &item_no);

    switch (item_no) {
        case 1:
            printf("You selected Coffee. Please select your preferred brew: (a) Espresso, (b) Latte, (c) Cappuccino\n");
            char brew_type;
            scanf(" %c", &brew_type);

            switch (brew_type) {
                case 'a':
                    printf("Your order: Espresso\n");
                    break;
                case 'b':
                    printf("Your order: Latte\n");
                    break;
                case 'c':
                    printf("Your order: Cappuccino\n");
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        case 2:
            printf("You selected Tea. Please select your preferred flavor: (a) Earl Grey, (b) Green Tea, (c) Peppermint\n");
            char flavor_type;
            scanf(" %c", &flavor_type);

            switch (flavor_type) {
                case 'a':
                    printf("Your order: Earl Grey\n");
                    break;
                case 'b':
                    printf("Your order: Green Tea\n");
                    break;
                case 'c':
                    printf("Your order: Peppermint\n");
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        case 3:
            printf("You selected Juice. Please select your preferred flavor: (a) Orange, (b) Apple, (c) Pomegranate\n");
            char juice_flavor;
            scanf(" %c", &juice_flavor);

            switch (juice_flavor) {
                case 'a':
                    printf("Your order: Orange Juice\n");
                    break;
                case 'b':
                    printf("Your order: Apple Juice\n");
                    break;
                case 'c':
                    printf("Your order: Pomegranate Juice\n");
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        default:
            printf("Invalid item number. Please try again.\n");
    }

    printf("Thank you for your order. Enjoy your coffee! :D\n");
    system("pause");
    return 0;
}