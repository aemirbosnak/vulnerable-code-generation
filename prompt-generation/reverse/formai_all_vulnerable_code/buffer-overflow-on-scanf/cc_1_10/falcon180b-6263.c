//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    float price;
} item;

void add_item(item *menu, int *count) {
    char name[MAX_NAME];
    float price;

    printf("Enter item name: ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter item price: $");
    scanf("%f", &price);

    strcpy(menu[*count].name, name);
    menu[*count].price = price;

    (*count)++;
}

void display_menu(item *menu, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%-20s $%.2f\n", menu[i].name, menu[i].price);
    }
}

void calculate_total(item *menu, int count, float *total) {
    int i;

    *total = 0;

    for (i = 0; i < count; i++) {
        *total += menu[i].price;
    }
}

int main() {
    int count = 0;
    item menu[MAX_ITEMS];
    float total = 0;

    printf("Welcome to the Cafe Billing System!\n");

    while (count < MAX_ITEMS) {
        printf("\nDo you want to add an item to the menu? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_item(menu, &count);
        } else {
            break;
        }
    }

    printf("\nMenu:\n");
    display_menu(menu, count);

    printf("\nTotal: $%.2f\n", total);

    return 0;
}