//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int choice = 1, bill_amount = 0, total_bill = 0;
    char customer_name[100], food_item[100], choice_text[100];

    printf("Welcome to the C Cafe Billing System!\n");
    printf("Please choose your meal:\n");

    do {
        printf("1. Coffee - $1.50\n");
        printf("2. Tea - $1.25\n");
        printf("3. Sandwich - $2.50\n");
        printf("4. Pizza - $3.50\n");
        printf("5. Soda - $1.00\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice!= 6) {
            switch (choice) {
                case 1:
                    printf("Coffee selected!\n");
                    break;
                case 2:
                    printf("Tea selected!\n");
                    break;
                case 3:
                    printf("Sandwich selected!\n");
                    break;
                case 4:
                    printf("Pizza selected!\n");
                    break;
                case 5:
                    printf("Soda selected!\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
            printf("Enter your name: ");
            scanf("%s", customer_name);
            printf("Enter the quantity of %s: ", food_item);
            scanf("%d", &bill_amount);
            total_bill += bill_amount;
            printf("\n");
            printf("Thank you for your order, %s!\n", customer_name);
            printf("Your total bill is: $%.2f\n", total_bill);
        } else {
            printf("Thank you for visiting the C Cafe Billing System!\n");
            break;
        }
    } while (choice!= 6);

    return 0;
}