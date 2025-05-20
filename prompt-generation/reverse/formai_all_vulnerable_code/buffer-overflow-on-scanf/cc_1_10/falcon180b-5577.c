//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[20];
    int id;
} Customer;

typedef struct {
    char name[20];
    double price;
} Item;

Customer customers[MAX_CUSTOMERS];
Item items[MAX_ITEMS];

int num_customers = 0;
int num_items = 0;

void add_customer() {
    char name[20];
    int id;

    printf("Enter customer name: ");
    scanf("%s", name);

    printf("Enter customer ID: ");
    scanf("%d", &id);

    strcpy(customers[num_customers].name, name);
    customers[num_customers].id = id;

    num_customers++;
}

void add_item() {
    char name[20];
    double price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%lf", &price);

    strcpy(items[num_items].name, name);
    items[num_items].price = price;

    num_items++;
}

void display_menu() {
    printf("\n");
    printf("1. Add customer\n");
    printf("2. Add item\n");
    printf("3. Place order\n");
    printf("4. View order history\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    srand(time(NULL));

    int choice;

    do {
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
                // Place order code here
                break;
            case 4:
                // View order history code here
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}