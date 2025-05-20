//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int account_number;
    char name[30];
    float balance;
};

void display_menu();
void create_account();
void view_account();
void view_all_accounts();
void deposit();
void withdraw();
void delete_account();

int num_of_accounts = 0;
struct Account accounts[50];

int main() {
    int choice;
    display_menu();
    scanf("%d", &choice);
    while(choice != 8) {
        switch(choice) {
            case 1:
                create_account();
                break;
            case 2:
                view_account();
                break;
            case 3:
                view_all_accounts();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                delete_account();
                break;
            case 7:
                display_menu();
                break;
            default:
                printf("Invalid Choice\n");
        }
        printf("Press any key to continue.\n");
        getchar();
        getchar();
        system("clear");
        display_menu();
        scanf("%d", &choice);
    }
    return 0;
}

void display_menu() {
    printf("C Banking Record System\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. View All Accounts\n");
    printf("4. Deposit\n");
    printf("5. Withdraw\n");
    printf("6. Delete Account\n");
    printf("7. Display Menu\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

void create_account() {
    struct Account new_account;
    printf("Enter Account Number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter name: ");
    scanf("%s", new_account.name);
    printf("Enter balance: ");
    scanf("%f", &new_account.balance);
    accounts[num_of_accounts] = new_account;
    num_of_accounts++;
    printf("Account created successfully.\n");
}

void view_account() {
    int account_number, i;
    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    for(i = 0; i < num_of_accounts; i++) {
        if(accounts[i].account_number == account_number) {
            printf("Account Number: %d\n", accounts[i].account_number);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %f\n", accounts[i].balance);
            return;
        }
    }
    printf("No account found with number %d.\n", account_number);
}

void view_all_accounts() {
    int i;
    printf("All Accounts:\n");
    for(i = 0; i < num_of_accounts; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %f\n", accounts[i].balance);
    }
}

void deposit() {
    int account_number, i;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    for(i = 0; i < num_of_accounts; i++) {
        if(accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful.\n");
            return;
        }
    }
    printf("No account found with number %d.\n", account_number);
}

void withdraw() {
    int account_number, i;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    for(i = 0; i < num_of_accounts; i++) {
        if(accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if(amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawal successful.\n");
            return;
        }
    }
    printf("No account found with number %d.\n", account_number);
}

void delete_account() {
    int account_number, i, j;
    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    for(i = 0; i < num_of_accounts; i++) {
        if(accounts[i].account_number == account_number) {
            for(j = i; j < num_of_accounts - 1; j++) {
                accounts[j] = accounts[j+1];
            }
            num_of_accounts--;
            printf("Account deleted successfully.\n");
            return;
        }
    }
    printf("No account found with number %d.\n", account_number);
}