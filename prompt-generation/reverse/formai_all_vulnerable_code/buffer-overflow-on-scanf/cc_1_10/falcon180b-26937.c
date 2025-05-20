//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

struct entry {
    char name[MAX_NAME_LEN + 1];
    char number[MAX_NUMBER_LEN + 1];
    time_t last_modified;
};

int compare_entries(const void *a, const void *b) {
    const struct entry *entry_a = (const struct entry *)a;
    const struct entry *entry_b = (const struct entry *)b;
    return strcmp(entry_a->name, entry_b->name);
}

void print_entry(const struct entry *entry) {
    printf("%s: %s\n", entry->name, entry->number);
}

int main() {
    FILE *phonebook_file;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[MAX_NAME_LEN + 1];

    printf("Enter the name of the phonebook file: ");
    scanf("%s", filename);

    phonebook_file = fopen(filename, "r");

    if (phonebook_file == NULL) {
        printf("Error: Phonebook file not found.\n");
        return 1;
    }

    while (num_entries < MAX_ENTRIES && fscanf(phonebook_file, "%s %s", entries[num_entries].name, entries[num_entries].number) == 2) {
        entries[num_entries].last_modified = time(NULL);
        num_entries++;
    }

    qsort(entries, num_entries, sizeof(struct entry), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    fclose(phonebook_file);

    return 0;
}