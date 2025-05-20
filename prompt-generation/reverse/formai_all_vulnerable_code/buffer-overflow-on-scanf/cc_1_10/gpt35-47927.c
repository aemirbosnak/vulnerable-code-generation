//FormAI DATASET v1.0 Category: Banking Record System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankRecord{
    char name[30];
    char accno[20];
    float balance;
}*records;

int numOfRecords;

void createRecord(){
    printf("Enter the number of records: ");
    scanf("%d", &numOfRecords);
    records = (struct BankRecord*) malloc(numOfRecords * sizeof(struct BankRecord));
    for(int i=0; i<numOfRecords; i++){
        printf("\nEnter the name of customer %d: ", i+1);
        scanf(" %[^\n]s", records[i].name);
        printf("Enter the account number of customer %d: ", i+1);
        scanf(" %[^\n]s", records[i].accno);
        printf("Enter the opening balance of customer %d: ", i+1);
        scanf("%f", &records[i].balance);
    }
}

void viewAllRecords(){
    printf("\nAll Bank Records\n");
    for(int i=0; i<numOfRecords; i++){
        printf("\n---------------\n");
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %s\n", records[i].accno);
        printf("Balance: %.2f\n", records[i].balance);
    }
    printf("\n\n");
}

void searchRecord(){
    char searchName[30];
    printf("\nEnter the name of the customer to search: ");
    scanf(" %[^\n]s", searchName);
    int found = 0;
    for(int i=0; i<numOfRecords; i++){
        if(strcmp(records[i].name, searchName) == 0){
            printf("\n---------------\n");
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %s\n", records[i].accno);
            printf("Balance: %.2f\n", records[i].balance);
            found = 1;
        }
    }
    if(!found){
        printf("\nCustomer not found.\n");
    }
    printf("\n\n");
}

void depositMoney(){
    char accno[20];
    float amount;
    printf("\nEnter the account number to deposit money: ");
    scanf(" %[^\n]s", accno);
    int found = 0;
    for(int i=0; i<numOfRecords; i++){
        if(strcmp(records[i].accno, accno) == 0){
            printf("\nEnter the amount to deposit: ");
            scanf("%f", &amount);
            records[i].balance += amount;
            printf("\nDeposit successful. Available balance: %.2f\n", records[i].balance);
            found = 1;
        }
    }
    if(!found){
        printf("\nAccount not found.\n");
    }
    printf("\n\n");
}

void withdrawMoney(){
    char accno[20];
    float amount;
    printf("\nEnter the account number to withdraw money: ");
    scanf(" %[^\n]s", accno);
    int found = 0;
    for(int i=0; i<numOfRecords; i++){
        if(strcmp(records[i].accno, accno) == 0){
            printf("\nEnter the amount to withdraw: ");
            scanf("%f", &amount);
            if(records[i].balance >= amount){
                records[i].balance -= amount;
                printf("\nWithdrawal successful. Available balance: %.2f\n", records[i].balance);
            }
            else{
                printf("\nInsufficient balance.\n");
            }
            found = 1;
        }
    }
    if(!found){
        printf("\nAccount not found.\n");
    }
    printf("\n\n");
}

void deleteRecord(){
    char accno[20];
    printf("\nEnter the account number to delete record: ");
    scanf(" %[^\n]s", accno);
    int foundIndex = -1;
    for(int i=0; i<numOfRecords; i++){
        if(strcmp(records[i].accno, accno) == 0){
            foundIndex = i;
            break;
        }
    }
    if(foundIndex != -1){
        for(int i=foundIndex; i<numOfRecords-1; i++){
            strcpy(records[i].name, records[i+1].name);
            strcpy(records[i].accno, records[i+1].accno);
            records[i].balance = records[i+1].balance;
        }
        numOfRecords--;
        printf("\nRecord deleted.\n");
    }
    else{
        printf("\nAccount not found.\n");
    }
    printf("\n\n");
}

int main(){
    int choice;
    while(1){
        printf("Welcome to the Banking Record System\n");
        printf("1. Create new record(s)\n");
        printf("2. View all records\n");
        printf("3. Search record by name\n");
        printf("4. Deposit money\n");
        printf("5. Withdraw money\n");
        printf("6. Delete record\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                createRecord();
                break;

            case 2:
                viewAllRecords();
                break;

            case 3:
                searchRecord();
                break;

            case 4:
                depositMoney();
                break;

            case 5:
                withdrawMoney();
                break;

            case 6:
                deleteRecord();
                break;

            case 7:
                printf("\nThank you for using the Banking Record System.\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n\n");
        }
    }
    free(records);
    return 0;
}