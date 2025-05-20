//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_ITEM_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_ITEM_LENGTH];
    float cost;
} item;

typedef struct {
    char name[MAX_CATEGORY_LENGTH];
    int num_items;
    item *items;
} category;

int main() {

    char input[MAX_ITEM_LENGTH];
    category categories[MAX_CATEGORIES];
    int num_categories = 0;
    int current_category = 0;

    printf("Welcome to the Expense Tracker\n");
    printf("Press enter to continue\n");
    getchar();

    while (1) {
        printf("Enter a category name (or type 'done' to finish):\n");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        } else if (num_categories >= MAX_CATEGORIES) {
            printf("Maximum number of categories reached\n");
            continue;
        }

        strcpy(categories[num_categories].name, input);
        categories[num_categories].num_items = 0;
        categories[num_categories].items = (item *) malloc(MAX_ITEMS * sizeof(item));

        num_categories++;
        current_category = num_categories - 1;
    }

    while (1) {
        printf("Enter a category name to add an item to:\n");
        scanf("%s", input);

        for (int i = 0; i < num_categories; i++) {
            if (strcmp(input, categories[i].name) == 0) {
                current_category = i;
                break;
            }
        }

        printf("Enter an item name:\n");
        scanf("%s", input);

        for (int i = 0; i < current_category; i++) {
            if (strcmp(categories[i].name, input) == 0) {
                printf("Category already exists\n");
                break;
            }
        }

        printf("Enter an item cost:\n");
        scanf("%f", &categories[current_category].items[categories[current_category].num_items].cost);

        categories[current_category].num_items++;

        printf("Item added\n");
    }

    printf("Expense tracker complete\n");

    return 0;
}