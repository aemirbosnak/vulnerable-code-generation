//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    char name[50];
    int account_number;
    float balance;
};

int main() {
    struct Record bank_records[100];
    int num_records = 0;

    while(1) {
        int choice;
        printf("\nWelcome to the QuickBank Record System.\n");
        printf("Choose an option:\n");
        printf("1. Create a new record\n");
        printf("2. Search for a record\n");
        printf("3. Print all records\n");
        printf("4. Delete a record\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            struct Record new_record;
            printf("Enter name: ");
            scanf("%s", new_record.name);
            printf("Enter account number: ");
            scanf("%d", &new_record.account_number);
            printf("Enter balance: ");
            scanf("%f", &new_record.balance);

            bank_records[num_records] = new_record;
            num_records++;

            printf("Record created.\n");
        } else if(choice == 2) {
            int search_account_number;
            printf("Enter the account number you want to search for: ");
            scanf("%d", &search_account_number);

            for(int i=0; i<num_records; i++) {
                if(bank_records[i].account_number == search_account_number) {
                    printf("Record found:\n");
                    printf("Name: %s\n", bank_records[i].name);
                    printf("Account number: %d\n", bank_records[i].account_number);
                    printf("Balance: $%.2f\n", bank_records[i].balance);
                }
            }
        } else if(choice == 3) {
            for(int i=0; i<num_records; i++) {
                printf("Record number: %d\n", i+1);
                printf("Name: %s\n", bank_records[i].name);
                printf("Account number: %d\n", bank_records[i].account_number);
                printf("Balance: $%.2f\n", bank_records[i].balance);
                printf("\n");
            }
        } else if(choice == 4) {
            int delete_account_number;
            printf("Enter the account number you want to delete: ");
            scanf("%d", &delete_account_number);

            for(int i=0; i<num_records; i++) {
                if(bank_records[i].account_number == delete_account_number) {
                    for(int j=i; j<num_records-1; j++) {
                        bank_records[j] = bank_records[j+1];
                    }
                    num_records--;
                    printf("Record deleted.\n");
                }
            }
        } else if(choice == 5) {
            printf("Thank you for using the QuickBank Record System.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}