//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to display main menu
void displayMenu()
{
    printf("Welcome to Your Expense Tracker\n");
    printf("--------------------------------\n");
    printf("1. Add an Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete an Expense\n");
    printf("4. Exit\n");
}

// Function to add an expense
void addExpense(FILE *fp)
{
    char date[20], description[50];
    float amount;

    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%s", date);

    printf("Enter Description: ");
    scanf("%s", description);

    printf("Enter Amount: ");
    scanf("%f", &amount);

    // Append the expense to the file
    fprintf(fp, "%s %s %.2f\n", date, description, amount);

    printf("Expense Added Successfully!\n\n");
}

// Function to display all expenses
void viewExpenses(FILE *fp)
{
    char date[20], description[50];
    float amount;

    printf("\nDate\t\tDescription\tAmount\n");
    printf("----------------------------------------\n");

    // Read the data from the file and display it
    while(fscanf(fp, "%s %s %f\n", date, description, &amount) != EOF)
    {
        printf("%s\t%s\t%.2f\n", date, description, amount);
    }

    printf("\n");
}

// Function to delete an expense
void deleteExpense(FILE *fp)
{
    char date[20], description[50];
    float amount;

    char dateToDelete[20], descriptionToDelete[50];

    printf("Enter Date (dd/mm/yyyy) of Expense to Delete: ");
    scanf("%s", dateToDelete);

    printf("Enter Description of Expense to Delete: ");
    scanf("%s", descriptionToDelete);

    // Temporary file to hold data
    FILE *temp = fopen("temp.txt", "w");

    // Read the data from the file and delete the required expense
    while(fscanf(fp, "%s %s %f\n", date, description, &amount) != EOF)
    {
        if(strcmp(dateToDelete, date) == 0 && strcmp(descriptionToDelete, description) == 0)
        {
            printf("Expense Deleted Successfully!\n\n");
        }
        else
        {
            fprintf(temp, "%s %s %.2f\n", date, description, amount);
        }
    }

    // Close both files
    fclose(fp);
    fclose(temp);

    // Remove the original file and rename the temporary file
    remove("expenses.txt");
    rename("temp.txt", "expenses.txt");

    // Open the original file in the append mode
    fp = fopen("expenses.txt", "a");
}

// Main function
int main()
{
    int choice;

    // Open the file in the append mode
    FILE *fp = fopen("expenses.txt", "a");

    if(fp == NULL)
    {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addExpense(fp);
                break;
            case 2:
                viewExpenses(fp);
                break;
            case 3:
                deleteExpense(fp);
                break;
            case 4:
                printf("Thank you for using the Expense Tracker!\n");
                break;
            default:
                printf("Invalid Input!\n\n");
        }
    }
    while(choice != 4);

    // Close the file
    fclose(fp);

    return 0;
}