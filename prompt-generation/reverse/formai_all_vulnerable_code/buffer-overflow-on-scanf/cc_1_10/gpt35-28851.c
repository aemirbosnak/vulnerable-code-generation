//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
// Hi there! I'm here to help you build a JSON parser in C!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON 1000 // Maximum size of JSON string

// Define prototypes for our helper functions
char* readJSON();
int countFields(char* json, char** keys, char** values);
void printFields(char** keys, char** values, int count);

// Main method
int main() {
    // Welcome message
    printf("Welcome to my JSON parser example program in C!\n");
    printf("Please enter your JSON string:\n");

    // Read the JSON string from input
    char* json = readJSON();

    // Initialize arrays for storing keys and values
    char* keys[MAX_JSON];
    char* values[MAX_JSON];

    // Count the number of fields and populate arrays
    int count = countFields(json, keys, values);

    // Print out the parsed fields
    printf("\nParsed fields:\n");
    printFields(keys, values, count);

    // Farewell message
    printf("\nHope you enjoyed using my JSON parser example program in C!\n");

    // Exit the program with code 0 (success)
    return 0;
}

// Helper function to read a JSON string from user input
char* readJSON() {
    // Initialize buffer for storing JSON string
    char buffer[MAX_JSON];

    // Read input from user
    scanf("%[^\n]", buffer);

    // Allocate memory for copying input
    char* json = malloc(strlen(buffer) + 1);

    // Copy input into allocated memory
    strcpy(json, buffer);

    // Return pointer to JSON string
    return json;
}

// Helper function to count the number of fields in a JSON string
int countFields(char* json, char** keys, char** values) {
    // Initialize counters
    int keyCount = 0;
    int valueCount = 0;

    // Find the first '{' character in the JSON string
    char* start = strchr(json, '{');

    // Find the last '}' character in the JSON string
    char* end = strrchr(json, '}');

    // Calculate the length of the JSON object string
    int length = end - start;

    // Create copy of JSON object string
    char* objectStr = malloc(length + 1);
    strncpy(objectStr, start, length);
    objectStr[length] = '\0';

    // Tokenize copy of JSON object string by comma and colon
    char* tokens = strtok(objectStr, ",:");
    while (tokens != NULL) {
        // Store key or value in appropriate array, based on position of token in JSON object string
        if (keyCount == valueCount) {
            keys[keyCount] = tokens;
            keyCount++;
        }
        else {
            values[valueCount] = tokens;
            valueCount++;
        }

        // Move to next token
        tokens = strtok(NULL, ",:");
    }

    // Return total number of fields parsed
    return keyCount;
}

// Helper function to print out parsed keys and values
void printFields(char** keys, char** values, int count) {
    // Loop through each key-value pair and print them out
    for (int i = 0; i < count; i++) {
        printf("  %s: %s\n", keys[i], values[i]);
    }
}