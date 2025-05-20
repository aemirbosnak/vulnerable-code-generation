//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Sorry, cannot add more items.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item price: ");
    scanf("%s", items[num_items].price);

    num_items++;
}

void display_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%s\n", i+1, items[i].name, items[i].price);
    }
}

void calculate_total() {
    double total = 0.0;

    printf("Select items to order:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%s\n", i+1, items[i].name, items[i].price);
    }

    char input[MAX_NAME_LEN];
    scanf("%s", input);

    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(input, items[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Invalid selection.\n");
        return;
    }

    printf("Total: $%.2f\n", items[index].price);
}

int main() {
    printf("Welcome to the Cafe Billing System!\n");

    while (1) {
        printf("1. Add item\n2. Display items\n3. Calculate total\n4. Exit\n");
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
                calculate_total();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}