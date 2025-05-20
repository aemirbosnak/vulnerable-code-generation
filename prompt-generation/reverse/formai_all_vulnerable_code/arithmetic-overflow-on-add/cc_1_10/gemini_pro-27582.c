//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
} customer;

typedef struct {
    int invoice_number;
    char date[20];
    customer customer;
    medicine medicines[100];
    int num_medicines;
    float total_amount;
} invoice;

void add_medicine(medicine *medicines, int *num_medicines) {
    printf("Enter the name of the medicine: ");
    scanf(" %s", medicines[*num_medicines].name);
    printf("Enter the quantity of the medicine: ");
    scanf(" %d", &medicines[*num_medicines].quantity);
    printf("Enter the price of the medicine: ");
    scanf(" %f", &medicines[*num_medicines].price);
    (*num_medicines)++;
}

void add_customer(customer *customer) {
    printf("Enter the name of the customer: ");
    scanf(" %s", customer->name);
    printf("Enter the address of the customer: ");
    scanf(" %s", customer->address);
    printf("Enter the phone number of the customer: ");
    scanf(" %s", customer->phone);
}

void create_invoice(invoice *invoice) {
    printf("Enter the invoice number: ");
    scanf(" %d", &invoice->invoice_number);
    printf("Enter the date of the invoice: ");
    scanf(" %s", invoice->date);
    add_customer(&invoice->customer);
    printf("Enter the number of medicines: ");
    scanf(" %d", &invoice->num_medicines);
    for (int i = 0; i < invoice->num_medicines; i++) {
        add_medicine(invoice->medicines, &invoice->num_medicines);
    }
    invoice->total_amount = 0;
    for (int i = 0; i < invoice->num_medicines; i++) {
        invoice->total_amount += invoice->medicines[i].quantity * invoice->medicines[i].price;
    }
}

void print_invoice(invoice *invoice) {
    printf("Invoice Number: %d\n", invoice->invoice_number);
    printf("Date: %s\n", invoice->date);
    printf("Customer Name: %s\n", invoice->customer.name);
    printf("Customer Address: %s\n", invoice->customer.address);
    printf("Customer Phone: %s\n", invoice->customer.phone);
    printf("Medicines:\n");
    for (int i = 0; i < invoice->num_medicines; i++) {
        printf("\t%s %d %.2f\n", invoice->medicines[i].name, invoice->medicines[i].quantity, invoice->medicines[i].price);
    }
    printf("Total Amount: %.2f\n", invoice->total_amount);
}

int main() {
    int choice;
    invoice invoice;
    while (1) {
        printf("1. Create Invoice\n");
        printf("2. Print Invoice\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                create_invoice(&invoice);
                break;
            case 2:
                print_invoice(&invoice);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}