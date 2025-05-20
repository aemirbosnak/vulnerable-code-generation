//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, n, choice, total = 0, flag = 0;
    char name[MAX];
    struct expense
    {
        char name[MAX];
        int amount;
        struct expense *next;
    } *head = NULL;

    printf("Welcome to your personal expense tracker!\n");

    // Loop to get the number of expenses
    printf("How many expenses do you want to track? ");
    scanf("%d", &n);

    // Allocate memory for each expense
    for (i = 0; i < n; i++)
    {
        struct expense *new_expense = (struct expense *)malloc(sizeof(struct expense));
        new_expense->next = head;
        head = new_expense;
    }

    // Get the name and amount of each expense
    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the expense: ");
        scanf("%s", head->name);

        printf("Enter the amount of the expense: ");
        scanf("%d", &head->amount);

        head = head->next;
    }

    // Calculate the total expense
    for (head =  head->next; head; head = head->next)
    {
        total += head->amount;
    }

    // Print the total expense
    printf("Your total expense is: $%d\n", total);

    // Free the memory allocated for each expense
    for (head =  head->next; head; head = head->next)
    {
        free(head);
    }

    return 0;
}