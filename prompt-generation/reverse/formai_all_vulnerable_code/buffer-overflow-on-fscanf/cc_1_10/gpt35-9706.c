//FormAI DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of the index record
typedef struct {
    char word[50];
    int offset;
    int size;
} IndexRecord;

// Function to compare two index records
int compare(const void *a, const void *b) {
    return strcmp(((IndexRecord*)a)->word, ((IndexRecord*)b)->word);
}

int main() {

    // Size of the index
    const int INDEX_SIZE = 100;

    // Open the file
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Initialize the index
    IndexRecord* index = (IndexRecord*)malloc(sizeof(IndexRecord) * INDEX_SIZE);
    int index_count = 0;

    // Read the file and build the index
    int offset = 0;
    char word[50];
    while (fscanf(file, "%s", word) == 1) {

        // Add the record to the index
        index[index_count].offset = offset;
        index[index_count].size = strlen(word);
        strncpy(index[index_count].word, word, 50);

        // Increment the count
        index_count++;

        // If we've reached the end of the index, stop reading
        if (index_count >= INDEX_SIZE) {
            break;
        }

        // Update the offset
        offset += strlen(word) + 1; // 1 for the space character
    }

    // Close the file
    fclose(file);

    // Sort the index
    qsort(index, index_count, sizeof(IndexRecord), compare);

    // Test the index
    char search_term[50];
    while (1) {

        // Get the search term from the user
        printf("Enter a word to search for: ");
        scanf("%s", search_term);

        // Find the index record that matches the search term
        for (int i = 0; i < index_count; i++) {
            if (strcmp(index[i].word, search_term) == 0) {

                // Open the file and go to the correct offset
                file = fopen("data.txt", "r");
                fseek(file, index[i].offset, SEEK_SET);

                // Output the word and its surrounding text
                printf("%.*s\n", index[i].size, index[i].word);

                // Close the file and break
                fclose(file);
                break;
            }
        }
    }

    // Free the memory used by the index
    free(index);

    return 0;
}