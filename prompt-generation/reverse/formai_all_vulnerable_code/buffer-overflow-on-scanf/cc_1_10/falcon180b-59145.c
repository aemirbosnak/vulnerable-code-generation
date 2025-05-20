//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE_TYPES 20
#define MAX_EXPENSE_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} expense_item_t;

typedef struct {
    char name[50];
    int num_items;
    expense_item_t items[MAX_EXPENSE_ITEMS];
} expense_type_t;

int main() {
    int num_types = 0;
    expense_type_t types[MAX_EXPENSE_TYPES];

    printf("Welcome to the expense tracker!\n\n");

    while (1) {
        printf("\n");
        printf("1. Add expense type\n");
        printf("2. Add expense item\n");
        printf("3. View expenses by type\n");
        printf("4. View expenses by month\n");
        printf("5. Quit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter expense type name: ");
            scanf("%s", types[num_types].name);
            types[num_types].num_items = 0;
            num_types++;
            break;

        case 2:
            printf("Enter expense type name: ");
            scanf("%s", types[num_types].name);
            printf("Enter expense item name: ");
            scanf("%s", types[num_types].items[types[num_types].num_items].name);
            printf("Enter expense item amount: $");
            scanf("%f", &types[num_types].items[types[num_types].num_items].amount);
            types[num_types].num_items++;
            break;

        case 3:
            printf("Enter expense type name: ");
            scanf("%s", types[num_types].name);
            printf("\nExpense type: %s\n", types[num_types].name);
            for (int i = 0; i < types[num_types].num_items; i++) {
                printf("Item %d: %s - $%.2f\n", i+1, types[num_types].items[i].name, types[num_types].items[i].amount);
            }
            break;

        case 4:
            printf("Enter month (mm/yyyy): ");
            scanf("%s", types[num_types].name);
            break;

        case 5:
            printf("Thanks for using the expense tracker!\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}