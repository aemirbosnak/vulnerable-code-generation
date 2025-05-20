//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>

#define MAX_EXPENSES 100

struct expense {
    char name[50];
    float amount;
    char category[50];
    char date[20];
};

void add_expense(struct expense *expenses, int index, char *name, float amount, char *category, char *date) {
    strcpy(expenses[index].name, name);
    expenses[index].amount = amount;
    strcpy(expenses[index].category, category);
    strcpy(expenses[index].date, date);
}

void print_expenses(struct expense *expenses, int count) {
    printf("Expense Name         | Amount | Category | Date\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s | $%5.2f | %-15s | %-15s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int count = 0;

    printf("Enter expense name: ");
    scanf("%s", expenses[count].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[count].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[count].category);
    printf("Enter expense date (mm/dd/yyyy): ");
    scanf("%s", expenses[count].date);
    count++;

    while (count < MAX_EXPENSES) {
        printf("Do you want to add another expense? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("Enter expense name: ");
            scanf("%s", expenses[count].name);
            printf("Enter expense amount: ");
            scanf("%f", &expenses[count].amount);
            printf("Enter expense category: ");
            scanf("%s", expenses[count].category);
            printf("Enter expense date (mm/dd/yyyy): ");
            scanf("%s", expenses[count].date);
            count++;
        } else {
            break;
        }
    }

    printf("Expenses:\n");
    print_expenses(expenses, count);

    return 0;
}