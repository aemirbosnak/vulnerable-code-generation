//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the search list

typedef struct {
    char *name; // name of the item
    int id; // unique identifier for the item
} item_t;

void create_list(item_t *list[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        list[i] = (item_t *)malloc(sizeof(item_t));
        list[i]->name = (char *)malloc(MAX_SIZE * sizeof(char));
        list[i]->id = i;
        sprintf(list[i]->name, "Item %d", i);
    }
}

void print_list(item_t *list[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("[%d] %s\n", list[i]->id, list[i]->name);
    }
}

int search_list(item_t *list[], int size, char *query) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(list[i]->name, query) == 0) {
            return i;
        }
    }
    return -1; // item not found
}

int main() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    item_t *list[MAX_SIZE];
    create_list(list, size);

    print_list(list, size);

    char query[MAX_SIZE];
    printf("Enter the item to search: ");
    scanf("%s", query);

    int index = search_list(list, size, query);

    if (index!= -1) {
        printf("Item found at index %d\n", index);
    } else {
        printf("Item not found\n");
    }

    return 0;
}