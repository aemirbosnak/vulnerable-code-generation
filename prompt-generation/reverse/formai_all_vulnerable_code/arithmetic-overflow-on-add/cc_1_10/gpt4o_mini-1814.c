//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} MenuItem;

MenuItem menu[MAX_ITEMS];

void initializeMenu() {
    snprintf(menu[0].name, MAX_NAME_LEN, "Coffee");
    menu[0].price = 2.50;
    menu[0].quantity = 0;

    snprintf(menu[1].name, MAX_NAME_LEN, "Tea");
    menu[1].price = 1.50;
    menu[1].quantity = 0;

    snprintf(menu[2].name, MAX_NAME_LEN, "Sandwich");
    menu[2].price = 5.00;
    menu[2].quantity = 0;

    snprintf(menu[3].name, MAX_NAME_LEN, "Cake");
    menu[3].price = 3.00;
    menu[3].quantity = 0;

    snprintf(menu[4].name, MAX_NAME_LEN, "Water");
    menu[4].price = 1.00;
    menu[4].quantity = 0;

    printf("Our menu is so diverse, even a chameleon would get confused!\n");
}

void printMenu() {
    printf("\nWelcome to the Silly Cafe!\n");
    printf("Here's our menu:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu[i].price != 0) {
            printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
        }
    }
    printf("Select a menu item by entering the corresponding number! Or be wild and write '0'!\n\n");
}

void takeOrder() {
    int choice = -1;
    while (choice != 0) {
        printMenu();
        scanf("%d", &choice);

        if (choice > 0 && choice <= MAX_ITEMS && menu[choice - 1].price != 0) {
            printf("How many %s would you like? (Stop being greedy now!)\n", menu[choice - 1].name);
            int qty;
            scanf("%d", &qty);
            menu[choice - 1].quantity += qty;

            printf("You have ordered %d %s(s)!\n", qty, menu[choice - 1].name);
        } else if (choice == 0) {
            printf("You wish to escape? It's too late now, you've entered the Silly Cafe!\n");
            break;
        } else {
            printf("Oops! Invalid choice. Looks like your brain is on a coffee break!\n");
        }
    }
}

void generateBill() {
    float total = 0.0;
    printf("\nHere comes the bill, hope you brought your funny money!\n");
    printf("--------------------------------------\n");
    printf("Item\t\tQty\tPrice\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu[i].quantity > 0) {
            printf("%s\t\t%d\t$%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
            total += menu[i].price * menu[i].quantity;
        }
    }
    printf("--------------------------------------\n");
    printf("Total:\t\t\t$%.2f\n", total);
    printf("Thank you for your order! May your coffee be strong and your jokes be strong-er!\n");
}

int main() {
    printf("Welcome to the Silly Cafe Billing System!\n");
    printf("Initializing menu... get ready to be amazed!\n");
    initializeMenu();
    takeOrder();
    generateBill();
    
    printf("Don't forget to tell your friends about us - or at least the funny stories!\n");
    return 0;
}