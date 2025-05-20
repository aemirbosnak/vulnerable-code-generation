//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing menu items
struct Menu {
    int id;
    char name[50];
    float price;
};

// Struct for storing customer orders
struct Order {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to print the menu
void print_menu(struct Menu menu[], int size) {
    printf("C Cafe Menu\n");
    printf("-----------\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Rs. %.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to place an order
void place_order(struct Menu menu[], int menu_size, struct Order order[], int *order_count) {
    int choice, quantity;
    printf("Enter the menu item id: ");
    scanf("%d", &choice);
    
    // Find the menu item with the given id
    struct Menu chosen_item;
    for (int i = 0; i < menu_size; i++) {
        if (menu[i].id == choice) {
            chosen_item = menu[i];
            break;
        }
    }
    
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    
    // Add the order to the array
    strcpy(order[*order_count].name, chosen_item.name);
    order[*order_count].price = chosen_item.price;
    order[*order_count].quantity = quantity;
    (*order_count)++;
    
    printf("Order added successfully!\n");
}

// Function to print the order summary
void print_order_summary(struct Order order[], int size) {
    printf("Order Summary\n");
    printf("-------------\n");
    printf("%-30s%-10s%-10s\n", "Item", "Price", "Quantity");
    for (int i = 0; i < size; i++) {
        printf("%-30s%-10.2f%-10d\n", order[i].name, order[i].price, order[i].quantity);
    }
}

// Function to calculate the total bill
float calculate_bill(struct Order order[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += order[i].price * order[i].quantity;
    }
    return total;
}

int main() {
    // Initialize the menu
    struct Menu menu[] = {
        {1, "Espresso", 100},
        {2, "Cappuccino", 120},
        {3, "Latte", 140},
        {4, "Muffin", 80},
        {5, "Croissant", 70}
    };
    int menu_size = sizeof(menu) / sizeof(menu[0]);
    
    // Initialize the order array
    struct Order order[100];
    int order_count = 0;
    
    int choice = 0;
    
    while (choice != 4) {
        // Print the options
        printf("\nC Cafe Billing System\n");
        printf("---------------------\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. View Order Summary\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                print_menu(menu, menu_size);
                break;
            case 2:
                place_order(menu, menu_size, order, &order_count);
                break;
            case 3:
                if (order_count == 0) {
                    printf("No orders placed yet.\n");
                } else {
                    print_order_summary(order, order_count);
                    printf("Total bill: Rs. %.2f\n", calculate_bill(order, order_count));
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    printf("Thank you for your business!\n");
    
    return 0;
}