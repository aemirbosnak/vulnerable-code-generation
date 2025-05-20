//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int quantity;
    float price;
} item;

typedef struct {
    char name[50];
    int num_items;
} category;

typedef struct {
    char name[50];
    char address[100];
    int customer_id;
} customer;

item items[MAX_ITEMS];
category categories[MAX_CATEGORIES];
customer customers[MAX_CUSTOMERS];

int num_items = 0;
int num_categories = 0;
int num_customers = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter quantity: ");
    scanf("%d", &items[num_items].quantity);
    printf("Enter price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter address: ");
    scanf("%s", customers[num_customers].address);
    customers[num_customers].customer_id = num_customers + 1;
    num_customers++;
}

void display_items() {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %d units - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void display_categories() {
    printf("\nCategory List:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void display_customers() {
    printf("\nCustomer List:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s - %s - Customer ID: %d\n", customers[i].name, customers[i].address, customers[i].customer_id);
    }
}

int main() {
    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add item\n");
        printf("2. Add category\n");
        printf("3. Add customer\n");
        printf("4. Display items\n");
        printf("5. Display categories\n");
        printf("6. Display customers\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_category();
                break;
            case 3:
                add_customer();
                break;
            case 4:
                display_items();
                break;
            case 5:
                display_categories();
                break;
            case 6:
                display_customers();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 7);

    return 0;
}