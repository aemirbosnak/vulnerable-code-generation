//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
/* C Phone Book Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int main() {
    FILE *phonebook;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[MAX_NAME_LENGTH];

    /* Prompt user for phone book filename */
    printf("Enter phone book filename: ");
    scanf("%s", filename);

    /* Open phone book file */
    phonebook = fopen(filename, "r");
    if (phonebook == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    /* Read entries from file */
    while (fscanf(phonebook, "%s %s", entries[num_entries].name, entries[num_entries].number)!= EOF) {
        num_entries++;
    }
    fclose(phonebook);

    /* Sort entries alphabetically by name */
    for (int i = 0; i < num_entries; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (strcmp(entries[i].name, entries[j].name) > 0) {
                Entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }

    /* Print sorted entries */
    printf("Name\tNumber\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].name, entries[i].number);
    }

    return 0;
}