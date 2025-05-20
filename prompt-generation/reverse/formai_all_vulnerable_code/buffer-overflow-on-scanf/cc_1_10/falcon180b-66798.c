//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_CUSTOMERS 100

typedef struct {
    char name[50];
    char description[100];
    float price;
    int quantity;
} Medicine;

typedef struct {
    char name[50];
    char address[100];
    int phone;
} Customer;

Medicine medicines[MAX_MEDICINES];
Customer customers[MAX_CUSTOMERS];

int num_medicines = 0;
int num_customers = 0;

void add_medicine() {
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[num_medicines].name);

    printf("Enter the description of the medicine: ");
    scanf("%s", medicines[num_medicines].description);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[num_medicines].price);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[num_medicines].quantity);

    num_medicines++;
}

void add_customer() {
    printf("Enter the name of the customer: ");
    scanf("%s", customers[num_customers].name);

    printf("Enter the address of the customer: ");
    scanf("%s", customers[num_customers].address);

    printf("Enter the phone number of the customer: ");
    scanf("%d", &customers[num_customers].phone);

    num_customers++;
}

void display_medicines() {
    printf("Medicines:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s\t%s\t%.2f\t%d\n", medicines[i].name, medicines[i].description, medicines[i].price, medicines[i].quantity);
    }
}

void display_customers() {
    printf("Customers:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s\t%s\t%d\n", customers[i].name, customers[i].address, customers[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add medicine\n");
        printf("2. Add customer\n");
        printf("3. Display medicines\n");
        printf("4. Display customers\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                add_customer();
                break;
            case 3:
                display_medicines();
                break;
            case 4:
                display_customers();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}