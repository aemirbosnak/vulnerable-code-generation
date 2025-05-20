//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct bank_account{
    char account_holder[20];
    int account_number;
    float balance;
};

struct bank_account customer_accounts[10];

int main()
{
    int choice, i;
    struct bank_account *temp;
    char name[20];
    int account_number, balance;
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    printf("\nWelcome to the Banking System\n\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Check Balance\n");
    printf("4. Deposit Money\n");
    printf("5. Withdraw Money\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter your name: ");
            fgets(name, sizeof(name), stdin);
            temp = &customer_accounts[0];
            sprintf(temp->account_holder, "%s", name);
            printf("Enter your account number: ");
            scanf("%d", &account_number);
            temp->account_number = account_number;
            printf("Enter your initial balance: ");
            scanf("%f", &balance);
            temp->balance = balance;
            printf("Account Created Successfully\n");
            break;
        case 2:
            printf("Enter your name: ");
            fgets(name, sizeof(name), stdin);
            for(i = 0; i < 10; i++){
                if(strcmp(customer_accounts[i].account_holder, name) == 0){
                    temp = &customer_accounts[i];
                    printf("Your account number is: %d\n", temp->account_number);
                    printf("Your current balance is: %f\n", temp->balance);
                    break;
                }
            }
            if(i == 10){
                printf("Account not found\n");
            }
            break;
        case 3:
            printf("Enter your name: ");
            fgets(name, sizeof(name), stdin);
            for(i = 0; i < 10; i++){
                if(strcmp(customer_accounts[i].account_holder, name) == 0){
                    temp = &customer_accounts[i];
                    printf("Your account number is: %d\n", temp->account_number);
                    printf("Your current balance is: %f\n", temp->balance);
                    break;
                }
            }
            if(i == 10){
                printf("Account not found\n");
            }
            break;
        case 4:
            printf("Enter your name: ");
            fgets(name, sizeof(name), stdin);
            for(i = 0; i < 10; i++){
                if(strcmp(customer_accounts[i].account_holder, name) == 0){
                    temp = &customer_accounts[i];
                    printf("Enter your account number: ");
                    scanf("%d", &account_number);
                    if(account_number == temp->account_number){
                        printf("Enter the amount you want to deposit: ");
                        scanf("%f", &balance);
                        temp->balance += balance;
                        printf("Amount deposited successfully\n");
                        break;
                    }
                    else{
                        printf("Invalid account number\n");
                        break;
                    }
                }
            }
            if(i == 10){
                printf("Account not found\n");
            }
            break;
        case 5:
            printf("Enter your name: ");
            fgets(name, sizeof(name), stdin);
            for(i = 0; i < 10; i++){
                if(strcmp(customer_accounts[i].account_holder, name) == 0){
                    temp = &customer_accounts[i];
                    printf("Enter your account number: ");
                    scanf("%d", &account_number);
                    if(account_number == temp->account_number){
                        printf("Enter the amount you want to withdraw: ");
                        scanf("%f", &balance);
                        if(balance >= temp->balance){
                            temp->balance -= balance;
                            printf("Amount withdrawn successfully\n");
                            break;
                        }
                        else{
                            printf("Insufficient balance\n");
                            break;
                        }
                    }
                    else{
                        printf("Invalid account number\n");
                        break;
                    }
                }
            }
            if(i == 10){
                printf("Account not found\n");
            }
            break;
        case 6:
            printf("Thank you for using our banking system\n");
            break;
        default:
            printf("Invalid Choice\n");
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used = %.2f seconds\n", cpu_time_used);
    return 0;
}