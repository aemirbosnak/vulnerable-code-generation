//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct MenuItem {
    char name[50];
    double price;
} MenuItem;

typedef struct Order {
    int quantity;
    MenuItem menuItem;
} Order;

double total = 0.0;

void print_menu(MenuItem menu[], int size);
Order create_order(MenuItem menu[], int size);

int main() {

    MenuItem menu[] = {
        {"Cappuccino", 2.5},
        {"Latte", 3.0},
        {"Espresso", 2.0},
        {"Muffin", 1.5},
        {"Croissant", 1.5},
        {"Bagel", 2.0}
    };
    int size = sizeof(menu) / sizeof(menu[0]);

    printf("Welcome to the C Cafe!\n");
    printf("=========================\n");
    print_menu(menu, size);
    
    char choice;
    do {
        Order order = create_order(menu, size);
        printf("\nYou ordered %d %s(s) for $%.2f\n", order.quantity, order.menuItem.name, order.menuItem.price * order.quantity);
        total += order.menuItem.price * order.quantity;
        
        printf("Do you want to place another order? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("\nYour total is: $%.2f\n", total);
    printf("Thank you for visiting the C Cafe!\n");
    
    return 0;
}

void print_menu(MenuItem menu[], int size) {
    printf("Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

Order create_order(MenuItem menu[], int size) {
    int choice, quantity;
    printf("Enter number of item you want to order: ");
    scanf("%d", &choice);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    Order order = {quantity, menu[choice-1]};
    return order;
}