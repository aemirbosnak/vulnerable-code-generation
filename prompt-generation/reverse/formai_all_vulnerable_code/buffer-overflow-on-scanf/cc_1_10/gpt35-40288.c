//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu {
    char name[50];
    int price;
};

int main() {
    int choice, quantity, amount = 0, total = 0, i = 0, flag = 0;
    char ch, ans;
    struct menu menu_list[] = {{"Coffee", 40}, {"Tea", 30}, {"Pancakes", 60}, {"Omelette", 50}, {"Sandwich", 40}};
    int size = sizeof(menu_list) / sizeof(menu_list[0]);

    printf("\n\nWelcome to C Cafe Billing System!\n\n");

    do {
        printf("Please select an item from our menu:\n");
        printf("--------------------------------------------------------\n");
        for (i = 0; i < size; i++) {
            printf("%d. %s - Rs.%d\n", (i + 1), menu_list[i].name, menu_list[i].price);
        }
        printf("--------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        amount = quantity * menu_list[choice - 1].price;

        printf("--------------------------------------------------------\n");
        printf("You have ordered %d %s, for Rs.%d.\n\n", quantity, menu_list[choice - 1].name, amount);
        printf("Do you want to add this item to your cart? (y/n): ");
        scanf(" %c", &ans);

        if (ans == 'y' || ans == 'Y') {
            total += amount;
            printf("\nAdded to your cart successfully.\n\n");
        } else {
            printf("\n%s has been removed from your order.\n\n", menu_list[choice - 1].name);
        }

        printf("Do you want to continue shopping? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    if (total == 0) {
        printf("\nYou haven't purchased anything. Thank you for stopping by.\n");
        exit(0);
    }

    printf("\n\nTotal Bill: Rs. %d\n\n", total);

    printf("Do you have our loyalty card? (y/n): ");
    scanf(" %c", &ans);

    if (ans == 'y' || ans == 'Y') {
        total -= (total * 0.1);
        printf("\nCongratulations!, the loyalty card gives you a discount of 10%%.\n");
        printf("Your revised total is: Rs.%d.\n", total);
    }

    printf("\nThank you for shopping at C Cafe! Have a nice day.\n\n");

    return 0;
}