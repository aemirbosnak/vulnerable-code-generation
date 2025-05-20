//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    double amount;
} item_t;

int main() {
    int num_categories, num_items;
    char input_buffer[100];
    item_t items[MAX_ITEMS];
    int i, j;

    // Initialize number of categories and items
    num_categories = 0;
    num_items = 0;

    // Read in categories
    printf("Enter the number of expense categories: ");
    scanf("%d", &num_categories);

    for (i = 0; i < num_categories; i++) {
        printf("Enter category %d: ", i+1);
        scanf("%s", input_buffer);
        strcpy(items[i].category, input_buffer);
    }

    // Read in items
    printf("\nEnter the number of expense items: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("\nEnter item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", items[i].name);

        printf("Category: ");
        scanf("%s", items[i].category);

        printf("Amount: $");
        scanf("%lf", &items[i].amount);
    }

    // Print summary
    printf("\nExpense Summary:\n");
    for (i = 0; i < num_categories; i++) {
        printf("\n%s:\n", items[i].category);
        for (j = 0; j < num_items; j++) {
            if (strcmp(items[j].category, items[i].category) == 0) {
                printf("%s: $%.2f\n", items[j].name, items[j].amount);
            }
        }
    }

    return 0;
}