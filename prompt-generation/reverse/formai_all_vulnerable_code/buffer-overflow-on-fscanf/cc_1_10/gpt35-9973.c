//FormAI DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void display_menu();
void add_expense();
void view_expense();
void delete_expense();

int main()
{
    display_menu();
    return 0;
}

void display_menu()
{
    int option;

    printf("Welcome to the Expense Tracker!\n");
    printf("1. Add Expense\n");
    printf("2. View Expense\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("Choose your option: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            add_expense();
            break;
        case 2:
            view_expense();
            break;
        case 3:
            delete_expense();
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid option!\n");
            display_menu();
    }
}

void add_expense()
{

    char expense[100];
    float amount;
    int choice;

    printf("Enter Expense Description: ");
    scanf("%s", &expense);
    printf("Enter Expense Amount: ");
    scanf("%f", &amount);

    FILE *fp = fopen("expenses.txt", "a");
    if (fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    fprintf(fp, "%s %.2f\n", expense, amount);

    printf("Expense added successfully!\n");

    fclose(fp);

    printf("Would you like to add another expense? (1 for Yes / 0 for No): ");
    scanf("%d", &choice);

    if (choice == 1)
        add_expense();
    else if (choice == 0)
        display_menu();
    else
        printf("Invalid choice!\n");

}

void view_expense()
{
    char temp[100];
    float amount;

    FILE *fp = fopen("expenses.txt", "r");
    if (fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    printf("------------------------------------------------\n");
    printf("|             Expense Tracker Report           |\n");
    printf("------------------------------------------------\n");

    while(fscanf(fp, "%s %f", temp, &amount) != EOF)
    {
        printf("|  %-20s  |  $%-18.2f  |\n", temp, amount);
    }

    printf("------------------------------------------------\n");

    fclose(fp);

    printf("\n\n");

    display_menu();
}

void delete_expense()
{
    int line_to_delete;
    int current_line = 1;
    char temp[100];
    float amount;

    FILE *fp = fopen("expenses.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");

    if (fp == NULL || temp_file == NULL)
    {
        printf("Unable to open file(s)!\n");
        return;
    }

    printf("Enter line number to be deleted: ");
    scanf("%d", &line_to_delete);

    while(fscanf(fp, "%s %f", temp, &amount) != EOF)
    {
        if (current_line != line_to_delete)
            fprintf(temp_file, "%s %.2f\n", temp, amount);

        current_line++;
    }

    fclose(fp);
    fclose(temp_file);

    remove("expenses.txt");
    rename("temp.txt", "expenses.txt");

    printf("Expense deleted successfully!\n\n");

    display_menu();
}