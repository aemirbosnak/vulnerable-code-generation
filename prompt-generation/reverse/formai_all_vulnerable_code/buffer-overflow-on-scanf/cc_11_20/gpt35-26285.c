//FormAI DATASET v1.0 Category: Banking Record System ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Record {
    int account_number;
    char client_name[50];
    char account_type[10];
    float balance;
};

int main() {
    int choice, account_num, number_of_records = 0;
    char name[50], type[10];
    float balance;
    struct Record records[100];

    while(1) {
        printf("Please select an option: \n");
        printf("1. Add Record \n");
        printf("2. View Record \n");
        printf("3. Delete Record \n");
        printf("4. Exit \n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                for (int i = 0; i < number_of_records; i++) {
                    if (records[i].account_number == account_num) {
                        printf("[ERROR] Record with account number %d already exists.\n", account_num);
                        break;
                    }
                }

                printf("Enter client name: ");
                scanf("%s", name);

                printf("Enter account type (Checking/Savings): ");
                scanf("%s", type);

                printf("Enter balance: ");
                scanf("%f", &balance);

                struct Record record = {account_num, name, type, balance};
                records[number_of_records] = record;
                number_of_records++;

                printf("[SUCCESS] Record added successfully.\n");
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                for (int i = 0; i < number_of_records; i++) {
                    if (records[i].account_number == account_num) {
                        printf("Account Number: %d\n", records[i].account_number);
                        printf("Client Name: %s\n", records[i].client_name);
                        printf("Account Type: %s\n", records[i].account_type);
                        printf("Balance: %.2f\n", records[i].balance);
                        break;
                    } else if (i == number_of_records - 1) {
                        printf("[ERROR] Record with account number %d not found.\n", account_num);
                    }
                }
                break;

            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                for (int i = 0; i < number_of_records; i++) {
                    if (records[i].account_number == account_num) {
                        for (int j = i; j < number_of_records - 1; j++) {
                            records[j] = records[j+1];
                        }
                        number_of_records--;
                        printf("[SUCCESS] Record with account number %d deleted successfully.\n", account_num);
                        break;
                    } else if (i == number_of_records - 1) {
                        printf("[ERROR] Record with account number %d not found.\n", account_num);
                    }
                }
                break;

            case 4:
                printf("Exiting Banking Record System...\n");
                exit(0);

            default:
                printf("[ERROR] Invalid input. Please enter a valid option.\n");
                break;
        }
    }
    return 0;
}