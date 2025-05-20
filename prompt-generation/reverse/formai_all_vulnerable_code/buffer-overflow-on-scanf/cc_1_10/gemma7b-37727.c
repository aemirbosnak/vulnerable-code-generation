//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Expense
{
    char name[50];
    int amount;
    struct Expense* next;
} Expense;

void insert(Expense**, int, char*);

int main()
{
    Expense* head = NULL;
    int i = 0;
    char name[50];
    int amount;

    printf("Welcome to your personal expense tracker!\n");
    printf("------------------------\n");

    // Loop to insert expenses
    while (i < MAX)
    {
        printf("Enter the name of the expense: ");
        scanf("%s", name);

        printf("Enter the amount of the expense: ");
        scanf("%d", &amount);

        insert(&head, amount, name);
        i++;
    }

    // Print the expenses
    printf("Here is a list of your expenses:\n");
    for (Expense* current = head; current; current = current->next)
    {
        printf("Name: %s, Amount: %d\n", current->name, current->amount);
    }

    return 0;
}

void insert(Expense** head, int amount, char* name)
{
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));

    strcpy(newExpense->name, name);
    newExpense->amount = amount;

    if (*head == NULL)
    {
        *head = newExpense;
    }
    else
    {
        (*head)->next = newExpense;
        *head = newExpense;
    }
}