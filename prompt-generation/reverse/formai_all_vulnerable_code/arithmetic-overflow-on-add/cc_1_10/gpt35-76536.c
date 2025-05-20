//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int expense = 0;
    char category[50];
    char password[50];

    printf("Welcome to the Paranoid Expense Tracker\n");
    printf("Please enter your password: ");
    scanf("%s", password);

    // Encrypting the password
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] += 5;
    }

    printf("\nPassword encrypted successfully\n\n");

    printf("Please enter your expenses\n");
    printf("Type 'exit' in the category to quit\n");

    // Creating and opening the file for writing expenses
    FILE *fptr;
    fptr = fopen("paranoid_expenses.txt", "w");

    if (fptr == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    while (strcmp(category, "exit") != 0) {
        printf("Category: ");
        scanf("%s", category);

        // Checking if the user wants to quit
        if (strcmp(category, "exit") == 0) {
            break;
        }

        printf("Amount: ");
        scanf("%d", &expense);

        // Encrypting the expense amount
        expense += 135;

        // Writing the encrypted expense to the file
        fprintf(fptr, "%s: %d\n", category, expense);

        printf("Expense recorded successfully\n\n");
    }

    printf("Expenses saved in paranoid_expenses.txt\n");

    // Closing the file
    fclose(fptr);

    // Decrypting the password and expense
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] -= 5;
    }

    printf("\nPassword decrypted successfully\n");
    printf("Please enter your password to see the expenses: ");
    scanf("%s", password);

    // Encrypting the password again to see the expenses
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] += 5;
    }

    // Checking if the entered password is correct
    if (strcmp(password, "mypassword") == 0) {
        printf("\nPassword correct\n");

        // Opening the file for reading expenses
        fptr = fopen("paranoid_expenses.txt", "r");

        char buffer[1024];

        // Reading and decrypting the expenses from the file
        while (fgets(buffer, 1024, fptr)) {
            char *category = strtok(buffer, ":");
            char *expense_str = strtok(NULL, ":");
            int expense = atoi(expense_str);

            expense -= 135;

            printf("%s: %d\n", category, expense);
        }

        // Closing the file
        fclose(fptr);
    } else {
        printf("\nPassword incorrect. Terminating program.\n");
        exit(1);
    }

    return 0;
}