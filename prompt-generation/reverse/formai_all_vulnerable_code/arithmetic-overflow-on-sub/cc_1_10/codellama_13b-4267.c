//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 100
#define MAX_ITEMS 100
#define MAX_ITEM_NAME_LENGTH 20

struct item {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float cost;
};

void read_items(struct item items[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%s %d %f", items[i].name, &items[i].quantity, &items[i].cost);
    }
}

void print_items(struct item items[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d %f\n", items[i].name, items[i].quantity, items[i].cost);
    }
}

void sort_items(struct item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(items[i].name, items[j].name) > 0) {
                struct item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);
    read_items(items, n);
    sort_items(items, n);
    print_items(items, n);
    return 0;
}