//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

struct Expense
{
    char name[20];
    int amount;
    struct Expense* next;
};

void addExpense(struct Expense** head)
{
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    printf("Enter expense name: ");
    scanf("%s", newExpense->name);
    printf("Enter expense amount: ");
    scanf("%d", &newExpense->amount);
    newExpense->next = NULL;

    if (*head == NULL)
    {
        *head = newExpense;
    }
    else
    {
        (*head)->next = newExpense;
    }
}

void displayExpenses(struct Expense* head)
{
    while (head)
    {
        printf("%s - %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    struct Expense* head = NULL;
    int choice = 0;

    while (choice != 3)
    {
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addExpense(&head);
                break;
            case 2:
                displayExpenses(head);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}