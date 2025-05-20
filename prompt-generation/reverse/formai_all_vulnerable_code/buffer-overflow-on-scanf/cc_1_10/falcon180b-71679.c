//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[100];
    int quantity;
    double price;
};

struct item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    num_items++;
    printf("Enter item name: ");
    scanf("%s", items[num_items-1].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items-1].quantity);
    printf("Enter item price: ");
    scanf("%lf", &items[num_items-1].price);
}

void display_items() {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2lf\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Add Item\n2. Display Items\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
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
    }
    return 0;
}