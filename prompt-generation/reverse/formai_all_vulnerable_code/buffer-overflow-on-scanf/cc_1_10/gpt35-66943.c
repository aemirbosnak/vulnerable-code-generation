//FormAI DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char item_name[100];
    double amount;
    char date[11];
};

int main() {
    struct expense expenses[50];
    FILE *fptr; 
    int choice, num_expenses = 0;
    double total_expense = 0.0;

    while(1) {
        printf("\n\n1. Add Expense\n2. View Expenses\n3. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                if(num_expenses < 50) {
                    printf("Enter Item Name: ");
                    scanf(" %[^\n]%*c", expenses[num_expenses].item_name);
                    printf("Enter Expense Amount: ");
                    scanf("%lf", &expenses[num_expenses].amount);
                    printf("Enter Expense Date (dd/mm/yyyy): ");
                    scanf("%s", expenses[num_expenses].date);

                    total_expense += expenses[num_expenses].amount;
                    num_expenses++;
                } else {
                    printf("Maximum expenses reached.");
                }
                break;

            case 2:
                printf("%-15s %-15s %-15s\n", "Item Name", "Amount", "Date");
                printf("---------------------------------------\n");
                for(int i = 0; i < num_expenses; i++) {
                    printf("%-15s %-15.2lf %-15s\n", expenses[i].item_name, expenses[i].amount, expenses[i].date);
                }
                printf("---------------------------------------\n");
                printf("Total Expenses: %.2lf\n", total_expense);
                break;

            case 3:
                printf("Exiting program...\n");
                fptr = fopen("expenses.txt", "w");
                for(int i = 0; i < num_expenses; i++) {
                    fprintf(fptr, "%s,%.2lf,%s\n", expenses[i].item_name, expenses[i].amount, expenses[i].date);
                }
                fclose(fptr);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}