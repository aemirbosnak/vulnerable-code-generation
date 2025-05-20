//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, i, year, month, day, amount, total = 0, flag = 0, count = 0;
    FILE *fp;
    char ch, filename[20];

    printf("Welcome to Expense Tracker\n");

    while (1)
    {
        printf("\nPlease select an option:\n");
        printf("1. Add Expense\n");
        printf("2. Delete Expense\n");
        printf("3. View Expenses\n");
        printf("4. View Total Expenses\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("\nPlease enter the date of expense (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);

                printf("\nPlease enter the amount of the expense: ");
                scanf("%d", &amount);

                sprintf(filename, "%d-%d-%d.txt", year, month, day);
                fp = fopen(filename, "a+");

                if (fp == NULL)
                {
                    printf("\nError opening file");
                    break;
                }

                fprintf(fp, "%d\n", amount);
                fclose(fp);

                printf("\nExpense added successfully!");

                break;

            case 2:

                printf("\nPlease enter the date of expense to be deleted (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);

                sprintf(filename, "%d-%d-%d.txt", year, month, day);
                fp = fopen(filename, "r");

                if (fp == NULL)
                {
                    printf("\nError opening file");
                    break;
                }

                while (feof(fp) == 0)
                {
                    fscanf(fp, "%d", &i);

                    if (i != amount)
                        fprintf(fp, "%d\n", i);
                    else
                        flag = 1;
                }

                fclose(fp);

                if (flag == 1)
                    printf("\nExpense deleted successfully!");
                else
                    printf("\nExpense not found!");

                break;

            case 3:

                printf("\nPlease enter the date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);

                sprintf(filename, "%d-%d-%d.txt", year, month, day);
                fp = fopen(filename, "r");

                if (fp == NULL)
                {
                    printf("\nNo expenses for the selected date.");
                    break;
                }

                printf("\nExpenses for %d-%d-%d", day, month, year);

                while (feof(fp) == 0)
                {
                    fscanf(fp, "%d", &i);
                    printf("\n%d", i);
                    total += i;
                    count++;
                }

                fclose(fp);

                if (count == 0)
                    printf("\nNo expenses for the selected date.");
                else
                    printf("\nTotal Expenses: %d", total);

                break;

            case 4:

                total = 0;

                printf("\nPlease enter the month and year (mm yyyy): ");
                scanf("%d %d", &month, &year);

                printf("\nExpenses for %d-%d", month, year);

                for (day = 1; day <= 31; day++)
                {
                    sprintf(filename, "%d-%d-%d.txt", year, month, day);
                    fp = fopen(filename, "r");

                    if (fp != NULL)
                    {
                        while (feof(fp) == 0)
                        {
                            fscanf(fp, "%d", &i);
                            total += i;
                        }

                        fclose(fp);
                    }
                }

                printf("\nTotal Expenses: %d", total);

                break;

            case 5:

                printf("\nExiting program...");
                exit(0);

                break;

            default:

                printf("\nInvalid choice selected. Please try again.");

                break;
        }
    }

    return 0;
}