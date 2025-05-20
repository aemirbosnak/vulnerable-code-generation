//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

int compare_names(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int compare_numbers(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    int num_entries = 0;
    entry_t* entries = NULL;

    printf("Enter number of entries (up to %d): ", MAX_ENTRIES);
    scanf("%d", &num_entries);

    if (num_entries > 0 && num_entries <= MAX_ENTRIES) {
        entries = malloc(num_entries * sizeof(entry_t));

        for (int i = 0; i < num_entries; i++) {
            printf("Enter name for entry %d: ", i+1);
            scanf("%s", entries[i].name);

            printf("Enter number for entry %s: ", entries[i].name);
            scanf("%s", entries[i].number);
        }

        qsort(entries, num_entries, sizeof(entry_t), compare_names);

        printf("\nSorted by name:\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%s: %s\n", entries[i].name, entries[i].number);
        }

        qsort(entries, num_entries, sizeof(entry_t), compare_numbers);

        printf("\nSorted by number:\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%s: %s\n", entries[i].name, entries[i].number);
        }
    } else {
        printf("Invalid number of entries.\n");
    }

    free(entries);
    return 0;
}