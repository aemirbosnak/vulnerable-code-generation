//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // Maximum number of entries in the database

// Structure for each entry in the database
typedef struct {
    char *key; // Key for the entry
    int value; // Value for the entry
} Entry;

// Function to compare two keys
int compare_keys(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to print the database
void print_database(Entry *database, int num_entries) {
    printf("Database:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %d\n", database[i].key, database[i].value);
    }
}

// Main function
int main() {
    // Initialize the database with some entries
    Entry database[MAX_ENTRIES];
    int num_entries = 0;
    database[num_entries++] = (Entry){.key = "apple",.value = 5};
    database[num_entries++] = (Entry){.key = "banana",.value = 3};
    database[num_entries++] = (Entry){.key = "cherry",.value = 7};
    database[num_entries++] = (Entry){.key = "date",.value = 1};
    database[num_entries++] = (Entry){.key = "elderberry",.value = 2};
    database[num_entries++] = (Entry){.key = "fig",.value = 4};
    database[num_entries++] = (Entry){.key = "grape",.value = 6};

    // Sort the database by key
    qsort(database, num_entries, sizeof(Entry), compare_keys);

    // Print the sorted database
    print_database(database, num_entries);

    // Search for a key in the database
    char search_key[20];
    printf("\nEnter a key to search for: ");
    scanf("%s", search_key);
    Entry *result = bsearch(&(Entry){.key = search_key}, database, num_entries, sizeof(Entry), compare_keys);
    if (result!= NULL) {
        printf("\nFound entry with key '%s' and value %d\n", result->key, result->value);
    } else {
        printf("\nEntry not found.\n");
    }

    return 0;
}