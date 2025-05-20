//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Item structure
typedef struct Item {
    char name[50];
    double price;
    int quantity;
} Item;

// Table structure
typedef struct Table {
    int number;
    Item items[10];
    int num_items;
    double total;
} Table;

// Menu structure
typedef struct Menu {
    Item items[100];
    int num_items;
} Menu;

// Create a new table
Table* create_table(int number) {
    Table* table = malloc(sizeof(Table));
    table->number = number;
    table->num_items = 0;
    table->total = 0.0;
    return table;
}

// Add an item to a table
void add_item(Table* table, Item* item) {
    table->items[table->num_items] = *item;
    table->num_items++;
    table->total += item->price * item->quantity;
}

// Remove an item from a table
void remove_item(Table* table, int index) {
    for (int i = index; i < table->num_items - 1; i++) {
        table->items[i] = table->items[i + 1];
    }
    table->num_items--;
    table->total -= table->items[index].price * table->items[index].quantity;
}

// Get the total price of a table
double get_total(Table* table) {
    return table->total;
}

// Print a table
void print_table(Table* table) {
    printf("Table %d\n", table->number);
    printf("-------------------\n");
    for (int i = 0; i < table->num_items; i++) {
        printf("%s x%d = %.2f\n", table->items[i].name, table->items[i].quantity, table->items[i].price * table->items[i].quantity);
    }
    printf("Total: %.2f\n", table->total);
}

// Create a new menu
Menu* create_menu() {
    Menu* menu = malloc(sizeof(Menu));
    menu->num_items = 0;
    return menu;
}

// Add an item to a menu
void add_item_to_menu(Menu* menu, Item* item) {
    menu->items[menu->num_items] = *item;
    menu->num_items++;
}

// Get an item from a menu
Item* get_item_from_menu(Menu* menu, int index) {
    return &menu->items[index];
}

// Print a menu
void print_menu(Menu* menu) {
    printf("Menu\n");
    printf("-------------------\n");
    for (int i = 0; i < menu->num_items; i++) {
        printf("%s - %.2f\n", menu->items[i].name, menu->items[i].price);
    }
}

// Main function
int main() {
    // Create a menu
    Menu* menu = create_menu();
    add_item_to_menu(menu, &(Item) {"Coffee", 2.50, 0});
    add_item_to_menu(menu, &(Item) {"Tea", 1.50, 0});
    add_item_to_menu(menu, &(Item) {"Juice", 2.00, 0});
    add_item_to_menu(menu, &(Item) {"Sandwich", 5.00, 0});
    add_item_to_menu(menu, &(Item) {"Salad", 6.00, 0});

    // Create a table
    Table* table = create_table(1);

    // Add items to the table
    add_item(table, get_item_from_menu(menu, 0));
    add_item(table, get_item_from_menu(menu, 2));
    add_item(table, get_item_from_menu(menu, 3));

    // Print the table
    print_table(table);

    // Get the total price of the table
    double total = get_total(table);
    printf("Total: %.2f\n", total);

    return 0;
}