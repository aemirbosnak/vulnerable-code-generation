//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include<stdio.h>
#include<string.h>

struct customer
{
    int account_no;
    char name[30];
    float balance;
};

void add_customer(struct customer [], int *);
void deposit_amount(struct customer [], int);
void withdraw_amount(struct customer [], int);
void display_all(struct customer [], int);
void display_customer(struct customer [], int);

int main()
{
    struct customer bank[50];
    int num_customers = 0;
    int choice;
    
    do
    {
        printf("\nWelcome to Banking Record System");
        printf("\n1.Add a Customer\n2.Deposit Amount\n3.Withdraw Amount\n4.Display All Customers\n5.Display a Customer\n6.Exit");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                add_customer(bank, &num_customers);
                break;
            case 2:
                deposit_amount(bank, num_customers);
                break;
            case 3:
                withdraw_amount(bank, num_customers);
                break;
            case 4:
                display_all(bank, num_customers);
                break;
            case 5:
                display_customer(bank, num_customers);
                break;
            case 6:
                printf("\nThank you for using Banking Record System!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
        
    }while(choice != 6);
    
    return 0;
}

void add_customer(struct customer bank[], int *n)
{
    printf("\nAdding a Customer\n");
    printf("\nEnter the account number: ");
    scanf("%d", &bank[*n].account_no);
    
    printf("Enter the name of the customer: ");
    getchar();
    fgets(bank[*n].name, 30, stdin);
    
    printf("Enter the initial balance: ");
    scanf("%f", &bank[*n].balance);
    
    (*n)++;
    printf("\nCustomer added successfully!\n");
}

void deposit_amount(struct customer bank[], int n)
{
    int account_no, i;
    float amount;
    printf("\nDepositing Amount\n");
    printf("\nEnter account number: ");
    scanf("%d", &account_no);
    
    for(i = 0; i < n; i++)
    {
        if(bank[i].account_no == account_no)
        {
            printf("Enter the amount to be deposited: ");
            scanf("%f", &amount);
            bank[i].balance += amount;
            printf("\nAmount deposited successfully!\n");
            return;
        }
    }
    
    printf("\nAccount not found. Please enter a valid account number.\n");
}

void withdraw_amount(struct customer bank[], int n)
{
    int account_no, i;
    float amount;
    printf("\nWithdrawing Amount\n");
    printf("\nEnter account number: ");
    scanf("%d", &account_no);
    
    for(i = 0; i < n; i++)
    {
        if(bank[i].account_no == account_no)
        {
            printf("Enter the amount to be withdrawn: ");
            scanf("%f", &amount);
            if(amount > bank[i].balance)
            {
                printf("\nInsufficient balance. Please try again.\n");
                return;
            }
            bank[i].balance -= amount;
            printf("\nAmount withdrawn successfully!\n");
            return;
        }
    }
    
    printf("\nAccount not found. Please enter a valid account number.\n");
}

void display_all(struct customer bank[], int n)
{
    int i;
    printf("\nDisplaying all customers:\n");
    printf("Account Number\tCustomer Name\tInitial Balance\n");
    
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%s\t\t%f\n", bank[i].account_no, bank[i].name, bank[i].balance);
    }
}

void display_customer(struct customer bank[], int n)
{
    int account_no, i;
    printf("\nDisplaying a Customer\n");
    printf("\nEnter account number: ");
    scanf("%d", &account_no);
    
    for(i = 0; i < n; i++)
    {
        if(bank[i].account_no == account_no)
        {
            printf("\nAccount Number: %d\n", bank[i].account_no);
            printf("Customer Name: %s", bank[i].name);
            printf("Current balance: %f", bank[i].balance);
            return;
        }
    }
    
    printf("\nAccount not found. Please enter a valid account number.\n");
}