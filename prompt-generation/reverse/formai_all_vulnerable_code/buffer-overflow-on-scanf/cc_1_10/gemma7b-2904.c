//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    int menu_choice = 0;
    char username[20];
    char expense_name[50];
    int expense_amount = 0;
    FILE *fp;

    // Create a file pointer to open or create an expenses file
    fp = fopen("expenses.txt", "a");

    // Display a welcome message
    printf("Welcome to the Cyberpunk Expense Tracker!\n");

    // Display menu options
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");

    // Get the user's menu choice
    printf("Enter your choice: ");
    scanf("%d", &menu_choice);

    // Process the user's menu choice
    switch (menu_choice) {
        case 1:
            // Get the user's username, expense name, and amount
            printf("Enter your username: ");
            scanf("%s", username);

            printf("Enter the expense name: ");
            scanf("%s", expense_name);

            printf("Enter the expense amount: ");
            scanf("%d", &expense_amount);

            // Write the expense data to the file
            fprintf(fp, "%s, %s, %d\n", username, expense_name, expense_amount);

            // Display a confirmation message
            printf("Expense added successfully!\n");

            break;
        case 2:
            // Display a list of expenses
            printf("List of expenses:\n");

            // Read the expense data from the file
            fp = fopen("expenses.txt", "r");

            while (!feof(fp)) {
                fscanf(fp, "%s, %s, %d\n", username, expense_name, &expense_amount);

                printf("%s, %s, %d\n", username, expense_name, expense_amount);
            }

            fclose(fp);

            break;
        case 3:
            // Exit the program
            exit(0);
            break;
        default:
            // Display an error message
            printf("Invalid choice.\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}