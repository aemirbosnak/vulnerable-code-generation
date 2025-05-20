//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_CUSTOMERS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} customer;

int num_customers = 0;
customer customers[MAX_CUSTOMERS];

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);

    printf("Enter customer address: ");
    scanf("%s", customers[num_customers].address);

    printf("Enter customer phone number: ");
    scanf("%s", customers[num_customers].phone);

    printf("Enter customer email address: ");
    scanf("%s", customers[num_customers].email);

    num_customers++;
}

void view_customer(int index) {
    if (index >= 0 && index < num_customers) {
        printf("Name: %s\n", customers[index].name);
        printf("Address: %s\n", customers[index].address);
        printf("Phone: %s\n", customers[index].phone);
        printf("Email: %s\n\n", customers[index].email);
    } else {
        printf("Invalid customer index.\n");
    }
}

int main() {
    int choice;

    do {
        printf("Customer Database\n");
        printf("1. Add customer\n");
        printf("2. View customer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                printf("Enter customer index: ");
                scanf("%d", &choice);
                view_customer(choice - 1);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}