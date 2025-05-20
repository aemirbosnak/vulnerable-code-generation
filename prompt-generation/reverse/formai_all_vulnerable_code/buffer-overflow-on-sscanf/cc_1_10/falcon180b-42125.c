//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

int compare_names(const void *a, const void *b) {
    const entry_t *entry_a = (const entry_t *) a;
    const entry_t *entry_b = (const entry_t *) b;
    return strcmp(entry_a->name, entry_b->name);
}

int compare_numbers(const void *a, const void *b) {
    const entry_t *entry_a = (const entry_t *) a;
    const entry_t *entry_b = (const entry_t *) b;
    return strcmp(entry_a->number, entry_b->number);
}

void sort_entries(entry_t entries[], int num_entries, int (*compare_func)(const void *, const void *)) {
    qsort(entries, num_entries, sizeof(entry_t), compare_func);
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    FILE *phonebook_file;
    char line[1024];
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    phonebook_file = fopen("phonebook.txt", "r");
    if (phonebook_file == NULL) {
        printf("Error: Could not open phonebook file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), phonebook_file)!= NULL) {
        if (sscanf(line, "%s %s", name, number)!= 2) {
            printf("Error: Invalid entry in phonebook file.\n");
            return 1;
        }

        strcpy(entries[num_entries].name, name);
        strcpy(entries[num_entries].number, number);
        num_entries++;
    }

    fclose(phonebook_file);

    sort_entries(entries, num_entries, compare_names);

    printf("Sorted by name:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    sort_entries(entries, num_entries, compare_numbers);

    printf("\nSorted by number:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].number, entries[i].name);
    }

    return 0;
}