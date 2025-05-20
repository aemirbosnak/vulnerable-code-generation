//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int age;
    char gender[10];
    char phone[15];
} Customer;

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    char name[50];
    Customer customer;
    int numItems;
    Item items[MAX_ITEMS];
} Order;

int numCustomers = 0;
Customer customers[MAX_CUSTOMERS];

int main() {
    int choice;
    char name[50];
    int age;
    char gender[10];
    char phone[15];

    do {
        printf("1. Add customer\n");
        printf("2. View customers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter customer age: ");
                scanf("%d", &age);
                printf("Enter customer gender: ");
                scanf("%s", gender);
                printf("Enter customer phone number: ");
                scanf("%s", phone);

                strcpy(customers[numCustomers].name, name);
                customers[numCustomers].age = age;
                strcpy(customers[numCustomers].gender, gender);
                strcpy(customers[numCustomers].phone, phone);
                numCustomers++;
                break;

            case 2:
                printf("Customer list:\n");
                for(int i=0; i<numCustomers; i++) {
                    printf("%s - %d years old - %s - %s\n", customers[i].name, customers[i].age, customers[i].gender, customers[i].phone);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}