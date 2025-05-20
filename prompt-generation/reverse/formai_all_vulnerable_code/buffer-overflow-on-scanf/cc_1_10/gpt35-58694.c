//FormAI DATASET v1.0 Category: Banking Record System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for storing customer details
struct customer{
    char name[50];
    int account_no;
    float balance;
};

// Function to open a new account
void open_account(struct customer* ptr){
    printf("Enter Name: ");
    scanf("%s", ptr->name);
    printf("Enter Account Number: ");
    scanf("%d", &ptr->account_no);
    printf("Enter opening Balance: ");
    scanf("%f", &ptr->balance);
    printf("Account created successfully!\n");
}

// Function to display account details
void display_account(struct customer* ptr){
    printf("Account Holder Name: %s\n", ptr->name);
    printf("Account Number: %d\n", ptr->account_no);
    printf("Balance: %f\n", ptr->balance);
}

// Function to deposit money into account
void deposit_money(struct customer* ptr){
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    ptr->balance += amount;
    printf("Amount deposited successfully!\n");
}

// Function to withdraw money from account
void withdraw_money(struct customer* ptr){
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if(ptr->balance >= amount){
        ptr->balance -= amount;
        printf("Amount withdrawn successfully!\n");
    }
    else{
        printf("Insufficient balance!\n");
    }
}

int main(){
    int choice;
    struct customer customers[100]; // Array of structures to hold customer data
    int count = 0; // Count of number of customers in the record system
    
    printf("Welcome to C Banking Record System!\n");
    while(1){
        printf("\n***********************\n");
        printf("Please choose an option:\n");
        printf("1. Open a new account\n");
        printf("2. Display account details\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n");
        printf("\n***********************\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1){
            struct customer new_customer;
            open_account(&new_customer);
            customers[count] = new_customer;
            count++;
        }
        else if(choice == 2){
            int account_no;
            printf("Enter account number: ");
            scanf("%d", &account_no);
            int index = -1;
            for(int i=0; i<count; i++){
                if(customers[i].account_no == account_no){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                printf("Account not found!\n");
            }
            else{
                display_account(&customers[index]);
            }
        }
        else if(choice == 3){
            int account_no;
            printf("Enter account number: ");
            scanf("%d", &account_no);
            int index = -1;
            for(int i=0; i<count; i++){
                if(customers[i].account_no == account_no){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                printf("Account not found!\n");
            }
            else{
                deposit_money(&customers[index]);
            }
        }
        else if(choice == 4){
            int account_no;
            printf("Enter account number: ");
            scanf("%d", &account_no);
            int index = -1;
            for(int i=0; i<count; i++){
                if(customers[i].account_no == account_no){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                printf("Account not found!\n");
            }
            else{
                withdraw_money(&customers[index]);
            }
        }
        else if(choice == 5){
            printf("Thank you for using C Banking Record System!\n");
            break;
        }
        else{
            printf("Invalid choice!\n");
        }
    }
    return 0;
}