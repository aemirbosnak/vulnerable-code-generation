//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int category;
    int frequency;
} item_t;

void read_items(item_t* items) {
    FILE* input_file = fopen("items.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    int num_items = 0;
    while (fscanf(input_file, "%s %d", items[num_items].name, &items[num_items].category)!= EOF) {
        num_items++;
    }

    fclose(input_file);
}

void count_frequencies(item_t* items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        items[i].frequency = 1;
    }

    for (int i = 1; i < num_items; i++) {
        for (int j = 0; j < i; j++) {
            if (strcmp(items[i].name, items[j].name) == 0) {
                items[i].frequency += items[j].frequency;
                items[j].frequency = 0;
            }
        }
    }
}

void write_frequencies(item_t* items, int num_items) {
    FILE* output_file = fopen("frequencies.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    for (int i = 0; i < num_items; i++) {
        if (items[i].frequency > 0) {
            fprintf(output_file, "%s %d\n", items[i].name, items[i].frequency);
        }
    }

    fclose(output_file);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    read_items(items);
    count_frequencies(items, num_items);
    write_frequencies(items, num_items);

    return 0;
}