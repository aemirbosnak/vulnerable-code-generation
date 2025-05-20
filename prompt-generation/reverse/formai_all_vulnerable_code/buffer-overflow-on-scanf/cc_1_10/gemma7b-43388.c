//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[50];
    int account_number;
    double balance;
} Record;

Record records[MAX_RECORDS];

int main() {

    // Initialize the records array
    for (int i = 0; i < MAX_RECORDS; i++) {
        records[i].name[0] = '\0';
        records[i].account_number = 0;
        records[i].balance = 0.0;
    }

    // Add a new record
    Record new_record;
    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter account number: ");
    scanf("%d", &new_record.account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_record.balance);

    int record_index = -1;
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (records[i].account_number == new_record.account_number) {
            record_index = i;
            break;
        }
    }

    if (record_index == -1) {
        // Add the new record to the end of the array
        records[MAX_RECORDS - 1] = new_record;
    } else {
        // Update the existing record
        records[record_index] = new_record;
    }

    // Print the updated records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].account_number);
        printf("Balance: %.2lf\n", records[i].balance);
        printf("\n");
    }

    return 0;
}