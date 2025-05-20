//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure to hold the parsed data
typedef struct {
    char *identifier;
    int value;
} parsed_data_t;

// Function to parse the input string and return the parsed data
parsed_data_t parse_input(char *input) {
    parsed_data_t parsed_data;
    char *identifier = NULL;
    int value = 0;
    char *token = strtok(input, " ");

    while (token!= NULL) {
        if (isalpha(token[0])) {
            // Handle identifier
            if (identifier == NULL) {
                identifier = malloc(strlen(token) + 1);
                strcpy(identifier, token);
            } else {
                identifier = realloc(identifier, strlen(identifier) + strlen(token) + 1);
                strcat(identifier, " ");
                strcat(identifier, token);
            }
        } else {
            // Handle integer value
            value = atoi(token);
        }

        token = strtok(NULL, " ");
    }

    parsed_data.identifier = identifier;
    parsed_data.value = value;

    return parsed_data;
}

// Function to print the parsed data
void print_parsed_data(parsed_data_t parsed_data) {
    if (parsed_data.identifier!= NULL) {
        printf("Identifier: %s\n", parsed_data.identifier);
    }

    if (parsed_data.value!= 0) {
        printf("Value: %d\n", parsed_data.value);
    }
}

// Main function
int main() {
    char input[100];
    parsed_data_t parsed_data;

    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    parsed_data = parse_input(input);

    print_parsed_data(parsed_data);

    free(parsed_data.identifier);

    return 0;
}