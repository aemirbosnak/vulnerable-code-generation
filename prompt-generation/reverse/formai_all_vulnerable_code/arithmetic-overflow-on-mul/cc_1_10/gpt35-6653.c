//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu(void);
void placeOrder(int* total, int* subtotal);
void printBill(int total);

int main()
{
    int total = 0, subtotal = 0;

    printf("Welcome to the C Cafe!\n");

    // Loop until user chooses to exit
    while (1) {
        int choice;

        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                placeOrder(&total, &subtotal);
                break;
            case 2:
                printBill(total);
                break;
            case 3:
                printf("Thank you for visiting the C Cafe!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}

void displayMenu(void)
{
    printf("\n");
    printf("1. Place an order\n");
    printf("2. Print bill\n");
    printf("3. Exit\n\n");
}

void placeOrder(int* total, int* subtotal)
{
    int choice, quantity, price;

    printf("\n");
    printf("1. Espresso  $3\n");
    printf("2. Latte     $4\n");
    printf("3. Cappuccino $4\n");
    printf("4. Muffin    $2\n");
    printf("5. Croissant $3\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    switch (choice) {
        case 1:
            price = 3;
            break;
        case 2:
            price = 4;
            break;
        case 3:
            price = 4;
            break;
        case 4:
            price = 2;
            break;
        case 5:
            price = 3;
            break;
        default:
            printf("Invalid choice. Please try again.\n\n");
            return;
    }

    *subtotal += (price * quantity);
    *total += (price * quantity);

    printf("\nAdded %d %s to your order.\n\n", quantity, (choice == 1) ? "Espresso" :
                                                  (choice == 2) ? "Latte" :
                                                  (choice == 3) ? "Cappuccino" :
                                                  (choice == 4) ? "Muffin" :
                                                  "Croissant");
}

void printBill(int total)
{
    printf("\nYour bill is $%d.\n\n", total);
}