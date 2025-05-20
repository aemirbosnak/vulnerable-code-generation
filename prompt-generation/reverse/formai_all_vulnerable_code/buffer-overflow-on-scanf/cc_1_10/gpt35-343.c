//FormAI DATASET v1.0 Category: Banking Record System ; Style: medieval
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main() {
    char name[20], acc_no[10], type[5];
    float bal=0;

    printf("Welcome to the Medieval Banking Record System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your account number: ");
    scanf("%s", acc_no);
    printf("Please enter the type of account you want to open (current/savings): ");
    scanf("%s", type);

    type[0] = toupper(type[0]);

    printf("Thank you for opening an account, %s!\n", name);
    printf("Your account number is %s and you have opened a %s account.\n", acc_no, type);

    char command;
    do {
        printf("\nEnter the command you want to execute:\n");
        printf("b for balance, d for deposit, w for withdraw, q for quit.\n");
        scanf(" %c", &command);
        command = tolower(command);

        switch(command) {
            case 'b':
                printf("Your current balance is %.2f coins.\n", bal);
                break;
            case 'd': {
                float deposit = 0;
                printf("Enter the amount you want to deposit: ");
                scanf("%f", &deposit);
                bal += deposit;
                printf("%.2f coins have been deposited into your account.\n", deposit);
                break;
            }
            case 'w': {
                float withdraw = 0;
                printf("Enter the amount you want to withdraw: ");
                scanf("%f", &withdraw);
                if(withdraw <= bal) {
                    bal -= withdraw;
                    printf("%.2f coins have been withdrawn from your account.\n", withdraw);
                }
                else {
                    printf("Sorry, you do not have enough coins. Your balance is %.2f coins.\n", bal);
                }
                break;
            }
            case 'q':
                printf("Thank you for choosing our Medieval Banking Record System, %s!\n", name);
                break;
            default:
                printf("Invalid command. Please enter a valid command.\n");
        }
    } while(command != 'q');
}