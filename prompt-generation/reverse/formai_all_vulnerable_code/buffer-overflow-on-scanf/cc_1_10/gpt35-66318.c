//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to store menu items
struct MenuItem {
    int id;
    char name[20];
    float price;
};

// function to print menu
void print_menu(struct MenuItem menu[], int n)
{
    printf("ID\tName\t\tPrice\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t$%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

int main()
{
    // initialize menu items
    struct MenuItem menu[6];
    menu[0].id = 1;
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 1.50;
    menu[1].id = 2;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 1.00;
    menu[2].id = 3;
    strcpy(menu[2].name, "Bagel");
    menu[2].price = 2.00;
    menu[3].id = 4;
    strcpy(menu[3].name, "Muffin");
    menu[3].price = 1.50;
    menu[4].id = 5;
    strcpy(menu[4].name, "Croissant");
    menu[4].price = 2.50;
    menu[5].id = 6;
    strcpy(menu[5].name, "Juice");
    menu[5].price = 2.00;

    // print menu
    print_menu(menu, 6);

    // get order from user
    int item_id, quantity;
    float total = 0.0;
    char choice = 'y';
    while (choice == 'y') {
        printf("Enter item ID: ");
        scanf("%d", &item_id);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // calculate total cost of order
        for (int i = 0; i < 6; i++) {
            if (menu[i].id == item_id) {
                total += menu[i].price * quantity;
                break;
            }
        }

        printf("Add another item? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Total cost: $%.2f\n", total);

    return 0;
}