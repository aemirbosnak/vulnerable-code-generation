//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct food_item {
    char name[20];
    int price;
};

struct order_item {
    char name[20];
    int quantity;
    int price;
};

int main() {
    struct food_item menu[10]; // Max 10 items in menu
    struct order_item order[10]; // Max 10 orders
    int menu_count = 0;
    int order_count = 0;
    int total = 0;
    char choice[10];

    while (1) {
        printf("\n********** C Cafe Billing System **********\n");
        printf("1. Add item to menu\n");
        printf("2. View menu\n");
        printf("3. Place order\n");
        printf("4. View order\n");
        printf("5. Generate bill\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%s", choice);

        switch (choice[0]) {
            case '1':
                printf("Enter item name: ");
                scanf("%s", menu[menu_count].name);
                printf("Enter item price: ");
                scanf("%d", &menu[menu_count].price);
                menu_count++;
                printf("\nItem added to menu!\n");
                break;
            case '2':
                printf("\nMenu\n");
                for (int i = 0; i < menu_count; i++) {
                    printf("%s - $%d\n", menu[i].name, menu[i].price);
                }
                break;
            case '3':
                printf("Enter item name: ");
                scanf("%s", order[order_count].name);
                printf("Enter quantity: ");
                scanf("%d", &order[order_count].quantity);
                for (int i = 0; i < menu_count; i++) {
                    if (strcmp(menu[i].name, order[order_count].name) == 0) {
                        order[order_count].price = menu[i].price * order[order_count].quantity;
                        total += order[order_count].price;
                        order_count++;
                        printf("\nOrder placed!\n");
                        break;
                    }
                    if (i == menu_count - 1) {
                        printf("\nItem not found in menu!\n");
                    }
                }
                break;
            case '4':
                printf("\nOrder\n");
                for (int i = 0; i < order_count; i++) {
                    printf("%s - $%d x %d = $%d\n", order[i].name, menu[i].price, order[i].quantity, order[i].price);
                }
                break;
            case '5':
                printf("\nTotal bill: $%d\n", total);
                break;
            case '6':
                printf("\nThank you for choosing C Cafe!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}