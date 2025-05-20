//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item {
    char name[50];
    int price;
    int quantity;
};

int main() {
    struct item menu[5]; // create an array of 5 items in the menu
    strcpy(menu[0].name, "Coffee"); // set name of item 1 in the menu
    menu[0].price = 50; // set price of item 1 in the menu
    menu[0].quantity = 10; // set number of item 1 in the inventory
    strcpy(menu[1].name, "Tea"); // set name of item 2 in the menu
    menu[1].price = 30; // set price of item 2 in the menu
    menu[1].quantity = 15; // set number of item 2 in the inventory
    strcpy(menu[2].name, "Sandwich"); // set name of item 3 in the menu
    menu[2].price = 80; // set price of item 3 in the menu
    menu[2].quantity = 5; // set number of item 3 in the inventory
    strcpy(menu[3].name, "Burger"); // set name of item 4 in the menu
    menu[3].price = 100; // set price of item 4 in the menu
    menu[3].quantity = 6; // set number of item 4 in the inventory
    strcpy(menu[4].name, "Muffin"); // set name of item 5 in the menu
    menu[4].price = 60; // set price of item 5 in the menu
    menu[4].quantity = 10; // set number of item 5 in the inventory
    
    int bill = 0;
    int choice;
    int qty;
    printf("Welcome to C Cafe!\n");
    do {
        printf("Menu:\n");
        for (int i = 0; i < 5; i++) { // print out the menu
            printf("%d. %s - %d\n", i+1, menu[i].name, menu[i].price);
        }
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 6) { // exit program if choice is 6
            break;
        }
        printf("Enter the quantity: ");
        scanf("%d", &qty);
        if (qty > menu[choice-1].quantity) { // check if there is enough item
            printf("Sorry, we don't have enough %s.\n", menu[choice-1].name);
        } else {
            menu[choice-1].quantity -= qty; // decrease the quantity in the inventory
            bill += menu[choice-1].price * qty; // calculate the bill
        }
    } while (choice != 6);
    printf("Your total bill is: %d\n", bill);
    printf("Thank you for visiting C Cafe!\n");
    return 0;
}