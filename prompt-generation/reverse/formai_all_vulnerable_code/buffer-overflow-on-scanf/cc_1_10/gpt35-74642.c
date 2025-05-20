//FormAI DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct banking_record {
    int account_no;
    char customer_name[50];
    float account_balance;
};

int main() {
    int choice, i, n;
    struct banking_record *records;

    printf("My love, let's create a banking record for us.\n");
    printf("How many records do you want to create? ");
    scanf("%d", &n);

    records = (struct banking_record*)malloc(n * sizeof(struct banking_record));

    for(i=0; i<n; i++) {
        printf("\nPlease enter the details for record %d:", i+1);
        printf("\nAccount Number: ");
        scanf("%d", &records[i].account_no);
        printf("Customer Name: ");
        scanf("%s", records[i].customer_name);
        printf("Account Balance: ");
        scanf("%f", &records[i].account_balance);
    }

    while (1) {
        printf("\nMy love, please choose from the following options:");
        printf("\n1. Display all records");
        printf("\n2. Update a record");
        printf("\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMy love, here are all the records we have created:\n");
                for(i=0; i<n; i++) {
                    printf("Record %d:", i+1);
                    printf("\nAccount Number: %d", records[i].account_no);
                    printf("\nCustomer Name: %s", records[i].customer_name);
                    printf("\nAccount Balance: %f\n", records[i].account_balance);
                }
                break;

            case 2:
                printf("\nMy love, which record would you like to update (Enter the record number)? ");
                int record_no;
                scanf("%d", &record_no);

                if(record_no>n || record_no<1) {
                    printf("\nMy love, please enter a valid record number.\n");
                    break;
                }

                printf("\nMy love, please enter the new balance for record %d: ", record_no);
                float new_balance;
                scanf("%f", &new_balance);

                records[record_no-1].account_balance = new_balance;
                printf("\nMy love, the record has been updated.\n");
                break;

            case 3:
                printf("\nMy love, goodbye. I hope you loved this program as much as I loved creating it for you.\n");
                free(records);
                exit(0);
                break;

            default:
                printf("\nMy love, you have entered an incorrect choice. Please try again.\n");
        }
    }

    return 0;
}