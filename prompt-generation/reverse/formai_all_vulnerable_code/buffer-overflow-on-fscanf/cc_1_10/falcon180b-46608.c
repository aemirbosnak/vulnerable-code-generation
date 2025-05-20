//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

int compare_entries(const void *a, const void *b) {
    entry *entry_a = (entry *)a;
    entry *entry_b = (entry *)b;

    int name_compare = strcmp(entry_a->name, entry_b->name);

    if (name_compare == 0) {
        return strcmp(entry_a->number, entry_b->number);
    }

    return name_compare;
}

int main() {
    FILE *phonebook_file;
    entry entries[MAX_ENTRIES];
    int num_entries = 0;

    phonebook_file = fopen("phonebook.txt", "r");

    if (phonebook_file == NULL) {
        printf("Error: Could not open phonebook file.\n");
        return 1;
    }

    while (fscanf(phonebook_file, "%s %s\n", entries[num_entries].name, entries[num_entries].number)!= EOF) {
        num_entries++;
    }

    fclose(phonebook_file);

    qsort(entries, num_entries, sizeof(entry), compare_entries);

    printf("Sherlock Holmes' Phonebook:\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    return 0;
}