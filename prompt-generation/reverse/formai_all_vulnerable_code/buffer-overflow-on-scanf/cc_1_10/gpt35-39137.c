//FormAI DATASET v1.0 Category: Banking Record System ; Style: retro
#include<stdio.h>
#include<string.h>

// Define a structure for bank records
struct bankRecord{
    char name[50];
    int accountNo;
    float balance;
};

// Function for adding a new bank record
void addRecord(struct bankRecord records[], int *numRecords){
    struct bankRecord newRecord;
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter account number: ");
    scanf("%d", &newRecord.accountNo);
    printf("Enter initial balance: ");
    scanf("%f", &newRecord.balance);
    records[*numRecords] = newRecord;
    (*numRecords)++;
    printf("\nRecord added successfully!\n\n");
}

// Function for searching a bank record by name
void searchRecord(struct bankRecord records[], int numRecords){
    char nameSearch[50];
    printf("Enter name to search: ");
    scanf("%s", nameSearch);
    for(int i=0; i<numRecords; i++){
        if(strcmp(nameSearch, records[i].name) == 0){
            printf("\nName: %s\nAccount Number: %d\nBalance: %.2f\n\n", records[i].name, records[i].accountNo, records[i].balance);
            return;
        }
    }
    printf("\nRecord not found!\n\n");
}

// Function for editing a bank record by account number
void editRecord(struct bankRecord records[], int numRecords){
    int accountSearch;
    printf("Enter account number to edit: ");
    scanf("%d", &accountSearch);
    for(int i=0; i<numRecords; i++){
        if(accountSearch == records[i].accountNo){
            printf("\nEnter new name: ");
            scanf("%s", records[i].name);
            printf("Enter new balance: ");
            scanf("%f", &records[i].balance);
            printf("\nRecord updated successfully!\n\n");
            return;
        }
    }
    printf("\nRecord not found!\n\n");
}

// Function for printing all bank records
void printRecords(struct bankRecord records[], int numRecords){
    if(numRecords == 0){
        printf("\nNo records found!\n\n");
        return;
    }
    printf("\nBank Records:\n\n");
    for(int i=0; i<numRecords; i++){
        printf("Name: %s\nAccount Number: %d\nBalance: %.2f\n\n", records[i].name, records[i].accountNo, records[i].balance);
    }
}

int main(){
    // Declare variables and initialize to empty values
    struct bankRecord records[100];
    int numRecords = 0;
    char choice = '\0';
    
    // Main menu for banking record system
    while(choice != '5'){
        printf("Choose an option:\n");
        printf("1 - Add Record\n");
        printf("2 - Search Record\n");
        printf("3 - Edit Record\n");
        printf("4 - Print All Records\n");
        printf("5 - Exit\n");
        printf("> ");
        scanf(" %c", &choice);
        switch(choice){
            case '1':
                addRecord(records, &numRecords);
                break;
            case '2':
                searchRecord(records, numRecords);
                break;
            case '3':
                editRecord(records, numRecords);
                break;
            case '4':
                printRecords(records, numRecords);
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}