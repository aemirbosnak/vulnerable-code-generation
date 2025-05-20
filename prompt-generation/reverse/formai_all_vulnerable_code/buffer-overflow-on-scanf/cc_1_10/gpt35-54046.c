//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to hold each expense entry
struct Expense {
    char date[11];
    char category[20];
    float amount;
};

//Function to print the menu options
void printMenu() {
    printf("\n\n===== EXPENSE TRACKER =====\n\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    int numEntries = 0;
    struct Expense* expenses = (struct Expense*)malloc(sizeof(struct Expense));
    
    printf("Welcome to the Expense Tracker!\n");
    
    do {
        printMenu();
        scanf("%d", &option);
        
        switch(option) {
            case 1: {
                //Code to add new expense entry
                
                //Allocate memory for new expense entry
                numEntries++;
                expenses = (struct Expense*)realloc(expenses, numEntries*sizeof(struct Expense));
                
                //Get user input for new expense
                printf("\nADD NEW EXPENSE\n\n");
                printf("Date (mm/dd/yyyy): ");
                scanf("%s", expenses[numEntries-1].date);
                printf("Category: ");
                scanf("%s", expenses[numEntries-1].category);
                printf("Amount: ");
                scanf("%f", &expenses[numEntries-1].amount);
                
                printf("\nExpense added!\n");
                break;
            }
            
            case 2: {
                //Code to view all expenses
                
                if(numEntries == 0) {
                    printf("\nNo expenses found!\n");
                }
                else {
                    printf("\nALL EXPENSES\n\n");
                    for(int i = 0; i < numEntries; i++) {
                        printf("Date: %s\n", expenses[i].date);
                        printf("Category: %s\n", expenses[i].category);
                        printf("Amount: $%.2f\n\n", expenses[i].amount);
                    }
                }
                break;
            }
            
            case 3: {
                //Clean up dynamically allocated memory
                free(expenses);
                printf("\nThank you for using the Expense Tracker!\n");
                break;
            }
            
            default: {
                printf("\nInvalid option selected!\n");
                break;
            }
        }
    } while(option != 3);
    
    return 0;
}