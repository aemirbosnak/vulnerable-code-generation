//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for Cafe's Menu Item
struct MenuItem {
    char item_name[30];
    double item_price;
};

// Function to print the menu
void printMenu(struct MenuItem menu[], int n) {
    printf("\nMenu:\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s - $%.2lf\n", i+1, menu[i].item_name, menu[i].item_price);
    }
}

// Function to calculate the bill
double calculateBill(struct MenuItem menu[], int n, int order[], int size) {
    double bill = 0.0;
    for(int i=0; i<size; i++) {
        bill += menu[order[i]-1].item_price;
    }
    return bill;
}

int main() {
    // Create the menu
    struct MenuItem menu[6];
    strcpy(menu[0].item_name, "Espresso");
    menu[0].item_price = 2.50;
    strcpy(menu[1].item_name, "Cappuccino");
    menu[1].item_price = 3.00;
    strcpy(menu[2].item_name, "Latte");
    menu[2].item_price = 3.50;
    strcpy(menu[3].item_name, "Muffin");
    menu[3].item_price = 2.00;
    strcpy(menu[4].item_name, "Croissant");
    menu[4].item_price = 2.50;
    strcpy(menu[5].item_name, "Bagel");
    menu[5].item_price = 2.00;
    
    int choice, option;
    int order[10];
    int size = 0;
    
    printf("Welcome to Cafe X!\n");
    
    do {
        // Print the menu
        printMenu(menu, 6);
        
        // Take the user's order
        printf("\nEnter the item number to order (0 to finish): ");
        scanf("%d", &choice);
        
        if(choice != 0) {
            // Add the item to the order
            order[size++] = choice;
        }
    } while(choice != 0 && size < 10);
    
    // Print the finalized order
    printf("\nYour order:\n");
    for(int i=0; i<size; i++) {
        printf("%d. %s - $%.2lf\n", i+1, menu[order[i]-1].item_name, menu[order[i]-1].item_price);
    }
    
    // Calculate the bill
    double bill = calculateBill(menu, 6, order, size);
    
    // Generate a random order number
    srand(time(NULL));
    int order_number = rand() % 10000;
    
    // Print the bill and order number
    printf("\nTotal bill: $%.2lf\n", bill);
    printf("Order number: %d\n", order_number);
    
    printf("\nThank you for choosing Cafe X! Have a nice day!\n");
    
    return 0;
}