//FormAI DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct expense {
    char item[50];
    float cost;
} Expense;

void clear() // clear the console
{
    system("clear"); // change to "cls" in Windows
}

float calculateTotal(Expense expenses[], int count) // calculate the total cost of expenses
{
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].cost;
    }
    return total;
}

void printExpenses(Expense expenses[], int count) // print all expenses
{
    printf("\n");
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f\n", expenses[i].item, expenses[i].cost);
    }
    printf("\n");
}

int main() {
    int choice = 0;
    int count = 0;
    Expense expenses[100];
    clear();
    while (1) // loop forever until user chooses to quit
    {
        printf("Expense Tracker Menu:\n");
        printf("1. Add expense\n");
        printf("2. Print all expenses\n");
        printf("3. Calculate total cost of expenses\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                clear();
                printf("Add Expense:\n");
                printf("Enter item name: ");
                scanf("%s", expenses[count].item);
                printf("Enter cost: ");
                scanf("%f", &expenses[count].cost);
                count++;
                clear();
                break;
            case 2:
                clear();
                printExpenses(expenses, count);
                break;
            case 3:
                clear();
                printf("Total cost of expenses: $%.2f\n", calculateTotal(expenses, count));
                break;
            case 4:
                clear();
                printf("Thank you for using the expense tracker!\n");
                return 0;
            default:
                clear();
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}