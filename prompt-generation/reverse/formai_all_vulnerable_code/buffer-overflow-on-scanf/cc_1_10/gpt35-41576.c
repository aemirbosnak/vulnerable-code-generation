//FormAI DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constants
#define MAX_DESCRIPTION_LENGTH 50
#define MAX_TRANSACTIONS 100
#define PASSWORD "mypassword"

//struct for transaction
typedef struct{
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Transaction;

//global variables
Transaction transactions[MAX_TRANSACTIONS];
int numTransactions = 0;
float totalExpenses = 0.0;

//function prototypes
void addTransaction();
void deleteTransaction();
void viewTransactions();
void viewCategories();
void viewTotalExpenses();
void authenticate();

//main function
int main(){
    authenticate();

    int choice;
    do{
        printf("\n1. Add Transaction\n");
        printf("2. Delete Transaction\n");
        printf("3. View Transactions\n");
        printf("4. View Categories\n");
        printf("5. View Total Expenses\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addTransaction(); break;
            case 2: deleteTransaction(); break;
            case 3: viewTransactions(); break;
            case 4: viewCategories(); break;
            case 5: viewTotalExpenses(); break;
            case 6: break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);
    
    return 0;
}

//function to add a transaction
void addTransaction(){
    //check if max transaction limit has been reached
    if(numTransactions == MAX_TRANSACTIONS){
        printf("Transaction limit reached!\n");
        return;
    }

    //get inputs from user
    Transaction t;
    printf("\nEnter transaction description (max %d characters): ", MAX_DESCRIPTION_LENGTH);
    scanf("\n%[^\n]s", t.description);
    printf("Enter transaction amount: ");
    scanf("%f", &t.amount);

    //generate transaction id
    t.id = numTransactions+1;

    //add transaction to transactions array
    transactions[numTransactions] = t;
    numTransactions++;
    totalExpenses += t.amount;

    printf("\nTransaction added successfully!\n");
}

//function to delete a transaction
void deleteTransaction(){
    //check if there are any transactions
    if(numTransactions == 0){
        printf("No transactions found!\n");
        return;
    }

    //get transaction id from user
    int id;
    printf("\nEnter transaction id to delete: ");
    scanf("%d", &id);

    //search for transaction and delete
    for(int i=0; i<numTransactions; i++){
        if(transactions[i].id == id){
            totalExpenses -= transactions[i].amount;
            for(int j=i; j<numTransactions; j++){
                transactions[j] = transactions[j+1];
            }
            numTransactions--;
            printf("\nTransaction deleted successfully!\n");
            return;
        }
    }
    
    printf("\nTransaction with id %d not found!\n", id);
}

//function to view all transactions
void viewTransactions(){
    //check if there are any transactions
    if(numTransactions == 0){
        printf("No transactions found!\n");
        return;
    }

    //print header
    printf("\nID\tDESCRIPTION\t\tAMOUNT\n");

    //print transactions
    for(int i=0; i<numTransactions; i++){
        printf("%d\t%-24s  $%.2f\n", transactions[i].id, transactions[i].description, transactions[i].amount);
    }
}

//function to view all categories
void viewCategories(){
    //check if there are any transactions
    if(numTransactions == 0){
        printf("No transactions found!\n");
        return;
    }

    //create an array for unique categories
    char categories[numTransactions][MAX_DESCRIPTION_LENGTH];
    int numCategories = 0;

    //loop through transactions and add unique categories to array
    for(int i=0; i<numTransactions; i++){
        //check if category already exists
        int found = 0;
        for(int j=0; j<numCategories; j++){
            if(strcmp(categories[j], transactions[i].description) == 0){
                found = 1;
                break;
            }
        }
        //add new category
        if(!found){
            strcpy(categories[numCategories], transactions[i].description);
            numCategories++;
        }
    }

    //print categories
    printf("\nCATEGORIES:\n");
    for(int i=0; i<numCategories; i++){
        printf("%d. %s\n", i+1, categories[i]);
    }
}

//function to view total expenses
void viewTotalExpenses(){
    printf("\nTotal Expenses: $%.2f\n", totalExpenses);
}

//function to authenticate user
void authenticate(){
    char password[20];
    printf("Please enter password to access the program: ");
    scanf("%s", password);

    if(strcmp(password, PASSWORD) != 0){
        printf("Invalid password. Program exiting...\n");
        exit(0);
    }
}