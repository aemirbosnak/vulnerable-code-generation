//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void display_items() {
    printf("\nItem Name\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%f\n", items[i].name, items[i].price);
    }
}

void calculate_total() {
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price;
    }
    printf("\nTotal Expense: $%.2f\n", total);
}

int main() {
    printf("Welcome to Expense Tracker\n");
    printf("Enter 1 to add an item\n");
    printf("Enter 2 to display items\n");
    printf("Enter 3 to calculate total expense\n");
    printf("Enter 0 to exit\n");

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                calculate_total();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}