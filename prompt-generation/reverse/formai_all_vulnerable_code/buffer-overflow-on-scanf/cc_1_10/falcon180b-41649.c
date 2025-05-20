//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 100

typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[15];
} customer;

customer customers[MAX_CUSTOMERS];
int num_customers = 0;

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

void view_customers() {
    printf("Customer ID | Name | Address | Phone\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d | %s | %s | %s\n", customers[i].id, customers[i].name, customers[i].address, customers[i].phone);
    }
}

void search_customer() {
    printf("Enter customer ID to search: ");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].id == id) {
            printf("Customer found:\n");
            printf("ID: %d\n", customers[i].id);
            printf("Name: %s\n", customers[i].name);
            printf("Address: %s\n", customers[i].address);
            printf("Phone: %s\n", customers[i].phone);
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add customer\n");
        printf("2. View customers\n");
        printf("3. Search customer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                view_customers();
                break;
            case 3:
                search_customer();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}