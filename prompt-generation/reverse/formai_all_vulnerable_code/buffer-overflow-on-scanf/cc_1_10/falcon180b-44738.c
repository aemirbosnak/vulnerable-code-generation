//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 1000

typedef struct {
    char name[50];
    int id;
    float balance;
} Customer;

typedef struct {
    char name[50];
    int id;
    float price;
} Item;

Customer customers[MAX_CUSTOMERS];
Item items[MAX_ITEMS];

int num_customers = 0;
int num_items = 0;

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer ID: ");
    scanf("%d", &customers[num_customers].id);
    customers[num_customers].balance = 0.0;
    num_customers++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item ID: ");
    scanf("%d", &items[num_items].id);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void display_menu() {
    printf("\n");
    printf("1. Add customer\n");
    printf("2. Add item\n");
    printf("3. View customer balance\n");
    printf("4. View item details\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    int choice;

    system("clear");

    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_customer();
                break;
            case 2:
                add_item();
                break;
            case 3:
                printf("Enter customer ID: ");
                scanf("%d", &choice);
                for(int i=0; i<num_customers; i++) {
                    if(customers[i].id == choice) {
                        printf("Customer balance: %.2f\n", customers[i].balance);
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter item ID: ");
                scanf("%d", &choice);
                for(int i=0; i<num_items; i++) {
                    if(items[i].id == choice) {
                        printf("Item name: %s\n", items[i].name);
                        printf("Item ID: %d\n", items[i].id);
                        printf("Item price: %.2f\n", items[i].price);
                        break;
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}