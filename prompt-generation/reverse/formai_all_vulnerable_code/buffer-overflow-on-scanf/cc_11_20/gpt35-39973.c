//FormAI DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer{
    char name[30];
    int account_number;
    float balance;
}record[100]; //maximum 100 customers

int main(){
    int choice, num_customers=0, i, account_num;
    float deposit, withdraw;
    char name[30];

    printf("------Welcome to the Banking Record System------\n");

    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1) Add a new customer record\n");
        printf("2) Lookup customer record\n");
        printf("3) Deposit funds\n");
        printf("4) Withdraw funds\n");
        printf("5) Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice){
            case 1:
                printf("\nEnter customer name: ");
                fgets(name, 30, stdin);
                name[strcspn(name, "\n")] = 0; //remove newline character from input
                printf("Enter account number: ");
                scanf("%d", &record[num_customers].account_number);
                printf("Enter initial balance: $");
                scanf("%f", &record[num_customers].balance);
                strcpy(record[num_customers].name, name);
                num_customers++;
                printf("--New customer record added--\n");
                break;

            case 2:
                printf("\nEnter account number: ");
                scanf("%d", &account_num);
                for(i=0; i<num_customers; i++){
                    if(record[i].account_number == account_num){
                        printf("Name: %s\n", record[i].name);
                        printf("Account Number: %d\n", record[i].account_number);
                        printf("Current Balance: $%.2f\n", record[i].balance);
                        break;
                    }
                }
                if(i == num_customers){
                    printf("--Record not found--\n");
                }
                break;

            case 3:
                printf("\nEnter account number: ");
                scanf("%d", &account_num);
                for(i=0; i<num_customers; i++){
                    if(record[i].account_number == account_num){
                        printf("Current Balance: $%.2f\n", record[i].balance);
                        printf("Enter amount to deposit: $");
                        scanf("%f", &deposit);
                        record[i].balance += deposit;
                        printf("--Deposit successful--\n");
                        printf("New Balance: $%.2f\n", record[i].balance);
                        break;
                    }
                }
                if(i == num_customers){
                    printf("--Record not found--\n");
                }
                break;

            case 4:
                printf("\nEnter account number: ");
                scanf("%d", &account_num);
                for(i=0; i<num_customers; i++){
                    if(record[i].account_number == account_num){
                        printf("Current Balance: $%.2f\n", record[i].balance);
                        printf("Enter amount to withdraw: $");
                        scanf("%f", &withdraw);
                        if(withdraw > record[i].balance){
                            printf("--Insufficient balance--\n");
                        }
                        else{
                            record[i].balance -= withdraw;
                            printf("--Withdrawal successful--\n");
                            printf("New Balance: $%.2f\n", record[i].balance);
                        }
                        break;
                    }
                }
                if(i == num_customers){
                    printf("--Record not found--\n");
                }
                break;

            case 5:
                printf("--Thank you for using the Banking Record System--\n");
                exit(0);

            default:
                printf("--Invalid choice--\n");
        }
    }

    return 0;
}