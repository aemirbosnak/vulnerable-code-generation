//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME 50
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    float price;
} item;

item menu[MAX_ITEMS];
int num_items;

void add_item(char* name, float price) {
    strcpy(menu[num_items].name, name);
    menu[num_items].price = price;
    num_items++;
}

void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

int main() {
    int choice;
    float total = 0;
    char name[MAX_NAME];

    num_items = 0;
    add_item("Coffee", 2.50);
    add_item("Tea", 1.75);
    add_item("Cake", 3.50);

    while (1) {
        printf("Welcome to the Cafe!\n");
        printf("Please enter your name: ");
        scanf("%s", name);

        printf("\n%s, here is our menu:\n", name);
        print_menu();

        printf("\nPlease choose an item:\n");
        scanf("%d", &choice);
        if (choice < 1 || choice > num_items) {
            printf("Invalid choice.\n");
            continue;
        }

        total += menu[choice-1].price;
        printf("\nYou ordered %s for $%.2f.\n", menu[choice-1].name, menu[choice-1].price);
        printf("Your total is $%.2f.\n\n", total);
    }

    return 0;
}