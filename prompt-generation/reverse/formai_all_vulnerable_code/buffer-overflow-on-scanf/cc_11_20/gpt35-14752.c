//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
/*
 * This is a program that showcases unique error handling in C programming language.
 * The program is designed to simulate a bakery's online ordering system.
 * Errors that could occur range from invalid input to network failure.
 * 
 * Author: Arturo R. Garcia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 5
#define MAX_LEN 20

typedef struct {
    char name[MAX_LEN];
    int quantity;
    float price;
} Item;

int main(void) {
    Item items[MAX_ITEMS] = {
        {"Croissant", 2, 1.5},
        {"Baguette", 5, 3.0},
        {"Cinnamon Roll", 3, 2.0},
        {"Sourdough Bread", 1, 4.0},
        {"Pain au Chocolat", 4, 2.5}
    };
    
    int selection;
    int quantity;
    
    bool validInput = false;
    while (!validInput) {
        printf("Please select an item from the menu: \n");
        for (int i = 0; i < MAX_ITEMS; i++) {
            printf("%d. %s - $%.2f - Quantity: %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
        }
        printf("> ");
        
        if (!scanf("%d", &selection)) {
            printf("Invalid input. Please enter a number.\n");
            getchar();
        } else if (selection < 1 || selection > MAX_ITEMS) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_ITEMS);
        } else if (items[selection-1].quantity == 0) {
            printf("This item is out of stock. Please select another item.\n");
        } else {
            validInput = true;
        }
    }
    
    validInput = false;
    while (!validInput) {
        printf("Please enter the quantity of %s you would like to purchase: ", items[selection-1].name);
        if (!scanf("%d", &quantity)) {
            printf("Invalid input. Please enter a number.\n");
            getchar();
        } else if (quantity < 1) {
            printf("Invalid input. Please enter a positive number.\n");
        } else if (quantity > items[selection-1].quantity) {
            printf("We only have %d of these items in stock. Please enter a quantity equal or less than %d.\n", items[selection-1].quantity, items[selection-1].quantity);
        } else {
            validInput = true;
            items[selection-1].quantity -= quantity;
        }
    }
    
    printf("%d %s added to your cart.\n", quantity, items[selection-1].name);
    printf("Your total is $%.2f.\n", quantity * items[selection-1].price);
    
    
    // Simulating a network error
    int networkStatus = rand() % 2;
    if (networkStatus == 0) {
        printf("Error: Could not connect to the internet. Please check your connection.\n");
        exit(EXIT_FAILURE);
    }
    
    // Simulating insufficient funds
    float payment = rand() % 10;
    if (payment < quantity * items[selection-1].price) {
        printf("Error: Insufficient funds.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Payment successful. Your %d %s will be delivered shortly. Thank you for shopping with us!\n", quantity, items[selection-1].name);
    
    return 0;
}