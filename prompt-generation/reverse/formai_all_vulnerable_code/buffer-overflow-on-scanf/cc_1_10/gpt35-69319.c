//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define ITEM_NAME_LEN 20

/* Item Structure */
typedef struct {
    char name[ITEM_NAME_LEN];
    float price;
    int quantity;
} Item;

/* Function prototypes */
void print_menu();
void add_item(Item items[], int *count);
void print_bill(Item items[], int count);

/* Main function */
int main() {
    Item items[MAX_ITEMS];  // Array to hold items
    int count = 0;  // Count of items in array

    // Loop until user inputs 0
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &count);
                break;
            case 2:
                print_bill(items, count);
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

/* Function to print the menu */
void print_menu() {
    printf("--------------------------------------------------\n");
    printf("                  C Cafe Billing System        \n");
    printf("--------------------------------------------------\n");
    printf("1. Add item\n");
    printf("2. Print bill\n");
    printf("0. Exit\n");
    printf("--------------------------------------------------\n");
}

/* Function to add an item to the array */
void add_item(Item items[], int *count) {
    if (*count == MAX_ITEMS) {
        printf("Maximum items reached. Cannot add more.\n");
        return;
    }

    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter price: ");
    scanf("%f", &item.price);
    printf("Enter quantity: ");
    scanf("%d", &item.quantity);

    items[*count] = item;
    (*count)++;

    printf("Item added successfully.\n");
}

/* Function to print the bill */
void print_bill(Item items[], int count) {
    if (count == 0) {
        printf("No items found.\n");
        return;
    }

    float total = 0.0;
    printf("--------------------------------------------------\n");
    printf("                           BILL                       \n");
    printf("--------------------------------------------------\n");
    printf("ITEM NAME               PRICE       QUANTITY   AMOUNT\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        Item item = items[i];
        float amount = item.price * item.quantity;
        printf("%-20s  %10.2f  %10d  %10.2f\n", item.name, item.price, item.quantity, amount);
        total += amount;
    }
    printf("--------------------------------------------------\n");
    printf("TOTAL AMOUNT: %40.2f\n", total);
}