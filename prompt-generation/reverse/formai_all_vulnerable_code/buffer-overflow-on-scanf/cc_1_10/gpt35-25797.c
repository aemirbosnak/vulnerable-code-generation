//FormAI DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankRecord {
    char firstName[20];
    char lastName[20];
    char accountNumber[10];
    float balance;
    struct BankRecord* next;
} bank_record;

bank_record* head = NULL;

int menu();
float get_balance(char accountNumber[]);
void create_record();
void print_records();
void deposit();
void withdraw();

int main() {
    int option;
    do {
        option = menu();
        switch (option) {
            case 1:
                create_record();
                break;
            case 2:
                print_records();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                break;
            default:
                printf("Invalid Option!\n");
        }
    } while (option != 5);
    return 0;
}

int menu() {
    int option;
    printf("===== BANK RECORD SYSTEM =====\n");
    printf("1. Create New Record\n");
    printf("2. Display All Records\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    printf("\n");
    return option;
}

float get_balance(char accountNumber[]) {
    bank_record* ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->accountNumber, accountNumber) == 0) {
            return ptr->balance;
        }
        ptr = ptr->next;
    }
    return -1;
}

void create_record() {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    printf("Enter First Name: ");
    scanf("%s", new_record->firstName);
    printf("Enter Last Name: ");
    scanf("%s", new_record->lastName);
    printf("Enter Account Number: ");
    scanf("%s", new_record->accountNumber);
    printf("Enter Balance: ");
    scanf("%f", &new_record->balance);
    new_record->next = head;
    head = new_record;
    printf("New Record Created Successfully!\n\n");
}

void print_records() {
    bank_record* ptr = head;
    if (ptr == NULL) {
        printf("No Records Found!\n");
        return;
    }
    printf("FIRST NAME\tLAST NAME\tACCOUNT NUMBER\tBALANCE\n");
    while (ptr != NULL) {
        printf("%s\t\t%s\t\t%s\t\t%.2f\n", ptr->firstName, ptr->lastName, ptr->accountNumber, ptr->balance);
        ptr = ptr->next;
    }
    printf("\n");
}

void deposit() {
    char accountNumber[10];
    float amount;
    printf("Enter Account Number: ");
    scanf("%s", accountNumber);
    float balance = get_balance(accountNumber);
    if (balance == -1) {
        printf("Account Not Found!\n\n");
        return;
    }
    printf("Current Balance: %.2f\n", balance);
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid Amount!\n\n");
        return;
    }
    balance += amount;
    printf("New Balance: %.2f\n", balance);
    bank_record* ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->accountNumber, accountNumber) == 0) {
            ptr->balance = balance;
            printf("Deposit Successful!\n\n");
            return;
        }
        ptr = ptr->next;
    }
}

void withdraw() {
    char accountNumber[10];
    float amount;
    printf("Enter Account Number: ");
    scanf("%s", accountNumber);
    float balance = get_balance(accountNumber);
    if (balance == -1) {
        printf("Account Not Found!\n\n");
        return;
    }
    printf("Current Balance: %.2f\n", balance);
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > balance) {
        printf("Invalid Amount or Insufficient Balance!\n\n");
        return;
    }
    balance -= amount;
    printf("New Balance: %.2f\n", balance);
    bank_record* ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->accountNumber, accountNumber) == 0) {
            ptr->balance = balance;
            printf("Withdrawal Successful!\n\n");
            return;
        }
        ptr = ptr->next;
    }
}