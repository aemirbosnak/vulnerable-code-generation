//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50
#define MAX_CUSTOMERS 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Customer;

Item inventory[MAX_ITEMS];
Customer customers[MAX_CUSTOMERS];
int num_items = 0, num_customers = 0;

void add_item(char *name, int quantity) {
    if (num_items < MAX_ITEMS) {
        strcpy(inventory[num_items].name, name);
        inventory[num_items].quantity = quantity;
        num_items++;
    } else {
        printf("Inventory is full.\n");
    }
}

void remove_item(char *name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_items--;
            break;
        }
    }
}

void display_inventory() {
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

void add_customer(char *name) {
    if (num_customers < MAX_CUSTOMERS) {
        strcpy(customers[num_customers].name, name);
        customers[num_customers].id = num_customers + 1;
        num_customers++;
    } else {
        printf("Customer list is full.\n");
    }
}

void display_customers() {
    for (int i = 0; i < num_customers; i++) {
        printf("Customer %d: %s\n", customers[i].id, customers[i].name);
    }
}

int main() {
    char name[MAX_NAME_LEN];
    int quantity;
    char command;

    while (1) {
        printf("> ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                scanf("%s%d", name, &quantity);
                add_item(name, quantity);
                break;
            case 'r':
                scanf("%s", name);
                remove_item(name);
                break;
            case 'd':
                display_inventory();
                break;
            case 'A':
                scanf("%s", name);
                add_customer(name);
                break;
            case 'D':
                display_customers();
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}