//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int age;
    char gender[10];
    int table;
    int order[10];
    float bill;
} Customer;

void create_customer(Customer* customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter customer age: ");
    scanf("%d", &customer->age);
    printf("Enter customer gender: ");
    scanf("%s", customer->gender);
    printf("Enter customer table number: ");
    scanf("%d", &customer->table);
}

void display_customer(Customer customer) {
    printf("Customer Name: %s\n", customer.name);
    printf("Customer Age: %d\n", customer.age);
    printf("Customer Gender: %s\n", customer.gender);
    printf("Customer Table Number: %d\n", customer.table);
}

void create_order(Customer* customer, int num_items) {
    printf("Enter order items:\n");
    for (int i = 0; i < num_items; i++) {
        char item[20];
        float price;
        printf("Item %d: ", i+1);
        scanf("%s", item);
        printf("Price: ");
        scanf("%f", &price);
        customer->order[i] = (char*)malloc(sizeof(char) * (strlen(item)+1));
        strcpy(customer->order[i], item);
        customer->bill += price;
    }
}

void display_order(Customer customer) {
    printf("Order Items:\n");
    for (int i = 0; i < 10; i++) {
        if (customer.order[i]!= NULL) {
            printf("%s - $%.2f\n", customer.order[i], customer.bill/10);
        }
    }
}

void main() {
    srand(time(NULL));
    Customer customer;
    create_customer(&customer);
    int num_items = rand() % 10 + 1;
    create_order(&customer, num_items);
    display_customer(customer);
    display_order(customer);
    printf("Total Bill: $%.2f\n", customer.bill);
}