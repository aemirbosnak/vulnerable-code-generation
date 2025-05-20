//Falcon-180B DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 10000
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int count;
    float frequency;
    int category;
} item;

item items[MAX_ITEMS];
int num_items = 0;

int get_category(char *name) {
    if (strcmp(name, "electronics") == 0) {
        return 0;
    } else if (strcmp(name, "clothing") == 0) {
        return 1;
    } else if (strcmp(name, "books") == 0) {
        return 2;
    } else {
        return -1;
    }
}

void add_item(char *name, int category) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].count++;
            items[i].frequency = (float)items[i].count / num_items;
            return;
        }
    }
    if (num_items >= MAX_ITEMS) {
        printf("Error: too many items!\n");
        exit(1);
    }
    strcpy(items[num_items].name, name);
    items[num_items].category = category;
    items[num_items].count = 1;
    items[num_items].frequency = (float)items[num_items].count / num_items;
    num_items++;
}

void print_items() {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s %d %.2f %d\n", items[i].name, items[i].count, items[i].frequency, items[i].category);
    }
}

int main() {
    char name[50];
    int category;
    while (1) {
        printf("Enter item name (or type 'done' to finish): ");
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        category = get_category(name);
        if (category == -1) {
            printf("Error: invalid category!\n");
            continue;
        }
        add_item(name, category);
    }
    print_items();
    return 0;
}