//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100
#define MAX_OUTPUT_LEN 200

// Define a struct to hold the binary data
typedef struct {
    char data[MAX_INPUT_LEN];
    int len;
} binary_data_t;

// Function to convert binary data to text
void binary_to_text(binary_data_t *data) {
    int i, j;
    char temp[MAX_OUTPUT_LEN];

    // Initialize the output string
    temp[0] = '\0';

    // Loop through the binary data
    for (i = 0; i < data->len; i++) {
        // Check if the current bit is set
        if (data->data[i] == 1) {
            // If set, add a 1 to the output string
            temp[j++] = '1';
        } else {
            // If not set, add a 0 to the output string
            temp[j++] = '0';
        }
    }

    // Print the output string
    printf("Binary to Text: %s\n", temp);
}

// Function to convert text data to binary
void text_to_binary(binary_data_t *data) {
    int i, j;
    char temp[MAX_OUTPUT_LEN];

    // Initialize the output string
    temp[0] = '\0';

    // Loop through the text data
    for (i = 0; i < strlen(data->data); i++) {
        // Check if the current character is a 1 or a 0
        if (data->data[i] == '1') {
            // If 1, add a 1 to the output string
            temp[j++] = 1;
        } else if (data->data[i] == '0') {
            // If 0, add a 0 to the output string
            temp[j++] = 0;
        }
    }

    // Print the output string
    printf("Text to Binary: %s\n", temp);
}

int main() {
    binary_data_t data;

    // Prompt the user for binary data
    printf("Enter binary data (max length %d): ", MAX_INPUT_LEN);
    fgets(data.data, MAX_INPUT_LEN, stdin);

    // Convert the binary data to text
    binary_to_text(&data);

    // Prompt the user for text data
    printf("Enter text data (max length %d): ", MAX_OUTPUT_LEN);
    fgets(data.data, MAX_OUTPUT_LEN, stdin);

    // Convert the text data to binary
    text_to_binary(&data);

    return 0;
}