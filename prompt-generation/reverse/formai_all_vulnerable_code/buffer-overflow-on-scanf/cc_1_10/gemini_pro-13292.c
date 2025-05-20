//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[20];
} Customer;

Medicine *medicines;
int num_medicines;
Customer *customers;
int num_customers;

void add_medicine() {
    printf("Enter medicine name: ");
    scanf("%s", medicines[num_medicines].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[num_medicines].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[num_medicines].price);
    num_medicines++;
}

void add_customer() {
    printf("Enter customer ID: ");
    scanf("%d", &customers[num_customers].id);
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer address: ");
    scanf("%s", customers[num_customers].address);
    printf("Enter customer phone: ");
    scanf("%s", customers[num_customers].phone);
    num_customers++;
}

void sell_medicine() {
    int medicine_id, customer_id, quantity;
    printf("Enter medicine ID: ");
    scanf("%d", &medicine_id);
    printf("Enter customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    if (medicines[medicine_id].quantity >= quantity) {
        medicines[medicine_id].quantity -= quantity;
        // TODO: Update customer's purchase history
        printf("Medicine sold successfully\n");
    } else {
        printf("Insufficient stock\n");
    }
}

void print_medicines() {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void print_customers() {
    printf("ID\tName\tAddress\tPhone\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d\t%s\t%s\t%s\n", customers[i].id, customers[i].name, customers[i].address, customers[i].phone);
    }
}

int main() {
    medicines = malloc(sizeof(Medicine) * 100);
    customers = malloc(sizeof(Customer) * 100);
    num_medicines = 0;
    num_customers = 0;
    int choice;
    while (1) {
        printf("1. Add medicine\n2. Add customer\n3. Sell medicine\n4. Print medicines\n5. Print customers\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                add_customer();
                break;
            case 3:
                sell_medicine();
                break;
            case 4:
                print_medicines();
                break;
            case 5:
                print_customers();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}