//FormAI DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold banking records
struct banking_record {
    char name[50];
    int account_number;
    float balance;
};

int main() {
    int num_records;
    printf("Enter the number of banking records to create: ");
    scanf("%d", &num_records);
    
    // create an array of banking record structures
    struct banking_record records[num_records];
    
    // populate each record with user input
    for (int i = 0; i < num_records; i++) {
        printf("\nRecord %d:", i+1);
        printf("\nEnter name: ");
        scanf("%s", records[i].name);
        printf("Enter account number: ");
        scanf("%d", &records[i].account_number);
        printf("Enter balance: ");
        scanf("%f", &records[i].balance);
    }
    
    // print out the records
    printf("\nBanking Records:");
    for (int i = 0; i < num_records; i++) {
        printf("\nRecord %d: Name - %s, Account Number - %d, Balance - $%.2f", i+1, records[i].name, records[i].account_number, records[i].balance);
    }
    
    // find the record with the highest balance
    int highest_balance_index = 0;
    for (int i = 1; i < num_records; i++) {
        if (records[i].balance > records[highest_balance_index].balance) {
            highest_balance_index = i;
        }
    }
    printf("\n\nRecord with the highest balance: %s, Account Number - %d, Balance - $%.2f", records[highest_balance_index].name, records[highest_balance_index].account_number, records[highest_balance_index].balance);
    
    // find the average balance across all records
    float total_balance = 0;
    for (int i = 0; i < num_records; i++) {
        total_balance += records[i].balance;
    }
    float average_balance = total_balance / num_records;
    printf("\nAverage balance across all records: $%.2f", average_balance);
    
    return 0;
}