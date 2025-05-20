//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

struct transaction{
    char date[15];
    char description[50];
    float amount;
};

// Function to read input transaction
struct transaction read_transaction(){
    struct transaction t;
    printf("\nEnter the date (DD/MM/YYYY): ");
    scanf("%s", t.date);
    printf("\nEnter the description: ");
    scanf("%s", t.description);
    printf("\nEnter the amount: ");
    scanf("%f", &t.amount);
    return t;
}

// Function to print transaction details
void print_transaction(struct transaction t){
    printf("\n%s    %-30s $%.2f", t.date, t.description, t.amount);
}

// Function to calculate balance
float calculate_balance(struct transaction t[], int size){
    float balance = 0.0;
    for(int i=0; i<size; i++){
        balance += t[i].amount;
    }
    return balance;
}

int main(){
    int n;
    printf("\nEnter the number of transactions: ");
    scanf("%d", &n);

    struct transaction transactions[n];
    for(int i=0; i<n; i++){
        printf("\nTransaction %d:", i+1);
        transactions[i] = read_transaction();
    }

    printf("\n\nTransaction Details:");
    printf("\n-----------------------------");
    for(int i=0; i<n; i++){
        print_transaction(transactions[i]);
    }

    float balance = calculate_balance(transactions, n);
    printf("\n\nTotal Balance: $%.2f\n\n", balance);

    return 0;
}