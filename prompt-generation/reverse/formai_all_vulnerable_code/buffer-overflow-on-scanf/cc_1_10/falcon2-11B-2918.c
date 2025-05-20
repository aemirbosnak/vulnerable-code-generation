//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Menu {
    char name[20];
    int price;
};

int main() {
    struct Menu menu[4] = {
        {"Coke", 2.99},
        {"Pizza", 9.99},
        {"Burger", 4.99},
        {"Coffee", 2.50}
    };

    int n = sizeof(menu)/sizeof(menu[0]);

    char customer[20];
    int cost = 0;

    printf("Welcome to the Cafe!\n");
    printf("Please choose from the menu:\n");
    for (int i = 0; i < n; i++) {
        printf("%s : $%.2f\n", menu[i].name, menu[i].price);
    }

    printf("\n");

    printf("Enter customer's name: ");
    scanf("%s", customer);

    printf("\n");

    printf("Enter the number of items: ");
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice < n) {
            cost += menu[choice].price;
        } else {
            printf("Invalid choice!\n");
        }
    }

    printf("Your bill is: $%.2f\n", cost);

    printf("\n");

    printf("Thank you for visiting the Cafe!\n");

    return 0;
}