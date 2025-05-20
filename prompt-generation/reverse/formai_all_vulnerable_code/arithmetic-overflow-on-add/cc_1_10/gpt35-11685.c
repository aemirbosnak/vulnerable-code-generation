//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

struct MenuItem {
    char name[20];
    int price;
};

struct Order {
    char name[20];
    int quantity;
    int price;
};

int main() {
    struct MenuItem menu[] = {
        {"Coffee", 50},
        {"Tea", 40},
        {"Sandwich", 80},
        {"Burger", 100},
        {"Pizza", 200}
    };
    int num_items = sizeof(menu) / sizeof(menu[0]);
    struct Order orders[20];
    int num_orders = 0, total = 0;
    printf("Welcome to the Cafe Billing System\n\n");
    while(1) {
        printf("Menu:\n");
        for(int i = 0; i < num_items; i++) {
            printf("%d. %s - Rs %d\n", i + 1, menu[i].name, menu[i].price);
        }
        printf("%d. Confirm Order\n", num_items + 1);
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == num_items + 1) {
            break;
        }
        if(choice < 1 || choice > num_items) {
            printf("Invalid choice, please try again\n");
            continue;
        }
        struct MenuItem item = menu[choice - 1];
        int quantity;
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        orders[num_orders].quantity = quantity;
        orders[num_orders].price = quantity * item.price;
        total += orders[num_orders].price;
        num_orders++;
        printf("%s x %d added to order\n", item.name, quantity);
    }
    printf("\n==========================\n");
    printf("Cafe Billing System Invoice\n");
    printf("==========================\n");
    for(int i = 0; i < num_orders; i++) {
        printf("%s x %d - Rs %d\n", orders[i].name, orders[i].quantity, orders[i].price);
    }
    printf("Total: Rs %d\n", total);
    printf("==========================\n");
    printf("Thank you for your order\n");
    printf("==========================\n");
    return 0;
}