//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bank record structure
typedef struct bank_record {
    int account_no;
    char name[50];
    float balance;
} Bank_Record;

// Function prototypes
void add_record(Bank_Record records[], int *num_records);
void display_records(Bank_Record records[], int num_records);

int main() {
    int num_records = 0;
    Bank_Record records[100];

    int choice = 0;
    do {
        printf("\n------------------------------------\n");
        printf("             BANK RECORDS            \n");
        printf("------------------------------------\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void add_record(Bank_Record records[], int *num_records) {
    printf("\nEnter account number: ");
    scanf("%d", &records[*num_records].account_no);

    printf("Enter name: ");
    scanf("%s", records[*num_records].name);

    printf("Enter balance: ");
    scanf("%f", &records[*num_records].balance);

    (*num_records)++;

    printf("Record added successfully!\n");
}

void display_records(Bank_Record records[], int num_records) {
    printf("\n------------------------------------\n");
    printf("             BANK RECORDS            \n");
    printf("------------------------------------\n");
    printf("Account No.     Name                Balance\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < num_records; i++) {
        printf("%-15d%-20s%.2f\n", records[i].account_no, records[i].name, records[i].balance);
    }
}