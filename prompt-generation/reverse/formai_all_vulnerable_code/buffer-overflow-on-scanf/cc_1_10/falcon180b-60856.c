//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define structure for menu items
struct menu_item {
    char name[100];
    float price;
};

// Function to display menu
void display_menu(struct menu_item menu[], int num_items) {
    printf("Cafe Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to get customer order
void get_order(struct menu_item menu[], int num_items, char order[100]) {
    printf("Enter your order (e.g. 1. Coffee): ");
    scanf("%s", order);
    int item_num = atoi(order) - 1;
    if (item_num >= 0 && item_num < num_items) {
        strcpy(order, menu[item_num].name);
    } else {
        printf("Invalid order.\n");
        exit(1);
    }
}

// Function to calculate total price
float calculate_total(struct menu_item menu[], int num_items, char order[]) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(menu[i].name, order) == 0) {
            return menu[i].price;
        }
    }
    printf("Invalid order.\n");
    exit(1);
}

// Main function
int main() {
    struct menu_item menu[] = {{"Coffee", 3.50}, {"Tea", 2.50}, {"Cake", 4.50}};
    int num_items = sizeof(menu) / sizeof(menu[0]);
    
    char order[100];
    float total_price = 0;
    
    while (1) {
        display_menu(menu, num_items);
        get_order(menu, num_items, order);
        total_price += calculate_total(menu, num_items, order);
        
        printf("Total price: $%.2f\n", total_price);
        printf("Do you want to order something else? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (tolower(choice) == 'n') {
            break;
        }
    }
    
    printf("Thank you for your order. Total price: $%.2f\n", total_price);
    return 0;
}