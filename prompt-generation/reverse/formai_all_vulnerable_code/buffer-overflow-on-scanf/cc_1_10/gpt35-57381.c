//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n\n");
    printf("\t\t========== MENU ==========\n");
    printf("\t\tItem Code     Description          Price\n");
    printf("\t\tP01           Coffee               50.00\n");
    printf("\t\tP02           Tea                  30.00\n");
    printf("\t\tP03           Hot Chocolate        60.00\n");
    printf("\t\tP04           Cappuccino           70.00\n");
    printf("\t\tP05           Espresso             80.00\n");
    printf("\t\tP06           Latte                90.00\n");
}

void askOrder(int *coffee, int *tea, int *hotChocolate, int *cappuccino, int *espresso, int *latte) {
    printf("\n\n");
    printf("\t\tEnter the quantity of each item:\n");
    printf("\t\tCoffee: ");
    scanf("%d", coffee);
    printf("\t\tTea: ");
    scanf("%d", tea);
    printf("\t\tHot Chocolate: ");
    scanf("%d", hotChocolate);
    printf("\t\tCappuccino: ");
    scanf("%d", cappuccino);
    printf("\t\tEspresso: ");
    scanf("%d", espresso);
    printf("\t\tLatte: ");
    scanf("%d", latte);
}

void calculateBill(int coffee, int tea, int hotChocolate, int cappuccino, int espresso, int latte, double *subtotal, double *tax, double *total) {
    *subtotal = (coffee * 50) + (tea * 30) + (hotChocolate * 60) + (cappuccino * 70) + (espresso * 80) + (latte * 90);
    *tax = *subtotal * 0.05;
    *total = *subtotal + *tax;
}

void printReceipt(int coffee, int tea, int hotChocolate, int cappuccino, int espresso, int latte, double subtotal, double tax, double total) {
    printf("\n\n");
    printf("\t\t========== RECEIPT ==========\n");
    printf("\t\tItem Code     Description          Price     Quantity   Total\n");
    if(coffee > 0) {
        double coffeeTotal = coffee * 50;
        printf("\t\tP01           Coffee             50.00        %d      %.2f\n", coffee, coffeeTotal);
    }
    if(tea > 0) {
        double teaTotal = tea * 30;
        printf("\t\tP02           Tea                30.00        %d      %.2f\n", tea, teaTotal);
    }
    if(hotChocolate > 0) {
        double hotChocolateTotal = hotChocolate * 60;
        printf("\t\tP03           Hot Chocolate      60.00        %d      %.2f\n", hotChocolate, hotChocolateTotal);
    }
    if(cappuccino > 0) {
        double cappuccinoTotal = cappuccino * 70;
        printf("\t\tP04           Cappuccino         70.00        %d      %.2f\n", cappuccino, cappuccinoTotal);
    }
    if(espresso > 0) {
        double espressoTotal = espresso * 80;
        printf("\t\tP05           Espresso           80.00        %d      %.2f\n", espresso, espressoTotal);
    }
    if(latte > 0) {
        double latteTotal = latte * 90;
        printf("\t\tP06           Latte              90.00        %d      %.2f\n", latte, latteTotal);
    }
    printf("\t\t\t\t\t\t\t\t--------\n");
    printf("\t\t\t\t\t\t\tSUBTOTAL:   %.2f\n", subtotal);
    printf("\t\t\t\t\t\t\tTAX:        %.2f\n", tax);
    printf("\t\t\t\t\t\t\t========\n");
    printf("\t\t\t\t\t\t\tTOTAL:      %.2f\n\n", total);
}

int main() {
    int coffee = 0, tea = 0, hotChocolate = 0, cappuccino = 0, espresso = 0, latte = 0;
    double subtotal, tax, total;
    displayMenu();
    askOrder(&coffee, &tea, &hotChocolate, &cappuccino, &espresso, &latte);
    calculateBill(coffee, tea, hotChocolate, cappuccino, espresso, latte, &subtotal, &tax, &total);
    printReceipt(coffee, tea, hotChocolate, cappuccino, espresso, latte, subtotal, tax, total);
    return 0;
}