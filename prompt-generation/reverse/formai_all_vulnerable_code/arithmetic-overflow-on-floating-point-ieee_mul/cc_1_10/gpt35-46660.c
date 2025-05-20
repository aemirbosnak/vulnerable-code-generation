//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//definitions and global variables

#define MAX_MENU_ITEMS 20
#define MAX_ORDER_ITEMS 10

char *menu[MAX_MENU_ITEMS];
float prices[MAX_MENU_ITEMS];
int menu_items_count = 0;

char order[MAX_ORDER_ITEMS];
float order_prices[MAX_ORDER_ITEMS];
int order_items_count = 0;

float subtotal = 0.0;
float tax = 0.0;
float total = 0.0;
float tips = 0.0;

//functions definitions

void initialize_menu() {
    menu[0] = "Mead";
    prices[0] = 6.0;
    menu[1] = "Roast Beef";
    prices[1] = 12.0;
    menu[2] = "Bread and Cheese";
    prices[2] = 8.0;
    menu[3] = "Stew";
    prices[3] = 10.0;
    menu_items_count = 4;
}

void display_menu() {
    printf("Menu Items\n");
    printf("---------------------\n");
    for(int i=0; i<menu_items_count; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i], prices[i]);
    }
    printf("---------------------\n");
}

void add_to_order(int item_number) {
    if(order_items_count >= MAX_ORDER_ITEMS) {
        printf("Sorry, you cannot order more than %d items.\n", MAX_ORDER_ITEMS);
        return;
    }
    int index = item_number-1;
    order[order_items_count] = *menu[index];
    order_prices[order_items_count] = prices[index];
    order_items_count++;
    printf("Added %s - $%.2f to your order.\n", menu[index], prices[index]);
}

void display_order() {
    printf("Your Order\n");
    printf("---------------------\n");
    for(int i=0; i<order_items_count; i++) {
        printf("%d. %s - $%.2f\n", i+1, order[i], order_prices[i]);
    }
    printf("---------------------\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", total);
}

void calculate_bill() {
    for(int i=0; i<order_items_count; i++) {
        subtotal += order_prices[i];
    }
    tax = subtotal * 0.15;
    total = subtotal + tax;
}

void get_tips() {
    char tips_input[10];
    printf("Enter tips (in percentage): ");
    scanf("%s", tips_input);
    tips = atof(tips_input);
}

void display_bill() {
    printf("Your Bill\n");
    printf("---------------------\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", total);
    printf("Tips (%.2f%%): $%.2f\n", tips, (total*tips)/100);
    printf("---------------------\n");
    printf("Thank you for visiting the tavern!\n");
}

//main function

int main() {
    printf("Welcome to the tavern!\n");
    printf("---------------------\n");
    initialize_menu();
    display_menu();
    while(1) {
        printf("Enter item number to add to your order (0 to finish):");
        char input[10];
        scanf("%s", input);
        int item_number = atoi(input);
        if(item_number == 0) {
            printf("\n\n");
            break;
        }
        add_to_order(item_number);
    }
    calculate_bill();
    get_tips();
    display_bill();
    return 0;
}