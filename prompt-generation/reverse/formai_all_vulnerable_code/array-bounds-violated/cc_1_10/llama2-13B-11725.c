//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_VALUE 0
#define MAX_VALUE 100

typedef struct {
    int value;
    char name[20];
} item_t;

item_t items[10];

void init_items(void) {
    int i;

    for (i = 0; i < 10; i++) {
        items[i].value = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
        snprintf(items[i].name, sizeof(items[i].name), "Item %d", i);
    }
}

void add_item(item_t* item) {
    int i;

    for (i = 0; i < 10; i++) {
        if (items[i].value > item->value) {
            break;
        }
    }

    items[i].value = item->value;
    strcpy(items[i].name, item->name);
}

void print_items(void) {
    int i;

    for (i = 0; i < 10; i++) {
        printf("%d. %s\n", items[i].value, items[i].name);
    }
}

int main(void) {
    srand(time(NULL));

    init_items();

    item_t item1;
    item1.value = 25;
    strcpy(item1.name, "Item 1");

    item_t item2;
    item2.value = 42;
    strcpy(item2.name, "Item 2");

    add_item(&item1);
    add_item(&item2);

    print_items();

    return 0;
}