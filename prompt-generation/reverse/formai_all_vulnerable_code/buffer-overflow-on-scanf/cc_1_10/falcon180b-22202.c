//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    double price;
    int quantity;
};

struct Customer {
    int id;
    char name[50];
    int age;
    char address[100];
};

void createItem(struct Item* items, int* count) {
    int choice;

    printf("Enter 1 to create a new item\n");
    printf("Enter 0 to go back\n");
    scanf("%d", &choice);

    if (choice == 1) {
        if (*count >= MAX_ITEMS) {
            printf("Maximum items limit reached!\n");
            return;
        }

        printf("Enter item ID: ");
        scanf("%d", &items[*count].id);

        printf("Enter item name: ");
        scanf("%s", items[*count].name);

        printf("Enter item price: ");
        scanf("%lf", &items[*count].price);

        printf("Enter item quantity: ");
        scanf("%d", &items[*count].quantity);

        (*count)++;
    }
}

void displayItems(struct Item items[], int count) {
    printf("ID\tName\tPrice\tQuantity\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2lf\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }
}

void main() {
    struct Item items[MAX_ITEMS];
    int count = 0;

    while (1) {
        printf("\n1. Create item\n");
        printf("2. Display items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createItem(items, &count);
                break;

            case 2:
                displayItems(items, count);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}