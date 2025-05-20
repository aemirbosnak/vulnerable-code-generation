//FormAI DATASET v1.0 Category: Banking Record System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to store bank record
typedef struct bank_record {
    char name[50];
    int account_number;
    float balance;
} bank_record;

int main() {
    //declaring an array of bank records
    bank_record records[10];

    //loop to get input from user and store in the bank record array
    for(int i=0; i<10; i++) {
        printf("Enter name of customer %d: ", i+1);
        scanf("%s", records[i].name);
        printf("Enter account number of customer %d: ", i+1);
        scanf("%d", &records[i].account_number);
        printf("Enter balance of customer %d: ", i+1);
        scanf("%f", &records[i].balance);
    }

    //loop to display the bank record array
    printf("\nBank Records:\n");
    printf("Name\t\tAccount Number\tBalance\n");
    for(int i=0; i<10; i++) {
        printf("%s\t\t%d\t\t%.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }

    //searching for a specific account number in the bank record array
    int search_account_number;
    printf("\nEnter account number to search: ");
    scanf("%d", &search_account_number);

    int flag = 0; //flag variable to indicate whether account number is found or not
    for(int i=0; i<10; i++) {
        if(records[i].account_number == search_account_number) {
            flag = 1;
            printf("\nAccount Found!\n");
            printf("Name: %s\nAccount Number: %d\nBalance: %.2f\n", records[i].name, records[i].account_number, records[i].balance);

            //updating balance of found account
            char choice;
            printf("\nDo you want to update the balance of this account? (y/n):");
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') {
                printf("Enter new balance: ");
                scanf("%f", &records[i].balance);
                printf("Balance updated!\n");

                printf("\nUpdated Account Details:\n");
                printf("Name: %s\nAccount Number: %d\nBalance: %.2f\n", records[i].name, records[i].account_number, records[i].balance);
            }
            break;
        }
    }

    if(flag == 0) {
        printf("\nAccount not found!\n");
    }

    return 0;
}