//Falcon-180B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 10
#define MAX_VALUE 1000

// Define a struct to represent an item
typedef struct {
    char name[50];
    int category;
    int value;
} Item;

// Define a struct to represent a category
typedef struct {
    char name[50];
    int count;
} Category;

// Function to compare two items based on their value
int compareItems(const void *a, const void *b) {
    const Item *itemA = a;
    const Item *itemB = b;
    return itemB->value - itemA->value;
}

// Function to compare two categories based on their count
int compareCategories(const void *a, const void *b) {
    const Category *categoryA = a;
    const Category *categoryB = b;
    return categoryB->count - categoryA->count;
}

// Function to read items from a file
void readItems(Item items[], int numItems, FILE *file) {
    for (int i = 0; i < numItems; i++) {
        fscanf(file, "%s %d %d", items[i].name, &items[i].category, &items[i].value);
    }
}

// Function to read categories from a file
void readCategories(Category categories[], int numCategories, FILE *file) {
    for (int i = 0; i < numCategories; i++) {
        fscanf(file, "%s %d", categories[i].name, &categories[i].count);
    }
}

// Function to write categories to a file
void writeCategories(Category categories[], int numCategories, FILE *file) {
    for (int i = 0; i < numCategories; i++) {
        fprintf(file, "%s %d\n", categories[i].name, categories[i].count);
    }
}

// Function to find the k most popular categories
void findPopularCategories(Item items[], int numItems, Category categories[], int numCategories, int k) {
    for (int i = 0; i < numItems; i++) {
        int categoryIndex = items[i].category - 1;
        categories[categoryIndex].count++;
    }
    qsort(categories, numCategories, sizeof(Category), compareCategories);
    for (int i = 0; i < k && i < numCategories; i++) {
        printf("%s: %d\n", categories[i].name, categories[i].count);
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    int numItems;
    fscanf(inputFile, "%d", &numItems);
    Item items[MAX_ITEMS];
    readItems(items, numItems, inputFile);

    int numCategories;
    fscanf(inputFile, "%d", &numCategories);
    Category categories[MAX_CATEGORIES];
    readCategories(categories, numCategories, inputFile);

    fclose(inputFile);

    printf("Top 5 most popular categories:\n");
    findPopularCategories(items, numItems, categories, numCategories, 5);

    fclose(outputFile);
    return 0;
}