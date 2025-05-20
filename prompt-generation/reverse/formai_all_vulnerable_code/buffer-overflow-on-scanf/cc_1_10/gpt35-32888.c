//FormAI DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    int acc_num;
    float balance;
}Account;

void deposit(Account *acc, float amt){
    acc->balance += amt;
    printf("Deposit successful! Your new balance is %.2f\n", acc->balance);
}

void withdraw(Account *acc, float amt){
    if(acc->balance < amt){
        printf("Sorry, you have insufficient funds.\n");
    }else{
        acc->balance -= amt;
        printf("Withdrawal successful! Your new balance is %.2f\n", acc->balance);
    }
}

void transfer(Account *sender, Account *receiver, float amt){
    if(sender->balance < amt){
        printf("Sorry, you have insufficient funds.\n");
    }else{
        sender->balance -= amt;
        receiver->balance += amt;
        printf("Transfer successful! Your new balance is %.2f\n", sender->balance);
    }
}

int main(){
    Account acc1 = {"John Smith", 123456, 5000.00};
    Account acc2 = {"Jane Doe", 654321, 1000.00};
    
    int choice, acc_choice;
    float amt;
    
    printf("Welcome to My Bank Record System!\n\n");
    printf("Please select an option:\n");
    printf("1. Deposit\n2. Withdraw\n3. Transfer\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("Which account would you like to deposit to?\n");
            printf("1. %s's Account\n2. %s's Account\n", acc1.name, acc2.name);
            scanf("%d", &acc_choice);
            
            if(acc_choice == 1){
                printf("How much would you like to deposit into %s's Account?\n", acc1.name);
                scanf("%f", &amt);
                deposit(&acc1, amt);
            }else{
                printf("How much would you like to deposit into %s's Account?\n", acc2.name);
                scanf("%f", &amt);
                deposit(&acc2, amt);
            }
            break;
            
        case 2:
            printf("Which account would you like to withdraw from?\n");
            printf("1. %s's Account\n2. %s's Account\n", acc1.name, acc2.name);
            scanf("%d", &acc_choice);
            
            if(acc_choice == 1){
                printf("How much would you like to withdraw from %s's Account?\n", acc1.name);
                scanf("%f", &amt);
                withdraw(&acc1, amt);
            }else{
                printf("How much would you like to withdraw from %s's Account?\n", acc2.name);
                scanf("%f", &amt);
                withdraw(&acc2, amt);
            }
            break;
            
        case 3:
            printf("Which account would you like to transfer from?\n");
            printf("1. %s's Account\n2. %s's Account\n", acc1.name, acc2.name);
            scanf("%d", &acc_choice);
            
            if(acc_choice == 1){
                printf("How much would you like to transfer from %s's Account?\n", acc1.name);
                scanf("%f", &amt);
                transfer(&acc1, &acc2, amt);
            }else{
                printf("How much would you like to transfer from %s's Account?\n", acc2.name);
                scanf("%f", &amt);
                transfer(&acc2, &acc1, amt);
            }
            break;
            
        default:
            printf("Invalid option selected.\n");
            break;
    }
    
    return 0;
}