//FormAI DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating a structure to store the banking record
struct BankingRecord {
    char name[50];
    int accountNumber;
    float balance;
};

int main() {
    int numRecords = 0;
    printf("Enter the number of banking records: ");
    scanf("%d", &numRecords);

    // Allocating memory to store records dynamically
    struct BankingRecord *bankRecords = (struct BankingRecord*) malloc(numRecords * sizeof(struct BankingRecord));

    // Reading input from user and storing it in the array
    for (int i = 0; i < numRecords; i++) {
        printf("\nEnter details of record %d:\n", i+1);
        printf("Name: ");
        scanf("%s", bankRecords[i].name);
        printf("Account Number: ");
        scanf("%d", &bankRecords[i].accountNumber);
        printf("Balance: ");
        scanf("%f", &bankRecords[i].balance);
    }

    // Displaying the input records
    printf("\n\nInput Records:\n\n");
    printf("Name\tAccount Number\tBalance\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%s\t%d\t%.2f\n", bankRecords[i].name, bankRecords[i].accountNumber, bankRecords[i].balance);
    }

    // Sorting the records based on balance in ascending order
    for (int i = 0; i < numRecords; i++) {
        for (int j = i+1; j < numRecords; j++) {
            if (bankRecords[j].balance < bankRecords[i].balance) {
                struct BankingRecord temp = bankRecords[i];
                bankRecords[i] = bankRecords[j];
                bankRecords[j] = temp;
            }
        }
    }

    // Displaying the sorted records
    printf("\n\nSorted Records:\n\n");
    printf("Name\tAccount Number\tBalance\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%s\t%d\t%.2f\n", bankRecords[i].name, bankRecords[i].accountNumber, bankRecords[i].balance);
    }

    // Freeing dynamically allocated memory
    free(bankRecords);

    return 0;
}