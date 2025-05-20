//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for items in menu
struct MenuItem {
    char itemName[50];
    double itemPrice;
};

// Function to print menu
void printMenu(struct MenuItem menu[], int size) {
    printf("========== MENU ==========\n");
    for(int i=0; i<size; i++) {
        printf("%d. %s: $%.2f\n", i+1, menu[i].itemName, menu[i].itemPrice);
    }
    printf("==========================\n");
}

// Function to calculate total bill amount
double calculateBill(int order[], struct MenuItem menu[], int size) {
    double total = 0;
    for(int i=0; i<size; i++) {
        total += order[i] * menu[i].itemPrice;
    }
    return total;
}

int main() {
    // Initialize menu items
    struct MenuItem menu[5];
    strcpy(menu[0].itemName, "Coffee");
    menu[0].itemPrice = 2.50;
    strcpy(menu[1].itemName, "Tea");
    menu[1].itemPrice = 2.00;
    strcpy(menu[2].itemName, "Sandwich");
    menu[2].itemPrice = 4.50;
    strcpy(menu[3].itemName, "Cake");
    menu[3].itemPrice = 3.00;
    strcpy(menu[4].itemName, "Muffin");
    menu[4].itemPrice = 2.00;

    // Print menu
    printMenu(menu, 5);

    // Initialize order array
    int order[5] = {0};

    // Get user input for order
    char input[50];
    int choice, quantity;
    double total;
    while(1) {
        printf("Enter item number and quantity (separated by a space) or 'done' to exit: ");
        fgets(input, 50, stdin);
        if(strcmp(input, "done\n") == 0) {
            break;
        }
        sscanf(input, "%d %d", &choice, &quantity);
        order[choice-1] += quantity;
    }

    // Print order
    printf("========== ORDER ==========\n");
    for(int i=0; i<5; i++) {
        if(order[i] > 0) {
            printf("%s: %d\n", menu[i].itemName, order[i]);
        }
    }
    printf("===========================\n");

    // Calculate and print total
    total = calculateBill(order, menu, 5);
    printf("Total bill: $%.2f\n", total);

    return 0;
}