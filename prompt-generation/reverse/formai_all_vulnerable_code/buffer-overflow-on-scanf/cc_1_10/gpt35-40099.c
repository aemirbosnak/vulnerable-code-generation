//FormAI DATASET v1.0 Category: Banking Record System ; Style: statistical
#include<stdio.h>
#include<string.h>

struct banking_record {
    char name[20], account_type[20];
    int account_number;
    float balance;
} customer[10];

int num_of_customers = 0;

void add_new_customer() {
    printf("\nEnter customer name: ");
    scanf("%s", customer[num_of_customers].name);
    printf("Enter account type (savings/current): ");
    scanf("%s", customer[num_of_customers].account_type);
    printf("Enter account number: ");
    scanf("%d", &customer[num_of_customers].account_number);
    printf("Enter the initial balance: ");
    scanf("%f", &customer[num_of_customers].balance);
    num_of_customers++;
    printf("\nCustomer added successfully!\n\n");
}

void display_all_customers() {
    if(num_of_customers == 0){
        printf("\nNo customers found!\n\n");
    } else {
        printf("\n%-15s%-15s%-20s%s\n", "Name", "Account Type", "Account Number", "Balance");
        for(int i=0;i<num_of_customers;i++){
            printf("%-15s%-15s%-20d%.2f\n", customer[i].name, customer[i].account_type, customer[i].account_number, customer[i].balance);
        }
        printf("\n");
    }
}

int search_customer_by_account_number(int num) {
    for(int i=0;i<num_of_customers;i++){
        if(customer[i].account_number == num){
            return i;
        }
    }
    return -1;
}

void deposit_money() {
    int account_number;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);
    int index = search_customer_by_account_number(account_number);
    if(index == -1){
        printf("\nCustomer not found!\n\n");
    } else {
        printf("Enter the amount to deposit: ");
        scanf("%f", &amount);
        customer[index].balance += amount;
        printf("\nDeposit successful!\nNew balance: %.2f\n\n", customer[index].balance);
    }
}

void withdraw_money() {
    int account_number;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);
    int index = search_customer_by_account_number(account_number);
    if(index == -1){
        printf("\nCustomer not found!\n\n");
    } else {
        printf("Enter the amount to withdraw: ");
        scanf("%f", &amount);
        if(customer[index].balance >= amount){
            customer[index].balance -= amount;
            printf("\nWithdrawal successful!\nNew balance: %.2f\n\n", customer[index].balance);
        } else {
            printf("\nInsufficient balance!\n\n");
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n-------------------------------------------\n");
        printf("Welcome to Banking Record System\n");
        printf("-------------------------------------------\n");
        printf("\n1. Add new customer");
        printf("\n2. Display all customers");
        printf("\n3. Deposit money");
        printf("\n4. Withdraw money");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_new_customer(); break;
            case 2: display_all_customers(); break;
            case 3: deposit_money(); break;
            case 4: withdraw_money(); break;
            case 5: printf("\nExiting program... Thank you for using our system.\n\n"); break;
            default: printf("\nInvalid choice. Please try again.\n\n");
        }
    } while(choice!=5);
    return 0;
}