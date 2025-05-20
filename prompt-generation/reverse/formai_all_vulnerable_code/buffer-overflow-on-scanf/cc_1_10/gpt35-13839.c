//FormAI DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct bankRecord {
    char account_no[20];
    char account_holder_name[50];
    float balance;
} records[500];
 
int num_records = 0;
 
void addRecord() {
    struct bankRecord newRecord;
    printf("Enter Account number: \n");
    scanf("%s", newRecord.account_no);
    printf("Enter Account holder name: \n");
    getchar();
    fgets(newRecord.account_holder_name, 50, stdin);
    printf("Enter balance: \n");
    scanf("%f", &newRecord.balance);
    records[num_records++] = newRecord;
    printf("Record added successfully!\n");
}
 
void viewAllRecords() {
    if(num_records == 0) {
        printf("No records found!\n");
        return;
    }
    printf("Account No.\tAccount Holder Name\tBalance\n");
    for(int i=0; i<num_records; i++) {
        struct bankRecord currentRecord = records[i];
        printf("%s\t\t%s\t\t%.2f\n", currentRecord.account_no, currentRecord.account_holder_name, currentRecord.balance);
    }
}
 
void viewRecordByAccountNo() {
    if(num_records == 0) {
        printf("No records found!\n");
        return;
    }
    char searchAccountNo[20];
    printf("Enter account number to search: ");
    scanf("%s", searchAccountNo);
    for(int i=0; i<num_records; i++) {
        struct bankRecord currentRecord = records[i];
        if(strcmp(currentRecord.account_no, searchAccountNo) == 0) {
            printf("Account No.\tAccount Holder Name\tBalance\n");
            printf("%s\t\t%s\t\t%.2f\n", currentRecord.account_no, currentRecord.account_holder_name, currentRecord.balance);
            return;
        }
    }
    printf("No record with account number %s found!\n", searchAccountNo);
}
 
void menu() {
    printf("Banking Record System\n");
    printf("1. Add new record\n");
    printf("2. View all records\n");
    printf("3. View record by account number\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}
 
int main() {
    while(1) {
        menu();
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewAllRecords();
                break;
            case 3:
                viewRecordByAccountNo();
                break;
            case 4:
                printf("Exiting... Thank you for using Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}