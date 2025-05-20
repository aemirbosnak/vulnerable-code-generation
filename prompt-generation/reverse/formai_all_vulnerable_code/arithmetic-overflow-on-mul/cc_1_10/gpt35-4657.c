//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    int choice, qty, bill = 0, c = 0;
    char cont = 'y';
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pizza"};
    int prices[5] = {20, 10, 30, 40, 50};
    printf("\t\t_______________________\n\t\t| C Cafe Billing System |\n");
    printf("\t\t|______________________|\n\n");

    do {
        for (int i = 0; i < 5; i++) {
            printf("%d. %-20s Rs.%d/-\n", i + 1, items[i], prices[i]);
        }

        printf("\nEnter the choice of the customer: ");
        scanf("%d", &choice);

        printf("\nEnter the quantity of the item: ");
        scanf("%d", &qty);

        if (choice > 0 && choice < 6) {
            bill += prices[choice - 1] * qty;
            printf("\nItem added to the bill.\n");
            c++;
        }
        else {
            printf("\nInvalid choice.\n");
        }

        printf("\nDo you want to add more items (y/n) ?");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    printf("\n\n\t\t------------------------\n\t\t  Bill Details:\n\t\t------------------------\n");
    if (c == 0) {
        printf("\n\t   No items purchased");
    }
    else {
        for (int i = 0; i < 5; i++) {
            if (prices[i] * qty > 0) {
                printf("\n\t %-20s Rs.%d/-", items[i], prices[i] * qty);
            }
        }
        printf("\n\t\t___________________________\n\t\t   Total Bill: Rs.%d/-\n\t\t----------------------------\n", bill);
    }

    return 0;
}