//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Declaring variables
    char customer_name[20];
    int table_num, num_of_guests, order_choice, quantity, subtotal, total = 0;
    char order_name[20];
    int order_price;
    char choice;

    // Welcome message
    printf("Welcome to C Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", &customer_name);
    printf("Hello %s!\n", customer_name);
    printf("Please enter your table number: ");
    scanf("%d", &table_num);
    printf("How many guests are there in your party?\n");
    scanf("%d", &num_of_guests);
    printf("Thank you! Let's get started.\n");

    // Ordering loop
    do {
        // Display menu
        printf("==== MENU ====\n");
        printf("1. Hot coffee      | RM5\n");
        printf("2. Iced coffee     | RM7\n");
        printf("3. Cappuccino      | RM8\n");
        printf("4. Latte           | RM9\n");
        printf("5. Croissant       | RM6\n");
        printf("6. Sandwich        | RM8\n");
        printf("7. Pasta           | RM12\n");
        printf("8. Quit ordering\n");

        // Get user input
        printf("Enter your choice: ");
        scanf("%d", &order_choice);

        // Calculate subtotal and add to total
        switch (order_choice) {
            case 1:
                strcpy(order_name, "Hot coffee");
                order_price = 5;
                break;
            case 2:
                strcpy(order_name, "Iced coffee");
                order_price = 7;
                break;
            case 3:
                strcpy(order_name, "Cappuccino");
                order_price = 8;
                break;
            case 4:
                strcpy(order_name, "Latte");
                order_price = 9;
                break;
            case 5:
                strcpy(order_name, "Croissant");
                order_price = 6;
                break;
            case 6:
                strcpy(order_name, "Sandwich");
                order_price = 8;
                break;
            case 7:
                strcpy(order_name, "Pasta");
                order_price = 12;
                break;
            case 8:
                printf("Thank you for ordering!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        if (order_choice >= 1 && order_choice <= 7) {
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            subtotal = order_price * quantity;
            total += subtotal;
            printf("%d X %s = RM%d\n", quantity, order_name, subtotal);
        }

        // Ask user if they want to continue ordering
        printf("Do you want to order anything else? (y/n): ");
        scanf(" %c", &choice);
    } while (choice != 'n');

    // Display total bill
    printf("==== BILL ====\n");
    printf("Customer name: %s\n", customer_name);
    printf("Table number: %d\n", table_num);
    printf("Number of guests: %d\n", num_of_guests);
    printf("Total bill: RM%d\n", total);

    return 0;
}