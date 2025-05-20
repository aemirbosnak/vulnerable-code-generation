//FormAI DATASET v1.0 Category: Banking Record System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankingRecord {
    char account_number[50];
    char account_holder_name[50];
    float balance;
} record[100];

int menu() {
    int choice;
    printf("\n----Banking Record System----\n\n");
    printf("1. Add Record\n");
    printf("2. Display All Records\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Search Record\n");
    printf("6. Edit Record\n");
    printf("7. Delete Record\n");
    printf("8. Exit\n");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    return choice;
}

int count = 0;

void add_record() {
    printf("\nEnter Account Number: ");
    scanf("%s", &record[count].account_number);
    printf("Enter Account Holder Name: ");
    scanf("%s", &record[count].account_holder_name);
    printf("Enter Balance: ");
    scanf("%f", &record[count].balance);
    count++;
    printf("Record Added Successfully!\n");
}

void display_all_records() {
    if(count == 0) {
        printf("\nNo Records Found!\n");
        return;
    }
    printf("\n----All Records----\n\n");
    for(int i=0; i<count; i++) {
        printf("Record #%d:\n", i+1);
        printf("Account Number: %s\n", record[i].account_number);
        printf("Account Holder Name: %s\n", record[i].account_holder_name);
        printf("Balance: $%.2f\n\n", record[i].balance);
    }
}

void deposit_money() {
    char account_number[50];
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%s", &account_number);
    for(int i=0; i<count; i++) {
        if(strcmp(account_number, record[i].account_number) == 0) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            record[i].balance += amount;
            printf("\n$%.2f Deposited Successfully to Account #%s\n", amount, record[i].account_number);
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

void withdraw_money() {
    char account_number[50];
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%s", &account_number);
    for(int i=0; i<count; i++) {
        if(strcmp(account_number, record[i].account_number) == 0) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            if(amount > record[i].balance) {
                printf("\nInsufficient Balance!\n");
                return;
            }
            record[i].balance -= amount;
            printf("\n$%.2f Withdrawn Successfully from Account #%s\n", amount, record[i].account_number);
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

void search_record() {
    char account_number[50];
    printf("\nEnter Account Number: ");
    scanf("%s", &account_number);
    for(int i=0; i<count; i++) {
        if(strcmp(account_number, record[i].account_number) == 0) {
            printf("\n----Record Found----\n\n");
            printf("Account Number: %s\n", record[i].account_number);
            printf("Account Holder Name: %s\n", record[i].account_holder_name);
            printf("Balance: $%.2f\n\n", record[i].balance);
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

void edit_record() {
    char account_number[50];
    printf("\nEnter Account Number to Edit: ");
    scanf("%s", &account_number);
    for(int i=0; i<count; i++) {
        if(strcmp(account_number, record[i].account_number) == 0) {
            printf("\nEnter New Account Number: ");
            scanf("%s", &record[i].account_number);
            printf("Enter New Account Holder Name: ");
            scanf("%s", &record[i].account_holder_name);
            printf("Enter New Balance: ");
            scanf("%f", &record[i].balance);
            printf("\nRecord Edited Successfully!\n");
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

void delete_record() {
    char account_number[50];
    printf("\nEnter Account Number to Delete: ");
    scanf("%s", &account_number);
    for(int i=0; i<count; i++) {
        if(strcmp(account_number, record[i].account_number) == 0) {
            for(int j=i; j<count-1; j++) {
                record[j] = record[j+1];
            }
            count--;
            printf("\nRecord Deleted Successfully!\n");
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

int main() {
    int choice;
    while(1) {
        choice = menu();
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_all_records();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                search_record();
                break;
            case 6:
                edit_record();
                break;
            case 7:
                delete_record();
                break;
            case 8:
                printf("\nThank You for Using Banking Record System!\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}