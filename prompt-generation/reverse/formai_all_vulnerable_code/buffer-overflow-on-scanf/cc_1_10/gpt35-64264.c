//FormAI DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <string.h>

struct bank_record {
    char name[50];
    int age;
    char address[100];
    char account_type[20];
    int account_number;
    float balance;
};

void create_account(struct bank_record records[], int *num_accounts) {
    char name[50];
    int age;
    char address[100];
    char account_type[20];
    int account_number;
    float balance;
    
    printf("Enter name: ");
    scanf("%s", name);
    
    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Enter address: ");
    scanf("%s", address);
    
    printf("Enter account type: ");
    scanf("%s", account_type);
    
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    printf("Enter balance: ");
    scanf("%f", &balance);
    
    strcpy(records[*num_accounts].name, name);
    records[*num_accounts].age = age;
    strcpy(records[*num_accounts].address, address);
    strcpy(records[*num_accounts].account_type, account_type);
    records[*num_accounts].account_number = account_number;
    records[*num_accounts].balance = balance;
    
    printf("Account created successfully!\n\n");
    
    *num_accounts += 1;
}

void display_accounts(struct bank_record records[], int num_accounts) {
    if (num_accounts == 0) {
        printf("No accounts found!\n\n");
        return;
    }
    
    printf("\n\n --- BANK RECORDS --- \n\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Account number: %d\n", records[i].account_number);
        printf("Account holder: %s\n", records[i].name);
        printf("Account type: %s\n", records[i].account_type);
        printf("Account holder age: %d\n", records[i].age);
        printf("Account holder address: %s\n", records[i].address);
        printf("Account balance: %.2f\n\n", records[i].balance);
    }
}

void search_account(struct bank_record records[], int num_accounts) {
    int account_number;
    printf("Enter account number to search: ");
    scanf("%d", &account_number);
    
    for (int i = 0; i < num_accounts; i++) {
        if (records[i].account_number == account_number) {
            printf("Account found!\n");
            printf("Account holder: %s\n", records[i].name);
            printf("Account type: %s\n", records[i].account_type);
            printf("Account holder age: %d\n", records[i].age);
            printf("Account holder address: %s\n", records[i].address);
            printf("Account balance: %.2f\n\n", records[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n\n");
}

void deposit_amount(struct bank_record records[], int num_accounts) {
    int account_number, deposit_amount;
    printf("Enter account number to deposit amount: ");
    scanf("%d", &account_number);
    
    for (int i = 0; i < num_accounts; i++) {
        if (records[i].account_number == account_number) {
            printf("Current account balance: %.2f\n", records[i].balance);
            printf("Enter amount to deposit: ");
            scanf("%d", &deposit_amount);
            records[i].balance += deposit_amount;
            printf("Deposit successful! New balance: %.2f\n\n", records[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n\n");
}

void withdraw_amount(struct bank_record records[], int num_accounts) {
    int account_number, withdraw_amount;
    printf("Enter account number to withdraw amount: ");
    scanf("%d", &account_number);
    
    for (int i = 0; i < num_accounts; i++) {
        if (records[i].account_number == account_number) {
            printf("Current account balance: %.2f\n", records[i].balance);
            printf("Enter amount to withdraw: ");
            scanf("%d", &withdraw_amount);
            if (records[i].balance < withdraw_amount) {
                printf("Insufficient balance!\n\n");
                return;
            }
            records[i].balance -= withdraw_amount;
            printf("Withdrawal successful! New balance: %.2f\n\n", records[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n\n");
}

void print_menu() {
    printf("===============================\n");
    printf("    BANK RECORD SYSTEM MENU    \n");
    printf("===============================\n");
    printf("1. Create account\n");
    printf("2. Display accounts\n");
    printf("3. Search account\n");
    printf("4. Deposit amount\n");
    printf("5. Withdraw amount\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct bank_record records[100];
    int num_accounts = 0;
    int choice;
    
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                create_account(records, &num_accounts);
                break;
            case 2:
                display_accounts(records, num_accounts);
                break;
            case 3:
                search_account(records, num_accounts);
                break;
            case 4:
                deposit_amount(records, num_accounts);
                break;
            case 5:
                withdraw_amount(records, num_accounts);
                break;
            case 6:
                printf("Goodbye!\n\n");
                break;
            default:
                printf("Invalid choice!\n\n");
        }
    } while (choice != 6);
    
    return 0;
}