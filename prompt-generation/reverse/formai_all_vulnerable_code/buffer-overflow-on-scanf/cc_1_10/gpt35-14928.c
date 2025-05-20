//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Global Variables */

int totalBill = 0;

/* Function Declarations */

void addItem(char itemName[], int itemPrice, int quantity);
void printBill();

/* Main Function */

int main() {
    printf("Welcome to the Cafe Billing System\n\n");
    printf("Today's Special: FREE 'Sadness' with every order!\n");
    printf("Enter 'exit' to exit the program.\n\n");

    while(1) {
        char itemName[30];
        int itemPrice, quantity;

        printf("Enter the name of the item: ");
        scanf("%s", itemName);

        if(strcmp(itemName, "exit") == 0) {
            break;
        }

        printf("Enter the price of the item: ");
        scanf("%d", &itemPrice);

        printf("Enter the quantity of the item: ");
        scanf("%d", &quantity);

        printf("%d %s(s) added to the cart!\n", quantity, itemName);

        addItem(itemName, itemPrice, quantity);
    }

    printBill();

    return 0;
}

/* Function Definitions */

void addItem(char itemName[], int itemPrice, int quantity) {
    int totalItemPrice = itemPrice * quantity;
    printf("%d %s(s) added to the bill for a total of %d$\n", quantity, itemName, totalItemPrice);
    totalBill += totalItemPrice;
}

void printBill() {
    printf("\n\n********** BILL **********\n\n");
    printf("Total Bill: %d$\n", totalBill);

    if(totalBill == 0) {
        printf("Looks like you didn't order anything, are you really in a cafe or just wasting our time?\n");
    }
    else if(totalBill < 50) {
        printf("Looks like it's just a regular day for you, better luck next time.\n");
    }
    else if(totalBill >= 50 && totalBill < 100) {
        printf("Well well well, looks like someone is feeling fancy today.\n");
    }
    else if(totalBill >= 100 && totalBill < 200) {
        printf("Wow, looks like someone hit the jackpot. Or did you rob a bank?\n");
    }
    else {
        printf("Whoa! Are you Bill Gates or Warren Buffet? We're not worthy.\n");
    }

    printf("\nThank you for choosing our cafe, have a good day!\n\n");
}