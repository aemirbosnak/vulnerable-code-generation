//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Menu items and their prices
typedef struct {
    char name[50];
    float price;
} Item;

Item menu[] = {
    {"Cappuccino", 3.50},
    {"Latte", 3.75},
    {"Espresso", 2.50},
    {"Americano", 3.00},
    {"Macchiato", 2.75},
    {"Mocha", 3.85},
    {"Hot Chocolate", 2.95},
    {"Tea", 2.25},
    {"Cookies", 1.50},
    {"Muffins", 2.25}
};

// Function to display menu
void displayMenu() {
    printf("\n***** Welcome to Peaceful Cafe *****\n");
    printf("\n**** Menu ****\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to get user input
int getUserChoice() {
    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 11) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > 11);
    return choice;
}

// Function to calculate total price
float calculateTotal(int choice, int quantity) {
    return menu[choice-1].price * quantity;
}

// Function to process order
void processOrder(int choice, int quantity) {
    printf("\nYou ordered %d %s(s) with a total price of $%.2f.\n", quantity, menu[choice-1].name, calculateTotal(choice, quantity));
}

// Function to print receipt
void printReceipt(char name[50], float total) {
    printf("\n***** Receipt *****\n");
    printf("Name: %s\n", name);
    printf("------------------\n");
    printf("Total: $%.2f\n", total);
}

int main() {
    char name[50];
    int choice, quantity;
    float total;

    displayMenu();
    choice = getUserChoice();
    printf("How many %s(s) would you like? ", menu[choice-1].name);
    scanf("%d", &quantity);

    processOrder(choice, quantity);
    printf("Enter your name: ");
    scanf("%s", name);
    total = calculateTotal(choice, quantity);

    printReceipt(name, total);

    return 0;
}