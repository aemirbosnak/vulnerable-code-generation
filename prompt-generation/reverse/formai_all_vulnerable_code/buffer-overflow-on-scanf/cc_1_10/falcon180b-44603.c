//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct item {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
};

struct item items[MAX_ITEMS];
int num_items;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item price: ");
    scanf("%s", items[num_items].price);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    num_items++;
}

void view_items() {
    printf("Item Name\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void update_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items-1].name);

    printf("Enter item price: ");
    scanf("%s", items[num_items-1].price);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items-1].quantity);
}

void delete_item() {
    printf("Enter item name: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < num_items-1; j++) {
                strcpy(items[j].name, items[j+1].name);
                strcpy(items[j].price, items[j+1].price);
                items[j].quantity = items[j+1].quantity;
            }
            num_items--;
            break;
        }
    }
}

int main() {
    num_items = 0;

    while (1) {
        printf("1. Add item\n2. View items\n3. Update item\n4. Delete item\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                update_item();
                break;
            case 4:
                delete_item();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}