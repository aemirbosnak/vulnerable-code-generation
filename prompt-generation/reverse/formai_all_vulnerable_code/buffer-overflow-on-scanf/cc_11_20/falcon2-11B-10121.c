//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct BankRecord {
    char name[50];
    int account_number;
    float balance;
    char password[10];
};

int main() {
    srand(time(NULL));
    struct BankRecord records[100];

    int choice = 1;
    int i;
    int j;

    while (choice!= 0) {
        printf("\nBank Record System\n");
        printf("1. Add new record\n");
        printf("2. Search for a record\n");
        printf("3. Update a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < 100; i++) {
                    if (records[i].name == NULL) {
                        break;
                    }
                }
                if (i == 100) {
                    printf("\nNo empty record found.\n");
                } else {
                    printf("\nEnter the details of the new record:\n");
                    printf("Name: ");
                    scanf("%s", records[i].name);
                    printf("Account Number: ");
                    scanf("%d", &records[i].account_number);
                    printf("Balance: ");
                    scanf("%f", &records[i].balance);
                    printf("Password: ");
                    scanf("%s", records[i].password);
                    printf("\nNew record added successfully.\n");
                }
                break;
            case 2:
                printf("\nEnter the account number of the record you want to search: ");
                scanf("%d", &records[i].account_number);
                for (j = 0; j < 100; j++) {
                    if (records[j].account_number == records[i].account_number) {
                        printf("\nName: %s\nAccount Number: %d\nBalance: %f\nPassword: %s\n", records[j].name, records[j].account_number, records[j].balance, records[j].password);
                        break;
                    }
                }
                if (j == 100) {
                    printf("\nRecord not found.\n");
                }
                break;
            case 3:
                printf("\nEnter the account number of the record you want to update: ");
                scanf("%d", &records[i].account_number);
                for (j = 0; j < 100; j++) {
                    if (records[j].account_number == records[i].account_number) {
                        printf("\nEnter the new details of the record: \n");
                        printf("Name: ");
                        scanf("%s", records[j].name);
                        printf("Account Number: ");
                        scanf("%d", &records[j].account_number);
                        printf("Balance: ");
                        scanf("%f", &records[j].balance);
                        printf("Password: ");
                        scanf("%s", records[j].password);
                        printf("\nRecord updated successfully.\n");
                        break;
                    }
                }
                break;
            case 4:
                printf("\nEnter the account number of the record you want to delete: ");
                scanf("%d", &records[i].account_number);
                for (j = 0; j < 100; j++) {
                    if (records[j].account_number == records[i].account_number) {
                        printf("\nRecord deleted successfully.\n");
                        break;
                    }
                }
                break;
            case 5:
                printf("\nThank you for using the Banking Record System.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}