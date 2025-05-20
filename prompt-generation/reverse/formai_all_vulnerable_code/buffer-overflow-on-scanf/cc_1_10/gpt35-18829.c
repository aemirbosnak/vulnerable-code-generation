//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the structure for the customer account records
struct account {
    char name[50];
    char address[100];
    int account_no;
    float balance;
};

int main() {
    printf("Welcome to the ABC Banking Record System\n");
    int num_customers;

    //Prompt user for number of customers
    printf("How many customers do you want to add to the record system?\n");
    scanf("%d", &num_customers);

    //Dynamically allocate memory for customer account records
    struct account *bank_records = (struct account *) malloc(num_customers * sizeof(struct account));

    //Prompt user to input customer details and save to records
    for(int i=0; i<num_customers; i++) {
        printf("Enter customer name:\n");
        scanf("%s", bank_records[i].name);
        printf("Enter customer address:\n");
        scanf("%s", bank_records[i].address);
        printf("Enter customer account number:\n");
        scanf("%d", &bank_records[i].account_no);
        printf("Enter customer balance:\n");
        scanf("%f", &bank_records[i].balance);
    }

    //Display the customer records
    printf("-----------------------------------------------------------\n");
    printf("Name\tAddress\t\tAccount No.\tBalance\n");
    printf("-----------------------------------------------------------\n");
    for(int i=0; i<num_customers; i++) {
        printf("%s\t%s\t\t%d\t\t%.2f\n", bank_records[i].name, bank_records[i].address, bank_records[i].account_no, bank_records[i].balance);
    }

    //Prompt user to update a customer's balance
    printf("Enter the account number of the customer whose balance you want to update:\n");
    int account_num;
    scanf("%d", &account_num);
    for(int i=0; i<num_customers; i++) {
        if(bank_records[i].account_no == account_num) {
            printf("Enter the new balance for %s:\n", bank_records[i].name);
            float new_balance;
            scanf("%f", &new_balance);
            bank_records[i].balance = new_balance;
            break;
        }
    }

    //Display updated customer record
    printf("-----------------------------------------------------------\n");
    printf("Name\tAddress\t\tAccount No.\tBalance\n");
    printf("-----------------------------------------------------------\n");
    for(int i=0; i<num_customers; i++) {
        printf("%s\t%s\t\t%d\t\t%.2f\n", bank_records[i].name, bank_records[i].address, bank_records[i].account_no, bank_records[i].balance);
    }

    //Free dynamically allocated memory
    free(bank_records);

    return 0;
}