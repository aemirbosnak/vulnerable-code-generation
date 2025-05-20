//FormAI DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h> 

#define MAX_TRANSACTIONS 10
#define MAX_LENGTH 50

//Declaring struct Transaction
struct Transaction{
    char name[MAX_LENGTH];
    float amount;
};

int main(){
    struct Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;
    char input[MAX_LENGTH], name[MAX_LENGTH];
    float amount;
    
    printf("Welcome to the Expense Tracker program!\n");
    printf("Please enter your transactions:\n");
    
    while(numTransactions < MAX_TRANSACTIONS){
        printf("Transaction %d: ", numTransactions+1);
        fgets(input, MAX_LENGTH, stdin);
        
        //parsing the input string
        sscanf(input, "%s %f", name, &amount);
        
        // converting name to lowercase
        int i = 0;
        while(name[i]){
            name[i] = tolower(name[i]);
            i++;
        }
        
        if(strcmp(name, "quit") == 0){
            break;
        }
        
        // checking for valid amount
        if(amount <= 0){
            printf("Invalid amount. Transaction must be greater than 0\n");
            continue;
        }
        
        // adding transaction to array
        struct Transaction transaction = {name, amount};
        
        transactions[numTransactions] = transaction;
        numTransactions++;
    }
    
    float total = 0;
    
    // printing all the transactions
    printf("\n**Transactions**\n");
    for(int i=0; i<numTransactions; i++){
        printf("%s: $%.2f\n", transactions[i].name, transactions[i].amount);
        
        total += transactions[i].amount;
    }
    
    printf("Total: $%.2f", total);
    
    return 0;
}