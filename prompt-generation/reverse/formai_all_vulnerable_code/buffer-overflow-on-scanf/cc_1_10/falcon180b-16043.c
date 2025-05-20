//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    float cost;
} item;

void add_item(item* items, int num_items, char* name, float cost) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].cost += cost;
            return;
        }
    }
    if (num_items < MAX_ITEMS) {
        strcpy(items[num_items].name, name);
        items[num_items].cost = cost;
        num_items++;
    }
}

void print_items(item* items, int num_items) {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s: $%.2f\n", items[i].name, items[i].cost);
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;
    char name[MAX_NAME_LEN];
    float cost;

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("Enter the name of the expense: ");
        scanf("%s", name);

        printf("Enter the cost of the expense: $");
        scanf("%f", &cost);

        add_item(items, num_items, name, cost);

        printf("\nExpense added successfully!\n");

        int choice;
        printf("Would you like to: \n1. Add another expense\n2. Print expenses\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                break;
            case 2:
                print_items(items, num_items);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}