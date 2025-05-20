//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Define the maximum length of a hexadecimal string
#define MAX_HEX_LEN 100

// Define the thread data structure
typedef struct {
    char *hex_string;
    int start_index;
    int end_index;
    int result;
} thread_data_t;

// Define the thread function
void *thread_func(void *arg) {
    // Get the thread data
    thread_data_t *data = (thread_data_t *)arg;

    // Convert the hexadecimal string to an integer
    int result = 0;
    for (int i = data->start_index; i < data->end_index; i++) {
        // Get the character at the current index
        char c = data->hex_string[i];

        // Convert the character to a digit
        int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else {
            // Invalid character
            result = -1;
            break;
        }

        // Add the digit to the result
        result = result * 16 + digit;
    }

    // Store the result in the thread data
    data->result = result;

    // Return NULL to indicate that the thread has finished
    return NULL;
}

int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hexadecimal string from the command line
    char *hex_string = argv[1];

    // Check if the hexadecimal string is valid
    for (int i = 0; i < strlen(hex_string); i++) {
        char c = hex_string[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
            printf("Invalid hexadecimal string: %s\n", hex_string);
            return EXIT_FAILURE;
        }
    }

    // Get the length of the hexadecimal string
    int hex_len = strlen(hex_string);

    // Check if the hexadecimal string is too long
    if (hex_len > MAX_HEX_LEN) {
        printf("Hexadecimal string is too long: %s\n", hex_string);
        return EXIT_FAILURE;
    }

    // Create a thread pool
    pthread_t threads[4];

    // Create the thread data
    thread_data_t data[4];

    // Divide the hexadecimal string into four parts
    int part_len = hex_len / 4;
    for (int i = 0; i < 4; i++) {
        data[i].hex_string = hex_string;
        data[i].start_index = i * part_len;
        data[i].end_index = (i + 1) * part_len;
        data[i].result = -1;
    }

    // Create the threads
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    // Join the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Check if any of the threads failed
    for (int i = 0; i < 4; i++) {
        if (data[i].result == -1) {
            printf("Invalid hexadecimal string: %s\n", hex_string);
            return EXIT_FAILURE;
        }
    }

    // Concatenate the results of the threads
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result = result * 0x100000000 + data[i].result;
    }

    // Print the result
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}