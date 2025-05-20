//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} item_t;

int main() {
    int num_items;
    item_t items[MAX_ITEMS];
    char input[MAX_NAME_LEN + MAX_AMOUNT_LEN + 2]; // +2 for space and null terminator

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    if (num_items > MAX_ITEMS) {
        printf("Error: Too many items!\n");
        return 1;
    }

    printf("Enter the items:\n");

    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i+1);
        scanf("%s", input);

        strncpy(items[i].name, input, MAX_NAME_LEN);
        items[i].name[MAX_NAME_LEN-1] = '\0';

        strncpy(items[i].amount, input+strlen(items[i].name)+1, MAX_AMOUNT_LEN);
        items[i].amount[MAX_AMOUNT_LEN-1] = '\0';
    }

    // Calculate total amount
    double total_amount = 0.0;

    for (int i = 0; i < num_items; i++) {
        total_amount += atof(items[i].amount);
    }

    // Print summary
    printf("\nSummary:\n");
    printf("Total items: %d\n", num_items);
    printf("Total amount: $%.2f\n", total_amount);

    return 0;
}