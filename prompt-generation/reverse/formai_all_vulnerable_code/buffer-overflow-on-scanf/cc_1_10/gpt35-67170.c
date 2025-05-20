//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int stock;
} item;

int n_items = 0;

item items[MAX_ITEMS];

int is_password_correct(char* input) {
    char* password = "9Lkefv6cK22VJguE3Jm7"; // password to access the program
    return strcmp(input, password) == 0;
}

void print_items() {
    printf("\nItems in stock:\n");
    printf("Name\tPrice\tStock\n");
    for (int i = 0; i < n_items; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].stock);
    }
    printf("\n");
}

void add_item() {
    char name[MAX_NAME_LENGTH];
    printf("\nEnter the name of the item: ");
    scanf("%s", name);
    for (int i = 0; i < n_items; i++) {
        if (strcmp(name, items[i].name) == 0) {
            printf("\nERROR: Item already exists.\n");
            return;
        }
    }
    float price;
    printf("Enter the price of the item: ");
    scanf("%f", &price);
    int stock;
    printf("Enter the stock of the item: ");
    scanf("%d", &stock);
    if (n_items >= MAX_ITEMS) {
        printf("\nERROR: Maximum number of items reached.\n");
        return;
    }
    item new_item = {
        .price = price,
        .stock = stock
    };
    strcpy(new_item.name, name);
    items[n_items++] = new_item;
    printf("\nItem added successfully.\n");
}

void sell_item() {
    char name[MAX_NAME_LENGTH];
    printf("\nEnter the name of the item to be sold: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < n_items; i++) {
        if (strcmp(name, items[i].name) == 0) {
            found = 1;
            if (items[i].stock > 0) {
                items[i].stock--;
                printf("\nItem sold successfully.");
            } else {
                printf("\nERROR: Item out of stock.");
            }
            break;
        }
    }
    if (!found) {
        printf("\nERROR: Item not found.");
    }
}

void process_command(char* command) {
    if (strcmp(command, "list") == 0) {
        print_items();
    } else if (strcmp(command, "add") == 0) {
        add_item();
    } else if (strcmp(command, "sell") == 0) {
        sell_item();
    } else {
        printf("\nERROR: Invalid command.\n");
    }
}

int main()
{
    char command[MAX_NAME_LENGTH];
    printf("Enter password: ");
    scanf("%s", command);
    if (is_password_correct(command)) {
        printf("\nAccess granted.\n");
        while (1) {
            printf("\nEnter a command (list/add/sell/quit): ");
            scanf("%s", command);
            if (strcmp(command, "quit") == 0) {
                break;
            }
            process_command(command);
        }
    } else {
        printf("\nAccess denied.\n");
    }
    return 0;
}