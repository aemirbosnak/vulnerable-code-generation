//Falcon-180B DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    int count;
} Item;

typedef struct {
    char name[50];
    int count;
} Category;

int main() {
    Item items[MAX_ITEMS];
    Category categories[MAX_CATEGORIES];
    int num_items = 0;
    int num_categories = 0;
    char input[100];
    int choice;

    srand(time(NULL));

    do {
        printf("Enter an item name (or type 'done' to finish):\n");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        for (int i = 0; i < num_items; i++) {
            if (strcmp(items[i].name, input) == 0) {
                items[i].count++;
                break;
            }
        }

        if (num_items >= MAX_ITEMS) {
            printf("Maximum number of items reached.\n");
            continue;
        }

        strcpy(items[num_items].name, input);
        items[num_items].count = 1;
        num_items++;
    } while (1);

    for (int i = 0; i < num_items; i++) {
        printf("%s: %d\n", items[i].name, items[i].count);
    }

    do {
        printf("Enter a category name (or type 'done' to finish):\n");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        for (int i = 0; i < num_categories; i++) {
            if (strcmp(categories[i].name, input) == 0) {
                categories[i].count++;
                break;
            }
        }

        if (num_categories >= MAX_CATEGORIES) {
            printf("Maximum number of categories reached.\n");
            continue;
        }

        strcpy(categories[num_categories].name, input);
        categories[num_categories].count = 1;
        num_categories++;
    } while (1);

    printf("\nItem frequency by category:\n");

    for (int i = 0; i < num_categories; i++) {
        printf("%s: ", categories[i].name);

        for (int j = 0; j < num_items; j++) {
            if (strcmp(items[j].name, categories[i].name) == 0) {
                printf("%s ", items[j].name);
            }
        }

        printf("\n");
    }

    return 0;
}