//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} menu_item;

int num_items = 0;
menu_item items[MAX_ITEMS];

void add_item(char *name, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    num_items++;
}

void print_menu() {
    printf("MENU:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void take_order() {
    int choice;
    float total = 0;

    printf("Please enter your order:\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_items) {
        printf("Invalid choice.\n");
        return;
    }

    total += items[choice-1].price;

    printf("Your total is $%.2f.\n", total);
}

int main() {
    add_item("Coffee", 2.50);
    add_item("Tea", 1.75);
    add_item("Cake", 3.50);

    while (1) {
        print_menu();
        take_order();
    }

    return 0;
}