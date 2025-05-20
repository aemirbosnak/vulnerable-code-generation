//Falcon-180B DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} category;

item items[MAX_ITEMS];
category categories[MAX_CATEGORIES];
int num_items = 0;
int num_categories = 0;

void load_data()
{
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open data file.\n");
        exit(1);
    }

    char line[256];
    while (fgets(line, 256, fp)!= NULL) {
        item *item = &items[num_items];
        category *category = &categories[num_categories];

        char *token = strtok(line, ",");
        strcpy(item->name, token);
        item->id = num_items;
        num_items++;

        token = strtok(NULL, ",");
        strcpy(category->name, token);
        category->id = num_categories;
        num_categories++;
    }

    fclose(fp);
}

void print_items()
{
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s (%d)\n", items[i].name, items[i].id);
    }
}

void print_categories()
{
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s (%d)\n", categories[i].name, categories[i].id);
    }
}

void main()
{
    load_data();
    print_items();
    print_categories();
}