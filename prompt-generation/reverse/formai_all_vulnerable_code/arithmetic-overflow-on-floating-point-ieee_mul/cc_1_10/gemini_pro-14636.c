//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Constants and defines
#define MAX_ITEMS 100
#define ITEM_DESC_LEN 50
#define MAX_DISCOUNT 50
#define TAX_RATE 12.5

// Structure for items
typedef struct {
    char description[ITEM_DESC_LEN];
    int quantity;
    float unit_price;
} Item;

// Structure for the cafe bill
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float subtotal;
    float discount_amount;
    float tax_amount;
    float total_amount;
} CafeBill;

// Functions
void add_item(CafeBill *bill, Item item);
void print_bill(CafeBill bill);
float calculate_subtotal(CafeBill bill);
float calculate_discount_amount(CafeBill bill, float discount_rate);
float calculate_tax_amount(CafeBill bill);
float calculate_total_amount(CafeBill bill);

// Main function
int main() {
    // Create a new cafe bill
    CafeBill bill;
    bill.num_items = 0;
    bill.subtotal = 0.0;
    bill.discount_amount = 0.0;
    bill.tax_amount = 0.0;
    bill.total_amount = 0.0;

    // Add some items to the bill
    Item item1 = {"Latte", 1, 3.50};
    add_item(&bill, item1);
    Item item2 = {"Cappuccino", 2, 4.00};
    add_item(&bill, item2);
    Item item3 = {"Croissant", 1, 2.50};
    add_item(&bill, item3);

    // Calculate the subtotal
    bill.subtotal = calculate_subtotal(bill);

    // Calculate the discount amount
    bill.discount_amount = calculate_discount_amount(bill, 10.0);

    // Calculate the tax amount
    bill.tax_amount = calculate_tax_amount(bill);

    // Calculate the total amount
    bill.total_amount = calculate_total_amount(bill);

    // Print the bill
    print_bill(bill);

    return 0;
}

// Function to add an item to a cafe bill
void add_item(CafeBill *bill, Item item) {
    if (bill->num_items < MAX_ITEMS) {
        bill->items[bill->num_items] = item;
        bill->num_items++;
    }
}

// Function to print a cafe bill
void print_bill(CafeBill bill) {
    printf("Cafe Bill\n");
    printf("==================\n");
    for (int i = 0; i < bill.num_items; i++) {
        printf("%s\t%d\t%.2f\n", bill.items[i].description, bill.items[i].quantity, bill.items[i].unit_price);
    }
    printf("Subtotal:\t%.2f\n", bill.subtotal);
    printf("Discount:\t-%.2f\n", bill.discount_amount);
    printf("Tax:\t\t%.2f\n", bill.tax_amount);
    printf("Total:\t\t%.2f\n", bill.total_amount);
}

// Function to calculate the subtotal of a cafe bill
float calculate_subtotal(CafeBill bill) {
    float subtotal = 0.0;
    for (int i = 0; i < bill.num_items; i++) {
        subtotal += bill.items[i].quantity * bill.items[i].unit_price;
    }
    return subtotal;
}

// Function to calculate the discount amount of a cafe bill
float calculate_discount_amount(CafeBill bill, float discount_rate) {
    float discount_amount = 0.0;
    if (discount_rate > 0.0 && discount_rate <= MAX_DISCOUNT) {
        discount_amount = bill.subtotal * discount_rate / 100.0;
    }
    return discount_amount;
}

// Function to calculate the tax amount of a cafe bill
float calculate_tax_amount(CafeBill bill) {
    float tax_amount = 0.0;
    tax_amount = bill.subtotal * TAX_RATE / 100.0;
    return tax_amount;
}

// Function to calculate the total amount of a cafe bill
float calculate_total_amount(CafeBill bill) {
    float total_amount = 0.0;
    total_amount = bill.subtotal - bill.discount_amount + bill.tax_amount;
    return total_amount;
}