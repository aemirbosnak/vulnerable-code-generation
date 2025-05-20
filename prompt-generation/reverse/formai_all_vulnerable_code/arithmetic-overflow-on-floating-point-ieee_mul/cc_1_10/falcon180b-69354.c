//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} item_t;

void read_items(item_t items[], int *num_items) {
    char input[1024];
    int i = 0;

    printf("Enter items (name price quantity):\n");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        strcpy(items[i].name, token);
        token = strtok(NULL, " ");
        items[i].price = atof(token);
        token = strtok(NULL, " ");
        items[i].quantity = atoi(token);
        i++;

        if (i >= MAX_ITEMS) {
            printf("Error: Too many items!\n");
            exit(1);
        }

        token = strtok(NULL, " ");
    }

    *num_items = i;
}

void print_items(item_t items[], int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s $%.2f x %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

float calculate_total(item_t items[], int num_items) {
    float total = 0.0;

    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }

    return total;
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    read_items(items, &num_items);
    print_items(items, num_items);

    float total = calculate_total(items, num_items);
    printf("Total: $%.2f\n", total);

    return 0;
}