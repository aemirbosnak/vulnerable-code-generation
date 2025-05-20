//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int code;
    char name[50];
    int quantity;
    float cost;
};

typedef struct Item Item;

void read_item(Item * item) {
    printf("Enter item code: ");
    scanf("%d", &item->code);
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter item cost: ");
    scanf("%f", &item->cost);
}

void print_item(Item * item) {
    printf("%d\t%s\t%d\t%.2lf\n", item->code, item->name, item->quantity, item->cost);
}

int main() {
    int max_items;
    printf("Enter maximum number of items: ");
    scanf("%d", &max_items);

    Item * items = (Item *) malloc(max_items * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    int num_items = 0;
    char command[10];
    while (1) {
        printf("Enter command (add, remove, print, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (num_items == max_items) {
                printf("Maximum number of items reached\n");
            } else {
                Item * item = &items[num_items];
                read_item(item);
                num_items++;
            }
        } else if (strcmp(command, "remove") == 0) {
            int code;
            printf("Enter code of item to remove: ");
            scanf("%d", &code);

            int index = -1;
            for (int i = 0; i < num_items; i++) {
                if (items[i].code == code) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                printf("Item not found\n");
            } else {
                for (int i = index; i < num_items - 1; i++) {
                    items[i] = items[i + 1];
                }
                num_items--;
                printf("Item removed\n");
            }
        } else if (strcmp(command, "print") == 0) {
            printf("Code\tName\tQuantity\tCost\n");
            for (int i = 0; i < num_items; i++) {
                print_item(&items[i]);
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    free(items);
    return 0;
}