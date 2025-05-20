//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int type; // 1 for income, -1 for expense
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, float amount, int type) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].amount = amount;
    items[num_items].type = type;

    num_items++;
}

void view_items() {
    printf("\nCurrent Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %.2f %s\n", items[i].name, items[i].amount, items[i].type > 0 ? "Income" : "Expense");
    }
}

void delete_item(int index) {
    if (index < 0 || index >= num_items) {
        printf("Error: Invalid index.\n");
        return;
    }

    for (int i = index; i < num_items - 1; i++) {
        items[i] = items[i + 1];
    }

    num_items--;
}

void calculate_totals() {
    float total = 0;
    int num_expenses = 0;

    for (int i = 0; i < num_items; i++) {
        total += items[i].amount;
        if (items[i].type < 0) {
            num_expenses++;
        }
    }

    float savings = total + (num_expenses * 30); // Assuming an average savings of 30% on expenses
    printf("\nTotal Balance: %.2f", total);
    printf("\nTotal Savings: %.2f", savings);
}

int main() {
    char name[50];
    float amount;
    int choice, type;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Delete Item\n");
        printf("4. Calculate Totals\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter type (1 for income, -1 for expense): ");
                scanf("%d", &type);
                add_item(name, amount, type);
                break;
            case 2:
                view_items();
                break;
            case 3:
                printf("Enter index to delete: ");
                scanf("%d", &choice);
                delete_item(choice);
                break;
            case 4:
                calculate_totals();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}