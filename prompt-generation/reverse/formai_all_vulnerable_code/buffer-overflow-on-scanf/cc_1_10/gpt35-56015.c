//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_LENGTH 20
#define MAX_ORDER_NUM 50

typedef struct MenuItem {
    char name[MAX_MENU_LENGTH];
    float price;
} MenuItem;

MenuItem menu[] = {
    {"Espresso", 2.50},
    {"Cappuccino", 3.00},
    {"Latte", 3.50},
    {"Mocha", 4.00},
    {"Americano", 2.00},
    {"Hot Chocolate", 3.00},
    {"Tea", 1.50}
};

typedef struct Order {
    MenuItem item;
    int quantity;
} Order;

Order order[MAX_ORDER_NUM];
int num_orders = 0;

void add_order(MenuItem item, int quantity) {
    if(num_orders >= MAX_ORDER_NUM) {
        printf("Order limit reached\n");
        return;
    }
    
    Order new_order;
    new_order.item = item;
    new_order.quantity = quantity;
    
    order[num_orders] = new_order;
    num_orders++;
}

void print_menu() {
    printf("MENU\n");
    for(int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("\n");
}

void print_order() {
    printf("ORDER\n");
    for(int i = 0; i < num_orders; i++) {
        printf("%s - $%.2f x %d\n", order[i].item.name, order[i].item.price, order[i].quantity);
    }
    printf("\n");
}

float calculate_total() {
    float total = 0.0;
    for(int i = 0; i < num_orders; i++) {
        total += order[i].item.price * order[i].quantity;
    }
    return total;
}

int main() {
    print_menu();
    
    while(1) {
        printf("Enter menu item name or 'done' to finish ordering: ");
        char input[MAX_MENU_LENGTH];
        scanf("%s", input);

        if(strcmp(input, "done") == 0) {
            break;
        }

        int quantity;
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        int found = 0;
        for(int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
            if(strcmp(input, menu[i].name) == 0) {
                add_order(menu[i], quantity);
                printf("%s %d added to order\n", menu[i].name, quantity);
                found = 1;
                break;
            }
        }
        
        if(!found) {
            printf("Invalid menu item\n");
        }
    }
    
    print_order();
    printf("Total: $%.2f\n", calculate_total());
    
    return 0;
}