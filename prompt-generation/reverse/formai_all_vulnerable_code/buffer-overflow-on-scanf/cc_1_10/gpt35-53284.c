//FormAI DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Record;

/* Function prototypes */
void addRecord(Record records[], int *count);
void viewRecords(Record records[], int count);
void searchRecord(Record records[], int count);
void deleteRecord(Record records[], int *count);

int main() {
    Record records[100];
    int count = 0;
    int choice;

    do {
        printf("\nBanking Record System\n");
        printf("-----------------------------------\n");
        printf("1. Add a new record\n");
        printf("2. View all records\n");
        printf("3. Search for a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addRecord(records, &count);
                break;
                
            case 2:
                viewRecords(records, count);
                break;
                
            case 3:
                searchRecord(records, count);
                break;
                
            case 4:
                deleteRecord(records, &count);
                break;
                
            case 5:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

/* Function to add a new record to the system */
void addRecord(Record records[], int *count) {
    Record newRecord;
    
    printf("\nEnter account number: ");
    scanf("%d", &newRecord.account_number);
    
    printf("Enter name: ");
    scanf("%s", newRecord.name);

    printf("Enter balance: ");
    scanf("%f", &newRecord.balance);
    
    records[*count] = newRecord;
    (*count)++;
    
    printf("\nRecord added successfully.\n");
}

/* Function to view all records in the system */
void viewRecords(Record records[], int count) {
    if(count == 0) {
        printf("\nNo records found.\n");
        return;
    }
    
    printf("\n%-20s %-20s %-20s\n", "Account Number", "Name", "Balance");
    printf("-----------------------------------------------------------\n");
    
    for(int i = 0; i < count; i++) {
        printf("%-20d %-20s %-20.2f\n", records[i].account_number, records[i].name, records[i].balance);
    }
}

/* Function to search for a specific record in the system */
void searchRecord(Record records[], int count) {
    if(count == 0) {
        printf("\nNo records found.\n");
        return;
    }
    
    int accountNumber;
    printf("\nEnter account number to search for: ");
    scanf("%d", &accountNumber);
    
    for(int i = 0; i < count; i++) {
        if(records[i].account_number == accountNumber) {
            printf("\n%-20s %-20s %-20s\n", "Account Number", "Name", "Balance");
            printf("-----------------------------------------------------------\n");
            printf("%-20d %-20s %-20.2f\n", records[i].account_number, records[i].name, records[i].balance);
            return;
        }
    }
    
    printf("\nRecord not found.\n");
}

/* Function to delete a specific record from the system */
void deleteRecord(Record records[], int *count) {
    if(*count == 0) {
        printf("\nNo records found.\n");
        return;
    }
    
    int accountNumber;
    printf("\nEnter account number to delete: ");
    scanf("%d", &accountNumber);
    
    for(int i = 0; i < *count; i++) {
        if(records[i].account_number == accountNumber) {
            for(int j = i; j < *count - 1; j++) {
                records[j] = records[j + 1];
            }
            (*count)--;
            printf("\nRecord deleted successfully.\n");
            return;
        }
    }
    
    printf("\nRecord not found.\n");
}