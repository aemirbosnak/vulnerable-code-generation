//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>

struct Item {
    char name[20];
    double price;
    int quantity;
};

struct Item items[] = {
    {"Coffee", 2.50, 1},
    {"Tea", 1.00, 1},
    {"Sandwich", 3.50, 1},
    {"Cake", 5.00, 1}
};

int main() {
    int choice;
    double total = 0.0;

    printf("Welcome to the cafe!\n");
    printf("What would you like to order?\n");

    for (int i = 0; i < 4; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }

    printf("Enter your choice (1-%d): ", 4);
    scanf("%d", &choice);

    while (choice > 0 && choice <= 4) {
        if (choice == 1) {
            printf("You ordered %d Coffee(s).\n", items[1].quantity);
            total += items[1].price * items[1].quantity;
        } else if (choice == 2) {
            printf("You ordered %d Tea(s).\n", items[2].quantity);
            total += items[2].price * items[2].quantity;
        } else if (choice == 3) {
            printf("You ordered %d Sandwich(s).\n", items[3].quantity);
            total += items[3].price * items[3].quantity;
        } else {
            printf("You ordered %d Cake(s).\n", items[4].quantity);
            total += items[4].price * items[4].quantity;
        }

        printf("Do you want to order more? (Y/N): ");
        scanf("%s", &choice);
    }

    printf("Your total bill is $%.2f.\n", total);
    return 0;
}