//FormAI DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for customer account
struct Customer{
    char name[50];
    char account_type[50];
    int account_number;
    float balance;
};

//function to add new customer
int add_customer(struct Customer* customer_list){
    int size = sizeof(customer_list) / sizeof(customer_list[0]);
    printf("Enter the following details:\n");
    printf("Name: ");
    scanf("%s", customer_list[size].name);
    printf("Account type: ");
    scanf("%s", customer_list[size].account_type);
    printf("Account number: ");
    scanf("%d", &customer_list[size].account_number);
    printf("Balance: ");
    scanf("%f", &customer_list[size].balance);
    printf("Customer Added Successfully!\n");
    return size+1;
}

//function to deposit amount
void deposit_money(struct Customer* customer_list, int index){
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    customer_list[index].balance += amount;
    printf("New balance: %.2f\n", customer_list[index].balance);
}

//function to withdraw amount
void withdraw_money(struct Customer* customer_list, int index){
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if(amount > customer_list[index].balance){
        printf("Insufficient balance!\n");
    }else{
        customer_list[index].balance -= amount;
        printf("New balance: %.2f\n", customer_list[index].balance);
    }
}

//function to view account details
void view_details(struct Customer* customer_list, int index){
    printf("Name: %s\n", customer_list[index].name);
    printf("Account type: %s\n", customer_list[index].account_type);
    printf("Account number: %d\n", customer_list[index].account_number);
    printf("Balance: %.2f\n", customer_list[index].balance);
}

int main(){
    struct Customer customers[10];
    int choice = 0;
    int size = 0;
    int account_number;

    do{
        printf("\n");
        printf("1. Add new customer\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. View account details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                size = add_customer(customers);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                for(int i=0; i<size; i++){
                    if(customers[i].account_number == account_number){
                        deposit_money(customers, i);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                for(int i=0; i<size; i++){
                    if(customers[i].account_number == account_number){
                        withdraw_money(customers, i);
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                for(int i=0; i<size; i++){
                    if(customers[i].account_number == account_number){
                        view_details(customers, i);
                        break;
                    }
                }
                break;
            case 5:
                printf("Thank you for using our services!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 5);

    return 0;
}