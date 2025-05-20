//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    char address[100];
    int phone;
} Customer;

int num_items = 0;
Item items[MAX_ITEMS];

int num_customers = 0;
Customer customers[MAX_CUSTOMERS];

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    num_items++;
}

void view_items() {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, items[i].name, items[i].quantity, items[i].price);
    }
}

void add_customer() {
    printf("\nEnter customer name: ");
    scanf("%s", customers[num_customers].name);

    printf("Enter customer address: ");
    scanf("%s", customers[num_customers].address);

    printf("Enter customer phone number: ");
    scanf("%d", &customers[num_customers].phone);

    num_customers++;
}

void view_customers() {
    printf("\nCustomer List:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d. %s (%s) - %d\n", i+1, customers[i].name, customers[i].address, customers[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("\n\nWelcome to the Medical Store Management System!\n");
        printf("1. Add item\n2. View item list\n3. Add customer\n4. View customer list\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                add_customer();
                break;
            case 4:
                view_customers();
                break;
            case 5:
                printf("\nThank you for using our system! Have a great day!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}