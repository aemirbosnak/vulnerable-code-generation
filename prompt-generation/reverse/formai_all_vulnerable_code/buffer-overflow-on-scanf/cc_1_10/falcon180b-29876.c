//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 20
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} item;

int num_items;
item menu[MAX_ITEMS];
float total_price;

void add_item(item *item) {
    strcpy(menu[num_items].name, item->name);
    menu[num_items].price = item->price;
    num_items++;
}

void display_menu() {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
}

void place_order(int order_size) {
    printf("Enter %d items you want to order:\n", order_size);
    for (int i = 0; i < order_size; i++) {
        char name[MAX_NAME_LEN];
        float price;
        printf("Item #%d name: ", i+1);
        scanf("%s", name);
        printf("Item #%d price: ", i+1);
        scanf("%f", &price);
        item item = {name, price};
        add_item(&item);
    }
}

void calculate_total() {
    total_price = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_price += menu[i].price;
    }
}

void print_receipt() {
    printf("Receipt:\n");
    printf("Items ordered:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("Total price: $%.2f\n", total_price);
}

int main() {
    printf("Welcome to Cafe Billing System!\n");
    int order_size;
    printf("Enter the number of items you want to order: ");
    scanf("%d", &order_size);
    place_order(order_size);
    calculate_total();
    print_receipt();
    return 0;
}