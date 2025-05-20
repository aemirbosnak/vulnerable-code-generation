//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some constant values
#define MAX_NAME_LENGTH 30
#define MAX_ADDRESS_LENGTH 100
#define MAX_RECORDS 100

// Struct definition for customer record
typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    double balance;
} CustomerRecord;

// Function prototypes
void addRecord(CustomerRecord customerRecords[], int *numRecordsPtr);
CustomerRecord getRecord(int account_number, CustomerRecord customerRecords[], int numRecords);
void updateRecord(int account_number, CustomerRecord customerRecords[], int numRecords);
void deleteRecord(int account_number, CustomerRecord customerRecords[], int *numRecordsPtr);
void printAllRecords(CustomerRecord customerRecords[], int numRecords);
void printRecord(CustomerRecord record);

int main() {
    CustomerRecord customerRecords[MAX_RECORDS];
    int numRecords = 0;
    int choice;
    int account_number;

    do {
        printf("\n");
        printf("1. Add a new record\n");
        printf("2. Get a record\n");
        printf("3. Update a record\n");
        printf("4. Delete a record\n");
        printf("5. Print all records\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(customerRecords, &numRecords);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printRecord(getRecord(account_number, customerRecords, numRecords));
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                updateRecord(account_number, customerRecords, numRecords);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                deleteRecord(account_number, customerRecords, &numRecords);
                break;
            case 5:
                printAllRecords(customerRecords, numRecords);
                break;
            case 6:
                printf("Exiting program...\n\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void addRecord(CustomerRecord customerRecords[], int *numRecordsPtr) {
    CustomerRecord customerRecord;

    printf("Enter account number: ");
    scanf("%d", &customerRecord.account_number);

    // Check if account number is already in the records
    for (int i = 0; i < *numRecordsPtr; i++) {
        if (customerRecords[i].account_number == customerRecord.account_number) {
            printf("An account with that number already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf("%s", customerRecord.name);

    printf("Enter address: ");
    scanf("%s", customerRecord.address);

    printf("Enter balance: ");
    scanf("%lf", &customerRecord.balance);

    customerRecords[*numRecordsPtr] = customerRecord;
    (*numRecordsPtr)++;
}

CustomerRecord getRecord(int account_number, CustomerRecord customerRecords[], int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        if (customerRecords[i].account_number == account_number) {
            return customerRecords[i];
        }
    }

    printf("Record not found.\n");
    return customerRecords[0];
}

void updateRecord(int account_number, CustomerRecord customerRecords[], int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        if (customerRecords[i].account_number == account_number) {
            printf("Enter name: ");
            scanf("%s", customerRecords[i].name);

            printf("Enter address: ");
            scanf("%s", customerRecords[i].address);

            printf("Enter balance: ");
            scanf("%lf", &customerRecords[i].balance);

            printf("Record successfully updated.\n");
            return;
        }
    }

    printf("Record not found.\n");
}

void deleteRecord(int account_number, CustomerRecord customerRecords[], int *numRecordsPtr) {
    int indexToDelete = -1;

    for (int i = 0; i < *numRecordsPtr; i++) {
        if (customerRecords[i].account_number == account_number) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("Record not found.\n");
        return;
    }

    for (int i = indexToDelete; i < (*numRecordsPtr)-1; i++) {
        customerRecords[i] = customerRecords[i+1];
    }

    (*numRecordsPtr)--;
    printf("Record successfully deleted.\n");
}

void printAllRecords(CustomerRecord customerRecords[], int numRecords) {
    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Account Number\t\tName\t\tAddress\t\tBalance\n");
    printf("========================================================\n");

    for (int i = 0; i < numRecords; i++) {
        CustomerRecord record = customerRecords[i];
        printf("%d\t\t%s\t\t%s\t\t%.2lf\n", record.account_number, record.name, record.address, record.balance);
    }
}

void printRecord(CustomerRecord record) {
    printf("Account Number\t\tName\t\tAddress\t\tBalance\n");
    printf("========================================================\n");
    printf("%d\t\t%s\t\t%s\t\t%.2lf\n", record.account_number, record.name, record.address, record.balance);
}