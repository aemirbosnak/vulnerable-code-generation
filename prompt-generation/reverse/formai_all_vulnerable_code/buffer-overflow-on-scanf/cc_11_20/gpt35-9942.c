//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    char name[50];
    int account_num;
    float balance;
};

int main(void) {
    struct bank_record bank_records[10];
    int num_records = 0;

    printf("Welcome to the Banking Record System. I am Sherlock Holmes, now let's begin.\n");

    while (1) {
        char command[10];
        printf("Enter command (ADD, LIST, BALANCE, or QUIT): ");
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            if (num_records == 10) {
                printf("Cannot add more records. Maximum limit reached.\n");
                continue;
            }

            struct bank_record record;
            printf("Enter name: ");
            scanf("%s", record.name);
            printf("Enter account number: ");
            scanf("%d", &record.account_num);
            printf("Enter balance: ");
            scanf("%f", &record.balance);

            bank_records[num_records] = record;
            num_records++;

            printf("Record added successfully.\n");
        }
        else if (strcmp(command, "LIST") == 0) {
            if (num_records == 0) {
                printf("No records to list.\n");
                continue;
            }

            printf("Name\tAccount Number\tBalance\n");
            for (int i = 0; i < num_records; i++) {
                printf("%s\t%d\t%.2f\n", bank_records[i].name, bank_records[i].account_num, bank_records[i].balance);
            }
        }
        else if (strcmp(command, "BALANCE") == 0) {
            int account_num;
            printf("Enter account number: ");
            scanf("%d", &account_num);

            for (int i = 0; i < num_records; i++) {
                if (bank_records[i].account_num == account_num) {
                    printf("Account balance for %s is %.2f.\n", bank_records[i].name, bank_records[i].balance);
                    break;
                }
                else if (i == num_records - 1) {
                    printf("Record with account number %d not found.\n", account_num);
                }
            }
        }
        else if (strcmp(command, "QUIT") == 0) {
            printf("Thank you for using the Banking Record System, goodbye!\n");
            break;
        }
        else {
            printf("Invalid command. Please enter ADD, LIST, BALANCE, or QUIT.\n");
        }
    }

    return 0;
}