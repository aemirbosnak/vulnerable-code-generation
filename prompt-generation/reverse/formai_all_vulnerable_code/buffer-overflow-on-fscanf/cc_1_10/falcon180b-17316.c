//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

int main() {
    FILE *file;
    int num_entries = 0;
    entry_t entries[MAX_ENTRIES];

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read in entries from file
    while (fscanf(file, "%s %s\n", entries[num_entries].name, entries[num_entries].number)!= EOF) {
        num_entries++;
    }
    fclose(file);

    // Sort entries alphabetically
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (strcmp(entries[i].name, entries[j].name) > 0) {
                entry_t temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }

    // Print sorted entries
    printf("Sorted Phonebook:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    return 0;
}