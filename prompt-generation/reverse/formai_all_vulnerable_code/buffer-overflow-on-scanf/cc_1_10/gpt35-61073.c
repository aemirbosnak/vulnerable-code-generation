//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>

// function prototypes
void display_menu();
void take_order();
void display_bill();

// variables
int total_items = 0;
float total_cost = 0;

int main()
{
    int option;
    do {
        printf("\nWelcome to Visionary Cafe\n\n");
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Display Bill\n");
        printf("4. Exit\n\n");
        printf("Enter your option: ");
        
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                display_menu();
                break;
            case 2:
                take_order();
                break;
            case 3:
                display_bill();
                break;
            case 4:
                printf("\nThank you for visiting Visionary Cafe!\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

void display_menu() {
    printf("\nMenu:\n1. Cappuccino - $3.50\n2. Latte - $4.00\n3. Espresso - $2.50\n4. Mocha - $4.50\n");
}

void take_order() {
    int item_choice, quantity;
    float price;
    printf("\nWhat would you like to order? Enter item number: ");
    scanf("%d", &item_choice);
    printf("\nHow many would you like? Enter quantity: ");
    scanf("%d", &quantity);

    switch(item_choice) {
        case 1:
            price = 3.50;
            break;
        case 2:
            price = 4.00;
            break;
        case 3:
            price = 2.50;
            break;
        case 4:
            price = 4.50;
            break;
        default:
            printf("\nInvalid item number!\n");
            return;
    }
    // update total items and cost
    total_items += quantity;
    total_cost += (quantity * price);
}

void display_bill() {
    if (total_items == 0) {
        printf("\nNo items ordered yet!\n");
        return;
    }

    printf("\nBill:\n");
    printf("Total Items: %d\n", total_items);
    printf("Total Cost: $%.2f\n", total_cost);
}