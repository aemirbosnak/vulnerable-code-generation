//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

struct item {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
};

struct order {
    struct item items[MAX_ITEMS];
    int num_items;
    double total;
};

void print_menu();
struct item get_item();
bool add_item_to_order(struct item, struct order*);
void print_order(struct order);
void clear_order(struct order*);

int main() {
    struct order my_order;
    clear_order(&my_order);
    
    while (true) {
        print_menu();
        
        char choice;
        printf("Enter your choice (a-g or q): ");
        scanf(" %c", &choice);
        
        if (choice == 'q') {
            break;
        }
        
        struct item item = get_item();
        
        if (!add_item_to_order(item, &my_order)) {
            printf("The item was not added to the order.\n");
        } else {
            printf("The item was added to the order.\n");
        }
        
        printf("Current order:\n");
        print_order(my_order);
    }
    
    printf("Final order:\n");
    print_order(my_order);
    
    return 0;
}

void print_menu() {
    printf("========== MENU ==========\n");
    printf("a) Coffee........$2.00\n");
    printf("b) Tea...........$1.50\n");
    printf("c) Sandwich......$5.00\n");
    printf("d) Soup..........$3.50\n");
    printf("e) Salad.........$4.00\n");
    printf("f) Cake..........$3.00\n");
    printf("g) Juice.........$2.50\n");
}

struct item get_item() {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
    
    printf("Enter the name of the item: ");
    scanf("%s", name);
    
    printf("Enter the price of the item: ");
    scanf("%lf", &price);
    
    printf("Enter the quantity of the item: ");
    scanf("%d", &quantity);
    
    struct item item;
    strcpy(item.name, name);
    item.price = price;
    item.quantity = quantity;
    
    return item;
}

bool add_item_to_order(struct item item, struct order *order) {
    if (item.name[0] == '\0' || item.price == 0 || item.quantity == 0) {
        return false;
    }
    
    if (order->num_items == MAX_ITEMS) {
        return false;
    }
    
    order->items[order->num_items] = item;
    order->num_items++;
    order->total += item.price * item.quantity;
    
    return true;
}

void print_order(struct order order) {
    printf("===== ORDER =====\n");
    
    for (int i = 0; i < order.num_items; i++) {
        printf("%s x%d $%.2f\n", order.items[i].name, order.items[i].quantity, order.items[i].price);
    }
    
    printf("Total: $%.2f\n", order.total);
}

void clear_order(struct order *order) {
    memset(order, 0, sizeof(struct order));
}