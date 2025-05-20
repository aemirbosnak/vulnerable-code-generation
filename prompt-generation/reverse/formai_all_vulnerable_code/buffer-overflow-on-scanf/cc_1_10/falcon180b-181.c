//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_CUSTOMERS 100

typedef struct {
    char name[100];
    int age;
    int customer_id;
} Customer;

typedef struct {
    char name[100];
    float price;
    int item_id;
} Item;

typedef struct {
    char name[100];
    int balance;
    int customer_id;
} Account;

void add_customer(Customer customers[], int *num_customers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*num_customers].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[*num_customers].age);
    customers[*num_customers].customer_id = *num_customers;
    (*num_customers)++;
}

void add_item(Item items[], int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    items[*num_items].item_id = *num_items;
    (*num_items)++;
}

void add_account(Account accounts[], int *num_accounts) {
    printf("Enter account name: ");
    scanf("%s", accounts[*num_accounts].name);
    printf("Enter account balance: ");
    scanf("%d", &accounts[*num_accounts].balance);
    accounts[*num_accounts].customer_id = -1;
    (*num_accounts)++;
}

void display_menu(void) {
    printf("\n");
    printf("1. Add customer\n");
    printf("2. Add item\n");
    printf("3. Add account\n");
    printf("4. Place order\n");
    printf("5. View order history\n");
    printf("6. Exit\n");
    printf("\n");
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    Item items[MAX_ITEMS];
    int num_items = 0;

    Account accounts[MAX_CUSTOMERS];
    int num_accounts = 0;

    int choice, customer_id, item_id, account_id;

    while(1) {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_customer(customers, &num_customers);
                break;

            case 2:
                add_item(items, &num_items);
                break;

            case 3:
                add_account(accounts, &num_accounts);
                break;

            case 4:
                printf("Enter customer ID: ");
                scanf("%d", &customer_id);

                printf("Enter item ID: ");
                scanf("%d", &item_id);

                printf("Order placed successfully!\n");
                break;

            case 5:
                printf("Enter customer ID: ");
                scanf("%d", &customer_id);

                for(int i=0; i<num_accounts; i++) {
                    if(accounts[i].customer_id == customer_id) {
                        printf("Customer name: %s\n", accounts[i].name);
                        printf("Account balance: %d\n", accounts[i].balance);
                        break;
                    }
                }

                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}