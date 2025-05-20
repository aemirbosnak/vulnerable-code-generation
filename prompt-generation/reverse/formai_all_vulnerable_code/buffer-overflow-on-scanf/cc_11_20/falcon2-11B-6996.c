//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    char customer_name[50];
    int items_purchased = 0;
    double total_cost = 0.0;
    char item[50];

    // Customer menu
    printf("Welcome to our Cafe! What would you like to order?\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Sandwich\n");
    printf("4. Burger\n");
    printf("5. Soda\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &items_purchased);

    // Order menu
    switch (items_purchased) {
        case 1:
            printf("You have ordered Coffee\n");
            break;
        case 2:
            printf("You have ordered Tea\n");
            break;
        case 3:
            printf("You have ordered Sandwich\n");
            break;
        case 4:
            printf("You have ordered Burger\n");
            break;
        case 5:
            printf("You have ordered Soda\n");
            break;
        default:
            printf("Invalid choice, please try again\n");
            break;
    }

    // Bill calculation
    if (items_purchased == 1) {
        total_cost = 10.0;
    } else if (items_purchased == 2) {
        total_cost = 8.0;
    } else if (items_purchased == 3) {
        total_cost = 12.0;
    } else if (items_purchased == 4) {
        total_cost = 15.0;
    } else if (items_purchased == 5) {
        total_cost = 5.0;
    }

    // Print bill
    printf("\nBill for %s\n", customer_name);
    printf("Total cost: %.2f\n", total_cost);
    printf("Items purchased:\n");
    if (items_purchased > 0) {
        printf("Coffee\n");
        printf("Tea\n");
        printf("Sandwich\n");
        printf("Burger\n");
        printf("Soda\n");
    } else {
        printf("No items purchased\n");
    }

    return 0;
}