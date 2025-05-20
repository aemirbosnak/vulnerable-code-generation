//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ITEM_LENGTH 20
#define MAX_ITEMS 100

struct Item {
    char name[MAX_ITEM_LENGTH];
    int quantity;
    float price;
};

struct Customer {
    char name[MAX_NAME_LENGTH];
    int num_items;
    struct Item items[MAX_ITEMS];
    float total;
};

void print_items(struct Customer customer) {
    printf("NAME\t  QUANTITY\tPRICE\n");
    for(int i=0; i<customer.num_items; i++) {
        printf("%-10s  %-10d  %.2f\n", customer.items[i].name, customer.items[i].quantity, customer.items[i].price);
    }
}

void calculate_total(struct Customer *customer) {
    float total = 0;
    for(int i=0; i<customer->num_items; i++) {
        total += customer->items[i].price * customer->items[i].quantity;
    }
    customer->total = total;
}

int main() {
    int num_customers;
    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);

    struct Customer *customers = (struct Customer*)malloc(num_customers * sizeof(struct Customer));

    for(int i=0; i<num_customers; i++) {
        printf("\nEnter customer name: ");
        scanf(" %[^\n]s", customers[i].name);
        printf("Enter number of items ordered: ");
        scanf("%d", &customers[i].num_items);

        for(int j=0; j<customers[i].num_items; j++) {
            printf("\nEnter item %d name: ", j+1);
            scanf(" %[^\n]s", customers[i].items[j].name);
            printf("Enter item %d quantity: ", j+1);
            scanf("%d", &customers[i].items[j].quantity);
            printf("Enter item %d price: ", j+1);
            scanf("%f", &customers[i].items[j].price);
        }

        calculate_total(&customers[i]);

        printf("\n\n----------------------------------------------\n");
        printf("\t\t BILLING SYSTEM\n");
        printf("----------------------------------------------\n\n");

        printf("Customer name: %s\n", customers[i].name);
        printf("Number of items ordered: %d\n", customers[i].num_items);
        print_items(customers[i]);
        printf("TOTAL: %.2f\n\n", customers[i].total);
    }

    free(customers);

    return 0;
}