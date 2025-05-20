//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

// structure for storing phone book entries
typedef struct entry {
    char name[50];
    char number[15];
} Entry;

// function for comparing names
int compare_names(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

// function for comparing numbers
int compare_numbers(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

// function for printing phone book entries
void print_entries(Entry* entries, int count) {
    printf("Name\tNumber\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    Entry* entries = malloc(MAX_ENTRIES * sizeof(Entry));
    int count = 0;

    // prompt user for phone book entries
    while (count < MAX_ENTRIES && scanf("%s %s", entries[count].name, entries[count].number) == 2) {
        count++;
    }

    // sort entries by name
    qsort(entries, count, sizeof(Entry), compare_names);

    // print sorted phone book entries
    printf("Sorted by name:\n");
    print_entries(entries, count);

    // sort entries by number
    qsort(entries, count, sizeof(Entry), compare_numbers);

    // print sorted phone book entries
    printf("\nSorted by number:\n");
    print_entries(entries, count);

    free(entries);
    return 0;
}