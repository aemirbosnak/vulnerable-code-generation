//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define PRICE_PER_HR 100

typedef struct {
    char item_name[20];
    int qty;
    float price;
} Item;

typedef struct {
    int table_num;
    char customer_name[20];
    int num_items;
    Item items[MAX_ITEMS];
    float total_amount;
} Bill;

int main() {
    int num_tables, choice, i, j, table_num, num_items, item_index;
    char customer_name[20];
    float total_amount;
    Bill *bills;
    
    printf("Enter the number of tables in the cafe: ");
    scanf("%d", &num_tables);
    
    bills = (Bill*)malloc(num_tables * sizeof(Bill));
    if (bills == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    while (1) {
        printf("1. New order\n");
        printf("2. View order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter table number: ");
            scanf("%d", &table_num);
            if (table_num <= 0 || table_num > num_tables) {
                printf("Invalid table number!\n");
                continue;
            }
            printf("Enter customer name: ");
            scanf("%s", customer_name);
            printf("Enter number of items: ");
            scanf("%d", &num_items);
            if (num_items <= 0 || num_items > MAX_ITEMS) {
                printf("Invalid number of items!\n");
                continue;
            }
            for (i = 0; i < num_items; i++) {
                printf("Enter item name: ");
                scanf("%s", bills[table_num-1].items[i].item_name);
                printf("Enter quantity: ");
                scanf("%d", &bills[table_num-1].items[i].qty);
                bills[table_num-1].items[i].price = PRICE_PER_HR;
            }
            bills[table_num-1].table_num = table_num;
            strcpy(bills[table_num-1].customer_name, customer_name);
            bills[table_num-1].num_items = num_items;
            bills[table_num-1].total_amount = PRICE_PER_HR * num_items;
            printf("Order placed successfully!\n");
        }
        else if (choice == 2) {
            printf("Enter table number: ");
            scanf("%d", &table_num);
            if (table_num <= 0 || table_num > num_tables) {
                printf("Invalid table number!\n");
                continue;
            }
            printf("Table %d - Customer: %s\n", table_num, bills[table_num-1].customer_name);
            printf("Items\n-----\n");
            total_amount = 0;
            for (i = 0; i < bills[table_num-1].num_items; i++) {
                printf("%d - %s - %.2f\n", bills[table_num-1].items[i].qty, bills[table_num-1].items[i].item_name, bills[table_num-1].items[i].price);
                total_amount += bills[table_num-1].items[i].qty * bills[table_num-1].items[i].price;
            }
            printf("-----\n");
            printf("Total amount: %.2f\n", total_amount);
        }
        else {
            break;
        }
    }
    
    free(bills);
    return 0;
}