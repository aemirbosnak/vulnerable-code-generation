//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum size for our JSON strings
#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 256

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValuePair;

// Cheerful function to ignore whitespace
void ignoreWhitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

// Function to parse a single key-value pair
int parseKeyValue(const char **json, KeyValuePair *pair) {
    // We're getting ready for some fun! Here we go!
    ignoreWhitespace(json);

    if (**json != '"') {
        printf("Oops! Expected '\"' at the beginning of a key.\n");
        return 0;
    }

    (*json)++;  // Skip the opening quote

    char *keyPtr = pair->key;
    while (**json != '"' && **json != '\0') {
        *keyPtr++ = **json;
        (*json)++;
    }
    *keyPtr = '\0';  // Null-terminate our string

    if (**json != '"') {
        printf("Oops! Expected '\"' at the end of key.\n");
        return 0;
    }

    (*json)++;  // Skip the closing quote

    ignoreWhitespace(json);

    if (**json != ':') {
        printf("Oops! Expected ':' after key.\n");
        return 0;
    }
    
    (*json)++;  // Skip ':'

    ignoreWhitespace(json);

    if (**json != '"') {
        printf("Oops! Expected '\"' at the beginning of value.\n");
        return 0;
    }

    (*json)++;  // Opening quote for value

    char *valuePtr = pair->value;
    while (**json != '"' && **json != '\0') {
        *valuePtr++ = **json;
        (*json)++;
    }
    *valuePtr = '\0';  // Null-terminate value string
    
    if (**json != '"') {
        printf("Oops! Expected '\"' at the end of value.\n");
        return 0;
    }

    (*json)++;  // Skip closing quote for value

    return 1;  // Success! Yay!
}

// Function to parse JSON and print the key-value pairs
void parseJson(const char *json) {
    printf("Parsing your JSON string... Let's have some fun!\n");
    KeyValuePair pair;

    while (*json) {
        if (parseKeyValue(&json, &pair)) {
            printf("Found key: %s, value: %s\n", pair.key, pair.value);
        } else {
            printf("Oops! There was an error parsing the JSON... Let's try harder!\n");
            break;
        }
        ignoreWhitespace(&json);
        
        if (*json == ',') {
            json++;  // Move past the comma!
            continue;  // Check for more key-value pairs
        }
        break;  // No more pairs to parse
    }
}

int main() {
    char json[MAX_JSON_SIZE];

    // Cheerful user input
    printf("Welcome to the JSON Parser! 🎉\n");
    printf("Please enter a JSON string (e.g. {\"name\": \"Alice\", \"age\": \"30\"}):\n");
    
    if (fgets(json, sizeof(json), stdin) != NULL) {
        // Check if it started and ended with braces
        if(json[0] != '{' || json[strlen(json)-2] != '}') {
            printf("Oops! Your input should be a valid JSON object.\n");
            return 1;
        }
        
        json[strcspn(json, "\n")] = 0; // Remove the newline character

        parseJson(json + 1); // Skip initial '{' character
    } else {
        printf("Oops! Unable to read your input... Let's stay cheerful!\n");
    }

    printf("Thank you for using the JSON Parser! 🌟\n");
    return 0;
}