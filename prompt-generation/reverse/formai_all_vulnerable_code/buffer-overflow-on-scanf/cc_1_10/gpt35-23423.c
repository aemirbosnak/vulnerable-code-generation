//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 1000

/* Data structure for individual financial records */
struct FinancialRecord {
    char date[11];
    char category[25];
    double amount;
    char description[100];
};

/* Function to add a new financial record */
void addRecord(struct FinancialRecord records[], int *totalRecords) {
    char temp[100];
    printf("\nEnter the date (in MM/DD/YYYY format): ");
    scanf("%s", records[*totalRecords].date);
    printf("Enter the category: ");
    scanf("%s", records[*totalRecords].category);
    printf("Enter the amount: ");
    scanf("%lf", &records[*totalRecords].amount);
    printf("Enter the description: ");
    fgets(temp, sizeof(temp), stdin);
    fgets(records[*totalRecords].description, sizeof(records[*totalRecords].description), stdin);
    records[*totalRecords].description[strcspn(records[*totalRecords].description, "\n")] = 0; // Removes the newline character from the end of the input
    *totalRecords += 1;
    printf("\nRecord added successfully!\n");
}

/* Function to display all financial records */
void displayRecords(struct FinancialRecord records[], int totalRecords) {
    if (totalRecords == 0) {
        printf("\nNo records found!\n");
    }
    else {
        printf("\nAll financial records:\n");
        printf("-----------------------\n");
        printf("Date\t\tCategory\tAmount\tDescription\n");
        for (int i = 0; i < totalRecords; i++) {
            printf("%s\t%s\t%.2lf\t%s\n", records[i].date, records[i].category, records[i].amount, records[i].description);
        }
    }
}

/* Function to display a summary of total expenses for each category */
void summary(struct FinancialRecord records[], int totalRecords) {
    if (totalRecords == 0) {
        printf("\nNo records found!\n");
    }
    else {
        double totalExpenses = 0;
        char uniqueCategories[MAX_RECORDS][25];
        double categoryTotals[MAX_RECORDS] = {0};
        int numCategories = 0;
        int categoryFound;
        for (int i = 0; i < totalRecords; i++) {
            totalExpenses += records[i].amount;
            categoryFound = 0;
            for (int j = 0; j < numCategories; j++) {
                if (strcmp(records[i].category, uniqueCategories[j]) == 0) {
                    categoryTotals[j] += records[i].amount;
                    categoryFound = 1;
                    break;
                }
            }
            if (!categoryFound) {
                strcpy(uniqueCategories[numCategories], records[i].category);
                categoryTotals[numCategories] += records[i].amount;
                numCategories += 1;
            }
        }
        printf("\nSummary of expenses for each category:\n");
        printf("---------------------------------------\n");
        printf("Category\t\tTotal Expenses\n");
        for (int i = 0; i < numCategories; i++) {
            printf("%s\t\t\t%.2lf\n", uniqueCategories[i], categoryTotals[i]);
        }
        printf("\nTotal expenses: $%.2lf\n", totalExpenses);
    }
}

int main() {
    struct FinancialRecord records[MAX_RECORDS];
    int totalRecords = 0;
    int choice = 0;
    while (choice != 4) {
        printf("\n----------- Personal Finance Planner -----------\n");
        printf("1) Add a new financial record\n");
        printf("2) Display all financial records\n");
        printf("3) Display a summary of expenses by category\n");
        printf("4) Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(records, &totalRecords);
                break;
            case 2:
                displayRecords(records, totalRecords);
                break;
            case 3:
                summary(records, totalRecords);
                break;
            case 4:
                printf("\nThank you for using Personal Finance Planner!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice (1-4).\n");
        }
    }
    return 0;
}