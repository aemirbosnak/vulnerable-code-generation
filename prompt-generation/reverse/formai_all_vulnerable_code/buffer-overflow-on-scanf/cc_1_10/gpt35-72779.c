//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_RECORDS 10000
#define MAX_ACCOUNT_NUMBER 999999999

typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    double balance;
} Account;

Account records[MAX_RECORDS];
int num_records = 0;

void add_record() {
    int acc_num;
    char name[MAX_NAME_LENGTH];
    double balance;

    printf("Account Number: ");
    scanf("%d", &acc_num);

    if (acc_num > MAX_ACCOUNT_NUMBER) {
        printf("Invalid Account Number!\n");
        return;
    }

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == acc_num) {
            printf("Account Number already exists!\n");
            return;
        }
    }

    printf("Name: ");
    scanf("%s", name);

    printf("Balance: ");
    scanf("%lf", &balance);

    Account acc = {acc_num, name, balance};
    records[num_records++] = acc;

    printf("Record Added Successfully!\n");
}

void remove_record() {
    int acc_num;

    printf("Account Number: ");
    scanf("%d", &acc_num);

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == acc_num) {
            for (int j = i; j < num_records-1; j++) {
                records[j] = records[j+1];
            }
            num_records--;
            printf("Record Removed Successfully!\n");
            return;
        }
    }

    printf("Record not found!\n");
}

void print_record() {
    int acc_num;

    printf("Account Number: ");
    scanf("%d", &acc_num);

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == acc_num) {
            printf("Account Number: %d\n", records[i].account_number);
            printf("Name: %s\n", records[i].name);
            printf("Balance: %.2lf\n", records[i].balance);
            return;
        }
    }

    printf("Record not found!\n");
}

void print_all_records() {
    for (int i = 0; i < num_records; i++) {
        printf("Account Number: %d\n", records[i].account_number);
        printf("Name: %s\n", records[i].name);
        printf("Balance: %.2lf\n", records[i].balance);
        printf("\n");
    }
}

int main() {
    int choice;

    printf("Welcome to Cryptic Banking Record System!\n\n");

    while (1) {
        printf("1. Add Record\n");
        printf("2. Remove Record\n");
        printf("3. Print Record\n");
        printf("4. Print All Records\n");
        printf("5. Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                remove_record();
                break;
            case 3:
                print_record();
                break;
            case 4:
                print_all_records();
                break;
            case 5:
                printf("Thank you for using Cryptic Banking Record System!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\n");
    }

    return 0;
}