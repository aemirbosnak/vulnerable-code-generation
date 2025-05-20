//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME 50
#define MAX_PRICE 50

struct item {
    char name[MAX_NAME];
    float price;
};

void add_item(struct item items[], int size) {
    printf("Enter item name: ");
    scanf("%s", items[size].name);
    printf("Enter item price: ");
    scanf("%f", &items[size].price);
}

void print_menu(struct item items[], int size) {
    printf("Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void take_order(struct item items[], int size) {
    int choice;
    float total = 0.0;

    printf("Enter your order (item number): ");
    scanf("%d", &choice);

    while (choice >= 1 && choice <= size) {
        total += items[choice-1].price;
        printf("Would you like to add another item? (y/n): ");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'n') {
            break;
        }
        printf("Enter item number: ");
        scanf("%d", &choice);
    }

    printf("Total cost: $%.2f\n", total);
}

int main() {
    struct item menu[MAX_ITEMS];
    int size = 0;

    add_item(menu, size);
    while (1) {
        print_menu(menu, size);
        int choice;
        printf("Enter your choice:\n1. Add item\n2. Place order\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(menu, size);
                break;
            case 2:
                take_order(menu, size);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}