//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[MAX_NAME_LENGTH];
    char line[MAX_NAME_LENGTH];
    char *token;

    // Get filename from user
    printf("Enter filename: ");
    fgets(filename, MAX_NAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read entries from file
    while (fgets(line, MAX_NAME_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        strcpy(entries[num_entries].name, token);
        token = strtok(NULL, ",");
        strcpy(entries[num_entries].number, token);
        num_entries++;
    }

    // Close file
    fclose(file);

    // Print entries
    printf("Name\tNumber\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].name, entries[i].number);
    }

    return 0;
}