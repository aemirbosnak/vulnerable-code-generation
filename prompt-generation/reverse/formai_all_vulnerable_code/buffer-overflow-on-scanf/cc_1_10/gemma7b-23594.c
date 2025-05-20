//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu() {
    printf("\n--- Welcome to Caffeinated Dreams ---\n");
    printf("1. Lattes\n");
    printf("2. Cappuccinos\n");
    printf("3. Espresso\n");
    printf("4. Smoothies\n");
    printf("5. Coffee\n");
    printf("Please select an item:");
}

void calculateTotal(int item) {
    int cost = 0;
    switch (item) {
        case 1:
            cost = 3;
            break;
        case 2:
            cost = 4;
            break;
        case 3:
            cost = 5;
            break;
        case 4:
            cost = 6;
            break;
        case 5:
            cost = 2;
            break;
    }

    printf("Your selected item: ");
    switch (item) {
        case 1:
            printf("Latte\n");
            break;
        case 2:
            printf("Cappuccino\n");
            break;
        case 3:
            printf("Espresso\n");
            break;
        case 4:
            printf("Smoothie\n");
            break;
        case 5:
            printf("Coffee\n");
            break;
    }
    printf("Total cost: $%.2f\n", cost);
}

int main() {
    int item;

    displayMenu();
    scanf("%d", &item);

    calculateTotal(item);

    return 0;
}