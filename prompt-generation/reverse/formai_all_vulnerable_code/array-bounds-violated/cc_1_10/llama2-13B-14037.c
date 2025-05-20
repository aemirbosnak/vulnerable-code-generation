//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 1024

// Structure to hold the binary data
typedef struct {
    uint8_t data[MAX_INPUT_SIZE];
    size_t size;
} binary_data_t;

// Function to convert binary data to text
void binary_to_text(binary_data_t *data) {
    size_t i, j;
    char buffer[MAX_OUTPUT_SIZE];

    // Initialize output buffer
    buffer[0] = '\0';

    // Iterate through the input data
    for (i = 0; i < data->size; i++) {
        // If the current byte is not zero, add it to the output buffer
        if (data->data[i] != 0) {
            buffer[j++] = data->data[i];
        }
    }

    // Output the resulting text
    printf("%s\n", buffer);
}

// Function to convert text to binary data
void text_to_binary(binary_data_t *data) {
    size_t i, j;
    char buffer[MAX_INPUT_SIZE];

    // Initialize output buffer
    buffer[0] = '\0';

    // Iterate through the input text
    for (i = 0; i < strlen(data->data); i++) {
        // If the current character is not a space, add it to the output buffer
        if (data->data[i] != ' ') {
            buffer[j++] = data->data[i];
        }
    }

    // Convert the output buffer to binary data
    for (j = 0; j < j; j++) {
        data->data[i++] = buffer[j];
    }

    // Set the size of the binary data
    data->size = i;
}

int main() {
    binary_data_t data;

    // Prompt the user for input
    printf("Enter binary data (or press Enter for no input): ");

    // Read the input data
    fgets(data.data, MAX_INPUT_SIZE, stdin);

    // Convert the input data to text
    binary_to_text(&data);

    // Prompt the user for output format (text or binary)
    printf("Enter 't' for text output or 'b' for binary output: ");

    // Read the output format
    char output_format = getchar();

    // Convert the input data to the requested output format
    if (output_format == 't') {
        text_to_binary(&data);
    } else if (output_format == 'b') {
        binary_to_text(&data);
    } else {
        printf("Invalid output format. Exiting...\n");
        return 1;
    }

    // Print the resulting data
    printf("Resulting data (%c): %s\n", output_format, data.data);

    return 0;
}