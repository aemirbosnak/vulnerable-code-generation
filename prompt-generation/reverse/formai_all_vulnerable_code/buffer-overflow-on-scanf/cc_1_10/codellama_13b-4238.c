//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
/*
 *  Café Billing System
 *  Scalable Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structures
typedef struct {
    char name[50];
    int table_no;
    int bill_amount;
} Customer;

typedef struct {
    int item_code;
    char item_name[50];
    float price;
} Item;

typedef struct {
    int item_code;
    int quantity;
} Order;

// Function Prototypes
void create_customer(Customer *c);
void create_item(Item *i);
void create_order(Order *o);
void display_menu(Item menu[]);
void place_order(Customer *c, Order *o, Item menu[]);
void calculate_bill(Customer *c, Order *o, Item menu[]);
void display_bill(Customer *c);

// Global Variables
const int MAX_MENU_ITEMS = 10;
const int MAX_TABLES = 5;

// Function Definitions
void create_customer(Customer *c) {
    printf("Enter customer name: ");
    scanf("%s", c->name);
    printf("Enter table number: ");
    scanf("%d", &c->table_no);
}

void create_item(Item *i) {
    printf("Enter item code: ");
    scanf("%d", &i->item_code);
    printf("Enter item name: ");
    scanf("%s", i->item_name);
    printf("Enter item price: ");
    scanf("%f", &i->price);
}

void create_order(Order *o) {
    printf("Enter item code: ");
    scanf("%d", &o->item_code);
    printf("Enter quantity: ");
    scanf("%d", &o->quantity);
}

void display_menu(Item menu[]) {
    int i;
    printf("Menu:\n");
    for (i = 0; i < MAX_MENU_ITEMS; i++) {
        printf("%d. %s - Rs.%.2f\n", menu[i].item_code, menu[i].item_name, menu[i].price);
    }
}

void place_order(Customer *c, Order *o, Item menu[]) {
    int i;
    for (i = 0; i < MAX_MENU_ITEMS; i++) {
        if (menu[i].item_code == o->item_code) {
            c->bill_amount += menu[i].price * o->quantity;
            break;
        }
    }
}

void calculate_bill(Customer *c, Order *o, Item menu[]) {
    int i;
    for (i = 0; i < MAX_MENU_ITEMS; i++) {
        if (menu[i].item_code == o->item_code) {
            c->bill_amount += menu[i].price * o->quantity;
            break;
        }
    }
}

void display_bill(Customer *c) {
    printf("Customer Name: %s\n", c->name);
    printf("Table Number: %d\n", c->table_no);
    printf("Bill Amount: Rs.%.2f\n", c->bill_amount);
}

int main() {
    // Variables
    Customer customers[MAX_TABLES];
    Item menu[MAX_MENU_ITEMS];
    Order orders[MAX_TABLES];
    int i, j;

    // Create menu items
    for (i = 0; i < MAX_MENU_ITEMS; i++) {
        create_item(&menu[i]);
    }

    // Create customers and orders
    for (i = 0; i < MAX_TABLES; i++) {
        create_customer(&customers[i]);
        create_order(&orders[i]);
    }

    // Place orders and calculate bills
    for (i = 0; i < MAX_TABLES; i++) {
        place_order(&customers[i], &orders[i], menu);
        calculate_bill(&customers[i], &orders[i], menu);
    }

    // Display menu
    display_menu(menu);

    // Display bills
    for (i = 0; i < MAX_TABLES; i++) {
        display_bill(&customers[i]);
    }

    return 0;
}