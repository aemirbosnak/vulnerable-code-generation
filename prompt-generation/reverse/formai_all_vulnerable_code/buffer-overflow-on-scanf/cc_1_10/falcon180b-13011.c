//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int age;
} customer;

typedef struct {
    char name[50];
    int price;
} item;

customer customers[MAX_CUSTOMERS];
item items[MAX_ITEMS];

int num_customers = 0;
int num_items = 0;

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[num_customers].age);
    num_customers++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%d", &items[num_items].price);
    num_items++;
}

void display_menu() {
    printf("1. Add customer\n");
    printf("2. Add item\n");
    printf("3. Display customer details\n");
    printf("4. Display item details\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while(1) {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_customer();
                break;
            case 2:
                add_item();
                break;
            case 3:
                printf("Enter customer name: ");
                scanf("%s", customers[num_customers-1].name);
                printf("Customer name: %s\n", customers[num_customers-1].name);
                printf("Customer age: %d\n", customers[num_customers-1].age);
                break;
            case 4:
                printf("Enter item name: ");
                scanf("%s", items[num_items-1].name);
                printf("Item name: %s\n", items[num_items-1].name);
                printf("Item price: %d\n", items[num_items-1].price);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}