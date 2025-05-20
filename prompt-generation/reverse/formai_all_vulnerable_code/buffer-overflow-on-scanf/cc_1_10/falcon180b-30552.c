//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_QUANTITY_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char category[MAX_CATEGORY_LEN];
    char quantity[MAX_QUANTITY_LEN];
    char price[MAX_PRICE_LEN];
} item;

item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);

    printf("Enter the description of the item: ");
    scanf("%s", items[num_items].description);

    printf("Enter the category of the item: ");
    scanf("%s", items[num_items].category);

    printf("Enter the quantity of the item: ");
    scanf("%s", items[num_items].quantity);

    printf("Enter the price of the item: ");
    scanf("%s", items[num_items].price);

    num_items++;
}

void display_items() {
    printf("Name\tDescription\tCategory\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n", items[i].name, items[i].description, items[i].category, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;

    printf("Welcome to the Medical Store Management System\n");

    do {
        printf("\n1. Add an item\n2. Display items\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}