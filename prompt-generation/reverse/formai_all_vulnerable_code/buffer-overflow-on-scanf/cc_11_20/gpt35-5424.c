//FormAI DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#define MAX_RECORDS 100

struct Account {
    int accNum;
    char name[50];
    float balance;
};

struct Record {
    int recordNum;
    struct Account account;
    char transactionType[50];
    float transactionAmount;
};

int main() {
    struct Record records[MAX_RECORDS];
    int recordCount = 0;
    int option, accNum;

    // Program menu
    printf("Welcome to the Visionary Bank Record System\n");
    do {
        printf("\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Add a new record
                if (recordCount < MAX_RECORDS) {
                    struct Record newRecord;
                    printf("Enter Account Number: ");
                    scanf("%d", &accNum);
                    newRecord.recordNum = recordCount + 1;
                    newRecord.account.accNum = accNum;
                    printf("Enter Account Holder Name: ");
                    scanf("%s", newRecord.account.name);
                    printf("Enter Transaction Type: ");
                    scanf("%s", newRecord.transactionType);
                    printf("Enter Transaction Amount: ");
                    scanf("%f", &newRecord.transactionAmount);
                    printf("Enter Account Balance: ");
                    scanf("%f", &newRecord.account.balance);
                    records[recordCount++] = newRecord;
                }
                else {
                    printf("Record limit exceeded!\n");
                }
                break;
            case 2:
                // Display all records
                printf("No. | Acc Num | Acc Holder Name | Transaction Type | Transaction Amount | Balance\n");
                printf("----|---------|----------------|------------------|--------------------|--------\n");
                for (int i = 0; i < recordCount; i++) {
                    printf("%-3d | %-7d | %-15s | %-16s | %-18.2f | %.2f\n",
                           records[i].recordNum, records[i].account.accNum, records[i].account.name,
                           records[i].transactionType, records[i].transactionAmount, records[i].account.balance);
                }
                break;
            case 3:
                // Search for a record
                printf("Enter Account Number: ");
                scanf("%d", &accNum);
                for (int i = 0; i < recordCount; i++) {
                    if (records[i].account.accNum == accNum) {
                        printf("No. | Acc Num | Acc Holder Name | Transaction Type | Transaction Amount | Balance\n");
                        printf("----|---------|----------------|------------------|--------------------|--------\n");
                        printf("%-3d | %-7d | %-15s | %-16s | %-18.2f | %.2f\n",
                               records[i].recordNum, records[i].account.accNum, records[i].account.name,
                               records[i].transactionType, records[i].transactionAmount, records[i].account.balance);
                        break;
                    }
                    else if (i == recordCount - 1) {
                        printf("Record not found!\n");
                    }
                }
                break;
            case 4:
                // Exiting the program
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 4);

    return 0;
}