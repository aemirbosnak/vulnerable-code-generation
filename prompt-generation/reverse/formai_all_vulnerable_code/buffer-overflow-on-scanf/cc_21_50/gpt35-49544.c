//FormAI DATASET v1.0 Category: Banking Record System ; Style: authentic
#include<stdio.h>  // standard input/output header file 
#include<stdlib.h> // standard library header file 

struct account{  // defining a struct "account"
    int account_number; // account number as integer data type
    char account_type[20]; // account type as character array data type
    float balance; // balance as float data type
}customer[100];  // defining an array customer of structure account with max 100 customers 

int main(){  // main function
    int choice,i=0,customer_count=0,account_number,found=0;  // declaring variables 
    char account_type[20]; 
    float balance; 
        
    while(1){  // infinite while loop
        printf("\n\n***********WELCOME TO BANK XYZ***********\n"); 
        printf("\n1. Open a new account"); 
        printf("\n2. Display all accounts"); 
        printf("\n3. Search for an account"); 
        printf("\n4. Deposit money to an account"); 
        printf("\n5. Withdraw money from an account"); 
        printf("\n6. Exit"); 
        printf("\n\nEnter your choice: "); 
        scanf("%d",&choice); 

        switch (choice){ // switch case
            case 1: // for opening a new account
                printf("\nEnter account number: "); 
                scanf("%d",&account_number); 
                printf("\nEnter account type: "); 
                scanf("%s",account_type); 
                printf("\nEnter balance: "); 
                scanf("%f",&balance); 
            
                customer[i].account_number=account_number; // assigning values to structure variables 
                strcpy(customer[i].account_type,account_type); 
                customer[i].balance=balance; 
                i++; // incrementing the counter
                customer_count++; // incrementing the customer count
                printf("\nAccount created successfully"); 
                break; 

            case 2: // for displaying all accounts
                if(customer_count==0){ // if accounts have not been created yet
                    printf("\nNo accounts created yet"); 
                } 
                else{ // if accounts have been created 
                    printf("\n**********LIST OF ACCOUNTS**********\n");
                    printf("\nAccount No.\tAccount Type\tBalance\n");
                    for(int j=0;j<i;j++){ // loop through all customers and display their account details
                        printf("\n%d\t\t%s\t\t%.2f",customer[j].account_number,customer[j].account_type,customer[j].balance);
                    } 
                } 
                break; 

            case 3: // for searching an account
                if(customer_count==0){ // if accounts have not been created yet
                    printf("\nNo accounts created yet"); 
                } 
                else{ // if accounts have been created
                    printf("\nEnter account number: "); 
                    scanf("%d",&account_number); 
                    for(int j=0;j<i;j++){ // loop through all customers and check if their account number matches the input account number
                        if(customer[j].account_number==account_number){ //if account found
                            printf("\nAccount found successfully"); 
                            printf("\nAccount No.\tAccount Type\tBalance\n");
                            printf("\n%d\t\t%s\t\t%.2f",customer[j].account_number,customer[j].account_type,customer[j].balance); 
                            found=1; // setting found flag to 1
                            break; 
                        }
                    } 
                    if(found==0){ // if account not found
                        printf("\nAccount not found"); 
                    } 
                } 
                break; 

            case 4: // for depositing money to an account
                if(customer_count==0){ // if accounts have not been created yet
                    printf("\nNo accounts created yet"); 
                } 
                else{ // if accounts have been created
                    printf("\nEnter account number: "); 
                    scanf("%d",&account_number); 
                    for(int j=0;j<i;j++){ // loop through all customers and check if their account number matches the input account number
                        if(customer[j].account_number==account_number){ // if account found
                            printf("\nEnter amount to deposit: "); 
                            float amount; 
                            scanf("%f",&amount); 
                            customer[j].balance+=amount; // add the deposited amount to the balance of the account
                            printf("\nDeposited successfully"); 
                            found=1; // setting found flag to 1
                            break; 
                        } 
                    } 
                    if(found==0){ // if account not found
                        printf("\nAccount not found"); 
                    }
                } 
                break; 

            case 5: // for withdrawing money from an account
                if(customer_count==0){ // if accounts have not been created yet
                    printf("\nNo accounts created yet"); 
                } 
                else{ // if accounts have been created 
                    printf("\nEnter account number: "); 
                    scanf("%d",&account_number); 
                    for(int j=0;j<i;j++){ // loop through all customers and check if their account number matches the input account number
                        if(customer[j].account_number==account_number){ // if account found
                            printf("\nEnter amount to withdraw: "); 
                            float amount; 
                            scanf("%f",&amount); 
                            if(amount>customer[j].balance){ // if requested amount for withdrawal is more than balance available in account
                                printf("\nError! Insufficient balance"); 
                            } 
                            else{ // if sufficient balance available to withdraw
                                customer[j].balance-=amount; // subtract the withdrawn amount from the balance of the account
                                printf("\nWithdrawn successfully"); 
                            } 
                            found=1; // setting found flag to 1
                            break; 
                        } 
                    } 
                    if(found==0){ // if account not found
                        printf("\nAccount not found"); 
                    } 
                } 
                break; 

            case 6: // for exiting the program
                printf("\nThank you for visiting bank XYZ!\n"); 
                exit(0); // terminating the program safely

            default: // for invalid input
                printf("\nInvalid input"); 
                break; 
        } 
    } 
    return 0; // end of the program 
}