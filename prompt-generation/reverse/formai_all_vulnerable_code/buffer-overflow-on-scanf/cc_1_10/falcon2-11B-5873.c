//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_AMOUNT_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} Expense;

Expense expenses[100];

int main() {
    int num_expenses = 0;
    int choice;
    
    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter the number of expenses you want to track: ");
    scanf("%d", &num_expenses);
    
    for (int i = 0; i < num_expenses; i++) {
        printf("Enter the name of expense %d: ", i+1);
        scanf("%s", expenses[i].name);
        
        printf("Enter the amount of expense %d: ", i+1);
        scanf("%s", expenses[i].amount);
    }
    
    printf("Enter the index of expense you want to view: ");
    scanf("%d", &choice);
    
    printf("Name: %s\n", expenses[choice].name);
    printf("Amount: %s\n", expenses[choice].amount);
    
    printf("Enter the index of expense you want to edit: ");
    scanf("%d", &choice);
    
    printf("Enter the new name for expense %d: ", choice+1);
    scanf("%s", expenses[choice].name);
    
    printf("Enter the new amount for expense %d: ", choice+1);
    scanf("%s", expenses[choice].amount);
    
    printf("Enter the index of expense you want to delete: ");
    scanf("%d", &choice);
    
    memset(expenses[choice].name, '\0', MAX_NAME_LEN);
    memset(expenses[choice].amount, '\0', MAX_AMOUNT_LEN);
    
    printf("Expense %d deleted successfully!\n", choice+1);
    
    return 0;
}