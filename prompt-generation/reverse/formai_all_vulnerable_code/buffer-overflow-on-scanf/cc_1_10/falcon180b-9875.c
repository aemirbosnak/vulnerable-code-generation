//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} item;

void add_item(item* items, int* num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item amount: ");
    scanf("%s", items[*num_items].amount);
    (*num_items)++;
}

void display_items(item* items, int num_items) {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %s\n", i+1, items[i].name, items[i].amount);
    }
}

void calculate_total(item* items, int num_items) {
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        total += atof(items[i].amount);
    }
    printf("\nTotal: %.2f\n", total);
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Personal Finance Planner!\n");
    while (1) {
        printf("\nOptions:\n1. Add item\n2. Display items\n3. Calculate total\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                calculate_total(items, num_items);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}