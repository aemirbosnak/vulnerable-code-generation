//FormAI DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000   // maximum number of expenses that can be tracked

// structure to store each expense
struct Expense {
    char date[11];          // date of the expense (format: yyyy/mm/dd)
    char category[31];      // category of the expense (e.g. food, transportation, etc.)
    char description[101];  // description of the expense
    float amount;           // amount spent on the expense
};

void print_menu() {
    printf("\n----- EXPENSE TRACKER -----\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Search Expenses\n");
    printf("4. Exit\n");
}

int main() {
    struct Expense expenses[MAX_EXPENSES];    // array to store all expenses
    int num_expenses = 0;   // counter for the number of expenses
    int choice;     // variable to store user choice
    char search_category[31];   // variable to store search category
    char search_month[8];   // variable to store search month
    int i;  // loop counter
    
    do {
        print_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:     // add an expense
                if (num_expenses == MAX_EXPENSES) {
                    printf("\nMaximum number of expenses reached!\n");
                } else {
                    printf("\nEnter details for Expense #%d:\n", num_expenses + 1);
                    printf("Date (yyyy/mm/dd): ");
                    scanf("%s", expenses[num_expenses].date);
                    printf("Category: ");
                    scanf("%s", expenses[num_expenses].category);
                    printf("Description: ");
                    scanf(" %[^\n]s", expenses[num_expenses].description);
                    printf("Amount: $");
                    scanf("%f", &expenses[num_expenses].amount);
                    num_expenses++;
                    printf("\nExpense added successfully!\n");
                }
                break;
            case 2:     // view all expenses
                if (num_expenses == 0) {
                    printf("\nNo expenses added yet!\n");
                } else {
                    printf("\n--- ALL EXPENSES ---\n");
                    for (i = 0; i < num_expenses; i++) {
                        printf("%d. Date: %s | Category: %s | Description: %s | Amount: $%.2f\n",
                                i+1, expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
                    }
                }
                break;
            case 3:     // search expenses
                printf("\n----- SEARCH EXPENSES -----\n");
                printf("1. Search by category\n");
                printf("2. Search by month\n");
                printf("Enter your choice (1-2): ");
                scanf("%d", &choice);
                
                if (choice == 1) {  // search by category
                    printf("\nEnter category to search for: ");
                    scanf("%s", search_category);
                    printf("\n--- EXPENSES FOR CATEGORY '%s' ---\n", search_category);
                    int found = 0;
                    for (i = 0; i < num_expenses; i++) {
                        if (strcmp(expenses[i].category, search_category) == 0) {
                            printf("%d. Date: %s | Category: %s | Description: %s | Amount: $%.2f\n",
                                    i+1, expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("No expenses found for category '%s'.\n", search_category);
                    }
                } else if (choice == 2) {   // search by month
                    printf("\nEnter month to search for (yyyy/mm): ");
                    scanf("%s", search_month);
                    printf("\n--- EXPENSES FOR MONTH '%s' ---\n", search_month);
                    int found = 0;
                    for (i = 0; i < num_expenses; i++) {
                        if (strncmp(expenses[i].date, search_month, 7) == 0) {
                            printf("%d. Date: %s | Category: %s | Description: %s | Amount: $%.2f\n",
                                    i+1, expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("No expenses found for month '%s'.\n", search_month);
                    }
                } else {
                    printf("\nInvalid choice!\n");
                }
                break;
            case 4:     // exit
                printf("\nThank you for using the Expense Tracker!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter 1-4 only.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}