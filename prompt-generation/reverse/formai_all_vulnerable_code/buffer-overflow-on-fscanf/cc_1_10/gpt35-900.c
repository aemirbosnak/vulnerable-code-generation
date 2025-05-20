//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    char accountNumber[10];
    char accountHolderName[100];
    double accountBalance;
    char accountType[20];
};

int main() {
    struct BankAccount account;
    char choice;
    FILE *filePointer;

    // Open or create a file to store account records
    filePointer = fopen("bankRecords.txt", "a+");

    if (!filePointer) {
        printf("Failed to open file. Exiting.\n");
        exit(1);
    }

    // Prompt the user to choose an action to perform
    printf("What would you like to do?\n");
    printf("1. Add an account\n");
    printf("2. Display all accounts\n");
    printf("3. Edit an account\n");
    printf("4. Exit\n");

    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            // Get account details from user and save them to file
            printf("Enter account number: ");
            scanf("%s", account.accountNumber);

            printf("Enter account holder name: ");
            scanf("%s", account.accountHolderName);

            printf("Enter account balance: ");
            scanf("%lf", &account.accountBalance);

            printf("Enter account type: ");
            scanf("%s", account.accountType);

            fprintf(filePointer, "%s\t%s\t%.2lf\t%s\n", account.accountNumber, account.accountHolderName, account.accountBalance, account.accountType);

            printf("Account added successfully!\n");
            break;
        case '2':
            // Display all accounts from file
            rewind(filePointer);

            printf("Account Number\tAccount Holder Name\tAccount Balance\tAccount Type\n");

            while (fscanf(filePointer, "%s\t%s\t%lf\t%s\n", account.accountNumber, account.accountHolderName, &account.accountBalance, account.accountType) != EOF) {
                printf("%s\t%s\t\t$%.2lf\t\t%s\n", account.accountNumber, account.accountHolderName, account.accountBalance, account.accountType);
            }
            break;
        case '3':
            // Edit an existing account by account number
            printf("Enter account number to edit: ");
            char accountNumber[10];
            scanf("%s", accountNumber);

            char accountLine[256];
            char *tempFile = "temp.txt";
            FILE *tempPointer = fopen(tempFile, "w");

            rewind(filePointer);

            while (fgets(accountLine, sizeof(accountLine), filePointer)) {
                char *token = strtok(accountLine, "\t");
                if (strcmp(token, accountNumber) == 0) {
                    printf("Enter updated account holder name: ");
                    scanf("%s", account.accountHolderName);

                    printf("Enter updated account balance: ");
                    scanf("%lf", &account.accountBalance);

                    printf("Enter updated account type: ");
                    scanf("%s", account.accountType);

                    fprintf(tempPointer, "%s\t%s\t%.2lf\t%s\n", account.accountNumber, account.accountHolderName, account.accountBalance, account.accountType);
                } else {
                    fprintf(tempPointer, "%s", accountLine);
                }
            }

            fclose(filePointer);
            fclose(tempPointer);

            remove("bankRecords.txt");
            rename(tempFile, "bankRecords.txt");

            filePointer = fopen("bankRecords.txt", "a+");
            break;
        case '4':
            // Close the file and exit
            fclose(filePointer);
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Exiting.\n");
            exit(1);
    }

    // Close the file and exit
    fclose(filePointer);
    return 0;
}