//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

void read_items(struct item items[]) {
    int i = 0;
    while (i < MAX_ITEMS && scanf("%s %d %f", items[i].name, &items[i].quantity, &items[i].price) == 3) {
        i++;
    }
}

void print_items(struct item items[]) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            printf("%s %d %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int choice, quantity;
    float price;

    read_items(items);

    while (1) {
        printf("1. Add item\n2. Remove item\n3. Update item\n4. Print items\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", items[0].name);
                printf("Enter quantity: ");
                scanf("%d", &items[0].quantity);
                printf("Enter price: ");
                scanf("%f", &items[0].price);
                break;

            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", items[0].name);
                memset(items[0].name, '\0', MAX_NAME_LENGTH);
                items[0].quantity = 0;
                items[0].price = 0;
                break;

            case 3:
                printf("Enter item name to update: ");
                scanf("%s", items[0].name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                items[0].quantity = quantity;

                printf("Enter new price: ");
                scanf("%f", &price);
                items[0].price = price;
                break;

            case 4:
                print_items(items);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}