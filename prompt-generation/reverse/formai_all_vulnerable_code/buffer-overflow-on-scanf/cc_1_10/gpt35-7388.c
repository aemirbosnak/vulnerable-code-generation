//FormAI DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record{
    char name[20];
    int acc_no;
    int balance;
};

void deposit_money(struct bank_record *record, int amount){
    printf("Depositing $%d into account no %d.\n", amount, record->acc_no);
    record->balance += amount;
}

void withdraw_money(struct bank_record *record, int amount){
    if(record->balance - amount < 0){
        printf("Insufficient balance for account no %d.\n", record->acc_no);
    }
    else{
        printf("Withdrawing $%d from account no %d.\n", amount, record->acc_no);
        record->balance -= amount;
    }
}

int main(){
    int num_records;
    printf("Welcome to the Bank Record System.\n");
    printf("How many records would you like to create? ");
    scanf("%d", &num_records);

    struct bank_record *records = malloc(num_records * sizeof(struct bank_record));
    for(int i=0; i<num_records; i++){
        printf("Enter the name for account %d: ", i+1);
        scanf("%s", records[i].name);

        printf("Enter the account number for account %d: ", i+1);
        scanf("%d", &records[i].acc_no);

        printf("Enter the initial balance for account %d: ", i+1);
        scanf("%d", &records[i].balance);
    }

    int choice;
    while(1){
        printf("\nPlease select an option:\n");
        printf("1. Deposit money\n");
        printf("2. Withdraw money\n");
        printf("3. View balance\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            int acc_no, amount;
            printf("Enter account number: ");
            scanf("%d", &acc_no);

            struct bank_record *record = NULL;
            for(int i=0; i<num_records; i++){
                if(records[i].acc_no == acc_no){
                    record = &records[i];
                    break;
                }
            }

            if(record != NULL){
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                deposit_money(record, amount);
            }
            else{
                printf("Account not found.\n");
            }
        }
        else if(choice == 2){
            int acc_no, amount;
            printf("Enter account number: ");
            scanf("%d", &acc_no);

            struct bank_record *record = NULL;
            for(int i=0; i<num_records; i++){
                if(records[i].acc_no == acc_no){
                    record = &records[i];
                    break;
                }
            }

            if(record != NULL){
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                withdraw_money(record, amount);
            }
            else{
                printf("Account not found.\n");
            }
        }
        else if(choice == 3){
            int acc_no;
            printf("Enter account number: ");
            scanf("%d", &acc_no);

            struct bank_record *record = NULL;
            for(int i=0; i<num_records; i++){
                if(records[i].acc_no == acc_no){
                    record = &records[i];
                    break;
                }
            }

            if(record != NULL){
                printf("Account no %d has a balance of $%d.\n", record->acc_no, record->balance);
            }
            else{
                printf("Account not found.\n");
            }
        }
        else if(choice == 4){
            printf("Exiting Bank Record System...\n");
            break;
        }
        else{
            printf("Invalid option.\n");
        }
    }

    free(records);
    return 0;
}