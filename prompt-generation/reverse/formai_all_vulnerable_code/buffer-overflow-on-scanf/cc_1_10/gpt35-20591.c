//FormAI DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of an expense
struct expense {
    char date[11]; // Format: DD/MM/YYYY
    char description[50];
    float amount;
};

// Function to add a new expense to the expense tracker
void addExpense(struct expense *tracker, int *total) {
    printf("\nEnter the details of the new expense:\n");

    printf("Date (DD/MM/YYYY): ");
    scanf("%s", tracker[*total].date);

    printf("Description: ");
    scanf("%s", tracker[*total].description);

    printf("Amount: ");
    scanf("%f", &tracker[*total].amount);

    printf("\nExpense added successfully!");
    (*total)++;
}

// Function to display all the expenses in the expense tracker
void displayExpenses(struct expense *tracker, int total) {
    if (total == 0) {
        printf("\nNo expenses found.\n");
        return;
    }

    printf("\nDate\t\tDescription\t\tAmount\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%s\t\t%s\t\t\t%.2f\n", tracker[i].date, tracker[i].description, tracker[i].amount);
    }
    printf("-------------------------------------------------------\n");
}

// Function to calculate the total expenses in the tracker
float calculateTotal(struct expense *tracker, int total) {
    float totalAmount = 0.0;

    for (int i = 0; i < total; i++) {
        totalAmount += tracker[i].amount;
    }

    return totalAmount;
}

// Main function to control the flow of the program
int main() {
    int option, total = 0;

    struct expense tracker[100];

    // Display the menu and get input from the user
    while (1) {
        printf("\nExpense Tracker\n");
        printf("---------------\n");

        printf("1. Add an Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addExpense(tracker, &total);
                break;

            case 2:
                displayExpenses(tracker, total);
                break;

            case 3:
                printf("\nTotal Expenses: %.2f\n", calculateTotal(tracker, total));
                break;

            case 4:
                printf("\nThank you for using the Expense Tracker!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}