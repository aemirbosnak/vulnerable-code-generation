//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 50 // max length of transaction description
#define MAX_TRANSACTIONS 100 // max number of transactions to be tracked

struct ExpenseTracker
{
    char description[MAX_LENGTH];
    float amount;
};

typedef struct ExpenseTracker Transaction;

// function declarations
void addTransaction(Transaction *, int *);
void deleteTransaction(Transaction *, int *);
void viewTransactions(Transaction *, int);
void viewTotal(Transaction *, int);

int main()
{
    Transaction transactions[MAX_TRANSACTIONS];
    int count = 0;
    int choice;
    
    do
    {
        printf("\n\tEXPENSE TRACKER\n");
        printf("1. Add a transaction\n");
        printf("2. Delete a transaction\n");
        printf("3. View all transactions\n");
        printf("4. View total expense\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addTransaction(transactions, &count);
                break;
                
            case 2:
                deleteTransaction(transactions, &count);
                break;
                
            case 3:
                viewTransactions(transactions, count);
                break;
                
            case 4:
                viewTotal(transactions, count);
                break;
                
            case 5:
                printf("Exiting the program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Try again.\n");
        }
        
    } while(choice != 5);
    
    return 0;
}

void addTransaction(Transaction *transactions, int *count)
{
    if(*count == MAX_TRANSACTIONS)
    {
        printf("Transaction limit reached!\n");
        return;
    }
    
    printf("Enter transaction description (max 50 characters): ");
    scanf("%s", (transactions + *count)->description);
    printf("Enter transaction amount: ");
    scanf("%f", &(transactions + *count)->amount);
    
    printf("\nTransaction added successfully!\n");
    
    (*count)++;
}

void deleteTransaction(Transaction *transactions, int *count)
{
    if(*count == 0)
    {
        printf("No transactions to delete!\n");
        return;
    }
    
    int index;
    printf("Enter transaction number to delete (1-%d): ", *count);
    scanf("%d", &index);
    
    if(index < 1 || index > *count)
    {
        printf("Invalid transaction number!\n");
        return;
    }
    
    for(int i = index-1; i < (*count)-1; i++)
    {
        strcpy((transactions + i)->description, (transactions + i + 1)->description);
        (transactions + i)->amount = (transactions + i + 1)->amount;
    }
    
    (*count)--;
    
    printf("\nTransaction deleted successfully!\n");
}

void viewTransactions(Transaction *transactions, int count)
{
    if(count == 0)
    {
        printf("No transactions to show!\n");
        return;
    }
    
    printf("Transaction History:\n");
    printf("___________________________________________________________________\n");
    printf("| Sno. |   Description                         |   Amount         |\n");
    printf("___________________________________________________________________\n");
    
    for(int i=0; i<count; i++)
    {
        printf("| %-4d | %-35s | %-16.2f|\n", i+1, (transactions + i)->description, (transactions + i)->amount);
    }
    
    printf("___________________________________________________________________\n");
}

void viewTotal(Transaction *transactions, int count)
{
    if(count == 0)
    {
        printf("No transactions to show!\n");
        return;
    }
    
    float total = 0.0;
    for(int i=0; i<count; i++)
    {
        total += (transactions + i)->amount;
    }
    
    printf("Total expense: %.2f\n", total);
}