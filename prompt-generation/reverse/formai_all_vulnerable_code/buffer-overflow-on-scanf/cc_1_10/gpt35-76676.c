//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
// C Expense Tracker Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store the expense details
struct Expense {
    char category[20];
    float amount;
    char date[20];
};

int main() {

    // create variables to store user input
    char user_input[20];
    char user_category[20];
    float user_amount;
    char user_date[20];

    // create a file pointer for creating a new file
    FILE *fptr;

    // create a new empty file
    fptr = fopen("expenses.txt", "w");

    if (fptr == NULL) {
        printf("Error creating file.");
        return 0;
    }

    // ask the user whether they want to enter a new expense or view all expenses
    printf("Enter 'add' to enter a new expense, or 'view' to view all expenses: ");
    fgets(user_input, 20, stdin);
    strtok(user_input, "\n");

    if (strcmp(user_input, "add") == 0) {

        // ask the user for the expense details
        printf("Enter category: ");
        fgets(user_category, 20, stdin);
        strtok(user_category, "\n");

        printf("Enter amount: ");
        scanf("%f", &user_amount);

        printf("Enter date (dd/mm/yyyy): ");
        getchar();
        fgets(user_date, 20, stdin);
        strtok(user_date, "\n");

        // create a new Expense struct and fill it with the user input
        struct Expense new_expense;
        strcpy(new_expense.category, user_category);
        new_expense.amount = user_amount;
        strcpy(new_expense.date, user_date);

        // write the new expense to the file
        fprintf(fptr, "%s,%.2f,%s\n", new_expense.category, new_expense.amount, new_expense.date);
        printf("\nExpense added successfully!");

    } else if (strcmp(user_input, "view") == 0) {

        // create a file pointer for reading from the file
        FILE *fptr_read;

        // open the expenses file for reading
        fptr_read = fopen("expenses.txt", "r");

        if (fptr_read == NULL) {
            printf("Error opening file.");
            return 0;
        }

        printf("\nListing all expenses:\n\n");

        // loop through each line in the file and print it to the console
        char line[50];
        while (fgets(line, 50, fptr_read)) {
            strtok(line, "\n");
            printf("%s\n", line);
        }

        fclose(fptr_read);
    }

    fclose(fptr);

    return 0;
}