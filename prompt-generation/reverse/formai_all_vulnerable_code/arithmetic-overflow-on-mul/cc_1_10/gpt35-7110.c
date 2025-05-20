//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include<stdio.h>
#include<stdlib.h>

#define MAX_MENU_ITEMS 10
#define MAX_ORDERS 50

typedef struct {
    char item_name[100];
    int item_price;
} Menu_Item;

typedef struct {
    Menu_Item menu;
    int quantity;
} Order;

void print_menu(Menu_Item menu[], int num_items) {
    printf("Menu:\n");
    for(int i=0; i<num_items; i++) {
        printf("%d. %s (%d)\n", i+1, menu[i].item_name, menu[i].item_price);
    }
}

int main() {
    Menu_Item menu[MAX_MENU_ITEMS] = {
        {"Coffee", 50},
        {"Tea", 20},
        {"Sandwich", 80},
        {"Burger", 100},
        {"French Fries", 60},
        {"Pizza", 150},
        {"Pasta", 120},
        {"Mojito", 70},
        {"Coke", 40},
        {"Juice", 30}
    };

    int num_items = sizeof(menu)/sizeof(menu[0]);
    Order order[MAX_ORDERS];
    int num_orders = 0;
    int choice, quantity;

    printf("*** Welcome to C Cafe ***\n");
    do {
        printf("\n");
        print_menu(menu, num_items);
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Thank you for visiting C Cafe!\n");
            break;
        }

        if(choice < 1 || choice > num_items) {
            printf("Invalid choice!\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        if(quantity <= 0) {
            printf("Invalid quantity!\n");
            continue;
        }

        order[num_orders].menu = menu[choice-1];
        order[num_orders].quantity = quantity;
        num_orders++;

        printf("%d %s added to your order.\n", quantity, menu[choice-1].item_name);

    } while(1);

    printf("\n*** Order Details ***\n");
    printf("Item\t\t\tPrice\t\tQuantity\tTotal\n");
    printf("----------------------------------------------------------------\n");
    int total = 0;
    for(int i=0; i<num_orders; i++) {
        printf("%-20s%-16d%-16d%d\n", order[i].menu.item_name, order[i].menu.item_price, order[i].quantity, order[i].menu.item_price * order[i].quantity);
        total += order[i].menu.item_price * order[i].quantity;
    }
    printf("----------------------------------------------------------------\n");
    printf("Total\t\t\t\t\t\t%d", total);

    return 0;
}