//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void expense_form(void)
{
    system("clear");

    printf("Please enter the expense category:");
    char category[20];
    scanf("%s", category);

    printf("Please enter the expense amount:");
    int amount;
    scanf("%d", &amount);

    printf("Please enter the expense description:");
    char description[100];
    scanf("%s", description);

    FILE *fp;
    fp = fopen("expenses.txt", "a");
    fprintf(fp, "%s, %d, %s\n", category, amount, description);
    fclose(fp);

    printf("Expense added successfully!\n");
    system("pause");
}

int main()
{
    int choice;

    printf("Welcome to the Expense Tracker!\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("Enter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            expense_form();
            break;
        case 2:
            // Implement view expenses function
            break;
    }

    return 0;
}