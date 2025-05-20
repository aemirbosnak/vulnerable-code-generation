//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CUSTOMERS 1000

typedef struct item {
    char name[50];
    float price;
    int quantity;
} Item;

typedef struct customer {
    char name[50];
    int age;
    char address[100];
} Customer;

Item items[MAX_ITEMS];
Customer customers[MAX_CUSTOMERS];

int num_items = 0;
int num_customers = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", &items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void display_items() {
    printf("Item Name\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", &customers[num_customers].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[num_customers].age);
    printf("Enter customer address: ");
    scanf("%s", &customers[num_customers].address);
    num_customers++;
}

void display_customers() {
    printf("Customer Name\tAge\tAddress\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s\t%d\t%s\n", customers[i].name, customers[i].age, customers[i].address);
    }
}

void main() {
    int choice;
    while (1) {
        printf("1. Add item\n2. Display items\n3. Add customer\n4. Display customers\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            display_items();
            break;
        case 3:
            add_customer();
            break;
        case 4:
            display_customers();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}