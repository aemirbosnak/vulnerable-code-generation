//FormAI DATASET v1.0 Category: Banking Record System ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ACCOUNTS 100  //maximum number of accounts allowed
#define MAX_NAME 50       //maximum length of account holder name
#define MAX_PASSWORD 20   //maximum length of password
#define BASE_BALANCE 5000 //minimum base balance allowed

//structure to store account details
typedef struct {
    char name[MAX_NAME];
    char password[MAX_PASSWORD];
    int account_no;
    float balance;
} Account;

//array of accounts
Account accounts[MAX_ACCOUNTS];

//total number of accounts
int current_accounts = 0;

//function to open a new account
void open_account(){
    printf("\n---Open New Account---\n");
    Account new_account;
    printf("Enter your name: ");
    scanf("%s", new_account.name);

    //password validation
    while(1){
        char temp_pass[MAX_PASSWORD];
        printf("Enter a password (Minimum 8 characters): ");
        scanf("%s", temp_pass);
        if(strlen(temp_pass) < 8){
            printf("Password must be atleast 8 characters long. Try again.\n");
        } else {
            //copy password to account structure
            strcpy(new_account.password, temp_pass);
            break;
        }
    }

    //generate unique account number
    new_account.account_no = 1000 + current_accounts + 1;

    //initial balance validation
    while(1){
        printf("Enter initial amount to deposit (Minimum %d): ", BASE_BALANCE);
        float balance;
        scanf("%f", &balance);
        if(balance < BASE_BALANCE){
            printf("Minimum balance not maintained. Try again.\n");
        } else {
            //copy balance to account structure
            new_account.balance = balance;
            break;
        }
    }

    //add new account to array of accounts
    accounts[current_accounts++] = new_account;
    printf("\nAccount created!\n");
    printf("Your account number is %d. Note it down for future reference.\n", new_account.account_no);
}

//function to display account details
void display_account(int account_no){
    int i;
    for(i=0;i<current_accounts;i++){
        if(accounts[i].account_no == account_no){
            printf("\n---Account Details---\n");
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Number: %d\n", accounts[i].account_no);
            printf("Balance: Rs. %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("\nAccount not found.\n");
}

//function to deposit money
void deposit(int account_no){
    int i;
    for(i=0;i<current_accounts;i++){
        if(accounts[i].account_no == account_no){
            printf("\nEnter amount to deposit: ");
            float amount;
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Updated balance: Rs. %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("\nAccount not found.\n");
}

//function to withdraw money
void withdraw(int account_no){
    int i;
    for(i=0;i<current_accounts;i++){
        if(accounts[i].account_no == account_no){
            printf("\nEnter amount to withdraw: ");
            float amount;
            scanf("%f", &amount);
            if(amount > accounts[i].balance){
                printf("Insufficient balance.\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Updated balance: Rs. %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("\nAccount not found.\n");
}

//function to authenticate account holder
int authenticate(int account_no, char *password){
    int i;
    for(i=0;i<current_accounts;i++){
        if(accounts[i].account_no == account_no){
            if(strcmp(accounts[i].password, password)==0){
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

int main(){
    int choice, account_no;
    char password[MAX_PASSWORD];

    while(1){
        printf("\n---BANKING RECORD SYSTEM---\n");
        printf("1. Open new Account\n");
        printf("2. Display Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                open_account();
                break;
            case 2:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_no);
                display_account(account_no);
                break;
            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_no);
                printf("Enter Password: ");
                scanf("%s", password);
                if(authenticate(account_no, password)){
                    deposit(account_no);
                } else {
                    printf("\nAuthentication failed.\n");
                }
                break;
            case 4:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_no);
                printf("Enter Password: ");
                scanf("%s", password);
                if(authenticate(account_no, password)){
                    withdraw(account_no);
                } else {
                    printf("\nAuthentication failed.\n");
                }
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}