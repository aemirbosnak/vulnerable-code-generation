//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];

int num_items = 0;

void add_item(char name[], float price, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Maximum number of items exceeded.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].quantity = quantity;

    num_items++;

    printf("%s added to inventory.\n", name);
}

void list_items() {
    printf("------------------------\n");
    printf("|%18s|%10s|\n", "Name", "Price");
    printf("------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("|%18s|$%.2f |\n", items[i].name, items[i].price);
    }

    printf("------------------------\n");
}

int main() {
    char input[50];

    while (1) {
        printf("\nCommand: ");
        fgets(input, 50, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        } else if (strcmp(input, "list\n") == 0) {
            list_items();
        } else if (strncmp(input, "add ", 4) == 0) {
            char name[50];
            float price;
            int quantity;

            sscanf(input, "add %s %f %d", name, &price, &quantity);

            add_item(name, price, quantity);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}