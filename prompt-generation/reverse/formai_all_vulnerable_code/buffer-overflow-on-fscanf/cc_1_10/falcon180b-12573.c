//Falcon-180B DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 1000000
#define MAX_CATEGORIES 1000
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    int count;
} Category;

Category categories[MAX_CATEGORIES];
int num_categories = 0;

void add_category(char* category) {
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].category, category) == 0) {
            categories[i].count++;
            return;
        }
    }
    strcpy(categories[num_categories].category, category);
    categories[num_categories].count = 1;
    num_categories++;
}

void print_categories() {
    printf("Category\tCount\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\t%d\n", categories[i].category, categories[i].count);
    }
}

int main() {
    srand(time(NULL));
    
    char filename[50] = "data.txt";
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    int num_items = 0;
    while (fscanf(file, "%s", categories[num_categories].category)!= EOF) {
        add_category(categories[num_categories].category);
        num_items++;
        if (num_items >= MAX_ITEMS) {
            break;
        }
    }
    
    fclose(file);
    
    printf("Number of items: %d\n", num_items);
    print_categories();
    
    return 0;
}