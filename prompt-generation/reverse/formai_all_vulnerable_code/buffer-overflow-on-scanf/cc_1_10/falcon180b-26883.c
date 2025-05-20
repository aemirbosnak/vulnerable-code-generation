//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 20
#define MAX_PRICE 10

struct item {
    char name[MAX_NAME];
    float price;
};

void add_item(struct item* items, int* num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: $");
    scanf("%f", &items[*num_items].price);
    (*num_items)++;
}

void display_menu(struct item* items, int num_items) {
    printf("Welcome to our cafe!\n");
    printf("Our menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void place_order(struct item* items, int num_items) {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_items) {
        printf("You chose %s - $%.2f\n", items[choice-1].name, items[choice-1].price);
    } else {
        printf("Invalid choice.\n");
    }
}

void calculate_bill(struct item* items, int num_items) {
    int choice;
    float bill = 0;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_items) {
        bill = items[choice-1].price;
        printf("Your bill is $%.2f\n", bill);
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    struct item menu[MAX_ITEMS];
    int num_items = 0;

    add_item(menu, &num_items);
    add_item(menu, &num_items);
    add_item(menu, &num_items);

    display_menu(menu, num_items);
    place_order(menu, num_items);
    calculate_bill(menu, num_items);

    return 0;
}