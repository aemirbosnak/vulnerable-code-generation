//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

int compare_names(const void *a, const void *b) {
    const char *name_a = ((const entry_t *)a)->name;
    const char *name_b = ((const entry_t *)b)->name;
    return strcmp(name_a, name_b);
}

int compare_numbers(const void *a, const void *b) {
    const char *number_a = ((const entry_t *)a)->number;
    const char *number_b = ((const entry_t *)b)->number;
    return strcmp(number_a, number_b);
}

entry_t *read_entries(FILE *file, int *num_entries) {
    entry_t *entries = malloc(MAX_ENTRIES * sizeof(entry_t));
    if (entries == NULL) {
        fprintf(stderr, "Error: could not allocate memory for entries.\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (fscanf(file, "%s %s\n", entries[i].name, entries[i].number) == 2) {
        i++;
        if (i >= MAX_ENTRIES) {
            fprintf(stderr, "Error: too many entries in file.\n");
            exit(EXIT_FAILURE);
        }
    }
    *num_entries = i;
    return entries;
}

void write_entries(FILE *file, entry_t *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s %s\n", entries[i].name, entries[i].number);
    }
}

void sort_entries(entry_t *entries, int num_entries, int (*compare_func)(const void *, const void *)) {
    qsort(entries, num_entries, sizeof(entry_t), compare_func);
}

int main() {
    FILE *file;
    entry_t *entries;
    int num_entries;

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open phonebook.txt for reading.\n");
        exit(EXIT_FAILURE);
    }

    entries = read_entries(file, &num_entries);
    fclose(file);

    printf("Sorting by name...\n");
    sort_entries(entries, num_entries, compare_names);
    write_entries(stdout, entries, num_entries);

    printf("\nSorting by number...\n");
    sort_entries(entries, num_entries, compare_numbers);
    write_entries(stdout, entries, num_entries);

    free(entries);
    return 0;
}