//FormAI DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addExpense(int*, int*, float*, char***, char***);
void viewExpenses(int, char**, char**);
void removeExpense(int*, float*, char***, char***);

int main()
{
    int numExpenses = 0, maxExpenses = 10;
    float* amounts;
    amounts = (float *)malloc(maxExpenses*sizeof(float));
    char** categories;
    categories = (char **)malloc(maxExpenses*sizeof(char *));
    char** descriptions;
    descriptions = (char **)malloc(maxExpenses*sizeof(char *)); 
    
    printf("Welcome to the Expense Tracker!\n");
    printf("Type 'add' to add a new expense.\n");
    printf("Type 'view' to view all expenses.\n");
    printf("Type 'remove' to remove an expense.\n");
    printf("Type 'exit' to quit the program.\n\n");
    char command[10];
    
    while(1)
    {
        printf("> ");
        scanf("%s", command);
        if(strcmp(command, "add") == 0)
            addExpense(&numExpenses, &maxExpenses, amounts, categories, descriptions);
        else if(strcmp(command, "view") == 0)
            viewExpenses(numExpenses, categories, descriptions);
        else if(strcmp(command, "remove") == 0)
            removeExpense(&numExpenses, amounts, categories, descriptions);
        else if(strcmp(command, "exit") == 0)
            break;
        else
            printf("Invalid command.\n");
    }
    
    free(amounts);
    for(int i=0;i<numExpenses;i++)
    {
        free(categories[i]);
        free(descriptions[i]);
    }
    free(categories);
    free(descriptions);
    
    return 0;
}

void addExpense(int* numExpenses, int* maxExpenses, float* amounts, char*** categories, char*** descriptions)
{
    char tempCategory[30];
    char tempDescription[100];
    float tempAmount;
    
    if(*numExpenses == *maxExpenses)
    {
        *maxExpenses *= 2;
        amounts = (float *)realloc(amounts, *maxExpenses*sizeof(float));
        *categories = (char **)realloc(*categories, *maxExpenses*sizeof(char *));
        *descriptions = (char **)realloc(*descriptions, *maxExpenses*sizeof(char *));
    }
    
    printf("Enter the category of the expense: ");
    scanf("%s", tempCategory);
    printf("Enter the description of the expense: ");
    scanf(" %[^\n]%*c", tempDescription);
    printf("Enter the amount spent: ");
    scanf("%f", &tempAmount);
    
    (*categories)[*numExpenses] = (char *)malloc(strlen(tempCategory)+1);
    strcpy((*categories)[*numExpenses], tempCategory);
    (*descriptions)[*numExpenses] = (char *)malloc(strlen(tempDescription)+1);
    strcpy((*descriptions)[*numExpenses], tempDescription);
    amounts[*numExpenses] = tempAmount;
    
    printf("Expense added!\n");
    (*numExpenses)++;
}

void viewExpenses(int numExpenses, char** categories, char** descriptions)
{
    if(numExpenses == 0)
    {
        printf("No expenses to display.\n");
        return;
    }
    
    printf("CATEGORIES\t\tDESCRIPTIONS\n");
    for(int i=0;i<numExpenses;i++)
    {
        printf("%s\t\t%s\n", categories[i], descriptions[i]);
    }
}

void removeExpense(int* numExpenses, float* amounts, char*** categories, char*** descriptions)
{
    if(*numExpenses == 0)
    {
        printf("No expenses to remove.\n");
        return;
    }
    
    int indexToRemove;
    printf("Enter the index of the expense to remove: ");
    scanf("%d", &indexToRemove);
    
    if(indexToRemove < 0 || indexToRemove >= *numExpenses)
    {
        printf("Invalid index.\n");
        return;
    }
    
    (*numExpenses)--;
    amounts[indexToRemove] = amounts[*numExpenses];
    free((*categories)[indexToRemove]);
    (*categories)[indexToRemove] = (*categories)[*numExpenses];
    free((*descriptions)[indexToRemove]);
    (*descriptions)[indexToRemove] = (*descriptions)[*numExpenses];
    
    printf("Expense removed.\n");
}