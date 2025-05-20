//FormAI DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CUSTOMERS 20

struct customer {
    char name[50];
    int account_number;
    float balance;
};

int num_customers = 0;
struct customer customers[MAX_CUSTOMERS]; 

void add_customer() {
    if(num_customers >= MAX_CUSTOMERS) {
        printf("Cannot add more customers\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter account number: ");
    scanf("%d", &customers[num_customers].account_number);
    printf("Enter balance: ");
    scanf("%f", &customers[num_customers].balance);
    num_customers++;
}

void view_customers() {
    if(num_customers == 0) {
        printf("No customers available\n");
        return;
    }
    
    for(int i=0; i<num_customers; i++) {
        printf("Name: %s\tAccount Number: %d\tBalance: %.2f\n", 
               customers[i].name, customers[i].account_number, customers[i].balance);
    }
}

void search_customer() {
    int account;
    printf("Enter the account number you want to search for: ");
    scanf("%d",&account);
    for (int i=0;i<num_customers;i++)
    {
        if(customers[i].account_number==account)
        {
            printf("Name: %s\tAccount Number: %d\tBalance: %.2f\n",customers[i].name,customers[i].account_number,customers[i].balance);
            return;
        }
    }
    printf("This account number doesn't exist. \n");
}

void withdraw() {
    int account;
    float withdraw_amount;
    printf("Enter the account number: ");
    scanf("%d",&account);
    for (int i=0; i<num_customers; i++)
    {
        if(customers[i].account_number==account)
        {
            printf("Current balance is %.2f\n",customers[i].balance);
            printf("Enter the amount you want to withdraw: ");
            scanf("%f",&withdraw_amount);
            if (withdraw_amount<=customers[i].balance){
                customers[i].balance-=withdraw_amount;
                printf("After withdrawing, your current balance is %.2f\n",customers[i].balance);
            }
            else{
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("This account number doesn't exist. \n");
}

void deposit() {
    int account;
    float deposit_amount;
    printf("Enter the account number: ");
    scanf("%d",&account);
    for (int i=0; i<num_customers; i++)
    {
        if(customers[i].account_number==account)
        {
            printf("Current balance is %.2f\n",customers[i].balance);
            printf("Enter the amount you want to deposit: ");
            scanf("%f",&deposit_amount);
            customers[i].balance+=deposit_amount;
            printf("After depositing, your current balance is %.2f\n",customers[i].balance);
            return;
        }
    }
    printf("This account number doesn't exist. \n");
}

int menu() {
    int choice;
    printf("\n---Welcome to the Banking Record System---\n");
    printf("1. Add new customer\n");
    printf("2. View all customers\n");
    printf("3. Search for customer\n");
    printf("4. Withdraw from an account\n");
    printf("5. Deposit into an account\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice = 0;
    
    while(choice != 6) {
        choice = menu();
        switch(choice) {
            case 1: add_customer();
                    break;
            case 2: view_customers();
                    break;
            case 3: search_customer();
                    break;
            case 4: withdraw();
                    break;
            case 5: deposit();
                    break;
            case 6: printf("Thank you for using the banking record system!\n");
                    break;
            default: printf("Invalid choice\n");
        }
    }
    
    return 0;
}