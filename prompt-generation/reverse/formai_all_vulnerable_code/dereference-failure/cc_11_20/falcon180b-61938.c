//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 32
#define MAX_VALUE_SIZE 128

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Metadata;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_SIZE];
    Metadata metadata;
    int key_index, value_index;
    char delimiter;

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s input_file delimiter\n", argv[0]);
        return 1;
    }

    // Open the input file
    if ((input_file = fopen(argv[1], "r")) == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    // Read the delimiter character
    delimiter = argv[2][0];

    // Read the first line to get the keys
    if (fgets(line, MAX_LINE_SIZE, input_file) == NULL) {
        printf("Error reading line from file.\n");
        fclose(input_file);
        return 1;
    }

    // Extract the keys from the first line
    key_index = 0;
    value_index = 0;
    char *token = strtok(line, ",");
    while (token!= NULL) {
        if (strlen(token) > MAX_KEY_SIZE - 1) {
            printf("Error: Key '%s' is too long.\n", token);
            fclose(input_file);
            return 1;
        }
        strcpy(metadata.key[key_index], token);
        key_index++;
        token = strtok(NULL, ",");
    }

    // Read the rest of the lines to get the values
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        // Extract the values for each key
        token = strtok(line, delimiter);
        while (token!= NULL) {
            if (strlen(token) > MAX_VALUE_SIZE - 1) {
                printf("Error: Value for key '%s' is too long.\n", metadata.key[value_index]);
                fclose(input_file);
                return 1;
            }
            strcpy(metadata.value[value_index], token);
            value_index++;
            token = strtok(NULL, delimiter);
        }
    }

    // Print the metadata
    for (int i = 0; i < key_index; i++) {
        printf("Key: %s\n", metadata.key[i]);
    }
    for (int i = 0; i < value_index; i++) {
        printf("Value for key '%s': %s\n", metadata.key[i], metadata.value[i]);
    }

    // Close the input file
    fclose(input_file);

    return 0;
}