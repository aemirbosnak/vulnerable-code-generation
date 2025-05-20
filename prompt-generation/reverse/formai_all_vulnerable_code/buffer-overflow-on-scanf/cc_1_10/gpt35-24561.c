//FormAI DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include<stdio.h>
#include<string.h>

struct record{
    char name[30];
    int account_number;
    float balance;
};

struct record customer[500];
int total_customers = 0;

void add_customer(){
    printf("Enter Customer Name: ");
    fflush(stdin);
    fgets(customer[total_customers].name, 30, stdin);
    
    printf("Enter Account Number: ");
    scanf("%d",&customer[total_customers].account_number);
    
    printf("Enter Balance: ");
    scanf("%f",&customer[total_customers].balance);
    
    total_customers++;
}

void display_customers(){
    if(total_customers == 0){
        printf("No Customers Found!\n");
        return;
    }
    
    printf("Name\tAccount Number\tBalance\n");
    for(int i=0;i<total_customers;i++){
        printf("%s\t%d\t\t%.2f\n",customer[i].name,customer[i].account_number,customer[i].balance);
    }
}

int search_customer(int account_number){
    for(int i=0;i<total_customers;i++){
        if(customer[i].account_number == account_number){
            return i;
        }
    }
    return -1;
}

void update_balance(){
    int account_number;
    printf("Enter Account Number to Update Balance: ");
    scanf("%d",&account_number);
    
    int index = search_customer(account_number);
    if(index == -1){
        printf("Customer not found!\n");
        return;
    }
    
    float new_balance;
    printf("Enter New Balance: ");
    scanf("%f",&new_balance);
    
    customer[index].balance = new_balance;
    printf("Balance updated successfully!\n");
}

void delete_customer(){
    int account_number;
    printf("Enter Account Number to Delete Customer: ");
    scanf("%d",&account_number);
    
    int index = search_customer(account_number);
    if(index == -1){
        printf("Customer not found!\n");
        return;
    }
    
    for(int i=index;i<total_customers-1;i++){
        strcpy(customer[i].name,customer[i+1].name);
        customer[i].account_number = customer[i+1].account_number;
        customer[i].balance = customer[i+1].balance;
    }
    total_customers--;
    printf("Customer deleted successfully!\n");
}

int main(){
    int option;
    do{
        printf("\nWelcome to Banking Record System\n");
        printf("1. Add Customer\n");
        printf("2. Display Customers\n");
        printf("3. Update Balance\n");
        printf("4. Delete Customer\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        
        switch(option){
            case 1:
                add_customer();
                break;
            case 2:
                display_customers();
                break;
            case 3:
                update_balance();
                break;
            case 4:
                delete_customer();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Option! Please try again.\n");
        }
    }while(option != 5);
    return 0;
}