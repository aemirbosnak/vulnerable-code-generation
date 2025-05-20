//FormAI DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaction{
    int amount;
    char transaction_type[10];
};

struct account{
    char customer_name[50];
    int account_number;
    int account_balance;
    struct transaction transaction_history[100];
    int transaction_count;
};

void create_account(struct account acc[], int *num_accounts){
    printf("\nEnter customer name: ");
    scanf("%s", acc[*num_accounts].customer_name);
    printf("Enter account number: ");
    scanf("%d", &acc[*num_accounts].account_number);
    printf("Enter initial account balance: ");
    scanf("%d", &acc[*num_accounts].account_balance);
    acc[*num_accounts].transaction_count = 0;
    *num_accounts += 1;
    printf("\nAccount added successfully.\n");
}

void add_transaction(struct account acc[], int index){
    printf("\nEnter transaction type (deposit/withdraw): ");
    scanf("%s", acc[index].transaction_history[acc[index].transaction_count].transaction_type);
    printf("Enter transaction amount: ");
    scanf("%d", &acc[index].transaction_history[acc[index].transaction_count].amount);
    if(strcmp(acc[index].transaction_history[acc[index].transaction_count].transaction_type, "deposit")==0){
        acc[index].account_balance += acc[index].transaction_history[acc[index].transaction_count].amount;
    }
    else if(strcmp(acc[index].transaction_history[acc[index].transaction_count].transaction_type, "withdraw")==0){
        acc[index].account_balance -= acc[index].transaction_history[acc[index].transaction_count].amount;
    }
    acc[index].transaction_count += 1;
    printf("\nTransaction added successfully.\n");
}

void display_account_details(struct account acc[], int index){
    printf("\nAccount Details:\n");
    printf("Customer Name: %s\n", acc[index].customer_name);
    printf("Account Number: %d\n", acc[index].account_number);
    printf("Account Balance: %d\n\n", acc[index].account_balance);
    printf("Transaction History:\n");
    printf("%-10s %-10s %-10s\n", "Type", "Amount", "Balance");
    for(int i=0; i<acc[index].transaction_count; i++){
        printf("%-10s %-10d %-10d\n", acc[index].transaction_history[i].transaction_type,
               acc[index].transaction_history[i].amount, acc[index].account_balance);
        if(strcmp(acc[index].transaction_history[i].transaction_type, "deposit")==0){
            acc[index].account_balance += acc[index].transaction_history[i].amount;
        }
        else if(strcmp(acc[index].transaction_history[i].transaction_type, "withdraw")==0){
            acc[index].account_balance -= acc[index].transaction_history[i].amount;
        }
    }
}

int main(){
    struct account accounts[100];
    int num_accounts = 0;
    int choice, account_num;
    do{
        printf("\n***Banking Record System***\n");
        printf("1. Create Account\n");
        printf("2. Add Transaction\n");
        printf("3. Display Account Details\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: create_account(accounts, &num_accounts);
                    break;
            case 2: printf("\nEnter account number: ");
                    scanf("%d", &account_num);
                    for(int i=0; i<num_accounts; i++){
                        if(accounts[i].account_number == account_num){
                            add_transaction(accounts, i);
                            break;
                        }
                        if(i==num_accounts-1){
                            printf("\nAccount not found.\n");
                        }
                    }
                    break;
            case 3: printf("\nEnter account number: ");
                    scanf("%d", &account_num);
                    for(int i=0; i<num_accounts; i++){
                        if(accounts[i].account_number == account_num){
                            display_account_details(accounts, i);
                            break;
                        }
                        if(i==num_accounts-1){
                            printf("\nAccount not found.\n");
                        }
                    }
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice.\n");
        }
    }while(1);

    return 0;
}