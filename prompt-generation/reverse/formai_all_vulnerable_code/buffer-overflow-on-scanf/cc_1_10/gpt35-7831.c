//FormAI DATASET v1.0 Category: Banking Record System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BankRecord {
    int recordID;
    char name[50];
    int accountNo;
    float balance;
    struct BankRecord *next;
}bankRecord;

bankRecord* createRecord(int id, char* name, int accountNo, float balance) {
    bankRecord* record = (bankRecord*) malloc(sizeof(bankRecord));
    record->recordID = id;
    strcpy(record->name, name);
    record->accountNo = accountNo;
    record->balance = balance;
    record->next = NULL;
    return record;
}

bankRecord* addRecord(bankRecord* head, bankRecord* record) {
    if(head == NULL) {
        return record;
    }
    else if(head->next == NULL) {
        head->next = record;
    }
    else {
        head->next = addRecord(head->next, record);
    }
    return head;
}

bankRecord* deleteRecord(bankRecord* head, int id) {
    if(head == NULL) {
        return NULL;
    }
    if(head->recordID == id) {
        bankRecord* temp = head->next;
        free(head);
        return temp;
    }
    head->next = deleteRecord(head->next, id);
    return head;
}

bankRecord* searchRecord(bankRecord* head, int id) {
    if(head == NULL) {
        return NULL;
    }
    if(head->recordID == id) {
        return head;
    }
    return searchRecord(head->next, id);
}

void printRecord(bankRecord* record) {
    printf("\n-------------------------------\n");
    printf("Record ID: %d\n", record->recordID);
    printf("Name: %s\n", record->name);
    printf("Account Number: %d\n", record->accountNo);
    printf("Balance: %.2f\n", record->balance);
    printf("-------------------------------\n");
}

void printAllRecords(bankRecord* head) {
    if(head == NULL) {
        printf("No records found\n");
        return;
    }
    else {
        while(head != NULL) {
            printRecord(head);
            head = head->next;
        }
    }
}

int main() {
    int choice, id, accountNo;
    char name[50];
    float balance;
    bankRecord* head = NULL;
    printf("1. Add Record\n");
    printf("2. Delete Record\n");
    printf("3. Search Record\n");
    printf("4. Print All Records\n");
    printf("5. Exit\n");
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter record ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter account number: ");
                scanf("%d", &accountNo);
                printf("Enter balance: ");
                scanf("%f", &balance);
                head = addRecord(head, createRecord(id, name, accountNo, balance));
                break;
            case 2:
                printf("Enter record ID to delete: ");
                scanf("%d", &id);
                head = deleteRecord(head, id);
                break;
            case 3:
                printf("Enter record ID to search: ");
                scanf("%d", &id);
                bankRecord* record = searchRecord(head, id);
                if(record == NULL) {
                    printf("Record not found\n");
                }
                else {
                    printRecord(record);
                }
                break;
            case 4:
                printAllRecords(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}