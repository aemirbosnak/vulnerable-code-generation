//FormAI DATASET v1.0 Category: Banking Record System ; Style: happy
//Welcome to our amazing C Banking Record System! 😎

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for Customer Data
struct Customer {
    char name[50];
    char address[50];
    char accountType[20];
    int accountNo;
    float balance;
};

int main() {
    //Variable Declaration
    int numCustomers;
    float total = 0;
    
    //Prompt user to enter number of customers
    printf("Welcome to C Banking Record System!\n\n");
    printf("Please enter the number of customers to input: ");
    scanf("%d", &numCustomers);

    //Dynamically allocate memory for customers
    struct Customer *customers = malloc(numCustomers * sizeof(struct Customer));

    //Prompt user to enter customer details
    for(int i=0; i<numCustomers; i++) {
        printf("\nCustomer #%d Details\n", i+1);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Address: ");
        scanf("%s", customers[i].address);
        printf("Account Type (Savings/Checking): ");
        scanf("%s", customers[i].accountType);
        printf("Account Number: ");
        scanf("%d", &customers[i].accountNo);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);

        total += customers[i].balance; //Update total balance
    }

    //Print Customer Data
    printf("\n\nBanking Record System\n");
    printf("-------------------------\n");
    printf("Customer Name\tAddress\t\tAccount Type\tAcc No.\tBalance\n");
    printf("-----------------------------------------------------------------------\n");
    for(int i=0; i<numCustomers; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t$%.2f\n", customers[i].name, customers[i].address, customers[i].accountType, customers[i].accountNo, customers[i].balance);
    }
    //Print Total Balance
    printf("-----------------------------------------------------------------------\n");
    printf("Total Balance in the Bank: $%.2f\n", total);

    //Free Dynamically Allocated Memory
    free(customers);

    printf("\n\nThank you for using our Banking Record System, have a great day! 😃");
    return 0;
}