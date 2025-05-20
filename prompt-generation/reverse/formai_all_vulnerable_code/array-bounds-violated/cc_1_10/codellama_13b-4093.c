//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int items_ordered[10];
    int num_items;
    float total;
};

void print_menu() {
    printf("Welcome to the Cafe!\n");
    printf("Here is our menu:\n");
    printf("1. Coffee: $2.00\n");
    printf("2. Tea: $1.50\n");
    printf("3. Mocha: $3.00\n");
    printf("4. Cappuccino: $3.50\n");
    printf("5. Latte: $4.00\n");
    printf("What would you like to order?\n");
}

void print_bill(struct customer *cust) {
    printf("Your total is $%.2f.\n", cust->total);
    printf("Thank you for choosing our Cafe!\n");
}

int main() {
    struct customer cust;
    int choice;

    print_menu();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            cust.items_ordered[cust.num_items++] = 1;
            cust.total += 2.00;
            break;
        case 2:
            cust.items_ordered[cust.num_items++] = 2;
            cust.total += 1.50;
            break;
        case 3:
            cust.items_ordered[cust.num_items++] = 3;
            cust.total += 3.00;
            break;
        case 4:
            cust.items_ordered[cust.num_items++] = 4;
            cust.total += 3.50;
            break;
        case 5:
            cust.items_ordered[cust.num_items++] = 5;
            cust.total += 4.00;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    print_bill(&cust);

    return 0;
}