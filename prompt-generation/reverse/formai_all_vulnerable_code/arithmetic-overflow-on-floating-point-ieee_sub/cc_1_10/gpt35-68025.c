//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Defining Limit constants for each type of fields used*/
#define LIMIT_ACC_NO 10
#define LIMIT_NAME 50
#define LIMIT_ADDRESS 100
#define LIMIT_PHONE_NO 12

/*Structure for keeping the details of Bank Account*/
struct Bank_Account{
	char acc_no[LIMIT_ACC_NO];
  char name[LIMIT_NAME];
  char address[LIMIT_ADDRESS];
  char phone_no[LIMIT_PHONE_NO];
	float balance;
};

/*Function to create a record for the bank account*/
struct Bank_Account create_account(){
	struct Bank_Account new_acc;
	printf("\nEnter the Account Number (Max. 10 Characters): ");
	gets(new_acc.acc_no);
	printf("Enter the Name (Max. 50 Characters): ");
	gets(new_acc.name);
	printf("Enter the Address (Max. 100 Characters): ");
	gets(new_acc.address);
	printf("Enter the Phone Number (Max. 12 Characters): ");
	gets(new_acc.phone_no);
	new_acc.balance = 0;
	printf("\nAccount has been created successfully.\n\n");
	return new_acc;
}

/*Function to get the option number from the user*/
int get_option(){
    int option;
    printf("\nPlease enter your option:\n\n");
    printf("1. Create New Account.\n");
    printf("2. View Account Details.\n");
    printf("3. Deposit Amount.\n");
    printf("4. Withdraw Amount.\n");
    printf("5. Quit\n\n");
    printf("Option: ");
    scanf("%d", &option);
    return option;
}

/*Function to print account detail*/
void print_account(struct Bank_Account acc){
	printf("\n\nAccount Details:\n\n");
	printf("Account Number: %s\n", acc.acc_no);
	printf("Name: %s\n", acc.name);
	printf("Address: %s\n", acc.address);
	printf("Phone Number: %s\n", acc.phone_no);
	printf("Balance: %f\n", acc.balance);
}

/*Function to deposit amount in user account*/
void deposit_amount(struct Bank_Account *acc_ptr){
	float amount;
	printf("\nEnter the Amount to be Deposited: ");
	scanf("%f", &amount);
	(*acc_ptr).balance += amount;
	printf("\nAmount Deposited Successfully.\n");
	print_account(*acc_ptr);	
}

/*Function to withdraw amount from user account*/
void withdraw_amount(struct Bank_Account *acc_ptr){
	float amount;
	printf("\nEnter the Amount to be Withdrawn: ");
	scanf("%f", &amount);
	if((*acc_ptr).balance < amount){
		printf("\nInsufficient Balance. Transaction can't be completed.\n\n");
	}else{
		(*acc_ptr).balance -= amount;
		printf("\nAmount Withdrawn Successfully.\n");
		print_account(*acc_ptr);
	}
}

int main(){
	int option;
	struct Bank_Account acc;

	printf("\t\tWelcome to Banking Record System\n\n");
  
	do{
		option = get_option();

		switch(option){
			case 1:	/*creating a new account*/
				acc = create_account();
				break;

			case 2:	/*viewing account details*/
				print_account(acc);
				break;

			case 3:	/*depositing amount*/
				deposit_amount(&acc);
				break;

			case 4:	/*withdrawing amount*/
				withdraw_amount(&acc);
				break;

			case 5:	/*quitting*/
				printf("\n\nGoodbye. Have a good day.\n\n");
				break;

			default:/*invalid input exception*/
				printf("\nInvalid Option. Please choose the valid option.\n");
				break;
		}

	}while(option!=5);

	return 0;	
}