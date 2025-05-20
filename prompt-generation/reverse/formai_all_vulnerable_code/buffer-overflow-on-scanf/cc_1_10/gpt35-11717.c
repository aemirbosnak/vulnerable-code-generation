//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for each bank record
typedef struct {
    char name[50];
    int account_num;
    double balance;
} BankRecord;

// Function to add new record to the bank records array
int addRecord(BankRecord records[], int num_records) {
    BankRecord new_record;
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter account number: ");
    scanf("%d", &new_record.account_num);
    printf("Enter balance: ");
    scanf("%lf", &new_record.balance);
    
    records[num_records] = new_record;
    return num_records + 1;
}

// Function to delete record from the bank records array
int deleteRecord(BankRecord records[], int num_records) {
    int account_num;
    printf("Enter account number to delete: ");
    scanf("%d", &account_num);
    
    int i;
    for (i = 0; i < num_records; i++) {
        if (records[i].account_num == account_num) {
            break;
        }
    }
    
    if (i == num_records) {
        printf("Account number not found.\n");
        return num_records;
    }
    
    memmove(records + i, records + i + 1, (num_records - i - 1) * sizeof(BankRecord));
    return num_records - 1;
}

// Function to update record in the bank records array
void updateRecord(BankRecord records[], int num_records) {
    int account_num;
    printf("Enter account number to update: ");
    scanf("%d", &account_num);
    
    int i;
    for (i = 0; i < num_records; i++) {
        if (records[i].account_num == account_num) {
            break;
        }
    }
    
    if (i == num_records) {
        printf("Account number not found.\n");
        return;
    }
    
    printf("Enter new name: ");
    scanf("%s", records[i].name);
    printf("Enter new balance: ");
    scanf("%lf", &records[i].balance);
}

// Function to print all bank records
void printRecords(BankRecord records[], int num_records) {
    printf("Name\tAccount#\tBalance\n");
    int i;
    for (i = 0; i < num_records; i++) {
        printf("%s\t%d\t\t%.2lf\n", records[i].name, records[i].account_num, records[i].balance);
    }
}

int main() {
    BankRecord records[100];
    int num_records = 0;
    int choice;
    
    do {
        printf("\n1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Update record\n");
        printf("4. Print records\n");
        printf("5. Exit\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                num_records = addRecord(records, num_records);
                break;
            case 2:
                num_records = deleteRecord(records, num_records);
                break;
            case 3:
                updateRecord(records, num_records);
                break;
            case 4:
                printRecords(records, num_records);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    
    return 0;
}