//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
};

void add_item(struct item items[], int count) {
    printf("Enter item name: ");
    scanf("%s", items[count].name);

    printf("Enter item price: $");
    scanf("%f", &items[count].price);
}

void display_menu(struct item items[], int count) {
    printf("\nMenu:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void take_order(struct item items[], int count) {
    int choice;
    float total = 0.0;

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= count) {
        total += items[choice-1].price;
        printf("\nYou ordered %s for $%.2f\n", items[choice-1].name, items[choice-1].price);
    } else {
        printf("\nInvalid choice!");
    }

    printf("\nTotal bill: $%.2f\n", total);
}

int main() {
    struct item menu[MAX_ITEMS];
    int count = 0;

    printf("\nWelcome to Sherlock's Cafe!\n");

    while (count < MAX_ITEMS) {
        add_item(menu, count);
        count++;
    }

    while (1) {
        display_menu(menu, count);

        int choice;
        printf("\nDo you want to order? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            take_order(menu, count);
        } else if (choice == 'n' || choice == 'N') {
            printf("\nThank you for visiting Sherlock's Cafe!\n");
            break;
        } else {
            printf("\nInvalid choice!");
        }
    }

    return 0;
}