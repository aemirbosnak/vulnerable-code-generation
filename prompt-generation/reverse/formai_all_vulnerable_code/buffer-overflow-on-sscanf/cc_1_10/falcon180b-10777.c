//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

int compare_names(const void *a, const void *b) {
    return strcasecmp(((struct entry *)a)->name, ((struct entry *)b)->name);
}

int compare_numbers(const void *a, const void *b) {
    return strcasecmp(((struct entry *)a)->number, ((struct entry *)b)->number);
}

void sort_entries(struct entry entries[], int num_entries, int (*compare_func)(const void *, const void *)) {
    qsort(entries, num_entries, sizeof(struct entry), compare_func);
}

int main() {
    FILE *phonebook_file;
    char input_buffer[100];
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    phonebook_file = fopen("phonebook.txt", "r");

    if (phonebook_file == NULL) {
        printf("Error opening phonebook file.\n");
        return 1;
    }

    while (fgets(input_buffer, sizeof(input_buffer), phonebook_file)!= NULL) {
        if (num_entries >= MAX_ENTRIES) {
            printf("Phonebook is full.\n");
            break;
        }

        if (sscanf(input_buffer, "%s %s", name, number)!= 2) {
            printf("Invalid entry format: %s\n", input_buffer);
            continue;
        }

        strcpy(entries[num_entries].name, name);
        strcpy(entries[num_entries].number, number);
        num_entries++;
    }

    fclose(phonebook_file);

    if (num_entries == 0) {
        printf("Phonebook is empty.\n");
        return 0;
    }

    sort_entries(entries, num_entries, compare_names);

    printf("Sorted by name:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    sort_entries(entries, num_entries, compare_numbers);

    printf("\nSorted by number:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    return 0;
}