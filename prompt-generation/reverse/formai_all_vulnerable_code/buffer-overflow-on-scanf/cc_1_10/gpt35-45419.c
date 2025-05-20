//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold the details of each item in the menu
struct item {
    int id;
    char name[50];
    float price;
};

// function to display the menu items
void display_menu(struct item menu[], int size) {
    printf("Menu:\n");
    printf("ID\tName\t\tPrice\n");
    for(int i=0; i<size; i++) {
        printf("%d\t%s\t\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// main function
int main() {
    // initialize the menu items
    struct item menu[5];
    menu[0].id = 1;
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 2.5;
    menu[1].id = 2;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 2.0;
    menu[2].id = 3;
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 5.0;
    menu[3].id = 4;
    strcpy(menu[3].name, "Cake");
    menu[3].price = 3.5;
    menu[4].id = 5;
    strcpy(menu[4].name, "Juice");
    menu[4].price = 3.0;

    // display the menu items
    display_menu(menu, 5);

    // take the user's order
    int order_ids[10];
    int order_quantities[10];
    int num_items = 0;
    char choice = 'y';
    while(choice == 'y') {
        printf("Enter the ID of the item you wish to order: ");
        int id;
        scanf("%d", &id);
        
        // check if the id is valid
        int valid_id = 0;
        for(int i=0; i<5; i++) {
            if(menu[i].id == id) {
                valid_id = 1;
                break;
            }
        }
        if(!valid_id) {
            printf("Invalid input. Please enter a valid ID.\n");
            continue;
        }

        printf("Enter the quantity of the item: ");
        int quantity;
        scanf("%d", &quantity);

        // add the order to the order list
        order_ids[num_items] = id;
        order_quantities[num_items] = quantity;
        num_items++;

        printf("Do you want to order anything else? (y/n): ");
        getchar();
        choice = getchar();
        printf("\n");
    }

    // calculate the billing amount
    float total_amount = 0;
    printf("Your order summary:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for(int i=0; i<num_items; i++) {
        // find the item in menu
        struct item ordered_item;
        for(int j=0; j<5; j++) {
            if(menu[j].id == order_ids[i]) {
                ordered_item = menu[j];
                break;
            }
        }

        // calculate the item amount
        float item_amount = ordered_item.price * order_quantities[i];
        total_amount += item_amount;

        printf("%d\t%s\t\t%d\t\t%.2f\n", ordered_item.id, ordered_item.name, order_quantities[i], item_amount);
    }

    printf("Total amount: %.2f\n", total_amount);

    return 0;
}