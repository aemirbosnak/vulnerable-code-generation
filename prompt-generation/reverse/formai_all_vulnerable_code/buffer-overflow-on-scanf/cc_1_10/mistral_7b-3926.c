//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10

// Struct to store item details
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Item;

// Global variables
Item items[MAX_ITEMS];
int num_items = 0;
float total_bill = 0;

// Function to add an item to the bill
void add_item(const char* name, float price, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached!\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].quantity = quantity;

    total_bill += price * quantity;
    num_items++;
}

// Function to print the bill
void print_bill() {
    printf("\n----------CCAFE BILLING SYSTEM----------\n");
    printf("| Item            | Quantity | Price   | Total  |\n");
    printf("---------------------------------------");

    for (int i = 0; i < num_items; i++) {
        printf("\n| %-15s | %-10d | %.2f | %.2f |", items[i].name, items[i].quantity, items[i].price, items[i].price * items[i].quantity);
    }

    printf("\n---------------------------------------");
    printf("\n|                Total Bill           |\n");
    printf("|                 %.2f                |\n", total_bill);
}

// Function to take input from user
void take_input() {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;

    printf("\nEnter item name (or 'done' to finish): ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strcmp(name, "done") == 0) {
        return;
    }

    printf("Enter price: ");
    scanf("%f", &price);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    add_item(name, price, quantity);
}

int main() {
    bool is_running = true;

    while (is_running) {
        take_input();
        print_bill();

        printf("\nPress 'y' to continue or 'n' to exit: ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            is_running = false;
        }
    }

    return 0;
}