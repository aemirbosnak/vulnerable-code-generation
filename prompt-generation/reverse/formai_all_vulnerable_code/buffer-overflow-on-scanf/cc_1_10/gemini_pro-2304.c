//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Thread structure
typedef struct {
    char *binary;
    int length;
    int decimal;
} thread_data;

// Thread function
void *convert_binary_to_decimal(void *arg) {
    thread_data *data = (thread_data *)arg;

    // Convert the binary string to an integer
    int decimal = 0;
    for (int i = data->length - 1; i >= 0; i--) {
        if (data->binary[i] == '1') {
            decimal += (1 << (data->length - 1 - i));
        }
    }

    // Store the decimal value in the thread data structure
    data->decimal = decimal;

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Get the binary string from the user
    char binary[100];
    printf("Enter a binary string: ");
    scanf("%s", binary);

    // Get the length of the binary string
    int length = strlen(binary);

    // Create a thread data structure
    thread_data data;
    data.binary = binary;
    data.length = length;

    // Create a thread
    pthread_t thread;
    pthread_create(&thread, NULL, convert_binary_to_decimal, &data);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Print the decimal value
    printf("The decimal value is: %d\n", data.decimal);

    return 0;
}