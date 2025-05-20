//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to display the menu
void showMenu() {
    printf("\n");
    printf("Welcome to the C Cafe\n");
    printf("====================\n");
    printf("1. Coffee...........$2.00\n");
    printf("2. Tea..............$1.50\n");
    printf("3. Cake.............$3.00\n");
    printf("4. Exit\n");
    printf("====================\n");
    printf("Please enter your choice: ");
}

int main() {
    int choice, quantity;
    float total = 0;

    // Loop until the user chooses to exit
    do {
        // Display the menu
        showMenu();
        scanf("%d", &choice);

        // Process the user's choice
        switch(choice) {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += quantity * 2.00;
                break;
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += quantity * 1.50;
                break;
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += quantity * 3.00;
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        // Display the current total
        printf("Total: $%.2f\n", total);

    } while(choice != 4);

    printf("Thank you for visiting the C Cafe!\n");

    return 0;
}