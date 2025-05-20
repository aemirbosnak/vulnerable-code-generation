//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 20
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} MenuItem;

MenuItem menu[MAX_MENU_ITEMS];
int num_items;

void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s ($%.2f)\n", i+1, menu[i].name, menu[i].price);
    }
}

float get_total(int* menu_items, int num_purchased) {
    float total = 0.0;
    for (int i = 0; i < num_purchased; i++) {
        total += menu[menu_items[i]-1].price;
    }
    return total;
}

int main() {
    // Initialize menu items
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 2.50;
    strcpy(menu[1].name, "Latte");
    menu[1].price = 4.00;
    strcpy(menu[2].name, "Cappuccino");
    menu[2].price = 3.50;
    num_items = 3;
    
    // Get user input for purchasing
    printf("Welcome to the cafe! What would you like to purchase?\n");
    print_menu();
    
    int* menu_items = (int*) malloc(num_items * sizeof(int));
    int num_purchased = 0;
    int item;
    do {
        printf("Enter the number of an item you'd like to purchase (or 0 to exit): ");
        scanf("%d", &item);
        if (item > 0 && item <= num_items) {
            menu_items[num_purchased++] = item;
            printf("You've added %s to your cart.\n", menu[item-1].name);
        } else if (item != 0) {
            printf("Invalid item number. Please try again.\n");
        }
    } while(item != 0);
    
    // Calculate and display total
    float total = get_total(menu_items, num_purchased);
    printf("Your total comes to $%.2f. Thank you for your purchase!\n", total);
    
    free(menu_items);
    return 0;
}