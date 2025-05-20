//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

//Structure for a transaction
struct transaction{
    char date[20];
    char description[100];
    float amount;
    int category;
};

//Function to add a transaction
void addTransaction(struct transaction* t){
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s",t->date);
    printf("Enter the description: ");
    scanf("%s",t->description);
    printf("Enter the amount: ");
    scanf("%f",&t->amount);
    printf("Enter the category (1-Income, 2-Expense): ");
    scanf("%d",&t->category);
}

//Function to display all transactions
void displayTransactions(struct transaction* t,int n){
    printf("\nDate\tDescription\tAmount\tCategory\n");
    for(int i=0;i<n;i++){
        printf("%s\t%s\t%.2f\t%d\n",t[i].date,t[i].description,t[i].amount,t[i].category);
    }
}

//Function to calculate total income and expense
void calculateTotal(struct transaction* t,int n){
    float income=0,expense=0;
    for(int i=0;i<n;i++){
        if(t[i].category==1){
            income+=t[i].amount;
        }
        else{
            expense+=t[i].amount;
        }
    }
    printf("\nTotal Income: %.2f\nTotal Expense: %.2f\n",income,expense);
}

//Main function
int main(){
    int n;
    printf("Enter the number of transactions: ");
    scanf("%d",&n);
    struct transaction t[n];
    for(int i=0;i<n;i++){
        addTransaction(&t[i]);
    }
    displayTransactions(t,n);
    calculateTotal(t,n);
    return 0;
}