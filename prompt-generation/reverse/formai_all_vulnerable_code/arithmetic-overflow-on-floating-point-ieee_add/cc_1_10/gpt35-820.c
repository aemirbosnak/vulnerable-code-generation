//FormAI DATASET v1.0 Category: Banking Record System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct bankRecord{
    int accountNumber;
    char firstName[20];
    char lastName[20];
    float balance;
};

void displayRecord(struct bankRecord record);
struct bankRecord createRecord();
void deposit(struct bankRecord *record, float amount);
void withdraw(struct bankRecord *record, float amount);

int main()
{
    int numRecords = 0;
    printf("Enter number of records to be created: ");
    scanf("%d", &numRecords);
    
    struct bankRecord *records = (struct bankRecord*) malloc(numRecords * sizeof(struct bankRecord));
    
    for(int i=0; i < numRecords; i++){
        printf("\nEnter details for record %d\n", i+1);
        records[i] = createRecord();
    }
    
    printf("\nRecords created successfully!\n");
    
    while(1){
        int accountNumber = -1;
        printf("\nEnter account number: ");
        scanf("%d", &accountNumber);
        
        if(accountNumber == -1){
            break;
        }
        
        struct bankRecord record = records[accountNumber-1];
        printf("\nAccount details:\n");
        displayRecord(record);
        
        int transactionType = 0;
        printf("\n\nEnter 1 for deposit, 2 for withdrawal, any other key to continue: ");
        scanf("%d", &transactionType);
        
        switch(transactionType){
            case 1:
                printf("\n\nEnter deposit amount: ");
                float depositAmount;
                scanf("%f", &depositAmount);
                deposit(&record, depositAmount);
                printf("\n\nTransaction successful!\n");
                displayRecord(record);
                break;
                
            case 2:
                printf("\n\nEnter withdrawal amount: ");
                float withdrawalAmount;
                scanf("%f", &withdrawalAmount);
                withdraw(&record, withdrawalAmount);
                printf("\n\nTransaction successful!\n");
                displayRecord(record);
                break;
                
            default:
                break;
        }
    }
    
    free(records);
    
    return 0;
}

void displayRecord(struct bankRecord record){
    printf("\nAccount Number: %d", record.accountNumber);
    printf("\nFirst Name: %s", record.firstName);
    printf("\nLast Name: %s", record.lastName);
    printf("\nBalance: %.2f\n", record.balance);
}

struct bankRecord createRecord(){
    struct bankRecord record;
    
    printf("\nEnter Account Number: ");
    scanf("%d", &record.accountNumber);
    
    printf("Enter First Name: ");
    scanf("%s", &record.firstName);
    
    printf("Enter Last Name: ");
    scanf("%s", &record.lastName);
    
    printf("Enter Account Balance: ");
    scanf("%f", &record.balance);
    
    return record;
}

void deposit(struct bankRecord *record, float amount){
    record->balance += amount;
}

void withdraw(struct bankRecord *record, float amount){
    if(record->balance < amount){
        printf("\n\nError: Not enough balance to withdraw %f\n", amount);
        return;
    }
    
    record->balance -= amount;
}