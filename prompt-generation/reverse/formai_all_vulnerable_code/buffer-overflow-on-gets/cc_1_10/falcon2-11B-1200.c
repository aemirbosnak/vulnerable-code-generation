//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    char address[100];
    float balance;
};

struct customer customers[10];
int customer_count = 0;

struct medicine {
    char name[50];
    char description[100];
    float price;
    int quantity;
};

struct medicine medicines[10];
int medicine_count = 0;

int main() {
    int choice = 0;
    int index = 0;
    int count = 0;

    while (choice!= 4) {
        printf("\nMedical Store Management System\n");
        printf("1. Add a new customer\n");
        printf("2. View all customers\n");
        printf("3. Add a new medicine\n");
        printf("4. View all medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer details:\n");
                gets(customers[index].name);
                gets(customers[index].address);
                printf("Customer balance: ");
                scanf("%f", &customers[index].balance);
                customer_count++;
                index++;
                break;

            case 2:
                printf("View all customers:\n");
                for (int i = 0; i < customer_count; i++) {
                    printf("Customer %d: %s - %s\n", i + 1, customers[i].name, customers[i].address);
                }
                break;

            case 3:
                printf("Enter medicine details:\n");
                gets(medicines[index].name);
                gets(medicines[index].description);
                printf("Medicine price: ");
                scanf("%f", &medicines[index].price);
                printf("Medicine quantity: ");
                scanf("%d", &medicines[index].quantity);
                medicine_count++;
                index++;
                break;

            case 4:
                printf("View all medicines:\n");
                for (int i = 0; i < medicine_count; i++) {
                    printf("Medicine %d: %s - %s - %f\n", i + 1, medicines[i].name, medicines[i].description, medicines[i].price);
                }
                break;

            case 5:
                printf("Exiting the program...\n");
                exit(0);
                break;
        }
    }

    return 0;
}