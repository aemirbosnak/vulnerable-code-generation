//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int compare(const void *a, const void *b) {
    const Entry *entry1 = a;
    const Entry *entry2 = b;
    return strcmp(entry1->name, entry2->name);
}

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int count = 0;
    char line[MAX_NAME_LENGTH + MAX_NUMBER_LENGTH + 2]; // +2 for newline and null terminator

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (count >= MAX_ENTRIES) {
            printf("Error: Maximum number of entries reached.\n");
            exit(1);
        }
        char *name = strtok(line, ":");
        char *number = strtok(NULL, ":");
        strcpy(entries[count].name, name);
        strcpy(entries[count].number, number);
        count++;
    }

    fclose(file);
    qsort(entries, count, sizeof(Entry), compare);

    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    return 0;
}