//FormAI DATASET v1.0 Category: Banking Record System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CUSTOMERS 1000

// Structure representing a bank customer record.
struct Customer {
    char name[50];
    char address[100];
    long int account_no;
    float balance;
};

typedef struct Customer Customer; // Alias for Customer structure.

// Recursive function that prints customer records in sorted order by account number.
void printRecords(Customer* customers, int start, int end) {
    if(start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    printRecords(customers, start, mid);
    printf("Name: %s\nAddress: %s\nAccount Number: %ld\nBalance: %.2f\n\n", customers[mid].name, customers[mid].address, customers[mid].account_no, customers[mid].balance);
    printRecords(customers, mid + 1, end);
}

int main() {
    int num_customers;
    Customer customers[MAX_CUSTOMERS];
    printf("Enter number of customers: ");
    scanf("%d", &num_customers);

    // Prompt for customer details.
    for(int i = 0; i < num_customers; i++) {
        printf("Enter details for Customer %d:\n", i+1);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Address: ");
        scanf("%s", customers[i].address);
        printf("Account Number: ");
        scanf("%ld", &customers[i].account_no);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
    }
    
    // Sort customers by account number in ascending order.
    for(int i = 1; i < num_customers; i++) {
        Customer temp = customers[i];
        int j = i - 1;
        while(j >= 0 && customers[j].account_no > temp.account_no) {
            customers[j+1] = customers[j];
            j--;
        }
        customers[j+1] = temp;
    }

    // Print customer records.
    printf("Customer Records:\n");
    printRecords(customers, 0, num_customers);
    return 0;
}