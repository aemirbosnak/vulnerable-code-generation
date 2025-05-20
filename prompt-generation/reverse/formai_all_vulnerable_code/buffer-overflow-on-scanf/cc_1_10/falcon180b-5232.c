//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_ACCOUNT_NUMBER_LEN 20
#define MAX_BALANCE_STR_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char account_number[MAX_ACCOUNT_NUMBER_LEN];
    char balance_str[MAX_BALANCE_STR_LEN];
    float balance;
} bank_record_t;

bank_record_t records[MAX_RECORDS];
int num_records = 0;

void add_record(char* name, char* account_number, float balance) {
    strcpy(records[num_records].name, name);
    strcpy(records[num_records].account_number, account_number);
    sprintf(records[num_records].balance_str, "$%.2f", balance);
    records[num_records].balance = balance;
    num_records++;
}

void print_record(int index) {
    printf("Name: %s\n", records[index].name);
    printf("Account Number: %s\n", records[index].account_number);
    printf("Balance: $%.2f\n\n", records[index].balance);
}

void print_all_records() {
    int i;
    for (i = 0; i < num_records; i++) {
        print_record(i);
    }
}

int main() {
    int choice, index;
    char name[MAX_NAME_LEN];
    char account_number[MAX_ACCOUNT_NUMBER_LEN];
    float balance;

    printf("Welcome to the Banking Record System!\n");
    printf("Please choose an option:\n");
    printf("1. Add Record\n");
    printf("2. Print All Records\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Account Number: ");
            scanf("%s", account_number);
            printf("Enter Balance: ");
            scanf("%f", &balance);
            add_record(name, account_number, balance);
            printf("Record added successfully!\n");
            break;
        case 2:
            printf("Printing all records:\n");
            print_all_records();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}