//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the global variables
int menuOption;
char menuName[100], customerName[100];
int quantity;
float price;
float totalPrice = 0;

// Declare the functions
void displayMenu();
void takeOrder();
void generateBill();

int main() {

    printf("Welcome to our Cafe!\n");

    printf("What is your name?\n");
    fgets(customerName, 100, stdin);
    printf("Hello, %s", customerName);

    displayMenu();

    takeOrder();

    generateBill();

    printf("Thank you for visiting!\n");

    return 0;

}

void displayMenu() {

    printf("\nMenu:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.50\n");
    printf("3. Croissant - $3.50\n");
    printf("4. Sandwich - $4.50\n");

}

void takeOrder() {

    printf("\nWhat would you like to order?\n");
    scanf("%d", &menuOption);

    switch(menuOption) {

        case 1:
            strcpy(menuName, "Coffee");
            price = 2.50;
            break;
        case 2:
            strcpy(menuName, "Tea");
            price = 1.50;
            break;
        case 3:
            strcpy(menuName, "Croissant");
            price = 3.50;
            break;
        case 4:
            strcpy(menuName, "Sandwich");
            price = 4.50;
            break;
        default:
            printf("Invalid option.\n");
            exit(0);

    }

    printf("How many %s do you want?\n", menuName);
    scanf("%d", &quantity);

    totalPrice += price * quantity;

}

void generateBill() {

    printf("\n-------BILL--------\n");
    printf("Customer name: %s", customerName);
    printf("Item\tQuantity\tPrice\tTotal\n");
    printf("%s\t%d\t\t%.2f\t%.2f\n", menuName, quantity, price, price*quantity);
    printf("\nTotal Bill: $%.2f\n", totalPrice);

}