//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QTY 1000
#define MAX_PRICE 100000

struct item {
    char name[MAX_NAME_LEN];
    int qty;
    float price;
};

struct item items[MAX_ITEMS];
int num_items;

void add_item() {
    printf("Enter item name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", items[num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].qty);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void display_items() {
    printf("\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].qty, items[i].price);
    }
}

void search_item() {
    char search_name[MAX_NAME_LEN];
    printf("Enter item name to search: ");
    scanf("%s", search_name);
    tolower(search_name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, search_name) == 0) {
            printf("\nItem found:\n");
            printf("Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].qty);
            printf("Price: $.%02f\n", items[i].price);
        }
    }
}

int main() {
    printf("Welcome to the Medical Store Management System!\n");
    printf("---------------------------------------------\n");
    num_items = 0;
    while (1) {
        printf("\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Search item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            display_items();
            break;
        case 3:
            search_item();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}