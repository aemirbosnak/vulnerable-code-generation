//FormAI DATASET v1.0 Category: Banking Record System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for bank customer record
struct customers{
    int account_number;
    char name[50];
    float balance;
};

//Function to read customer details
void read_customer_details(struct customers *c){
    printf("Enter account number: ");
    scanf("%d",&c->account_number);
    
    printf("Enter name: ");
    scanf("%s",c->name);
    
    printf("Enter balance: ");
    scanf("%f",&c->balance);
}

//Function to print customer details
void print_customer_details(struct customers *c){
    printf("Account number: %d\n",c->account_number);
    printf("Name: %s\n",c->name);
    printf("Balance: %f\n",c->balance);
}

//Function to search for a customer
void search_customer(struct customers *c,int account_number,int num_customers){
    int i,flag=0;
    for(i=0;i<num_customers;i++){
        if(c[i].account_number==account_number){
            print_customer_details(&c[i]);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Customer with account number %d not found\n",account_number);
    }
}

//Function to add a new customer
void add_customer(struct customers *c,int *num_customers){
    read_customer_details(&c[*num_customers]);
    (*num_customers)++;
}

int main(){
    struct customers c[10]; //Array to hold customer records
    int num_customers=0,option,account_number;
    
    while(1){
        printf("\n");
        printf("1. Search for a customer\n");
        printf("2. Add a new customer\n");
        printf("3. Print all customers\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d",&option);
        
        switch(option){
            case 1:
                printf("Enter account number: ");
                scanf("%d",&account_number);
                search_customer(c,account_number,num_customers);
                break;
            case 2:
                add_customer(c,&num_customers);
                printf("New customer added successfully\n");
                break;
            case 3:
                if(num_customers==0){
                    printf("No customers in the system\n");
                }
                for(int i=0;i<num_customers;i++){
                    print_customer_details(&c[i]);
                }
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    
    return 0;
}