//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_ITEMS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float total;
} Customer;

void print_menu() {
    printf("==================================\n");
    printf("Welcome to the Medical Store Management System\n");
    printf("==================================\n");
    printf("1. Add new item\n");
    printf("2. Update quantity of item\n");
    printf("3. Remove item\n");
    printf("4. Add new customer\n");
    printf("5. Update customer's total\n");
    printf("6. Remove customer\n");
    printf("7. Print all items\n");
    printf("8. Print all customers\n");
    printf("9. Exit\n");
    printf("==================================\n");
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;
    Customer customers[MAX_ITEMS];
    int num_customers = 0;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the item: ");
                char item_name[MAX_NAME_LENGTH];
                scanf("%s", item_name);
                printf("Enter the quantity of the item: ");
                int item_quantity;
                scanf("%d", &item_quantity);
                printf("Enter the price of the item: ");
                float item_price;
                scanf("%f", &item_price);
                Item item = {item_name, item_quantity, item_price};
                items[num_items++] = item;
                break;
            case 2:
                printf("Enter the name of the item: ");
                char item_name_update[MAX_NAME_LENGTH];
                scanf("%s", item_name_update);
                printf("Enter the new quantity of the item: ");
                int item_quantity_update;
                scanf("%d", &item_quantity_update);
                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, item_name_update) == 0) {
                        items[i].quantity = item_quantity_update;
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter the name of the item: ");
                char item_name_remove[MAX_NAME_LENGTH];
                scanf("%s", item_name_remove);
                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, item_name_remove) == 0) {
                        items[i] = items[num_items - 1];
                        num_items--;
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter the name of the customer: ");
                char customer_name[MAX_NAME_LENGTH];
                scanf("%s", customer_name);
                printf("Enter the total of the customer: ");
                float customer_total;
                scanf("%f", &customer_total);
                Customer customer = {customer_name, customer_total};
                customers[num_customers++] = customer;
                break;
            case 5:
                printf("Enter the name of the customer: ");
                char customer_name_update[MAX_NAME_LENGTH];
                scanf("%s", customer_name_update);
                printf("Enter the new total of the customer: ");
                float customer_total_update;
                scanf("%f", &customer_total_update);
                for (int i = 0; i < num_customers; i++) {
                    if (strcmp(customers[i].name, customer_name_update) == 0) {
                        customers[i].total = customer_total_update;
                        break;
                    }
                }
                break;
            case 6:
                printf("Enter the name of the customer: ");
                char customer_name_remove[MAX_NAME_LENGTH];
                scanf("%s", customer_name_remove);
                for (int i = 0; i < num_customers; i++) {
                    if (strcmp(customers[i].name, customer_name_remove) == 0) {
                        customers[i] = customers[num_customers - 1];
                        num_customers--;
                        break;
                    }
                }
                break;
            case 7:
                for (int i = 0; i < num_items; i++) {
                    printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
                }
                break;
            case 8:
                for (int i = 0; i < num_customers; i++) {
                    printf("%s\t%.2f\n", customers[i].name, customers[i].total);
                }
                break;
            case 9:
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    }
}