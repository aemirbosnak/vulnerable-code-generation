//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} menu_item;

menu_item menu[MAX_ITEMS];

void populate_menu() {
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 2.25;

    strcpy(menu[1].name, "Tea");
    menu[1].price = 1.75;

    strcpy(menu[2].name, "Juice");
    menu[2].price = 3.00;
}

void print_menu() {
    printf("Menu:\n");
    for(int i = 0; i < MAX_ITEMS; i++) {
        if(strcmp(menu[i].name, "") != 0) {
            printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
        }
    }
}

void place_order() {
    int choice;
    int quantity;

    printf("Enter the item number: ");
    scanf("%d", &choice);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    if(choice < 1 || choice > MAX_ITEMS || strcmp(menu[choice-1].name, "") == 0) {
        printf("Invalid choice.\n");
        return;
    }

    float price = menu[choice-1].price * quantity;
    printf("%d x %s - $%.2f\n", quantity, menu[choice-1].name, price);
}

int main() {
    populate_menu();
    int choice;

    do {
        printf("Welcome to C Cafe!\n");
        printf("Please select an option:\n");
        printf("1. View menu\n");
        printf("2. Place order\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_menu();
                break;
            case 2:
                place_order();
                break;
            case 3:
                printf("Thank you for visiting C Cafe!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}