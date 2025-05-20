//FormAI DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

typedef struct customer {          //structure to store customer data
    int account_number;
    char name[20];
    float balance;
} customer;

void display_customers(customer c[], int n);        //function to display all customers
void add_customer(customer c[], int *n);           //function to add new customer
void deposit(customer c[], int n);                 //function to deposit amount to customer account
void withdraw(customer c[], int n);                //function to withdraw amount from customer account
void search(customer c[], int n);                  //function to search for a customer based on account number

int main() {
    int n=0, option;
    customer c[50];             //array of structure to hold customer data
    
    do {
        printf("\n\n\t\tBanking Record System \n\n");
        printf("1. View all customers\n");
        printf("2. Add new customer\n");
        printf("3. Deposit amount to customer account\n");
        printf("4. Withdraw amount from customer account\n");
        printf("5. Search customer based on account number\n");
        printf("6. Exit\n\n");
        printf("Enter your option: ");
        
        scanf("%d", &option);           //getting user option
        
        switch(option) {
            case 1: display_customers(c,n); break;            //call to display all customers
            case 2: add_customer(c,&n); break;                //call to add new customer
            case 3: deposit(c,n); break;                      //call to deposit amount
            case 4: withdraw(c,n); break;                     //call to withdraw amount
            case 5: search(c,n); break;                       //call to search for customer
            case 6: printf("\nExiting program...\n"); break;  //exit program
            default: printf("\nInvalid option. Please try again.\n");   //in case of invalid option
        }
    
    } while(option != 6); //loop until user enters "6" to exit program
    
    return 0;   //end of program
}

void display_customers(customer c[], int n) {         //function to display all customers
    if(n==0) {
        printf("\nNo customers found.\n");
        return;
    }

    printf("\nAccount Number\t\tCustomer Name\t\tBalance\n");

    for(int i=0; i<n; i++) {
        printf("%d\t\t\t%s\t\t%.2f\n", c[i].account_number, c[i].name, c[i].balance);
    }
}

void add_customer(customer c[], int *n) {            //function to add new customer
    printf("\nEnter customer name: ");
    scanf("%s", c[*n].name);
    
    printf("\nEnter initial amount to be deposited: ");
    scanf("%f", &c[*n].balance);

    c[*n].account_number = *n + 1;              //setting account number as index of array + 1
    (*n)++;

    printf("\nSuccessfully added customer with account number %d.\n", c[*n-1].account_number);
}

void deposit(customer c[], int n) {                //function to deposit amount to customer account
    int acc;
    float amount;
    int flag=0;
    
    printf("\nEnter account number: ");
    scanf("%d", &acc);

    for(int i=0; i<n; i++) {        //search for account number in array
        if(c[i].account_number == acc) {
            printf("\nEnter amount to be deposited: ");
            scanf("%f", &amount);
            c[i].balance += amount;     //add amount to customer balance
            flag = 1;                   //mark customer as found
            printf("\nAmount deposited successfully. Updated balance: %.2f\n", c[i].balance);
            break;
        }
    }
    
    if(flag == 0) {
        printf("\nAccount Number not found.\n");
    }
}

void withdraw(customer c[], int n) {       //function to withdraw amount from customer account
    int acc;
    float amount;
    int flag=0;
    
    printf("\nEnter account number: ");
    scanf("%d", &acc);

    for(int i=0; i<n; i++) {        //search for account number in array
        if(c[i].account_number == acc) {
            printf("\nEnter amount to be withdrawn: ");
            scanf("%f", &amount);
            
            if(c[i].balance < amount) {     //check if sufficient balance is present
                printf("\nInsufficient Balance.\n");
                break;
            }
            
            c[i].balance -= amount;     //subtract amount from customer balance
            flag = 1;                   //mark customer as found
            printf("\nAmount withdrawn successfully. Updated balance: %.2f\n", c[i].balance);
            break;
        }
    }
    
    if(flag == 0) {
        printf("\nAccount Number not found.\n");
    }
}

void search(customer c[], int n) {      //function to search for a customer based on account number
    int acc;
    int flag=0;
    
    printf("\nEnter account number: ");
    scanf("%d", &acc);

    for(int i=0; i<n; i++) {        //search for account number in array
        if(c[i].account_number == acc) {
            flag = 1;                   //mark customer as found
            printf("\nAccount Number\t\tCustomer Name\t\tBalance\n");
            printf("%d\t\t\t%s\t\t%.2f\n", c[i].account_number, c[i].name, c[i].balance);
            break;
        }
    }
    
    if(flag == 0) {
        printf("\nAccount Number not found.\n");
    }
}