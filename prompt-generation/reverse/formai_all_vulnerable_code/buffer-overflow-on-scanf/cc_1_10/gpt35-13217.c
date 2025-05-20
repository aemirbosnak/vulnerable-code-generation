//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense{
    char category[50];
    float amount;
    char description[200];
};

int main()
{
    FILE *fp; //File pointer to access file
    char name[30], confirm_choice;
    int choice;
    float total_amount = 0;
    struct expense e; //Structure to store expense details

    printf("Welcome to Expense Tracker\n");

    printf("Please enter your name: ");
    scanf("%s", name);

    //Checking if the file exists otherwise,it creates new one
    fp = fopen(strcat(name,".txt"), "a+");
    if (fp==NULL)
    {
        printf("Error: Cannot read the file");
        exit(1);
    }

    printf("1. Add an expense\n2. View all expenses\n");
    scanf("%d", &choice);

    //Adding expense
    if (choice == 1)
    {
        printf("Enter expense category: ");
        scanf("%s", e.category);

        printf("Enter amount: ");
        scanf("%f", &e.amount);
        total_amount += e.amount;

        printf("Enter description: ");
        scanf(" %[^\n]s", e.description);

        fprintf(fp, "%s,%.2f,%s\n", e.category, e.amount, e.description);

        printf("Expense added successfully!\n");
    }

    //Viewing all expenses
    else if (choice == 2)
    {
        printf("\n Expense Category \t Amount \t Description\n");
        while (fscanf(fp, "%[^,],%f %[^\n]\n", e.category, &e.amount, e.description) != EOF)
        {
            printf("%-15s \t %.2f \t %s\n", e.category, e.amount, e.description);
            total_amount += e.amount;
        }
        printf("\nTotal expenses: %.2f\n", total_amount);
    }

    else
    {
        printf("\nInvalid choice!");
    }

    fclose(fp);

    return 0;
}