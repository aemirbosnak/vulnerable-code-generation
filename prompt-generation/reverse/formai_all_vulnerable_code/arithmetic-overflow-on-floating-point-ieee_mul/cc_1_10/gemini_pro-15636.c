//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of each item
typedef struct item {
    char name[50];
    float price;
    int quantity;
} item;

// Structure to store the details of the bill
typedef struct bill {
    item items[100];
    int num_items;
    float total_price;
} bill;

// Function to create a new item
item create_item(char *name, float price, int quantity) {
    item new_item;
    strcpy(new_item.name, name);
    new_item.price = price;
    new_item.quantity = quantity;
    return new_item;
}

// Function to add an item to the bill
void add_item_to_bill(bill *b, item i) {
    b->items[b->num_items] = i;
    b->num_items++;
}

// Function to calculate the total price of the bill
float calculate_total_price(bill *b) {
    float total_price = 0;
    for (int i = 0; i < b->num_items; i++) {
        total_price += b->items[i].price * b->items[i].quantity;
    }
    return total_price;
}

// Function to print the bill
void print_bill(bill *b) {
    printf("Cafe Billing System\n");
    printf("--------------------\n");
    for (int i = 0; i < b->num_items; i++) {
        printf("%s\t%f\t%d\n", b->items[i].name, b->items[i].price, b->items[i].quantity);
    }
    printf("--------------------\n");
    printf("Total: %f\n", b->total_price);
}

// Main function
int main() {
    // Create a new bill
    bill b;
    b.num_items = 0;
    b.total_price = 0;

    // Add items to the bill
    add_item_to_bill(&b, create_item("Coffee", 2.50, 2));
    add_item_to_bill(&b, create_item("Tea", 1.50, 1));
    add_item_to_bill(&b, create_item("Cake", 4.00, 1));

    // Calculate the total price of the bill
    b.total_price = calculate_total_price(&b);

    // Print the bill
    print_bill(&b);

    return 0;
}