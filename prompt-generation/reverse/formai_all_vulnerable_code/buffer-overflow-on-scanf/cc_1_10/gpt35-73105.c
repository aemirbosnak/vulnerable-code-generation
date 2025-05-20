//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define bank record structure
struct bankRecord {
    char name[100];
    int accountNumber;
    double balance;
};

// Define function for printing record
void printRecord(struct bankRecord *r) {
    printf("%s\n", r->name);
    printf("Account Number: %d\n", r->accountNumber);
    printf("Balance: %.2f\n", r->balance);
}

int main() {
    int choice, numRecords = 0;
    struct bankRecord records[100];

    while(1) {
        printf("1. Add record\n");
        printf("2. Display record\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", records[numRecords].name);
                printf("Enter account number: ");
                scanf("%d", &records[numRecords].accountNumber);
                printf("Enter balance: ");
                scanf("%lf", &records[numRecords].balance);
                printf("Record added successfully.\n");
                numRecords++;
                break;
            case 2:
                for(int i=0; i<numRecords; i++) {
                    printf("Record %d:\n", i+1);
                    printRecord(&records[i]);
                }
                break;
            case 3:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}