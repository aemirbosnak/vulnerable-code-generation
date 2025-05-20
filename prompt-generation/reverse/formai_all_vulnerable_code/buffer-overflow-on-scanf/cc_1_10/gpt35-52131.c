//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store menu items
typedef struct menu {
    char name[20];
    float price;
} Menu;

// Function declarations
void print_menu(Menu *menu_items, int count);
void calculate_bill(Menu *menu_items, int count);

int main() {
    // Create menu items
    Menu menu_items[5] = {{"Coffee", 2.50}, {"Tea", 1.50}, {"Sandwich", 3.25}, {"Cake", 2.75}, {"Muffin", 1.50}};
    int menu_count = 5;
    int option = 0;
    
    printf("Welcome to the Retro Cafe Billing System\n");
    printf("==========================================\n\n");
    
    // Display menu options
    printf("Please select an option:\n");
    printf("1. View Menu\n");
    printf("2. Calculate Bill\n");
    printf("3. Exit\n\n");
    
    do {
        printf("Enter option (1-3): ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                print_menu(menu_items, menu_count);
                break;
            case 2:
                calculate_bill(menu_items, menu_count);
                break;
            case 3:
                printf("Thank you for using Retro Cafe Billing System!\n");
                break;
            default:
                printf("Invalid option. Please enter a number between 1-3.\n");
                break;
        }
        
    } while(option != 3);
    
    return 0;
}

// Function to print menu items
void print_menu(Menu *menu_items, int count) {
    printf("Menu Items:\n");
    printf("==========================================\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %-10s $%.2f\n", i+1, menu_items[i].name, menu_items[i].price);
    }
    printf("\n");
}

// Function to calculate bill
void calculate_bill(Menu *menu_items, int count) {
    int order_count = 0;
    int *orders = (int*)malloc(count * sizeof(int));
    float total_cost = 0;
    
    // Get user orders
    for(int i = 0; i < count; i++) {
        printf("Enter quantity for %s: ", menu_items[i].name);
        scanf("%d", &orders[i]);
        order_count += orders[i];
        total_cost += (orders[i] * menu_items[i].price);
    }
    
    // Print order summary
    printf("\n");
    printf("Order Summary:\n");
    printf("==========================================\n");
    for(int i = 0; i < count; i++) {
        if(orders[i] > 0) {
            printf("%s - %d x $%.2f = $%.2f\n", menu_items[i].name, orders[i], menu_items[i].price, (orders[i] * menu_items[i].price));
        }
    }
    printf("Total order count: %d\n", order_count);
    printf("Total cost: $%.2f\n\n", total_cost);
    
    free(orders);
}