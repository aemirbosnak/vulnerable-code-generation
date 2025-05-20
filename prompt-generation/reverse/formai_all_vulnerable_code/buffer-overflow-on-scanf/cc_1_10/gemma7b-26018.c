//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu structure
typedef struct MenuItem {
    char name[50];
    float price;
    struct MenuItem* next;
} MenuItem;

// Define the bill structure
typedef struct Bill {
    char customer_name[50];
    char address[50];
    float total_amount;
    struct Bill* next;
} Bill;

// Function to add a menu item
void addMenuItem(MenuItem** head) {
    // Allocate memory for the new item
    MenuItem* new_item = (MenuItem*)malloc(sizeof(MenuItem));

    // Get the item name and price
    printf("Enter item name: ");
    scanf("%s", new_item->name);

    printf("Enter item price: ");
    scanf("%f", &new_item->price);

    // Add the item to the head of the list
    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
        *head = new_item;
    }
}

// Function to calculate the total amount
float calculateTotalAmount(MenuItem* head) {
    float total_amount = 0.0;

    // Iterate over the menu items
    for (MenuItem* item = head; item != NULL; item = item->next) {
        total_amount += item->price;
    }

    return total_amount;
}

// Function to add a bill
void addBill(Bill** head) {
    // Allocate memory for the new bill
    Bill* new_bill = (Bill*)malloc(sizeof(Bill));

    // Get the customer name and address
    printf("Enter customer name: ");
    scanf("%s", new_bill->customer_name);

    printf("Enter customer address: ");
    scanf("%s", new_bill->address);

    // Get the total amount
    new_bill->total_amount = calculateTotalAmount(head);

    // Add the bill to the head of the list
    if (*head == NULL) {
        *head = new_bill;
    } else {
        (*head)->next = new_bill;
        *head = new_bill;
    }
}

// Function to print the bills
void printBills(Bill* head) {
    // Iterate over the bills
    for (Bill* bill = head; bill != NULL; bill = bill->next) {
        printf("Customer name: %s\n", bill->customer_name);
        printf("Customer address: %s\n", bill->address);
        printf("Total amount: %.2f\n", bill->total_amount);
        printf("\n");
    }
}

int main() {
    // Create a menu head
    MenuItem* menu_head = NULL;

    // Create a bill head
    Bill* bill_head = NULL;

    // Add menu items
    addMenuItem(&menu_head);
    addMenuItem(&menu_head);

    // Add bills
    addBill(&bill_head);
    addBill(&bill_head);

    // Print bills
    printBills(bill_head);

    return 0;
}