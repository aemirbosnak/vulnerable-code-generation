//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} item;

item items[MAX_ITEMS];
int num_items;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item amount: ");
    scanf("%s", items[num_items].amount);
    num_items++;
}

void display_items() {
    printf("Item\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\n", items[i].name, items[i].amount);
    }
}

void calculate_total() {
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        total += atof(items[i].amount);
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    num_items = 0;
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("\n");
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
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}