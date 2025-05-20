//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankRecord {
    int account_number;
    char name[50];
    char address[100];
    float balance;
};

int main() {
    int n, choice, found = 0;
    printf("Enter the number of records to store: ");
    scanf("%d", &n);
    struct BankRecord records[n];

    //store record information
    printf("\nEnter the account details for each record:\n");
    for(int i=0;i<n;i++) {
        printf("\nRecord %d:\n", i+1);
        printf("Account Number: ");
        scanf("%d", &records[i].account_number);
        printf("Name: ");
        getchar();
        fgets(records[i].name, 50, stdin);
        printf("Address: ");
        fgets(records[i].address, 100, stdin);
        printf("Balance: ");
        scanf("%f", &records[i].balance);
    }

    //menu driven system
    do {
        printf("\nMenu:\n1. Search record by account number\n2. Display all records\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                found = 0;
                int account_number;
                printf("\nEnter Account Number to search: ");
                scanf("%d", &account_number);
                for(int i=0;i<n;i++) {
                    if(records[i].account_number == account_number) {
                        printf("\n\nRecord found!\n\nAccount Number: %d\nName: %s\nAddress: %s\nBalance: %.2f\n", records[i].account_number, records[i].name, records[i].address, records[i].balance);
                        found = 1;
                    }
                }
                if(found == 0) {
                    printf("\n\nRecord not found!\n\n");
                }
                break;

            case 2:
                printf("\n\nAll Records:\n\n");
                for(int i=0;i<n;i++) {
                    printf("Account Number: %d\nName: %sAddress: %s\nBalance: %.2f\n\n", records[i].account_number, records[i].name, records[i].address, records[i].balance);
                }
                break;

            case 3:
                printf("\n\nExiting...\n\n");
                exit(0);

            default:
                printf("\n\nInvalid choice!\n\n");
                break;
        }
    } while(choice != 3);

    return 0;
}