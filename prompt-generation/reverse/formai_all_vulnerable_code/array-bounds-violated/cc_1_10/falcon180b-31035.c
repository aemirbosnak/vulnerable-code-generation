//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 100
#define MAX_ITEMS 1000

struct category {
    char name[50];
    int count;
};

struct item {
    char name[50];
    double price;
    int category;
};

int main() {
    int num_categories, num_items, i, j;
    char input[100];
    struct category categories[MAX_CATEGORIES];
    struct item items[MAX_ITEMS];

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].count = 0;
    }

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter the price of item %d: ", i + 1);
        scanf("%lf", &items[i].price);
        printf("Enter the category of item %d: ", i + 1);
        scanf("%d", &items[i].category);
        categories[items[i].category - 1].count++;
    }

    printf("\nExpense Tracker\n");
    printf("Category\tCount\tTotal Expense\n");

    for (i = 0; i < num_categories; i++) {
        printf("%s\t", categories[i].name);
        for (j = 0; j < num_items; j++) {
            if (items[j].category == i + 1) {
                printf("%s\t%.2lf\t", items[j].name, items[j].price);
                categories[i].count++;
            }
        }
        printf("\n");
    }

    printf("\nTotal Expense by Category:\n");
    for (i = 0; i < num_categories; i++) {
        printf("%s\t%.2lf\n", categories[i].name, categories[i].count * 100.0);
    }

    return 0;
}