//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50

struct item {
    char name[20];
    double price;
};

struct item menu[MAX_ITEMS] = {
    {"Coffee", 2.50},
    {"Tea", 1.75},
    {"Soda", 1.25},
    {"Juice", 2.00},
    {"Pastry", 1.50},
    {"Sandwich", 3.50},
    {"Salad", 4.50},
    {"Chips", 1.00},
    {"Candy", 0.75},
    {"Water", 1.00}
};

int main() {
    int numItems = 0;
    double total = 0.00;

    printf("Welcome to the Cafe!\n");

    while (1) {
        printf("\nPlease select an item:\n");
        for (int i = 0; i < numItems; i++) {
            printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
        }
        printf("%d. Check out\n", numItems+1);

        int choice;
        scanf("%d", &choice);

        if (choice == numItems+1) {
            break;
        } else if (choice >= 1 && choice <= numItems) {
            total += menu[choice-1].price;
            printf("\nYou ordered a %s for $%.2f.\n", menu[choice-1].name, menu[choice-1].price);
            numItems++;
        } else {
            printf("\nInvalid selection.\n");
        }
    }

    printf("\nYour total is $%.2f.\n", total);
    printf("Thank you for visiting the Cafe!\n");

    return 0;
}