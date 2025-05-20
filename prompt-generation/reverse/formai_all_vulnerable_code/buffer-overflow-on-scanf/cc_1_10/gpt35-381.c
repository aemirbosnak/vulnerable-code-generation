//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define maximum no. of expenses to be recorded
#define MAX_EXPENSES 100

// Structure to store expense details
struct Expense {
    int id;
    char category[20];
    float amount;
    char date[11];
    char description[200];
};

// Function to display expense details
void displayExpense(struct Expense e) {
    printf("ID : %d\n", e.id);
    printf("Category : %s\n", e.category);
    printf("Amount : %.2f\n", e.amount);
    printf("Date : %s\n", e.date);
    printf("Description : %s\n", e.description);
}

int main() {
    int i=0, choice=0, expenseId;
    float totalExpenses=0;
    struct Expense expenses[MAX_EXPENSES];
    
    // Display options
    printf("Welcome to the expense tracker!\n");
    printf("1. Add new expense\n");
    printf("2. Display all expenses\n");
    printf("3. Display total expenses\n");
    printf("4. Search expense by ID\n");
    printf("5. Exit\n");
    
    while(choice != 5) {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Add new expense
                if(i < MAX_EXPENSES) {
                    printf("\nEnter expense category : ");
                    scanf("%s", &(expenses[i].category));
                    printf("Enter expense amount : ");
                    scanf("%f", &(expenses[i].amount));
                    printf("Enter expense date (dd-mm-yyyy) : ");
                    scanf("%s", &(expenses[i].date));
                    printf("Enter expense description : ");
                    scanf("%s", &(expenses[i].description));
                    expenses[i].id = i + 1;
                    printf("\nNew expense added successfully!\n");
                    displayExpense(expenses[i]);
                    i++;
                }
                else {
                    printf("\nMaximum no. of expenses reached!\n");
                }
                break;
                
            case 2:
                // Display all expenses
                printf("\nAll expenses:\n");
                for(int j=0; j<i; j++) {
                    displayExpense(expenses[j]);
                }
                break;
                
            case 3:
                // Display total expenses
                printf("\nTotal expenses : %.2f\n", totalExpenses);
                break;
            
            case 4:
                // Search expense by ID
                printf("\nEnter expense ID to search : ");
                scanf("%d", &expenseId);
                for(int j=0; j<i; j++) {
                    if(expenses[j].id == expenseId) {
                        displayExpense(expenses[j]);
                    }
                }
                break;
                
            case 5:
                // Exit program
                printf("\nExiting expense tracker...\n");
                break;
                
            default:
                printf("\nInvalid choice, please try again!\n");
        }
    }
    
    return 0;
}