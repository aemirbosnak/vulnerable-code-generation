//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of metadata
#define MAX_METADATA_LEN 100

// Define the metadata struct
typedef struct {
    char name[MAX_METADATA_LEN];
    char value[MAX_METADATA_LEN];
} Metadata;

// Define the metadata extractor function
Metadata* extract_metadata(char* str, int* num_metadata) {
    // Initialize variables
    int i, j;
    int num_pairs = 0;
    int num_chars = strlen(str);
    int in_quotes = 0;
    char current_name[MAX_METADATA_LEN];
    char current_value[MAX_METADATA_LEN];
    Metadata* metadata_list = NULL;
    
    // Iterate over the string
    for (i = 0; i < num_chars; i++) {
        // Check for metadata name and value
        if (str[i] == ':' && !in_quotes) {
            // Copy the current name to the metadata struct
            current_name[j] = '\0';
            strcpy(metadata_list[num_pairs].name, current_name);
            j = 0;
        } else if (str[i] == '"' && !in_quotes) {
            // Enter quote mode and ignore the quote
            in_quotes = 1;
        } else if (str[i] == '"' && in_quotes) {
            // Exit quote mode and copy the value to the metadata struct
            current_value[j] = '\0';
            strcpy(metadata_list[num_pairs].value, current_value);
            j = 0;
            in_quotes = 0;
            num_pairs++;
            metadata_list = realloc(metadata_list, sizeof(Metadata) * (num_pairs + 1));
        } else {
            // Copy the character to the appropriate variable
            if (in_quotes) {
                current_value[j] = str[i];
            } else {
                current_name[j] = str[i];
            }
            j++;
        }
    }
    
    // Set the number of metadata pairs
    *num_metadata = num_pairs;
    
    // Return the metadata list
    return metadata_list;
}

int main() {
    // Define the input string
    char input_str[] = "{\"name\":\"John Smith\",\"age\":30,\"city\":\"New York\"}";
    
    // Extract the metadata
    int num_metadata = 0;
    Metadata* metadata_list = extract_metadata(input_str, &num_metadata);
    
    // Print the metadata
    int i;
    for (i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata_list[i].name, metadata_list[i].value);
    }
    
    // Free the metadata list memory
    free(metadata_list);
    
    return 0;
}