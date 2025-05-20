//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ITEM_COUNT 10 // number of items in menu
#define NAME_SIZE 20 // max length of item name
#define TABLE_COUNT 5 // number of tables

typedef struct {
    char name[NAME_SIZE];
    int price;
} menu_item;

menu_item menu[ITEM_COUNT] = {{"Espresso", 150},
                                {"Latte", 200},
                                {"Cappuccino", 180},
                                {"Mocha", 220},
                                {"American", 100},
                                {"Hot Chocolate", 150},
                                {"Iced Tea", 120},
                                {"Fruit Smoothie", 180},
                                {"Croissant", 80},
                                {"Bagel", 100}};

int table_orders[TABLE_COUNT][ITEM_COUNT + 1]; // holds orders for each table

void print_menu() {
    printf("Menu:\n");
    printf("%-20s  %-10s\n", "Item", "Price (Rs)");
    for (int i = 0; i < ITEM_COUNT; i++) {
        printf("%-20s  %-10d\n", menu[i].name, menu[i].price);
    }
}

void print_orders() {
    for (int i = 0; i < TABLE_COUNT; i++) {
        printf("Table %d:\n", i+1);
        for (int j = 0; j < ITEM_COUNT + 1; j++) {
            if (table_orders[i][j] > 0) {
                if (j == ITEM_COUNT) {
                    printf("Total: %d\n", table_orders[i][j]);
                } else {
                    printf("%-20s  %d\n", menu[j].name, table_orders[i][j]);
                }
            }
        }
    }
}

void take_order(int table_number) {
    char item_name[NAME_SIZE];
    printf("Table %d Order:\n", table_number);
    print_menu();
    printf("Enter item name: ");
    scanf("%s", item_name);
    for (int i = 0; i < ITEM_COUNT; i++) {
        if (strcmp(menu[i].name, item_name) == 0) {
            int quantity;
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            table_orders[table_number-1][i] += quantity;
            printf("%d %s(s) added to table %d order\n", quantity, item_name, table_number);
            return;
        }
    }
    printf("Invalid item name\n");
}

void calculate_bill(int table_number) {
    int total = 0;
    printf("Table %d Bill:\n", table_number);
    for (int i = 0; i < ITEM_COUNT; i++) {
        if (table_orders[table_number-1][i] > 0) {
            total += table_orders[table_number-1][i] * menu[i].price;
            printf("%-20s  %d x %d = %d\n", menu[i].name, menu[i].price, 
                table_orders[table_number-1][i], menu[i].price * table_orders[table_number-1][i]);
        }
    }
    printf("Total: %d\n", total);
    table_orders[table_number-1][ITEM_COUNT] = total; // save the total for later use
}

int main() {
    int choice, table_number;
    while (1) {
        printf("\n************\nCAFE MANAGEMENT SYSTEM\n************\n");
        printf("1 - Take Order\n");
        printf("2 - Calculate Bill\n");
        printf("3 - View Orders\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter table number: ");
                scanf("%d", &table_number);
                if (table_number > TABLE_COUNT || table_number < 1) {
                    printf("Invalid table number\n");
                    break;
                }
                take_order(table_number);
                break;
            case 2:
                printf("Enter table number: ");
                scanf("%d", &table_number);
                if (table_number > TABLE_COUNT || table_number < 1) {
                    printf("Invalid table number\n");
                    break;
                }
                calculate_bill(table_number);
                break;
            case 3:
                print_orders();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}