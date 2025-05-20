//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CUSTOMERS 1000

typedef struct {
    char name[50];
    char address[100];
    int phone;
} customer;

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

customer customers[MAX_CUSTOMERS];
item items[MAX_ITEMS];

int num_customers = 0;
int num_items = 0;

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer address: ");
    scanf("%s", customers[num_customers].address);
    printf("Enter customer phone number: ");
    scanf("%d", &customers[num_customers].phone);
    num_customers++;
}

void view_customers() {
    printf("\nCustomer list:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d. %s %s %d\n", i+1, customers[i].name, customers[i].address, customers[i].phone);
    }
}

void add_item() {
    printf("\nEnter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void view_items() {
    printf("\nItem list:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s %.2f %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void main() {
    int choice;
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add customer\n");
        printf("2. View customer list\n");
        printf("3. Add item\n");
        printf("4. View item list\n");
        printf("5. Exit\n");
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
                add_item();
                break;
            case 4:
                view_items();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}