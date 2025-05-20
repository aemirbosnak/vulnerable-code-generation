//FormAI DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct product {
    int id;
    char name[50];
    int price;
    int quantity;
};

struct inventory {
    struct product items[MAX_ITEMS];
    int num_items;
};

void add_item(struct inventory *inv, struct product p) {
    if (inv->num_items < MAX_ITEMS) {
        inv->items[inv->num_items] = p;
        inv->num_items++;
        printf("%s added to inventory.\n",p.name);
    }
    else {
        printf("Inventory is full.\n");
    }
}

void remove_item(struct inventory *inv, int id) {
    int i,j;
    for (i = 0; i < inv->num_items; i++) {
        if (inv->items[i].id == id) {
            printf("%s removed from inventory.\n",inv->items[i].name);
            for (j = i; j < inv->num_items-1; j++) {
                inv->items[j] = inv->items[j + 1];
            }
            inv->num_items--;
            return;
        }
    }
    printf("Item not found.\n");
}

void print_inventory(struct inventory *inv) {
    if (inv->num_items == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    int i;
    printf("ID\tName\tPrice\tQuantity\n");
    for (i = 0; i < inv->num_items; i++) {
        printf("%d\t%s\t$%d\t%d\n",inv->items[i].id,inv->items[i].name,inv->items[i].price,inv->items[i].quantity);
    }
}

int main() {
    struct inventory inv;
    inv.num_items = 0;
    char command[50];
    while(1) {
        printf("Enter a command: ");
        scanf("%s",command);
        if (strcmp(command,"add") == 0) {
            struct product p;
            printf("Enter product ID: ");
            scanf("%d",&p.id);
            printf("Enter product name: ");
            scanf("%s",p.name);
            printf("Enter product price: ");
            scanf("%d",&p.price);
            printf("Enter product quantity: ");
            scanf("%d",&p.quantity);
            add_item(&inv,p);
        }
        else if (strcmp(command,"remove") == 0) {
            int id;
            printf("Enter product ID: ");
            scanf("%d",&id);
            remove_item(&inv,id);
        }
        else if (strcmp(command,"print") == 0) {
            print_inventory(&inv);
        }
        else if (strcmp(command,"exit") == 0) {
            printf("Exiting program.\n");
            exit(0);
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}