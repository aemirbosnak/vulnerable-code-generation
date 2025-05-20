//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_ACCT_NUM_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char acct_num[MAX_ACCT_NUM_LEN];
    float balance;
} Record;

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0;
    char choice;

    do {
        printf("\nBANKING RECORD SYSTEM\n");
        printf("----------------------\n");
        printf("1. Add a new record\n");
        printf("2. Search for a record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_records == MAX_RECORDS) {
                    printf("Cannot add more records. Maximum limit reached.\n");
                } else {
                    printf("Enter the name of the customer: ");
                    scanf("%s", records[num_records].name);
                    printf("Enter the account number: ");
                    scanf("%s", records[num_records].acct_num);
                    printf("Enter the initial balance: ");
                    scanf("%f", &records[num_records].balance);
                    num_records++;
                    printf("Record added successfully.\n");
                }
                break;

            case '2':
                printf("Enter the name of the customer to search: ");
                scanf("%s", records[0].name);

                for(int i=0; i<num_records; i++) {
                    if(strcmp(records[i].name, records[0].name) == 0) {
                        printf("Record found:\n");
                        printf("Name: %s\n", records[i].name);
                        printf("Account Number: %s\n", records[i].acct_num);
                        printf("Balance: $%.2f\n", records[i].balance);
                    }
                }
                break;

            case '3':
                printf("All records:\n");
                for(int i=0; i<num_records; i++) {
                    printf("Name: %s\n", records[i].name);
                    printf("Account Number: %s\n", records[i].acct_num);
                    printf("Balance: $%.2f\n", records[i].balance);
                    printf("\n");
                }
                break;

            case '4':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '4');

    return 0;
}