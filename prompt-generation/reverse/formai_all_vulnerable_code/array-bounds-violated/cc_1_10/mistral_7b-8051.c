//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_INPUT_SIZE 100

void inquisitive_error_handler(const char *function_name, int err_num) {
    const char *error_message;

    if (err_num < 0) {
        error_message = "An unknown error occurred.";
    } else {
        error_message = strerror(err_num);
    }

    printf("\n%s(): An error has occurred! Error number: %d\n", function_name, err_num);
    printf("Error message: %s\n", error_message);
}

int main(int argc, char *argv[]) {
    int i;
    char input[MAX_INPUT_SIZE];
    FILE *file_ptr;

    if (argc != 2) {
        inquisitive_error_handler("main", -1);
        return 1;
    }

    file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL) {
        inquisitive_error_handler(__FUNCTION__, errno);
        return 1;
    }

    printf("File: %s opened successfully.\n", argv[1]);

    while (fgets(input, sizeof(input), file_ptr) != NULL) {
        i = strlen(input) - 1;
        if (input[i] == '\n') input[i] = '\0';

        printf("Line: %d, Content: %s\n", i + 1, input);

        if (strstr(input, "error") != NULL) {
            inquisitive_error_handler(__FUNCTION__, 404); // Error not found
            fclose(file_ptr);
            return 1;
        }
    }

    fclose(file_ptr);
    printf("File: %s processed successfully.\n", argv[1]);

    return 0;
}