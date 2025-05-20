//FormAI DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure to hold expense record
struct expense {
    float amount;
    char category[20];
    char description[100];
};

// Declare an array to hold up to 100 expenses
struct expense expenses[100];

// Declare a variable to keep track of the number of expenses entered
int expense_count = 0;

int main() {
    
    char option[10];
    float temp_amount;
    char temp_category[20], temp_description[100];
    
    do {
        // Print the menu options
        printf("**** Expense Tracker ****\n");
        printf("1. Add new expense\n");
        printf("2. View all expenses\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        
        // Read the user's choice
        scanf("%s", option);
        
        // Perform the corresponding action based on user's choice
        if(strcmp(option, "1") == 0) {
            // Option to add new expense
            printf("Enter amount: $");
            scanf("%f", &temp_amount);
            expenses[expense_count].amount = temp_amount;
            
            printf("Enter category: ");
            scanf("%s", temp_category);
            strcpy(expenses[expense_count].category, temp_category);
            
            printf("Enter description: ");
            scanf("%s", temp_description);
            strcpy(expenses[expense_count].description, temp_description);
            
            // Increase expense count by 1
            expense_count++;
            printf("Expense added successfully!\n");
            
        } else if(strcmp(option, "2") == 0) {
            // Option to view all expenses
            if(expense_count == 0) {
                printf("No expenses found!\n");
            } else {
                printf("-----------------------\n");
                for(int i=0; i<expense_count; i++) {
                    printf("Expense %d:\n", i+1);
                    printf("Amount: $%0.2f\n", expenses[i].amount);
                    printf("Category: %s\n", expenses[i].category);
                    printf("Description: %s", expenses[i].description);
                    printf("-----------------------\n");
                }
            }
        } else if(strcmp(option, "3") == 0) {
            // Option to exit the program
            printf("Exiting program. Bye!\n");
            exit(0);
        } else {
            // Invalid option entered
            printf("Invalid option! Please try again.\n");
        }
        
    } while(1); // Infinite loop until user explicitly chooses to exit
    
    return 0;
}