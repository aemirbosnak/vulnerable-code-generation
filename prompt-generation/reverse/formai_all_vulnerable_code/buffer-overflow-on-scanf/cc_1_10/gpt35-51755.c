//FormAI DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // maximum number of records that can be stored

// defining a structure to hold each record
struct bankRecord {
    int account_no;
    char name[50];
    double balance;
};

void addRecord(struct bankRecord records[], int *record_count);
void displayRecords(struct bankRecord records[], int record_count);
void searchRecord(struct bankRecord records[], int record_count);
void editRecord(struct bankRecord records[], int record_count);

int main() {
    struct bankRecord records[MAX_RECORDS]; // array of structures to hold records
    int record_count = 0; // counter for number of records
    
    int choice; // variable to hold user's choice
    
    // displaying the menu and getting user's choice
    do {
        printf("\nBank Record System\n");
        printf("1. Add a New Record\n");
        printf("2. Display All Records\n");
        printf("3. Search a Record\n");
        printf("4. Edit a Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addRecord(records, &record_count); // calling addRecord function
                break;
            case 2:
                displayRecords(records, record_count); // calling displayRecords function
                break;
            case 3:
                searchRecord(records, record_count); // calling searchRecord function
                break;
            case 4:
                editRecord(records, record_count); // calling editRecord function
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}

void addRecord(struct bankRecord records[], int *record_count) {
    if(*record_count >= MAX_RECORDS) { // checking if maximum limit has been reached
        printf("Maximum limit reached! Cannot add new record.\n");
        return;
    }
    
    printf("Enter account number: ");
    scanf("%d", &records[*record_count].account_no);
    
    printf("Enter name: ");
    scanf("%s", records[*record_count].name);
    
    printf("Enter balance: ");
    scanf("%lf", &records[*record_count].balance);
    
    printf("Record added successfully!\n");
    
    (*record_count)++; // incrementing the record counter
}

void displayRecords(struct bankRecord records[], int record_count) {
    // checking if there are any records to display
    if(record_count == 0) {
        printf("No records found!\n");
        return;
    }
    
    printf("\nAccount No.\tName\t\t\tBalance\n");
    for(int i=0; i<record_count; i++) {
        printf("%d\t\t%s\t\t\t%.2lf\n", records[i].account_no, records[i].name, records[i].balance);
    }
}

void searchRecord(struct bankRecord records[], int record_count) {
    // checking if there are any records to search
    if(record_count == 0) {
        printf("No records found!\n");
        return;
    }
    
    int account_no;
    printf("Enter account number to search: ");
    scanf("%d", &account_no);
    
    // searching for the record with given account number
    for(int i=0; i<record_count; i++) {
        if(records[i].account_no == account_no) {
            printf("\nAccount No.\tName\t\t\tBalance\n");
            printf("%d\t\t%s\t\t\t%.2lf\n", records[i].account_no, records[i].name, records[i].balance);
            return;
        }
    }
    
    // if the function reaches here it means record was not found
    printf("Record not found!\n");
}

void editRecord(struct bankRecord records[], int record_count) {
    // checking if there are any records to edit
    if(record_count == 0) {
        printf("No records found!\n");
        return;
    }
    
    int account_no;
    printf("Enter account number to edit: ");
    scanf("%d", &account_no);
    
    // searching for the record with given account number
    for(int i=0; i<record_count; i++) {
        if(records[i].account_no == account_no) {
            printf("\nAccount No.\tName\t\t\tBalance\n");
            printf("%d\t\t%s\t\t\t%.2lf\n", records[i].account_no, records[i].name, records[i].balance);
            
            printf("Enter new account number: ");
            scanf("%d", &records[i].account_no);
            
            printf("Enter new name: ");
            scanf("%s", records[i].name);
            
            printf("Enter new balance: ");
            scanf("%lf", &records[i].balance);
            
            printf("Record edited successfully!\n");
            return;
        }
    }
    
    // if the function reaches here it means record was not found
    printf("Record not found!\n");
}