//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100

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
    customers[num_customers].balance = 0;
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
    printf("\nWelcome to the Cafe!\n");
    printf("1. Order\n");
    printf("2. Pay\n");
    printf("3. View Balance\n");
    printf("4. Exit\n");
}

int main() {
    system("clear");
    printf("\nWelcome to the Cafe Billing System!\n");
    printf("Please enter your name and ID to register:\n");
    scanf("%s %d", customers[0].name, &customers[0].id);
    customers[0].balance = 0;
    num_customers = 1;

    while(true) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item ID: ");
                int item_id;
                scanf("%d", &item_id);

                bool found = false;
                for(int i = 0; i < num_items; i++) {
                    if(items[i].id == item_id) {
                        printf("\nYou ordered %s for $%.2f\n", items[i].name, items[i].price);
                        customers[0].balance -= items[i].price;
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    printf("\nItem not found.\n");
                }
                break;

            case 2:
                printf("\nYour current balance is $%.2f\n", customers[0].balance);
                break;

            case 3:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}