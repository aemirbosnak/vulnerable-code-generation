//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000.00

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void remove_item() {
    printf("Enter item name to remove: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            num_items--;
            break;
        }
    }
}

void update_item() {
    printf("Enter item name to update: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            break;
        }
    }
}

void view_items() {
    printf("\nItem Name\tQuantity\tPrice\n");
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add item\n2. Remove item\n3. Update item\n4. View items\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                update_item();
                break;
            case 4:
                view_items();
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again...\n");
        }
    } while (choice!= 5);
    return 0;
}