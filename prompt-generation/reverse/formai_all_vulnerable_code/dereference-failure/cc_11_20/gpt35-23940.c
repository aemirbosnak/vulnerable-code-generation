//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum string length for input
#define MAX_INPUT_LENGTH 100

// Define a struct for key-value pairs
typedef struct {
    char key[MAX_INPUT_LENGTH];
    char value[MAX_INPUT_LENGTH];
} KeyValue;

// Define a struct for JSON objects
typedef struct {
    KeyValue* kv_pairs;
    int num_kv_pairs;
} JsonObject;

// Function to parse a JSON object from input string
void parse_json(char* input, JsonObject* output) {
    // Allocate memory for key-value pairs
    output->num_kv_pairs = 0;
    output->kv_pairs = (KeyValue*)malloc(sizeof(KeyValue));

    // Skip any whitespace at the beginning of the input
    while (*input == ' ' || *input == '\t' || *input == '\n' || *input == '\r') {
        input++;
    }

    // Check if input starts with a '{' character
    if (*input != '{') {
        printf("Error: Input must start with '{'\n");
        return;
    }
    input++;

    // Loop through input string until it ends or a '}' character is found
    while (*input != '\0' && *input != '}') {
        // Skip any whitespace
        while (*input == ' ' || *input == '\t' || *input == '\n' || *input == '\r') {
            input++;
        }

        // Parse the key string
        char* key_start = input;
        char* key_end = NULL;
        while (*input != '\0' && *input != ':' && *input != '}') {
            input++;
        }
        if (*input != ':') {
            printf("Error: Expected ':' after key\n");
            return;
        }
        key_end = input;
        input++;
        if (*key_end == ' ') {
            key_end--;
        }
        *key_end = '\0';

        // Skip any whitespace after ':'
        while (*input == ' ' || *input == '\t' || *input == '\n' || *input == '\r') {
            input++;
        }

        // Parse the value string
        char* value_start = input;
        char* value_end = NULL;
        while (*input != '\0' && *input != ',' && *input != '}') {
            input++;
        }
        value_end = input;
        if (*value_end == ' ') {
            value_end--;
        }
        if (*input == ',') {
            input++;
        }
        *value_end = '\0';

        // Create new key-value pair and add to output object
        output->num_kv_pairs++;
        output->kv_pairs = (KeyValue*)realloc(output->kv_pairs, output->num_kv_pairs * sizeof(KeyValue));
        strcpy(output->kv_pairs[output->num_kv_pairs-1].key, key_start);
        strcpy(output->kv_pairs[output->num_kv_pairs-1].value, value_start);
    }

    // Check if input ends with a '}' character
    if (*input != '}') {
        printf("Error: Input must end with '}'\n");
        return;
    }
}

// Main function to test the JSON parser
int main() {
    // Test case 1: Valid input string with one key-value pair
    char input1[] = "{ \"key1\": \"value1\" }";
    JsonObject output1;
    parse_json(input1, &output1);
    printf("Test case 1: %s => {", input1);
    for (int i = 0; i < output1.num_kv_pairs; i++) {
        printf(" \"%s\": \"%s\"", output1.kv_pairs[i].key, output1.kv_pairs[i].value);
    }
    printf(" }\n");

    // Test case 2: Valid input string with multiple key-value pairs
    char input2[] = "{ \"key1\": \"value1\", \"key2\": \"value2\", \"key3\": \"value3\" }";
    JsonObject output2;
    parse_json(input2, &output2);
    printf("Test case 2: %s => {", input2);
    for (int i = 0; i < output2.num_kv_pairs; i++) {
        printf(" \"%s\": \"%s\"", output2.kv_pairs[i].key, output2.kv_pairs[i].value);
    }
    printf(" }\n");

    // Test case 3: Invalid input string missing closing bracket
    char input3[] = "{ \"key1\": \"value1\", \"key2\": \"value2\" ";
    JsonObject output3;
    parse_json(input3, &output3);
    printf("Test case 3: %s => {", input3);
    for (int i = 0; i < output3.num_kv_pairs; i++) {
        printf(" \"%s\": \"%s\"", output3.kv_pairs[i].key, output3.kv_pairs[i].value);
    }
    printf(" }\n");

    return 0;
}