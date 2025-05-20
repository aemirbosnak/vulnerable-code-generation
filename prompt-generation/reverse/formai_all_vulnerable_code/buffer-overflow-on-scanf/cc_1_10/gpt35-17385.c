//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Struct to hold transaction data
struct expense {
    char title[50];
    float amount;
    time_t date;
};

//Function to add a new transaction record
void add_transaction(struct expense *transactions, int *count) {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    float amount;
    char title[50];
    
    printf("Enter transaction title: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0; //Remove newline character
    
    printf("Enter transaction amount: ");
    scanf("%f", &amount);
    getchar(); //Consume newline character
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%F %T", timeinfo);
    
    //Add transaction to array
    strcpy(transactions[*count].title, title);
    transactions[*count].amount = amount;
    transactions[*count].date = rawtime;
    (*count)++;
    
    printf("Transaction added successfully.\n");
}

//Function to display transaction history
void view_transactions(struct expense *transactions, int count) {
    if(count == 0) {
        printf("No transactions to display.\n");
        return;
    }
    
    printf("Transaction History:\n");
    printf("--------------------\n");
    for(int i = 0; i < count; i++) {
        struct tm *timeinfo = localtime(&(transactions[i].date));
        char buffer[80];
        strftime(buffer, 80, "%F %T", timeinfo);
        printf("%s - $%.2f\n", buffer, transactions[i].amount);
    }
}

int main() {
    struct expense transactions[100];
    int count = 0;
    int choice = 0;
    
    do {
        printf("\nExpense Tracker\n");
        printf("----------------\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); //Consume newline character
        
        switch(choice) {
            case 1: add_transaction(transactions, &count);
                    break;
            case 2: view_transactions(transactions, count);
                    break;
            case 3: printf("Exiting program.\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
                     break;
        }
    } while(choice != 3);
    
    return 0;
}