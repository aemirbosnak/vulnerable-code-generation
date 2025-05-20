//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    char address[100];
    float balance;
};

struct invoice {
    char customer_name[50];
    float total_amount;
    float tax_amount;
};

void print_customer(struct customer* customer) {
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Balance: $%.2f\n", customer->balance);
}

void print_invoice(struct invoice* invoice) {
    printf("Customer Name: %s\n", invoice->customer_name);
    printf("Total Amount: $%.2f\n", invoice->total_amount);
    printf("Tax Amount: $%.2f\n", invoice->tax_amount);
}

void generate_invoice(struct customer* customer, struct invoice* invoice) {
    float total_amount = 0.0;
    float tax_amount = 0.0;

    for (int i = 0; i < 10; i++) {
        total_amount += i * 10.0;
        tax_amount += i * 0.1;
    }

    invoice->total_amount = total_amount;
    invoice->tax_amount = tax_amount;
    strcpy(invoice->customer_name, customer->name);
}

int main() {
    struct customer customer;
    struct invoice invoice;

    printf("Enter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer address: ");
    scanf("%s", customer.address);
    printf("Enter customer balance: ");
    scanf("%f", &customer.balance);

    generate_invoice(&customer, &invoice);

    printf("Customer Name: %s\n", invoice.customer_name);
    printf("Total Amount: $%.2f\n", invoice.total_amount);
    printf("Tax Amount: $%.2f\n", invoice.tax_amount);

    return 0;
}