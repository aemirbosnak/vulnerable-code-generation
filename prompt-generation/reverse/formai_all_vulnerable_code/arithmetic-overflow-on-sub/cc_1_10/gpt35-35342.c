//FormAI DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the database index entry
typedef struct {
    char key[50];
    int offset;
} IndexEntry;

// Define a structure for the index itself
typedef struct {
    IndexEntry *entries;
    int num_entries;
} Index;

// Function to read a line of text from a file
char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, fp);
    if (read == -1) {
        free(line);
        return NULL;
    }
    if (line[read-1] == '\n') {
        line[read-1] = '\0';
    }
    return line;
}

// Function to add a new entry to the index
void add_entry_to_index(Index *index, char *key, int offset) {
    if (index->num_entries == 0) {
        index->entries = malloc(sizeof(IndexEntry));
        index->num_entries = 1;
    } else {
        index->entries = realloc(index->entries, (index->num_entries + 1) * sizeof(IndexEntry));
        index->num_entries++;
    }
    strcpy(index->entries[index->num_entries-1].key, key);
    index->entries[index->num_entries-1].offset = offset;
}

// Function to search for an entry in the index
int search_index(Index *index, char *key) {
    int i;
    for (i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].offset;
        }
    }
    return -1;
}

int main() {
    // Open the data file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open data file\n");
        exit(1);
    }

    // Create an empty index
    Index index;
    index.entries = NULL;
    index.num_entries = 0;

    // Read through the data file and build the index
    int offset = 0;
    while (1) {
        // Read a line from the file
        char *line = read_line(fp);
        if (line == NULL) {
            break;
        }

        // Extract the key from the line and add it to the index
        char *key = strtok(line, ",");
        add_entry_to_index(&index, key, offset);

        // Update the offset for the next line
        offset = ftell(fp);

        // Free the memory used by the line
        free(line);
    }

    // Close the data file
    fclose(fp);

    // Search the index for a particular key
    int result = search_index(&index, "John Smith");
    if (result == -1) {
        printf("Error: Key not found\n");
    } else {
        // Open the data file again and move to the correct position
        fp = fopen("data.txt", "r");
        fseek(fp, result, SEEK_SET);

        // Read and print the matching line
        char *line = read_line(fp);
        printf("Found: %s\n", line);

        // Free the memory used by the line
        free(line);

        // Close the data file
        fclose(fp);
    }

    // Free the memory used by the index
    free(index.entries);

    return 0;
}