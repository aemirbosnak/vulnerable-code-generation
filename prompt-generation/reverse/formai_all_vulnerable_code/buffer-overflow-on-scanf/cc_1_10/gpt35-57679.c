//FormAI DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Record;

void printRecord(Record r) {
    printf("Account Number: %d\n", r.account_number);
    printf("Name: %s\n", r.name);
    printf("Balance: %.2f\n", r.balance);
}

int searchRecord(Record records[], int numRecords, int accountNum) {
    for (int i = 0; i < numRecords; i++) {
        if (records[i].account_number == accountNum) {
            return i;
        }
    }
    return -1;
}

Record createRecord() {
    Record r;
    
    printf("Enter Account Number: ");
    scanf("%d", &r.account_number);
    fflush(stdin); // clear input buffer
    
    printf("Enter Name: ");
    fgets(r.name, sizeof(r.name), stdin);
    r.name[strcspn(r.name, "\n")] = 0; // remove trailing newline 
    
    printf("Enter Balance: ");
    scanf("%f", &r.balance);
    fflush(stdin); // clear input buffer
    
    return r;
}

void addRecord(Record records[], int *numRecords) {
    Record newRecord = createRecord();
    records[*numRecords] = newRecord;
    *numRecords += 1;
    printf("Record added successfully.\n");
}

void deposit(Record records[], int numRecords, int accountNum) {
    int index = searchRecord(records, numRecords, accountNum);
    if (index == -1) {
        printf("Record not found.\n");
        return;
    }
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    fflush(stdin); // clear input buffer
    
    records[index].balance += amount;
    printf("Deposit successful. New balance: %.2f\n", records[index].balance);
}

void withdraw(Record records[], int numRecords, int accountNum) {
    int index = searchRecord(records, numRecords, accountNum);
    if (index == -1) {
        printf("Record not found.\n");
        return;
    }
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    fflush(stdin); // clear input buffer
    
    if (amount > records[index].balance) {
        printf("Withdrawal amount exceeds available balance.\n");
        return;
    }
    
    records[index].balance -= amount;
    printf("Withdrawal successful. New balance: %.2f\n", records[index].balance);
}

void displayAllRecords(Record records[], int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        printf("Record #%d:\n", i+1);
        printRecord(records[i]);
        printf("\n");
    }
}

int main() {
    Record records[100];
    int numRecords = 0;
    int choice, accountNum;
    
    printf("********** C BANKING RECORD SYSTEM **********\n");
    printf("\n");
    
    while (1) {
        printf("1. Add Record\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin); // clear input buffer
        
        switch (choice) {
            case 1:
                addRecord(records, &numRecords);
                break;
            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accountNum);
                fflush(stdin); // clear input buffer
                deposit(records, numRecords, accountNum);
                break;
            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accountNum);
                fflush(stdin); // clear input buffer
                withdraw(records, numRecords, accountNum);
                break;
            case 4:
                displayAllRecords(records, numRecords);
                break;
            case 5:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}