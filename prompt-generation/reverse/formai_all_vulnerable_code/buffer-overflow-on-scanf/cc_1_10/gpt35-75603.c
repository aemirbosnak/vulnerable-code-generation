//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int order_id, menu_choice, quantity;
    float total_cost = 0;
    char customer_name[50];

    printf("Welcome to C Cafe!\n");

    // get customer name and order ID
    printf("Please enter your name: ");
    scanf("%s", &customer_name);
    printf("Please enter your order ID: ");
    scanf("%d", &order_id);

    // display menu and get order
    printf("\nMenu:\n");
    printf("1. Coffee - $1.50\n");
    printf("2. Tea - $1.25\n");
    printf("3. Sandwich - $2.75\n");
    printf("4. Cake - $3.00\n");
    printf("5. Exit ordering process\n");

    do {
        printf("\nPlease enter menu choice (1-5): ");
        scanf("%d", &menu_choice);

        if (menu_choice == 5) {
            break;
        }

        printf("Please enter quantity: ");
        scanf("%d", &quantity);

        switch (menu_choice) {
            case 1:
                total_cost += quantity * 1.5;
                break;
            case 2:
                total_cost += quantity * 1.25;
                break;
            case 3:
                total_cost += quantity * 2.75;
                break;
            case 4:
                total_cost += quantity * 3.0;
                break;
            default:
                printf("Invalid menu choice!\n");
        }
    } while (menu_choice != 5);

    // display total cost and exit message
    printf("\nOrder Summary:\n");
    printf("Customer name: %s\n", customer_name);
    printf("Order ID: %d\n", order_id);
    printf("Total cost: $%.2f\n", total_cost);
    printf("Thank you for ordering at C Cafe!\n");

    return 0;
}