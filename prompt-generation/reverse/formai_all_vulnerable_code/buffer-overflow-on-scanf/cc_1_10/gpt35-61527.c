//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct customer {
    int id;
    char name[50];
    int age;
    char sex[10];
    char phone[20];
};

void addCustomer(struct customer* arr, int n) {
    printf("Enter customer ID: ");
    scanf("%d", &arr[n].id);
    printf("Enter customer name: ");
    scanf("%s", arr[n].name);
    printf("Enter customer age: ");
    scanf("%d", &arr[n].age);
    printf("Enter customer sex: ");
    scanf("%s", arr[n].sex);
    printf("Enter customer phone number: ");
    scanf("%s", arr[n].phone);
    printf("Customer added successfully!\n");
}

void displayCustomer(struct customer* arr, int n) {
    printf("Customer ID: %d\n", arr[n].id);
    printf("Name: %s\n", arr[n].name);
    printf("Age: %d\n", arr[n].age);
    printf("Sex: %s\n", arr[n].sex);
    printf("Phone: %s\n", arr[n].phone);
}

int main() {
    struct customer customers[5];
    int choice, n = 0;
    do {
        printf("Enter your choice:\n");
        printf("1. Add a customer\n");
        printf("2. Display customer details\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (n < 5) {
                    addCustomer(customers, n);
                    n++;
                } else {
                    printf("Maximum number of customers reached!\n");
                }
                break;
            case 2:
                if (n > 0) {
                    printf("Enter customer ID: ");
                    int id;
                    scanf("%d", &id);
                    int i, found = 0;
                    for (i = 0; i < n; i++) {
                        if (customers[i].id == id) {
                            displayCustomer(customers, i);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Customer not found!\n");
                    }
                } else {
                    printf("No customers to display!\n");
                }
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}