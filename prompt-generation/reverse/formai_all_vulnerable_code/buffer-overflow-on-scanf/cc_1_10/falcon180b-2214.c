//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50
#define MAX_CATEGORIES 10

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

typedef struct {
    char name[20];
} Category;

Item items[MAX_ITEMS];
Customer customers[MAX_CUSTOMERS];
Category categories[MAX_CATEGORIES];

int num_items = 0, num_customers = 0, num_categories = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter quantity: ");
    scanf("%d", &items[num_items].quantity);
    printf("Enter price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter address: ");
    scanf("%s", customers[num_customers].address);
    printf("Enter phone number: ");
    scanf("%d", &customers[num_customers].phone);
    num_customers++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void display_items() {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s %-10d %-10.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void display_customers() {
    printf("\nCustomer List:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%-20s %-30s %d\n", customers[i].name, customers[i].address, customers[i].phone);
    }
}

void display_categories() {
    printf("\nCategory List:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%-20s\n", categories[i].name);
    }
}

int main() {
    system("clear");
    printf("\n\n");
    printf("Cyberpunk Medical Store Management System\n\n");
    int choice;

    do {
        printf("\n1. Add item\n");
        printf("2. Add customer\n");
        printf("3. Add category\n");
        printf("4. Display items\n");
        printf("5. Display customers\n");
        printf("6. Display categories\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_customer();
                break;
            case 3:
                add_category();
                break;
            case 4:
                display_items();
                break;
            case 5:
                display_customers();
                break;
            case 6:
                display_categories();
                break;
            case 7:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice!= 7);

    return 0;
}