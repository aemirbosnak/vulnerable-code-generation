//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct for JSON key-value pairs
typedef struct {
    char* key;
    char* value;
} kvpair_t;

// Define a struct for a JSON object
typedef struct {
    int num_pairs;
    kvpair_t* kv_pairs;
} json_obj_t;

// Function to parse a JSON object from a file
json_obj_t* parse_json(char* filename) {
    // Open the file for reading
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }
    
    // Get the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    
    // Allocate memory for the file content
    char* file_content = (char*) malloc(sizeof(char) * (file_size + 1));
    if (!file_content) {
        printf("Could not allocate memory for file content\n");
        return NULL;
    }
    
    // Read the file content into memory
    size_t num_read = fread(file_content, sizeof(char), file_size, fp);
    if (num_read != file_size) {
        printf("Error reading file %s\n", filename);
        return NULL;
    }
    
    // Add null terminator to the end of the file content
    file_content[file_size] = '\0';
    
    // Close the file
    fclose(fp);
    
    // Allocate memory for the JSON object
    json_obj_t* json_obj = (json_obj_t*) malloc(sizeof(json_obj_t));
    if (!json_obj) {
        printf("Could not allocate memory for JSON object\n");
        return NULL;
    }
    
    // Initialize the JSON object
    json_obj->num_pairs = 0;
    json_obj->kv_pairs = NULL;
    
    // Parse the JSON object contents
    char* current_char = file_content;
    while (*current_char != '\0') {
        if (isspace(*current_char)) {
            // Ignore whitespace
            current_char++;
        } else if (*current_char == '{') {
            // Start of JSON object, do nothing
            current_char++;
        } else if (*current_char == '}') {
            // End of JSON object, break out of loop
            break;
        } else if (*current_char == '"') {
            // Start of key or value string
            char* start_char = ++current_char;
            while (*current_char != '\0' && *current_char != '"') {
                current_char++;
            }
            if (*current_char == '\0') {
                // End of string not found
                printf("Error parsing JSON: end of string not found\n");
                return NULL;
            } else {
                // End of string found
                char* string = (char*) malloc(sizeof(char) * (current_char - start_char + 1));
                if (!string) {
                    printf("Could not allocate memory for string\n");
                    return NULL;
                }
                strncpy(string, start_char, current_char - start_char);
                string[current_char - start_char] = '\0';
                // Add key or value string to key-value pair
                if (json_obj->num_pairs > 0 && json_obj->kv_pairs[json_obj->num_pairs - 1].value == NULL) {
                    json_obj->kv_pairs[json_obj->num_pairs - 1].value = string;
                } else {
                    kvpair_t* kv_pair = (kvpair_t*) malloc(sizeof(kvpair_t));
                    if (!kv_pair) {
                        printf("Could not allocate memory for key-value pair\n");
                        return NULL;
                    }
                    kv_pair->key = string;
                    kv_pair->value = NULL;
                    json_obj->num_pairs++;
                    json_obj->kv_pairs = (kvpair_t*) realloc(json_obj->kv_pairs, sizeof(kvpair_t) * json_obj->num_pairs);
                    if (!json_obj->kv_pairs) {
                        printf("Could not reallocate memory for key-value pairs\n");
                        return NULL;
                    }
                    json_obj->kv_pairs[json_obj->num_pairs - 1] = *kv_pair;
                    free(kv_pair);
                }
                current_char++;
            }
        } else if (*current_char == ':') {
            // Separator between key and value, do nothing
            current_char++;
        } else if (*current_char == ',') {
            // Separator between key-value pairs, do nothing
            current_char++;
        } else {
            // Invalid character, break out of loop
            printf("Error parsing JSON: invalid character\n");
            return NULL;
        }
    }
    
    // Free the file content memory
    free(file_content);
    
    return json_obj;
}

// Main function to test the JSON parser
int main() {
    char* filename = "example.json";
    json_obj_t* json_obj = parse_json(filename);
    if (json_obj == NULL) {
        printf("Could not parse JSON file %s\n", filename);
    } else {
        printf("Key-value pairs:\n");
        for (int i = 0; i < json_obj->num_pairs; i++) {
            printf("%s: %s\n", json_obj->kv_pairs[i].key, json_obj->kv_pairs[i].value);
        }
        // Free memory used by JSON object
        for (int i = 0; i < json_obj->num_pairs; i++) {
            free(json_obj->kv_pairs[i].key);
            free(json_obj->kv_pairs[i].value);
        }
        free(json_obj->kv_pairs);
        free(json_obj);
    }
    return 0;
}