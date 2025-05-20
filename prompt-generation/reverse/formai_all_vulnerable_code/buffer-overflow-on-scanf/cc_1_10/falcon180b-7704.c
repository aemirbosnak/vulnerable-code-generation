//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total amount of bill
float calculateTotal(float amount, int quantity) {
    return amount * quantity;
}

// Function to display the menu
void displayMenu() {
    printf("\n");
    printf("Welcome to Cafe Billing System\n");
    printf("---------------------------------\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Cold Drink\n");
    printf("4. Snacks\n");
    printf("5. Exit\n");
    printf("\n");
}

// Function to take order from customer
void takeOrder() {
    int choice;
    float amount, total = 0.0;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter amount for Coffee: ");
            scanf("%f", &amount);
            total += calculateTotal(amount, 1);
            printf("\n");
            break;
        case 2:
            printf("Enter amount for Tea: ");
            scanf("%f", &amount);
            total += calculateTotal(amount, 1);
            printf("\n");
            break;
        case 3:
            printf("Enter amount for Cold Drink: ");
            scanf("%f", &amount);
            total += calculateTotal(amount, 1);
            printf("\n");
            break;
        case 4:
            printf("Enter amount for Snacks: ");
            scanf("%f", &amount);
            total += calculateTotal(amount, 1);
            printf("\n");
            break;
        case 5:
            printf("Thank you for visiting Cafe Billing System!\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("Total amount: %.2f\n", total);
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                takeOrder();
                break;
            case 5:
                printf("Exiting Cafe Billing System...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);

    return 0;
}