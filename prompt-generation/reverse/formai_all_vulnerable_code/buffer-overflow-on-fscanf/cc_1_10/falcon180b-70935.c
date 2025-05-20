//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_SIZE 50
#define MAX_PRICE_SIZE 10

typedef struct {
    char name[MAX_NAME_SIZE];
    char price[MAX_PRICE_SIZE];
} item;

int main() {
    int num_items = 0;
    item items[MAX_ITEMS];
    char input[100];
    char delimiter = ',';

    // Load items from file
    FILE *fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open items file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s,%s", items[num_items].name, items[num_items].price)!= EOF) {
        num_items++;
    }

    fclose(fp);

    printf("Expense Tracker\n");
    printf("-----------------\n");

    // Main loop
    while (1) {
        printf("Enter an expense category:\n");
        scanf("%s", input);

        // Search for item
        int i;
        for (i = 0; i < num_items; i++) {
            if (strcmp(input, items[i].name) == 0) {
                printf("Enter expense amount:\n");
                scanf("%s", items[i].price);
                break;
            }
        }

        // Add new item
        if (i == num_items) {
            printf("Enter expense category:\n");
            scanf("%s", items[num_items].name);
            printf("Enter expense amount:\n");
            scanf("%s", items[num_items].price);
            num_items++;
        }
    }

    return 0;
}