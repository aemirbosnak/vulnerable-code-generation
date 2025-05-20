//FormAI DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for string manipulation functions

//Structure to hold expense information
struct Expense {
    char description[50];
    float cost;
    char category[30];
    char date[20];
};

int main() {
    int choice;
    int numRecords = 0;
    int i;
    int recordFound = 0;
    float totalCost = 0.0;
    struct Expense expenses[100]; //Array of expenses with a maximum limit of 100 records

    while (1) {
        printf("\nWelcome to the expense tracker program!\n");
        printf("Choose an option from the following menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Search Expenses\n");
        printf("4. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                //Code to add a new expense record
                printf("\nEnter expense description: ");
                scanf("%s", expenses[numRecords].description);
                
                printf("Enter expense cost: ");
                scanf("%f", &expenses[numRecords].cost);
                
                printf("Enter expense category: ");
                scanf("%s", expenses[numRecords].category);
                
                printf("Enter expense date: ");
                scanf("%s", expenses[numRecords].date);
                
                totalCost += expenses[numRecords].cost; //Add cost to the total expense
                
                printf("\nExpense added successfully!\n");
                numRecords++; //Increment the counter for number of records
                break;
                
            case 2:
                //Code to view all expense records
                printf("\nTotal Expenses: $%0.2f\n\n", totalCost);
                
                if (numRecords == 0) {
                    printf("No expenses recorded!\n");
                } else {
                    printf("Expense Description \t Cost ($) \t Category \t Date\n");
                    
                    for (i = 0; i < numRecords; i++) {
                        printf("%s \t $%0.2f \t %s \t %s\n", expenses[i].description, expenses[i].cost, expenses[i].category, expenses[i].date);
                    }
                }
                break;
                
            case 3:
                //Code to search for a specific expense record
                if (numRecords == 0) {
                    printf("\nNo expenses recorded!\n");
                    break;
                }
                
                printf("\nEnter expense description to search: ");
                char searchQuery[50];
                scanf("%s", searchQuery);
                
                recordFound = 0;
                
                for (i = 0; i < numRecords; i++) {
                    if (strcmp(expenses[i].description, searchQuery) == 0) {
                        printf("\nExpense found!\n");
                        printf("Expense Description \t Cost ($) \t Category \t Date\n");
                        printf("%s \t $%0.2f \t %s \t %s\n", expenses[i].description, expenses[i].cost, expenses[i].category, expenses[i].date);
                        
                        recordFound = 1;
                    }
                }
                
                if (recordFound == 0) {
                    printf("\nExpense not found!\n");
                }
                break;
                
            case 4:
                //Code to exit the program
                printf("\nExiting Program...\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    
    return 0;
}