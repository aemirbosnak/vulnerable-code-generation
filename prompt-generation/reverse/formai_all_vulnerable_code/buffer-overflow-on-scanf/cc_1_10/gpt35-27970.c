//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Menu {
    char name[50];
    double price;
};

struct Order {
    char name[50];
    int quantity;
};

int main() {
    struct Menu menu[5];
    menu[0] = (struct Menu){"Coffee", 2.50};
    menu[1] = (struct Menu){"Tea", 2.00};
    menu[2] = (struct Menu){"Sandwich", 3.50};
    menu[3] = (struct Menu){"Bagel", 2.50};
    menu[4] = (struct Menu){"Croissant", 2.50};

    double total = 0.0;
    struct Order orders[100];
    int orderCount = 0;
    int choice, quantity;

    printf("Welcome to the C Cafe!\n");
    printf("------------------------\n\n");

    while (1) {
        printf("Menu:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
        }

        printf("6. Checkout and Print Bill\n");
        printf("\nEnter choice (1-6): ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("\n\n------------------------\n");
            printf("C Cafe Bill\n");
            printf("------------------------\n");

            for (int i = 0; i < orderCount; i++) {
                int j = 0;
                while (j < 50 && orders[i].name[j] != '\0') {
                    printf("%c", orders[i].name[j]);
                    j++;
                }
                printf(": %d * $%.2f = $%.2f\n", orders[i].quantity, menu[i].price, orders[i].quantity * menu[i].price);
                total += orders[i].quantity * menu[i].price;
            }

            printf("------------------------\n");
            printf("Total: $%.2f\n", total);
            printf("------------------------\n\n");

            return 0;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        strcpy(orders[orderCount].name, menu[choice-1].name);
        orders[orderCount].quantity = quantity;
        orderCount++;
    }

    return 0;
}