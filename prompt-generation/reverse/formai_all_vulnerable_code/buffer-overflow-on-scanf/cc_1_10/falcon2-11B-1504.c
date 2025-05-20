//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char item1[100], item2[100], item3[100];
    double price1, price2, price3;
    int qty1, qty2, qty3;

    printf("Welcome to the Happy Cafe!\n\n");
    printf("Please select your item(s):\n");
    printf("1. Coffee\n");
    printf("2. Sandwich\n");
    printf("3. Soda\n");
    printf("4. Exit\n");

    printf("Enter the name of your first item: ");
    scanf("%s", item1);
    printf("Enter the price of your first item: ");
    scanf("%lf", &price1);
    printf("Enter the quantity of your first item: ");
    scanf("%d", &qty1);

    printf("\n");

    printf("Enter the name of your second item: ");
    scanf("%s", item2);
    printf("Enter the price of your second item: ");
    scanf("%lf", &price2);
    printf("Enter the quantity of your second item: ");
    scanf("%d", &qty2);

    printf("\n");

    printf("Enter the name of your third item: ");
    scanf("%s", item3);
    printf("Enter the price of your third item: ");
    scanf("%lf", &price3);
    printf("Enter the quantity of your third item: ");
    scanf("%d", &qty3);

    printf("\n");

    if (strcmp(item1, "Coffee") == 0 && strcmp(item2, "Sandwich") == 0 && strcmp(item3, "Soda") == 0) {
        printf("Congratulations! You've just purchased the Happy Combo!\n\n");
    }
    else {
        printf("Thank you for your purchase!\n\n");
        printf("Item 1: %s - $%.2lf x %d = $%.2lf\n", item1, price1, qty1, price1 * qty1);
        printf("Item 2: %s - $%.2lf x %d = $%.2lf\n", item2, price2, qty2, price2 * qty2);
        printf("Item 3: %s - $%.2lf x %d = $%.2lf\n", item3, price3, qty3, price3 * qty3);
        printf("Total: $%.2lf\n", (price1 * qty1) + (price2 * qty2) + (price3 * qty3));
    }

    printf("Thank you for visiting the Happy Cafe! We hope to see you again soon!\n");

    return 0;
}