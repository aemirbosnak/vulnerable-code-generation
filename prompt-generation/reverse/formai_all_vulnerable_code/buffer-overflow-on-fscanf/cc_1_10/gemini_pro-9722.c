//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100
#define MAX_RECORDS 1000

typedef struct {
    char key[MAX_KEYS];
    int record_id;
} index_entry;

typedef struct {
    char data[MAX_RECORDS];
} record;

// Create a new index
index_entry *create_index(char *filename) {
    FILE *fp;
    index_entry *index;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the index
    index = malloc(sizeof(index_entry) * MAX_KEYS);
    if (index == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    // Read the index entries from the file
    int i = 0;
    while (fscanf(fp, "%s %d\n", index[i].key, &index[i].record_id) != EOF) {
        i++;
    }

    // Close the file
    fclose(fp);

    return index;
}

// Search the index for a key
int search_index(index_entry *index, char *key) {
    int i;

    // Linear search for the key
    for (i = 0; i < MAX_KEYS; i++) {
        if (strcmp(index[i].key, key) == 0) {
            return index[i].record_id;
        }
    }

    // Key not found
    return -1;
}

// Print the index
void print_index(index_entry *index) {
    int i;

    for (i = 0; i < MAX_KEYS; i++) {
        printf("%s %d\n", index[i].key, index[i].record_id);
    }
}

// Main function
int main() {
    index_entry *index;
    int record_id;

    // Create the index
    index = create_index("index.txt");
    if (index == NULL) {
        return 1;
    }

    // Search the index for a key
    record_id = search_index(index, "key1");
    if (record_id == -1) {
        printf("Key not found\n");
    } else {
        printf("Record ID: %d\n", record_id);
    }

    // Print the index
    print_index(index);

    // Free the memory allocated for the index
    free(index);

    return 0;
}