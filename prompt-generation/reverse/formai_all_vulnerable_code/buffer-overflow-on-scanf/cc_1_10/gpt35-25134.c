//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>

int main() {
    // Welcome messages
    printf("Welcome to the Mind-Bending C Cafe Billing System!\n");
    printf("Please enter your order:\n\n");

    // Menu options
    printf("1. Coffee\t\t$2.50\n");
    printf("2. Espresso\t\t$3.00\n");
    printf("3. Cappuccino\t\t$3.50\n");
    printf("4. Latte\t\t$4.00\n");
    printf("5. Quit\n\n");

    // Ordering loop
    int option;
    float total = 0.0f;

    do {
        printf("Enter the number of your selection (1-5): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Coffee added to order.\n");
                total += 2.5f;
                break;

            case 2:
                printf("Espresso added to order.\n");
                total += 3.0f;
                break;

            case 3:
                printf("Cappuccino added to order.\n");
                total += 3.5f;
                break;

            case 4:
                printf("Latte added to order.\n");
                total += 4.0f;
                break;

            case 5:
                printf("Thank you for your order!\n");
                break;

            default:
                printf("Invalid selection. Please choose a number between 1 and 5.\n");
                break;
        }
    } while (option != 5);

    // Display total and offer discount code
    printf("\nYour total comes to $%.2f.\n", total);
    printf("Enter discount code to get 10%% off your order: ");
    char discount[10];
    scanf("%s", discount);

    if (strcmp(discount, "MIND-BEND") == 0) {
        total *= 0.9f; // Apply 10% discount
        printf("\nDiscount applied. Your new total is $%.2f.\n", total);
    }

    // Goodbye message
    printf("\nThank you for visiting the Mind-Bending C Cafe!\n");

    return 0;
}