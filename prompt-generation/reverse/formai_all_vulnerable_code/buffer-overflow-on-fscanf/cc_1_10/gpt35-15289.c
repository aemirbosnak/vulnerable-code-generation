//FormAI DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for maximum number of records
#define MAX_RECORDS 100

// Define a struct to store record data
typedef struct {
    int id;
    char name[30];
} Record;

// Define a struct to store index data
typedef struct {
    char key[30];
    int position;
} Index;

// Define function to compare two strings
int compare_strings(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

int main() {
    // Define variables
    Record records[MAX_RECORDS];
    Index index[MAX_RECORDS];
    char search_key[30];
    int num_records = 0, num_index = 0;
    FILE* fp;

    // Open file for reading
    fp = fopen("data.txt", "r");

    // Read records from file
    while (fscanf(fp, "%d %s", &records[num_records].id, records[num_records].name) != EOF) {
        // Copy the name to the index key field
        strcpy(index[num_index].key, records[num_records].name);
        // Store the position of the record in the index
        index[num_index].position = num_records;
        // Increment number of records and index entries
        num_records++;
        num_index++;
    }

    // Sort index entries by name
    qsort(index, num_index, sizeof(Index), compare_strings);

    // Close file
    fclose(fp);

    // Prompt user for search key
    printf("Enter search key: ");
    scanf("%s", search_key);

    // Perform binary search on index
    int left = 0, right = num_index - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (strcmp(index[mid].key, search_key) == 0) {
            // If the search key is found, display the record
            printf("Record found: %d %s\n", records[index[mid].position].id, records[index[mid].position].name);
            break;
        } else if (strcmp(index[mid].key, search_key) < 0) {
            // If the search key is greater than the middle key, search the right half
            left = mid + 1;
        } else {
            // If the search key is less than the middle key, search the left half
            right = mid - 1;
        }
    }

    // If search key was not found, display error message
    if (left > right) {
        printf("Record not found.\n");
    }

    return 0;
}