//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int price;
} item;

item items[MAX_ITEMS];
int num_items = 0;

void add_item(char* name, int price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    num_items++;
}

void print_menu() {
    printf("Cafe Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%d\n", i+1, items[i].name, items[i].price);
    }
}

void take_order() {
    int choice;
    char name[50];
    int quantity;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Select an item from the menu:\n");
    print_menu();
    scanf("%d", &choice);

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    printf("You ordered %d %s(s) for a total of $%d.\n", quantity, items[choice-1].name, quantity * items[choice-1].price);
}

int main() {
    add_item("Coffee", 3);
    add_item("Tea", 2);
    add_item("Pastry", 4);

    int choice;

    while (1) {
        printf("Welcome to the cafe!\n");
        printf("1. Order\n2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            take_order();
        } else if (choice == 2) {
            printf("Thank you for visiting!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}