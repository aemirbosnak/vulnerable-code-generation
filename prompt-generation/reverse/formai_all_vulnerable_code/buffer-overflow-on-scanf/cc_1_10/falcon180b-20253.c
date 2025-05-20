//Falcon-180B DATASET v1.0 Category: Data mining ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 50
#define MAX_CATEGORY_NAME_LENGTH 50

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int count;
} category_t;

category_t categories[MAX_CATEGORIES];

void initialize_categories() {
    memset(categories, 0, sizeof(categories));
}

int get_category_index(char* name) {
    for(int i=0; i<MAX_CATEGORIES; i++) {
        if(strcmp(categories[i].name, name) == 0) {
            return i;
        }
    }
    strncpy(categories[MAX_CATEGORIES-1].name, name, MAX_CATEGORY_NAME_LENGTH);
    categories[MAX_CATEGORIES-1].count++;
    return MAX_CATEGORIES-1;
}

void add_item(char* category) {
    int index = get_category_index(category);
    categories[index].count++;
}

void print_categories() {
    printf("Category\tCount\n");
    for(int i=0; i<MAX_CATEGORIES; i++) {
        if(categories[i].count > 0) {
            printf("%s\t%d\n", categories[i].name, categories[i].count);
        }
    }
}

int main() {
    initialize_categories();
    char input[MAX_CATEGORY_NAME_LENGTH];

    while(1) {
        printf("Enter item category (or 'exit' to quit): ");
        scanf("%s", input);
        if(strcmp(input, "exit") == 0) {
            break;
        }
        add_item(input);
    }

    print_categories();

    return 0;
}