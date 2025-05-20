//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct Item {
    char name[50];
    int price;
};

struct Item menu[] = {
    {"Coffee", 5},
    {"Tea", 3},
    {"Coke", 8},
    {"Juice", 6},
    {"Sandwich", 10}
};

int main() {
    int choice;
    struct Item* item;
    int total = 0;

    printf("Welcome to Happy Cafe!\n");

    while (1) {
        printf("\nWhat would you like to order?\n");
        for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
            printf("%s: $%.2f\n", menu[i].name, menu[i].price);
        }
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
            if (strcmp(menu[i].name, "Coffee") == 0) {
                item = menu + i;
                break;
            }
        }

        if (item == NULL) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("You have ordered %s. Total cost: $%.2f\n", item->name, item->price);
        total += item->price;

        printf("Do you want to order more items? (y/n): ");
        char order_more = getchar();

        if (order_more == 'n' || order_more == '\n') {
            printf("Total cost: $%.2f\n", total);
            printf("Thank you for visiting Happy Cafe!\n");
            break;
        }
    }

    return 0;
}