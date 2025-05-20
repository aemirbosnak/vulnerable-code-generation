//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ITEMS 50

struct item {
    char name[50];
    float price;
};

void add_item(struct item *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    (*num_items)++;
}

void print_items(struct item *items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void calculate_total(struct item *items, int num_items, float *total) {
    for (int i = 0; i < num_items; i++) {
        *total += items[i].price;
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;
    float total = 0.0;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Enter 1 to add an item\n");
    printf("Enter 2 to print the menu\n");
    printf("Enter 3 to calculate the total\n");
    printf("Enter 4 to exit\n");

    int choice;
    while (choice!= 4) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                print_items(items, num_items);
                break;
            case 3:
                calculate_total(items, num_items, &total);
                printf("Total: $%.2f\n", total);
                break;
            case 4:
                printf("Thank you for using the Cafe Billing System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}