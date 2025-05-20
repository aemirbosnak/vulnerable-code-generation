//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define DELIMITER " "

char *input_buffer = NULL;
int input_buffer_size = BUFFER_SIZE;
int input_buffer_index = 0;

void init_input_buffer() {
    input_buffer = malloc(input_buffer_size * sizeof(char));
    if (input_buffer == NULL) {
        printf("Error: Failed to allocate input buffer.\n");
        exit(1);
    }
    input_buffer[0] = '\0';
    input_buffer_index = 0;
}

void append_to_input_buffer(char ch) {
    if (input_buffer_index >= input_buffer_size) {
        input_buffer_size += BUFFER_SIZE;
        input_buffer = realloc(input_buffer, input_buffer_size * sizeof(char));
        if (input_buffer == NULL) {
            printf("Error: Failed to reallocate input buffer.\n");
            exit(1);
        }
    }
    input_buffer[input_buffer_index++] = ch;
    input_buffer[input_buffer_index] = '\0';
}

void clear_input_buffer() {
    input_buffer_index = 0;
    input_buffer[0] = '\0';
}

void remove_trailing_whitespace(char *str) {
    int i;
    for (i = strlen(str) - 1; i >= 0 && isspace(str[i]); i--) {
        str[i] = '\0';
    }
}

int main() {
    init_input_buffer();
    printf("Enter a string: ");
    fgets(input_buffer, input_buffer_size, stdin);
    clear_input_buffer();
    char *token = strtok(input_buffer, DELIMITER);
    while (token!= NULL) {
        printf("%s\n", token);
        token = strtok(NULL, DELIMITER);
    }
    return 0;
}