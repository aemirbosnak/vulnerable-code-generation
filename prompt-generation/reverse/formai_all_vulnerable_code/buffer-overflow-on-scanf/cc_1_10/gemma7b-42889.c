//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("----------------------------------------\n");
    printf("Welcome to the Coffee Haven! Menu:\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Macchiato\n");
    printf("5. Mocha\n");
    printf("----------------------------------------\n");
}

int main() {
    int choice, quantity;
    float total_cost = 0.0f;
    char name[20];

    system("cls");
    display_menu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            total_cost += 2.50f;
            break;
        case 2:
            total_cost += 3.00f;
            break;
        case 3:
            total_cost += 2.00f;
            break;
        case 4:
            total_cost += 2.20f;
            break;
        case 5:
            total_cost += 2.70f;
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    total_cost *= quantity;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("----------------------------------------\n");
    printf("Order Summary for %s:\n", name);
    printf("Item: Coffee (%d) x $%.2f\n", quantity, total_cost);
    printf("Total Cost: $%.2f\n", total_cost);
    printf("Thank you for visiting the Coffee Haven, %s! Have a nice day!\n", name);
    printf("----------------------------------------\n");

    return 0;
}