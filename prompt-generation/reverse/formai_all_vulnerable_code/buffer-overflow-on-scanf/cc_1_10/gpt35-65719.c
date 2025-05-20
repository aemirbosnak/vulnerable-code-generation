//FormAI DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    int day;
    int month;
    int year;
    char item[50];
    double amount;
};

void print_expense(struct Expense expense) {
    printf("%02d/%02d/%04d | %23s | $%.2lf\n", expense.day, expense.month, expense.year, expense.item, expense.amount);
}

void print_divider() {
    printf("-------------------------|-----------------------|---------\n");
}

int main() {
    struct Expense expenses[100];
    int num_expenses = 0;

    while (1) {
        printf("What wilt thou expendeth, good sir knight?\n");

        char item[50];
        double amount;
        int day, month, year;

        printf("Name of the item: ");
        scanf("%s", item);

        printf("Amount spent in gold coins: ");
        scanf("%lf", &amount);

        printf("What day dideth thou spendeth it upon? Enter the day number: ");
        scanf("%d", &day);

        printf("What month of the year was it spent? Enter the month number: ");
        scanf("%d", &month);

        printf("And what year, in the name of the king? Enter the year in 4 digits: ");
        scanf("%d", &year);

        struct Expense expense = {day, month, year, item, amount};
        expenses[num_expenses++] = expense;

        print_divider();
        printf("Item                    | Date                  | Amount  \n");
        print_divider();

        for (int i = 0; i < num_expenses; i++) {
            print_expense(expenses[i]);
        }

        print_divider();

        printf("Wouldst thou like to add another expenditure, my lord? Y/N: ");
        char choice[2];
        scanf("%s", choice);

        if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0) {
            break;
        }
    }

    printf("Farewell, my liege.\n");
    
    return 0;
}