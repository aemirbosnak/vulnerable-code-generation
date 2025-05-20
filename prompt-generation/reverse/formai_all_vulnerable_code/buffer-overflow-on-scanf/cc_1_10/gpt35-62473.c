//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer
{
    char name[20];
    char account_number[10];
    char contact_number[15];
    double balance;
};

int num_customers = 0;

// Function to display menu
void display_menu()
{
    printf("\n\n************ Welcome to the Futuristic C Banking Record System ************");
    printf("\n\n1. Add a Customer");
    printf("\n2. Display Customer Details");
    printf("\n3. Update Customer Information");
    printf("\n4. Delete Customer");
    printf("\n5. Exit");
}

// Function to add a new customer
void add_customer(struct customer *c)
{
    getchar(); // to consume \n character left by previous scanf
    printf("\nEnter Name: ");
    scanf("%[^\n]s", c[num_customers].name);
    printf("Enter Account Number: ");
    scanf("%s", c[num_customers].account_number);
    printf("Enter Contact Number: ");
    scanf("%s", c[num_customers].contact_number);
    printf("Enter Initial Balance: ");
    scanf("%lf", &c[num_customers].balance);
    num_customers++;
    printf("\nCustomer Added Successfully!");
}

// Function to display all customer details
void display_details(struct customer *c)
{
    printf("\n************ Customer Details ************\n");
    for(int i=0; i<num_customers; i++)
    {
        printf("\nName: %s", c[i].name);
        printf("\nAccount Number: %s", c[i].account_number);
        printf("\nContact Number: %s", c[i].contact_number);
        printf("\nBalance: %.2lf\n", c[i].balance);
    }
}

// Function to update customer information
void update_customer(struct customer *c)
{
    char account_number[10];
    int found = 0;
    printf("\nEnter Account Number of Customer whose information needs to be updated: ");
    scanf("%s", account_number);

    for(int i=0; i<num_customers; i++)
    {
        if(strcmp(c[i].account_number, account_number) == 0)
        {
            getchar(); // to consume \n character left by previous scanf
            printf("\nEnter New Name: ");
            scanf("%[^\n]s", c[i].name);
            printf("Enter New Contact Number: ");
            scanf("%s", c[i].contact_number);
            printf("\nCustomer Information Updated Successfully!");
            found = 1;
            break;
        }
    }
    if(!found)
        printf("\nCustomer with Account Number %s not found! Please verify the Account Number and try again.\n", account_number);

}

// Function to delete a customer
void delete_customer(struct customer *c)
{
    char account_number[10];
    int found = 0;
    printf("\nEnter Account Number of Customer who needs to be deleted: ");
    scanf("%s", account_number);

    for(int i=0; i<num_customers; i++)
    {
        if(strcmp(c[i].account_number, account_number) == 0)
        {
            for(int j=i; j<num_customers-1; j++)
                c[j] = c[j+1];
            num_customers--;
            printf("\nCustomer Deleted Successfully!");
            found = 1;
            break;
        }
    }
    if(!found)
        printf("\nCustomer with Account Number %s not found! Please verify the Account Number and try again.\n", account_number);

}

int main()
{
    struct customer c[10];
    int choice;

    do
    {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(num_customers == 10)
                    printf("\nMaximum number of Customers reached!");
                else
                    add_customer(c);
                break;
            case 2:
                if(num_customers == 0)
                    printf("\nNo Customers found! Please add a customer first.\n");
                else
                    display_details(c);
                break;
            case 3:
                if(num_customers == 0)
                    printf("\nNo Customers found! Please add a customer first.\n");
                else
                    update_customer(c);
                break;
            case 4:
                if(num_customers == 0)
                    printf("\nNo Customers found! Please add a customer first.\n");
                else
                    delete_customer(c);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice! Please try again.\n");
        }
    } while(1);
    
    return 0;
}