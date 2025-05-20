//FormAI DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Expense {
    char category[25];
    double amount;
    char description[50];
    char date[15];
};

int main() {
    int choice, i, j;
    double totalExpense = 0.0;
    struct Expense expenses[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    do {
        printf("\n=====Expense Tracker MENU=====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Expense Category (Max 25 characters): ");
                scanf("%s", &expenses[i].category);
                printf("Enter Expense Amount: ");
                scanf("%lf", &expenses[i].amount);
                printf("Enter Expense Description (Max 50 characters): ");
                scanf("%s", &expenses[i].description);
                sprintf(expenses[i].date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
                totalExpense += expenses[i].amount;
                printf("\nExpense added successfully!\n");
                i++;
                break;
            case 2:
                printf("\nExpense Category\tExpense Amount\tExpense Description\tExpense Date\n");
                for(j=0; j<i; j++) {
                    printf("%s\t\t%.2lf\t\t%s\t\t%s\n", expenses[j].category, expenses[j].amount, expenses[j].description, expenses[j].date);
                }
                printf("\nTotal Expense: %.2lf\n", totalExpense);
                break;
            case 3:
                printf("\nThank you! Exiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}