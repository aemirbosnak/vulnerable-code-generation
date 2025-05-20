//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[100];
    int quantity;
    float price;
} item;

item menu[100];
int num_items = 0;

void add_item() {
    char name[100];
    int quantity;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    printf("Enter item price: ");
    scanf("%f", &price);

    strcpy(menu[num_items].name, name);
    menu[num_items].quantity = quantity;
    menu[num_items].price = price;

    num_items++;
}

void display_menu() {
    int i;

    printf("\nMENU\n");
    for (i = 0; i < num_items; i++) {
        printf("%d. %s - %d x $%.2f = $%.2f\n", i+1, menu[i].name, menu[i].quantity, menu[i].price, menu[i].price * menu[i].quantity);
    }
}

void place_order() {
    int choice;
    float total = 0;

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_items) {
        total += menu[choice-1].price * menu[choice-1].quantity;
        printf("\nYour order of %s has been placed.\n", menu[choice-1].name);
    } else {
        printf("\nInvalid choice.\n");
    }

    printf("\nTotal cost: $%.2f\n", total);
}

int main() {
    int choice;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please choose an option:\n");
    printf("1. Add item to menu\n");
    printf("2. Display menu\n");
    printf("3. Place order\n");
    printf("4. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_menu();
                break;
            case 3:
                place_order();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}