//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 20
#define MAX_PRICE 6
#define MAX_MENU 100

struct menu_item {
    char name[MAX_NAME];
    char description[MAX_MENU];
    float price;
};

struct order {
    int num_items;
    struct menu_item *items;
};

void add_item(struct menu_item *menu, int *num_items) {
    char name[MAX_NAME];
    char description[MAX_MENU];
    float price;

    printf("Enter the name of the item: ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter the description of the item: ");
    fgets(description, MAX_MENU, stdin);
    description[strcspn(description, "\n")] = '\0';

    printf("Enter the price of the item: ");
    scanf("%f", &price);

    strcpy(menu[*num_items].name, name);
    strcpy(menu[*num_items].description, description);
    menu[*num_items].price = price;

    (*num_items)++;
}

void display_menu(struct menu_item *menu, int num_items) {
    printf("\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

int main() {
    struct menu_item menu[MAX_ITEMS];
    int num_items = 0;

    add_item(menu, &num_items);
    add_item(menu, &num_items);
    add_item(menu, &num_items);

    int choice;
    printf("\nWelcome to our romantic cafe!\n\n");
    display_menu(menu, num_items);
    printf("\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= num_items) {
            printf("\nYou chose %s for $%.2f\n", menu[choice-1].name, menu[choice-1].price);
            break;
        } else {
            printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}