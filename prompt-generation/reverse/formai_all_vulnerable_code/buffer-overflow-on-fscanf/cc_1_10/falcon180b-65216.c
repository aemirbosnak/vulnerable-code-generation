//Falcon-180B DATASET v1.0 Category: Data mining ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_CATEGORY_LENGTH];
    int count;
} Category;

typedef struct {
    char name[MAX_CATEGORY_LENGTH];
    int quantity;
    int price;
} Item;

int main() {
    int numItems, numCategories;
    Category categories[MAX_CATEGORIES];
    Item items[MAX_ITEMS];
    char filename[100];
    FILE *fp;

    printf("Enter the name of the data file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fscanf(fp, "%d", &numItems);
    fscanf(fp, "%d", &numCategories);

    for (int i = 0; i < numCategories; i++) {
        fscanf(fp, "%s", categories[i].name);
    }

    for (int i = 0; i < numItems; i++) {
        fscanf(fp, "%s", items[i].name);
        fscanf(fp, "%d", &items[i].quantity);
        fscanf(fp, "%d", &items[i].price);

        for (int j = 0; j < numCategories; j++) {
            if (strcmp(items[i].name, categories[j].name) == 0) {
                categories[j].count++;
                break;
            }
        }
    }

    fclose(fp);

    for (int i = 0; i < numCategories; i++) {
        printf("%s: %d items\n", categories[i].name, categories[i].count);
    }

    return 0;
}