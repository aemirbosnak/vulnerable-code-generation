//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the menu structure
typedef struct Menu {
    char name[20];
    float price;
    struct Menu* next;
} Menu;

// Define the bill structure
typedef struct Bill {
    char customer_name[20];
    char address[20];
    float total_amount;
    struct Bill* next;
} Bill;

// Function to add a menu item
void add_menu_item(Menu** head) {
    Menu* new_item = (Menu*)malloc(sizeof(Menu));
    printf("Enter item name:");
    scanf("%s", new_item->name);
    printf("Enter item price:");
    scanf("%f", &new_item->price);
    new_item->next = *head;
    *head = new_item;
}

// Function to add a bill item
void add_bill_item(Bill** head) {
    Bill* new_bill_item = (Bill*)malloc(sizeof(Bill));
    printf("Enter customer name:");
    scanf("%s", new_bill_item->customer_name);
    printf("Enter customer address:");
    scanf("%s", new_bill_item->address);
    printf("Enter total amount:");
    scanf("%f", &new_bill_item->total_amount);
    new_bill_item->next = *head;
    *head = new_bill_item;
}

// Function to calculate total bill
float calculate_total_bill(Bill* head) {
    float total_bill = 0.0f;
    while (head) {
        total_bill += head->total_amount;
        head = head->next;
    }
    return total_bill;
}

// Function to print bill
void print_bill(Bill* head) {
    printf("Customer Name: %s\n", head->customer_name);
    printf("Customer Address: %s\n", head->address);
    printf("Total Bill: %.2f\n", calculate_total_bill(head));
}

int main() {
    Menu* menu_head = NULL;
    Bill* bill_head = NULL;

    // Add menu items
    add_menu_item(&menu_head);
    add_menu_item(&menu_head);

    // Add bill items
    add_bill_item(&bill_head);
    add_bill_item(&bill_head);

    // Print bill
    print_bill(bill_head);

    return 0;
}