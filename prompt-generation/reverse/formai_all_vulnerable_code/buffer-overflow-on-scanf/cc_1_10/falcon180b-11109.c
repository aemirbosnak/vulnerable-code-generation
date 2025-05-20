//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 1000

typedef struct {
    char name[50];
    char type[50];
    char manufacturer[50];
    char quantity[10];
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item type: ");
    scanf("%s", items[num_items].type);
    printf("Enter manufacturer: ");
    scanf("%s", items[num_items].manufacturer);
    printf("Enter quantity: ");
    scanf("%s", items[num_items].quantity);
    printf("Enter price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void display_items() {
    printf("Item Name\tType\tManufacturer\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%s\t%s\t%.2f\n", items[i].name, items[i].type, items[i].manufacturer, items[i].quantity, items[i].price);
    }
}

void search_item() {
    char search_name[50];
    printf("Enter item name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, search_name) == 0) {
            printf("Item found:\n");
            printf("Name: %s\n", items[i].name);
            printf("Type: %s\n", items[i].type);
            printf("Manufacturer: %s\n", items[i].manufacturer);
            printf("Quantity: %s\n", items[i].quantity);
            printf("Price: %.2f\n", items[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    printf("Welcome to Medical Store Management System\n");
    while (1) {
        printf("\n1. Add item\n2. Display items\n3. Search item\n4. Exit\n");
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
            printf("Invalid choice.\n");
        }
    }
    return 0;
}