//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <string.h>

typedef struct menu_item {    // Define a structure to hold menu items
    char name[20];
    float price;
} MenuItem;

typedef struct order_item {   // Define a structure to hold order items
    MenuItem* item;
    int quantity;
} OrderItem;

#define MAX_ITEMS 100         // Define the maximum number of menu items
int num_items = 0;            // Keep track of the number of menu items added
MenuItem menu[MAX_ITEMS];     // The menu item array

float subtotal = 0;           // Keep track of the order subtotal
OrderItem order[MAX_ITEMS];   // The order item array
int order_size = 0;           // Keep track of the number of items in the order

int print_menu() {            // Function to print the menu and return the number of items
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s ($%.2f)\n", i+1, menu[i].name, menu[i].price);
    }
    return num_items;
}

int get_menu_input() {        // Function to get menu item selection from user
    int choice;
    printf("Enter the number of your choice: ");
    scanf("%d", &choice);
    return choice-1;
}

void add_menu_item(char* name, float price) {   // Function to add a menu item to the menu
    if (num_items < MAX_ITEMS) {          // Check if the array is full
        MenuItem item = {name, price};
        menu[num_items++] = item;         // Add the new item to the array
        printf("%s ($%.2f) added to menu.\n", name, price);
    } else {
        printf("Menu is full. Cannot add item.\n");
    }
}

void add_to_order(int choice, int quantity) {  // Function to add an item to the order
    if (choice >= 0 && choice < num_items) {   // Check if the choice is valid
        OrderItem order_item = {&menu[choice], quantity};
        order[order_size++] = order_item;     // Add the new item to the order
        printf("%d %s(s) added to order.\n", quantity, menu[choice].name);
        subtotal += menu[choice].price * quantity;   // Increment the subtotal
    } else {
        printf("Invalid choice.\n");
    }
}

void print_order() {                            // Function to print the order
    printf("\nOrder:\n");
    for (int i = 0; i < order_size; i++) {
        printf("%d. %s - %d x $%.2f = $%.2f\n", i+1, order[i].item->name, order[i].quantity, order[i].item->price, order[i].item->price*order[i].quantity);
    }
    printf("Subtotal: $%.2f\n", subtotal);
}

void clear_order() {                            // Function to clear the order and update the subtotal
    order_size = 0;
    subtotal = 0;
    printf("Order cleared.\n");
}

int main() {
    add_menu_item("Coffee", 2.50);    // Add some menu items
    add_menu_item("Espresso", 3.00);
    add_menu_item("Latte", 3.50);
    add_menu_item("Cappuccino", 4.00);

    int choice;
    do {
        printf("\nMenu Options:\n1. View Menu\n2. Add Item to Order\n3. View Order\n4. Clear Order\n5. Quit\n");
        printf("Enter the number of your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: print_menu(); break;
            case 2: {
                int choice = get_menu_input();
                int quantity;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_to_order(choice, quantity);
                break;
            }
            case 3: print_order(); break;
            case 4: clear_order(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 5);
    return 0;
}