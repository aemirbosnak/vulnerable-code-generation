//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define TAX_RATE 0.05   // Tax rate of 5%
#define MAX_ITEMS 100   // Maximum number of items in a bill

typedef struct {
    int item_no;        // Item number
    char item_name[50]; // Item name
    float item_price;   // Item price
    int quantity;       // Quantity of the item
} Item;

int main() {
    Item items[MAX_ITEMS];  // Array of items in the bill
    int num_items = 0;      // Number of items in the bill
    float subtotal = 0;     // Subtotal of the bill
    float tax = 0;          // Amount of tax
    float total = 0;        // Total amount of the bill
    char input;             // Input from the user

    // Welcome message
    printf("Welcome to C Cafe!\n");

    // Menu of items
    printf("\nMenu:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $2.00\n");
    printf("3. Hot Chocolate - $3.00\n");
    printf("4. Sandwich - $5.00\n");
    printf("5. Salad - $4.00\n");
    printf("6. Soup - $3.50\n");

    // Get items from the user
    do {
        // Ask the user to enter the item number and quantity
        printf("\nEnter the item number: ");
        scanf("%d", &items[num_items].item_no);

        printf("Enter the quantity: ");
        scanf("%d", &items[num_items].quantity);

        // Set the price and name of the item based on the item number
        switch (items[num_items].item_no) {
            case 1:
                items[num_items].item_price = 2.5;
                strcpy(items[num_items].item_name, "Coffee");
                break;
            case 2:
                items[num_items].item_price = 2;
                strcpy(items[num_items].item_name, "Tea");
                break;
            case 3:
                items[num_items].item_price = 3;
                strcpy(items[num_items].item_name, "Hot Chocolate");
                break;
            case 4:
                items[num_items].item_price = 5;
                strcpy(items[num_items].item_name, "Sandwich");
                break;
            case 5:
                items[num_items].item_price = 4;
                strcpy(items[num_items].item_name, "Salad");
                break;
            case 6:
                items[num_items].item_price = 3.5;
                strcpy(items[num_items].item_name, "Soup");
                break;
            default:
                printf("Invalid item number.\n");
                continue;
        }

        // Calculate the subtotal of the bill
        subtotal += items[num_items].item_price * items[num_items].quantity;

        // Ask the user if they want to add more items
        printf("Do you want to add more items? (Y/N): ");
        scanf(" %c", &input);
        num_items++;

    } while (input == 'Y' || input == 'y');

    // Calculate the tax amount and total amount of the bill
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    // Print the bill
    printf("\n\nC Cafe Bill:\n");
    printf("------------------------------------------------------------\n");
    printf("| Item No. |      Item Name      | Price | Quantity | Amount |\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("| %8d | %20s | $%5.2f | %8d | $%5.2f |\n", items[i].item_no, 
               items[i].item_name, items[i].item_price, items[i].quantity, 
               items[i].item_price * items[i].quantity);
    }
    printf("------------------------------------------------------------\n");
    printf("|                                        Subtotal | $%5.2f |\n", subtotal);
    printf("|                                             Tax | $%5.2f |\n", tax);
    printf("| ---------------------------------------------- | ------- |\n");
    printf("|                                      Total Due | $%5.2f |\n", total);
    printf("------------------------------------------------------------\n");

    return 0;
}