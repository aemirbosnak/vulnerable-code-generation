//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int type; // 0 for income, 1 for expense
} Item;

Item items[MAX_ITEMS];
int current_item = 0;

void add_item() {
    if (current_item >= MAX_ITEMS) {
        printf("Cannot add item. Reached maximum limit.\n");
        return;
    }

    printf("Enter name: ");
    fgets(items[current_item].name, sizeof(items[current_item].name), stdin);
    items[current_item].name[strcspn(items[current_item].name, "\n")] = '\0';

    printf("Enter amount: ");
    scanf("%f", &items[current_item].amount);

    printf("Enter type (0 for income, 1 for expense): ");
    scanf("%d", &items[current_item].type);

    current_item++;
}

void display_balance() {
    float balance = 0;

    printf("\nCurrent balance:\n");

    for (int i = 0; i < current_item; i++) {
        if (items[i].type == 0) {
            balance += items[i].amount;
            printf("%s: %.2f (Income)\n", items[i].name, items[i].amount);
        } else {
            balance -= items[i].amount;
            printf("%s: %.2f (Expense)\n", items[i].name, items[i].amount);
        }
    }

    printf("Total balance: %.2f\n", balance);
}

int main() {
    int choice;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add item\n");
        printf("2. Display balance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_balance();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}