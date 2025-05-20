//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024

int main() {
    char input_buffer[MAX_LINE_SIZE];
    char *output_buffer = NULL;
    size_t output_buffer_size = 0;

    while (1) {
        printf("Enter a binary number (or type 'exit' to quit): ");
        if (fgets(input_buffer, MAX_LINE_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (strcmp(input_buffer, "exit") == 0) {
            break;
        }

        output_buffer = malloc(output_buffer_size + strlen(input_buffer) + 1);
        if (output_buffer == NULL) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        strcat(output_buffer, input_buffer);
        output_buffer_size += strlen(input_buffer);
    }

    printf("Enter the output file name: ");
    char output_file_name[MAX_LINE_SIZE];
    if (fgets(output_file_name, MAX_LINE_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fwrite(output_buffer, 1, output_buffer_size, output_file);
    fclose(output_file);

    free(output_buffer);
    printf("Done.\n");

    return 0;
}