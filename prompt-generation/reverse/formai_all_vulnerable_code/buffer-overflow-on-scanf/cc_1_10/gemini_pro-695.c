//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// A cheerful welcome message
void welcome() {
    printf("Welcome to the happiest cafe in town!\n");
    printf("Where every sip of coffee brings a smile :)\n\n");
}

// A menu with cheerful item names
char menu[][20] = {
    "Sunshine Latte",
    "Rainbow Cappuccino",
    "Smiley Pie",
    "Happy Muffin",
    "Joyful Smoothie"
};

// Prices for each menu item
int prices[] = {
    30,
    35,
    20,
    25,
    40
};

// Get the quantity ordered for each item
void getQuantity(int quantity[]) {
    int i;
    printf("Please enter the quantity for each item:\n");
    for (i = 0; i < 5; i++) {
        printf("%s: ", menu[i]);
        scanf("%d", &quantity[i]);
    }
}

// Calculate the total bill
int calculateBill(int quantity[], int prices[]) {
    int i;
    int total = 0;
    for (i = 0; i < 5; i++) {
        total += quantity[i] * prices[i];
    }
    return total;
}

// Print the bill with a cheerful message
void printBill(int total) {
    printf("\nHere's your bill, with a big smile on top!\n");
    printf("Total: %d\n", total);
    printf("Thank you for dining with us! We hope you had a joyful time :)\n");
}

// Main function
int main() {
    welcome();
    int quantity[5];
    getQuantity(quantity);
    int total = calculateBill(quantity, prices);
    printBill(total);
    return 0;
}